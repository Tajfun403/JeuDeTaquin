#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graph.h"
#include "GraphItem.h"
#include "../Helpers/Exceptions.h"

void SetAverages(struct GraphItem** arr, int n) {
	int range = n * 0.05;
	for (int i = 0; i < n; i++) {
		int currCount = 0;
		double currSum = 0;
		for (int j = i - range; j < i + range; j++) {
			if (j < 0 || j >= n) continue;
			currSum += arr[j]->Y;
			currCount++;
		}
		arr[i]->Avg = currSum / currCount;
	}
}

char* GenerateDB(struct GraphItem** arr, int n) {
	char* fileName = malloc(100);
	sprintf(fileName, "%s.dat", tmpnam(NULL)); // file path is created in user TEMP folder
	FILE* f = fopen(fileName, "w");
	if (f == NULL) {
		LOG_ERROR("Could not save database file!");
		return NULL;
	}

	fprintf(f, "# X Y Avg\n");
	for (int i = 0; i < n; i++) {
		fprintf(f, "%f %i %f\n", arr[i]->X, arr[i]->Y, arr[i]->Avg);
	}
	fclose(f);
	return fileName;
}

void GenerateGraph(struct GraphItem** arr, int n, char* imgPath) {
		// get both data sets
		// feed both to gnuplot. One with lines, the other without

		SetAverages(arr, n);
		char* DB = GenerateDB(arr, n);

		char cmd[10000];
		char* midBuff[100];

		strcpy(cmd, "gnuplot -e \"");
		strcat(cmd, "set terminal png size 1500, 1000;");

		sprintf(midBuff, "set output '%s';", imgPath);
		strcat(cmd, midBuff);

		sprintf(midBuff, "plot '%s' using 1:2 with points,", DB);
		strcat(cmd, midBuff);

		sprintf(midBuff, "'%s' using 1:3 with lines", DB);
		strcat(cmd, midBuff);
		strcat(cmd, "\"");

		system(cmd);
}