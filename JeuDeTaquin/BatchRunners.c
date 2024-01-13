#include "BatchRunners.h"
#include <stdlib.h>
#include "Graph/GraphItem.h"
#include "ArrayGen/TableauStructure.h"
#include "ArrayGen/TableauGen.h"
#include <stdbool.h>

struct Tableau* GenerateTables(int size, int count)
{
	struct Tableau* arr = (struct Tableau*)malloc(count * sizeof(struct Tableau));
	for (size_t i = 0; i < count; i++)
	{

	}
	return NULL;
}

void SaveTableaus(char* path, struct Tableaus* arr, int n) 
{

}

struct Tableau* LoadTableaus(char* path, int* n)
{
	return NULL;
}

char* AnalyzeTables(char* imgPath, struct Tableau* tableaus, int n)
{
	// TODO get amount of files
	// TODO create an array of GraphItems where the results will be saved for every run
	// TODO then feed that table into GenerateGraph();
	return NULL;
}
