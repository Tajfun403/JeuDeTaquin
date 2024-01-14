#include <stdlib.h>
#include "../../ArrayGen/TableauStructure.h"
#include "../../ArrayGen/TableauGen.h"
#include <stdbool.h>
#include "GenerateData.h"
#include "../MultithreadHelper.h"
#include "Generate.h"

struct Tableau** GenerateTablesSingleThread(int size, int count)
{
	struct Tableau** arr = (struct Tableau**)malloc(count * sizeof(struct Tableau*));
	for (size_t i = 0; i < count; i++)
	{
		float CurrStartNum = (float)i / count;
		arr[0] = GenerateTableau(CurrStartNum, size);
	}
	return arr;
}

struct Tableau** GenerateTablesMultiThread(int size, int count) {
	struct GenData** inputArray = malloc(sizeof(struct GenData*) * count);
	for (size_t i = 0; i < count; i++)
	{
		inputArray[i] = malloc(sizeof(struct GenData));
		float CurrStartNum = (float)i / count;
		inputArray[i]->size = size;
		inputArray[i]->startingNum = CurrStartNum;
	}

	struct Tableau** outputArray = (struct Tableau**)malloc(count * sizeof(struct Tableau*));

	RunBatch(&GenTable_Thread, inputArray, outputArray, count);

	return outputArray;
}

void* GenTable_Thread(void* input) {
	// Input is a tuple<startingNum, size>
	// output is a pointer to generated table
	struct GenData* data = (struct GenData*)input;

	return GenerateTableau(data->startingNum, data->size);
}
