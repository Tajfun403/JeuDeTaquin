#include "Graph.h"


void SetAverages(PlotItem** arr, int n) {
	int range = n * 0.1;
	for (int i = 0; i < n; i++) {
		int currCount = 0;
		double currSum = 0;
		for (int j = i - range; j < i + range; j++) {
			if (j < 0 || j >= n) continue;
			currSum += arr[j].Y;
			currCount++;
		}
		arr[i].Avg = cureSum / currCount;
	}

char* GenerateDB(PlotItem * *arr, int n) {
	char fileName[20];
	sprintf(fileName, "DB_%s.dat", tmpnam(nullptr));
	FILE* f = fopen(filename, "w");
	if (f == nullptr) return nullptr;

	fprintf(f, "# X Y Avg\n");
	for (int i = 0; i < n; i++) {
		fprintf(f, "%f %f %f", arr[i].X, arr[i].Y, arr[i].Avg);
		fclose(f);
		return fileName;
	}

	void GenerateGraph(PlotItem * *arr, int m) {
		// get both data sets
		// feed both to gnuplot. One with lines, the other without

		SetAverages(arr, n);
		char* DB = GenerateDB(arr, n);

		char cmd[10000];

		strcpy(cmd, "gnuplot -e \"");
		strcat(cmd, "set terminal png size 1500, 1000;")
		strcat(cmd, "set output '");
		strcat(cmd, filename);
		strcat(cmd, "';");
		strcat(cmd, "plot ");
		strcat(cmd, DB);
		strcat(cmd, "using 1:2 with points\");
		strcat(cmd, "'' using 1:3 with lines;");

		system(cmd);
	}
