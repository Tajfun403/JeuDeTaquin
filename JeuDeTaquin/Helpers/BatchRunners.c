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
#include "BatchRunners/Save.h"
#include "BatchRunners/Load.h"

struct Tableau** GenerateTables(int size, int count)
{
	return GenerateTablesMultiThread(size, count);
	// return GenerateTablesSingleThread(size, count);
}

void SaveTableaus(char* path, struct Tableau** arr, int n) 
{
	SaveTableausMultiThreaded(path, arr, n);
	// SaveTableausSingleThread(path, arr, n);
}

struct Tableau** LoadTableaus(char* path, int* n)
{
	LoadTableausMultiThread(path, n);
	// LoadTableausSingleThread(path, n);
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
