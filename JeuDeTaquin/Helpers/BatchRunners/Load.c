#pragma once
#include <stdlib.h>
#include "../../Graph/GraphItem.h"
#include "../../ArrayGen/TableauStructure.h"
#include "../../ArrayGen/TableauGen.h"
#include <stdbool.h>
#include "../../ArrayAnalyze/ArrayAnalyze.h"
#include "Windows.h"
#include "../Exceptions.h"
#include "stdio.h"
#include "../Clock.h"
#include "../MultithreadHelper.h"
#include "Load.h"

struct Tableau** LoadTableausSingleThread(char* path, int* n)
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

struct Tableau** LoadTableausMultiThread(char* path, int* n) {
	printf("Quering directory...\n");
	int CurrCapacity = 1;
	char** inputArray = malloc(1 * sizeof(char*));
	// first: find paths of all files to load
	
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
			inputArray = realloc(inputArray, CurrCapacity * sizeof(char*));
		}
		char* realPath = malloc(MAX_PATH);
		// findData.cFileName only returns the file name - with NO directory name
		sprintf(realPath, "%s//%s", path, foundData.cFileName);
		inputArray[i] = realPath;
		i++;
	} while (FindNextFile(hFind, &foundData));

	struct Tableau** outputArray = (struct Tableau**)malloc(i * sizeof(struct Tableau*));

	RunBatch(LoadTable_Thread, inputArray, outputArray, i);

	for (size_t j = 0; j < i; j++)
	{
		// throws exceptions
		// free(inputArray[j]);
	}
	// free(inputArray);

	*n = i;
	return outputArray;
}

static void* LoadTable_Thread(void* input) {
	// input is a file path
	// output is a pointer to a loaded struct Tableau*

	return LoadTableauFromFile(input);
}
