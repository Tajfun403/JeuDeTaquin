#include "BatchRunners.h"
#include <stdlib.h>
#include "../Graph/GraphItem.h"
#include "../ArrayGen/TableauStructure.h"
#include "../ArrayGen/TableauGen.h"
#include "BatchRunners/Generate.h"
#include "BatchRunners/Analyze.h"
#include <stdbool.h>
#include "../ArrayAnalyze/ArrayAnalyze.h"
#define LOCALISATION ""


struct Tableau** GenerateTables(int size, int count)
{
	return GenerateTablesMultiThread(size, count);
	// return GenerateTablesSingleThread(size, count);
}

void SaveTableaus(char* path, struct Tableaus** arr, int n) 
{
	// TODO save tables
	for (int i = 0; i < n; i++) {
		SaveTableau(*arr[n], path);
	}
}

struct Tableau** LoadTableaus(char* path, int* n)
{
	// Array of pointers to tableaus
	struct Tableau** tableausArray = malloc(*n * sizeof(struct Tableau*)); 
	for (int i = 0; i < *n, i++)
	{
		struct Tableau* tab = LoadTableauFromFile(path);
		tableausArray[i] = tab;
	}
	return tableausArray;
}

char* AnalyzeTables(char* imgPath, struct Tableau** tableaus, int n, int tableSize)
{
	return AnalyzeTablesMultiThreaded(imgPath, tableaus, n, tableSize);
}
