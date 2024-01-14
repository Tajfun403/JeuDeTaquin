#include <stdlib.h>
#include "../../ArrayGen/TableauStructure.h"
#include "GenerateData.h"
#include "../MultithreadHelper.h"
#include "../../Graph/GraphItem.h"
#include "../../Graph/Graph.h"
#include "../../ArrayAnalyze/ArrayAnalyze.h";
#include "Analyze.h"


char* AnalyzeTablesMultiThreaded(char* imgPath, struct Tableau** tableaus, int n, int tableSize) {
	struct GraphItem** results = malloc(sizeof(struct GraphItem*) * n);

	RunBatch(&AnalyzeTable_Thread, tableaus, results, n);

	printf("Generating graph\n");
	return GenerateGraph(results, n, imgPath, tableSize);
}

void* AnalyzeTable_Thread(void* input) {
	// Input is a pointer to a table
	// output is a pointer to a GraptItem
	struct Tableau* table = (struct Tableau*)input;

	int solution = SolveTableau(table);
	struct GraphItem* graphItem = malloc(sizeof(struct GraphItem));
	graphItem->X = table->startingNr;
	graphItem->Y = solution;
	graphItem->currRange = 0;
	graphItem->currSum = 0;
	return graphItem;

}