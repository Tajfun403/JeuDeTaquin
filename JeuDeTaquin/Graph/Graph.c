#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include "Graph.h"
#include "GraphItem.h"
#include "../Helpers/Exceptions.h"
#include "../Helpers/Clock.h"
#include <stdlib.h>

#define OPTIMIZED_AVG
#define CHECK_BOUNDS2

#ifndef OPTIMIZED_AVG
void SetAverages(struct GraphItem** arr, int n) {
	int maxRange = n * 0.05;
	for (int i = 0; i < n; i++) {
		int currCount = 0;
		double currSum = 0;
		int currAllowedRange = min(min(i, n - i - 1), maxRange);
		for (int j = i - currAllowedRange; j < i + currAllowedRange + 1; j++) {
#ifdef CHECK_BOUNDS
			if (j < 0 || j >= n) { 
				LOG_ERROR("Tried accessing index outside of range!");
				continue; 
			}
			currCount++; // just calc it myself
#endif
			currSum += arr[j]->Y;
		}
#ifdef CHECK_BOUNDS
		assert(currCount == (currAllowedRange * 2 + 1)); // works
#endif
		currCount = currAllowedRange * 2 + 1;
		arr[i]->Avg = currSum / currCount;
	}
}
#endif // !OPTIMIZED_AVG

#ifdef OPTIMIZED_AVG
void SetAverages(struct GraphItem** arr, int n) {
	int maxRange = n * 0.05;

	// set sums for first range of elements

	for (size_t i = 0; i < n; i++)
	{
		// only take as many items into avg as possible so that it is still even
		int currAllowedRange = min(min(i, n - i - 1), maxRange);
		struct GraphItem* currItem = arr[i];

		// fill first and last element
		if (i == 0 || i == n - 1) {
			currItem->Avg = currItem->Y;
			currItem->currSum = currItem->Y;
			currItem->currRange = 0;
			continue;
		}

		// copy current sum
		currItem->currSum = arr[i - 1]->currSum;
		currItem->currRange = arr[i - 1]->currRange;
		int oldRange = currItem->currRange;

		// moving away from left border: expand range
		if (currAllowedRange > oldRange) {
#ifdef CHECK_BOUNDS
			assert(currAllowedRange == oldRange + 1);
			assert(i + oldRange >= 0 && i + oldRange + 1 >= 0);
			assert(i + oldRange < n && i + oldRange + 1 < n);
#endif
			// □X□ (range = 1)
			// to
			// □□X□□ (range = 2)
			// - so need to add two items. One with old range, one with new extedned one
			currItem->currSum += arr[i + oldRange]->Y;
			currItem->currSum += arr[i + oldRange + 1]->Y;
			currItem->currRange++;
		}

		// moving closer to borders: shrink range
		else if (currAllowedRange < oldRange) {
#ifdef CHECK_BOUNDS
			assert(currAllowedRange == oldRange - 1);
			assert(i - oldRange >= 0 && i - oldRange - 1 >= 0);
			assert(i - oldRange < n && i - oldRange - 1 < n);
#endif
			// □□X□□ (range = 2)
			// to
			// --□X□ (range = 1)
			// - again need to remove two items
			currItem->currSum -= arr[i - oldRange]->Y;
			currItem->currSum -= arr[i - oldRange - 1]->Y;
			currItem->currRange--;
		}

		// just move the average points: remove one from very left, add one from the very right
		else {
#ifdef CHECK_BOUNDS
			assert(oldRange == currAllowedRange);
			assert(i - oldRange >= 0 && i + oldRange < n);
#endif
			// -□X□-- (range = 1)
			// to
			// --□X□- (range = 1)
			// - move two times
			currItem->currSum -= arr[i - oldRange - 1]->Y;
			currItem->currSum += arr[i + oldRange]->Y;
		}

		// update average
		assert(currItem->currRange == currAllowedRange);
		if (currAllowedRange >= 1)
			currItem->Avg = ((float)currItem->currSum) / ((currAllowedRange * 2.0) + 1.0);
		else {
			currItem->Avg = currItem->Y;
			currItem->currSum = currItem->Y;
		}
	}
}
#endif 

char* GenerateDB(struct GraphItem** arr, int n) {
	char* fileName = malloc(255);
	sprintf(fileName, "%s.dat", tmpnam(NULL)); // file path is created in user TEMP folder
	FILE* f = fopen(fileName, "w");
	if (f == NULL) {
		LOG_ERROR("Could not save database file!");
		return NULL;
	}

	fprintf(f, "# X Y Avg currRange currSum\n");
	for (int i = 0; i < n; i++) {
		fprintf(f, "%f %i %f %i %i\n", arr[i]->X, arr[i]->Y, arr[i]->Avg, arr[i]->currRange, arr[i]->currSum);
	}
	fclose(f);
	return fileName;
}

char* GenerateGraph(struct GraphItem** arr, int n, char* imgPath, int tableSize) {
	// get both data sets
	// feed both to gnuplot. One with lines, the other without
	long timeStart = GetCurrTimeMs();

	if (imgPath == NULL)
		imgPath = "graph.png";
	
	SetAverages(arr, n);
	char* DB = GenerateDB(arr, n);
	printf("Prepared graph data in %.3fs\n", (GetCurrTimeMs() - timeStart) / 1000.0);
	timeStart = GetCurrTimeMs();

	char cmd[10000];
	char* midBuff[100];

	strcpy(cmd, "gnuplot -e \"");
	strcat(cmd, "set terminal png size 1200, 800;");
	sprintf(midBuff, "set title 'Jea de Taquin (%i tables, %i items each)';", n, tableSize);
	strcat(cmd, midBuff);
	// the space for font does not scale accordingly
	/* strcat(cmd, "set tics font \\\", 20\\\";");
	strcat(cmd, "set title font \\\", 40\\\";"); */
	strcat(cmd, "set style line 1 linetype 1 linewidth 1 pointtype 0 lc rgb \\\"#3661ba\\\"; ");
	strcat(cmd, "set style line 2 linetype 1 linewidth 3 pointtype 3 lc rgb \\\"#7d36ba\\\"; ");
	strcat(cmd, "set xlabel 'Starting num';");
	strcat(cmd, "set ylabel 'X + Y indices of finished cell';");

	sprintf(midBuff, "set output '%s';", imgPath);
	strcat(cmd, midBuff);

	sprintf(midBuff, "plot '%s' using 1:2 title 'Values' with points ls 1, ", DB);
	strcat(cmd, midBuff);

	sprintf(midBuff, "'%s' using 1:3 title 'Average' with lines ls 2", DB);
	strcat(cmd, midBuff);
	strcat(cmd, "\"");

	system(cmd);
	printf("Drawn graph in %.3fs", (GetCurrTimeMs() - timeStart) / 1000.0);

	char* finalImgPath = malloc(255);
	_fullpath(finalImgPath, imgPath, 255);
	return finalImgPath;

}