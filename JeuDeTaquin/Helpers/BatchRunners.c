#include "BatchRunners.h"
#include <stdlib.h>
#include "../Graph/GraphItem.h"
#include "../ArrayGen/TableauStructure.h"
#include "../ArrayGen/TableauGen.h"
#include "BatchRunners/Generate.h"
#include "BatchRunners/Analyze.h"
#include <stdbool.h>
#include "../ArrayAnalyze/ArrayAnalyze.h"
#include "Windows.h"
#include "Exceptions.h"
#include "stdio.h"
#include "Clock.h"
#include "BatchRunners/Save.h";

struct Tableau** GenerateTables(int size, int count)
{
	return GenerateTablesMultiThread(size, count);
	// return GenerateTablesSingleThread(size, count);
}

void SaveTableaus(char* path, struct Tableau** arr, int n) 
{
	SaveTableausMultiThreaded(path, arr, n);
}

struct Tableau** LoadTableaus(char* path, int* n)
{
	printf("Loading tables...\n");
	long timeStart = GetCurrTimeMs();
	int CurrCapacity = 1;
	struct Tableau** tableausArray = malloc(CurrCapacity * sizeof(struct Tableau*));

	// https://stackoverflow.com/a/7773561
	HANDLE hFind;
	WIN32_FIND_DATA foundData;
	int i = 0;

	char searchPattern[MAX_PATH];
	sprintf(searchPattern, "%s//*.jdt", path);
	hFind = FindFirstFile(searchPattern, &foundData);
	if (hFind == -1) {
		LOG_ERROR("Could not find any files!\n");
		exit(-1);
		return NULL;
	}
	do {
		// analyze data from prev iteration (because the initial find is a "minus oneth" iteration
		if (i >= CurrCapacity) {
			CurrCapacity *= 2;
			tableausArray = realloc(tableausArray, CurrCapacity * sizeof(struct Tableau*));
		}
		char realPath[MAX_PATH];
		// findData.cFileName only returns the file name - with NO directory name
		sprintf(realPath, "%s//%s", path, foundData.cFileName);
		tableausArray[i] = LoadTableauFromFile(realPath);
		i++;
	} while (FindNextFile(hFind, &foundData));

	*n = i;
	printf("Finished in %.3fs\n", (GetCurrTimeMs() - timeStart) / 1000.0);
	return tableausArray;
}

void PrintTables(struct Tableau** tableaus, int n) {
	if (n > 10)
		LOG_WARNING("Amount of tables to print might be excessive!\n");
	for (size_t i = 0; i < n; i++)
	{
		printf("Tableau %i\n", i);
		PrintTableau(*tableaus[i]);
	}
}

char* AnalyzeTables(char* imgPath, struct Tableau** tableaus, int n, int tableSize)
{
	return AnalyzeTablesMultiThreaded(imgPath, tableaus, n, tableSize);
}
