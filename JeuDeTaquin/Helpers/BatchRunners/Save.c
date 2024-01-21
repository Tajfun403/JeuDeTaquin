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
#include "SaveData.h"
#include "../MultithreadHelper.h"
#include "Save.h"
#include "Math.h"

void SaveTableausSingleThread(char* path, struct Tableau** arr, int n) {
	printf("Saving tables...\n");
	// make sure dir exists
	// if it already does, this command will do nothing
	if (!CreateDirectory(path, NULL) && GetLastError() == ERROR_ALREADY_EXISTS) {
		LOG_WARNING("Save tables directory already exists. Files will be overwritten\n");
	}
	long timeStart = GetCurrTimeMs();
	int digitsCount = ceil(log10(n));
	for (size_t i = 0; i < n; i++)
	{
		char fileName[MAX_PATH];
		// https://stackoverflow.com/questions/13100821/variable-leading-zeroes-in-c99-printf#comment81624295_13100838
		sprintf(fileName, "%s//Table_%.*d.jdt", path, digitsCount, i);
		SaveTableau(*arr[i], fileName);
		// SaveTableau(*(arr[i]), path);
	}
	printf("Finished in %.3fs\n", (GetCurrTimeMs() - timeStart) / 1000.0);
}

void SaveTableausMultiThreaded(char* path, struct Tableau** arr, int n) {
	// make sure dir exists
	// if it already does, this command will do nothing
	if (!CreateDirectory(path, NULL) && GetLastError() == ERROR_ALREADY_EXISTS) {
		LOG_WARNING("Save tables directory already exists. Files will be overwritten\n");
	}

	int digitsCount = ceil(log10(n));
	struct SaveData** inputArray = malloc(sizeof(struct SaveData*) * n);
	for (size_t i = 0; i < n; i++)
	{
		inputArray[i] = malloc(sizeof(struct SaveData));
		inputArray[i]->basePath = path;
		inputArray[i]->index = i;
		inputArray[i]->tableau = arr[i];
		inputArray[i]->digitsCount = digitsCount;
	}

	RunBatch(SaveTable_Thread, inputArray, NULL, n);

	for (size_t i = 0; i < n; i++)
	{
		free(inputArray[i]);
	}
	free(inputArray);
}

void* SaveTable_Thread(void* input) {
	// Input is a tuple<tableau, basePath, index>
	// no output
	struct SaveData* data = (struct SaveData*)input;

	char fileName[MAX_PATH];
	sprintf(fileName, "%s//Table_%.*d.jdt", data->basePath, data->digitsCount, data->index);
	SaveTableau(*(data->tableau), fileName);
}