#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graph.h"
#include "GraphItem.h"

void SetAverages(struct GraphItem* arr, int n) {
	int range = n * 0.1;
	for (int i = 0; i < n; i++) {
		int currCount = 0;
		double currSum = 0;
		for (int j = i - range; j < i + range; j++) {
			if (j < 0 || j >= n) continue;
			currSum += arr[j].Y;
			currCount++;
		}
		arr[i].Avg = currSum / currCount;
	}
}

char* GenerateDB(struct GraphItem* arr, int n) {
	char fileName[20];
	sprintf(fileName, "DB_%s.dat", tmpnam(NULL));
	FILE* f = fopen(fileName, "w");
	if (f == NULL) return NULL;

	fprintf(f, "# X Y Avg\n");
	for (int i = 0; i < n; i++) {
		fprintf(f, "%f %f %f", arr[i].X, arr[i].Y, arr[i].Avg);
		fclose(f);
		return fileName;
	}
}

void GenerateGraph(struct GraphItem* arr, int n, char* imgPath) {
		// get both data sets
		// feed both to gnuplot. One with lines, the other without

		SetAverages(arr, n);
		char* DB = GenerateDB(arr, n);

		char cmd[10000];

		strcpy(cmd, "gnuplot -e \"");
		strcat(cmd, "set terminal png size 1500, 1000;");
		strcat(cmd, "set output '");
		strcat(cmd, DB);
		strcat(cmd, "';");
		strcat(cmd, "plot ");
		strcat(cmd, DB);
		strcat(cmd, "using 1:2 with points\\");
		strcat(cmd, "'' using 1:3 with lines;");

		system(cmd);
}