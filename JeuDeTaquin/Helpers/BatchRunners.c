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

struct Tableau** GenerateTables(int size, int count)
{
	return GenerateTablesMultiThread(size, count);
	// return GenerateTablesSingleThread(size, count);
}

void SaveTableaus(char* path, struct Tableau** arr, int n) 
{
	// make sure dir exists
	// if it already does, this command will do nothing
	if (!CreateDirectory(path, NULL) && GetLastError() == ERROR_ALREADY_EXISTS) {
		LOG_WARNING("Save tables directory already exists. Files will be overwritten\n");
	}
	for (size_t i = 0; i < n; i++)
	{
		char fileName[MAX_PATH];
		sprintf(fileName, "%s//Table_%i.jdt", path, i);
		SaveTableau(*arr[i], fileName);
		// SaveTableau(*(arr[i]), path);
	}
}

struct Tableau** LoadTableaus(char* path, int* n)
{
	int CurrCapacity = 1;
	struct Tableau** tableausArray = malloc(CurrCapacity * sizeof(struct Tableau*));

	// https://stackoverflow.com/a/7773561
	HANDLE hFind;
	WIN32_FIND_DATA FindData;
	int i = 0;

	char searchPattern[MAX_PATH];
	sprintf("%s//%s", path, "*.jdt");
	hFind = FindFirstFile(searchPattern, &FindData);
	if (hFind == NULL) {
		LOG_ERROR("Could not find any files!");
		return NULL;
	}
	tableausArray[i] = LoadTableauFromFile(FindData.cFileName);
	i++;
	while (FindNextFile(hFind, &FindData))
	{
		if (i >= CurrCapacity) {
			CurrCapacity *= 2;
			tableausArray = realloc(tableausArray, CurrCapacity * sizeof(struct Tableau*));
		}
		tableausArray[i] = LoadTableauFromFile(FindData.cFileName);
		i++;
	}
	*n = i;
	return tableausArray;
}

char* AnalyzeTables(char* imgPath, struct Tableau** tableaus, int n, int tableSize)
{
	return AnalyzeTablesMultiThreaded(imgPath, tableaus, n, tableSize);
}
