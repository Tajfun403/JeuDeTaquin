#include "BatchRunners.h"
#include <stdlib.h>
#include "../Graph/GraphItem.h"
#include "../ArrayGen/TableauStructure.h"
#include "../ArrayGen/TableauGen.h"
#include "BatchRunners/Generate.h"
#include "BatchRunners/Analyze.h"
#include <stdbool.h>


struct Tableau** GenerateTables(int size, int count)
{
	return GenerateTablesMultiThread(size, count);
	// return GenerateTablesSingleThread(size, count);
}

void SaveTableaus(char* path, struct Tableaus** arr, int n) 
{
	for (int i = 0; i < n; i++) {

	}
}

struct Tableau** LoadTableaus(char* path, int* n)
{
	return NULL;
}

char* AnalyzeTables(char* imgPath, struct Tableau** tableaus, int n)
{
	// TODO get amount of files
	// TODO create an array of GraphItems where the results will be saved for every run
	// TODO then feed that table into GenerateGraph();
	AnalyzeTablesMultiThreaded(imgPath, tableaus, n);
	return NULL;
}
