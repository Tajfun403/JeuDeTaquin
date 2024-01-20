// JeuDeTaquin.cpp : Defines the entry point for the application.
//

#define MULTITHREAD

#include "JeuDeTaquin.h"
#include "Helpers/UserInputStruct.h"
#include "Helpers/UserInput.h"
#include "Helpers/BatchRunners.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	// struct UserInput* input = malloc(sizeof(struct UserInput));
	struct UserInput input = { 0 };
	if (!TakeUserInput(&input, argc, argv)) {
		printf("Could not read input!\n");
		return;
	}

	struct Tableau** tables;
	if (!ShouldUseExistingTables(input)) {
		printf("Generating tables\n");
		tables = GenerateTables(input.TableauSize, input.TableauCount);
	}
	else {
		tables = LoadTableaus(input.InputPath, &input.TableauCount);
	}

	// save the tables if user wanted to
	if (input.TablesOutputPath != NULL) {
		SaveTableaus(input.TablesOutputPath, tables, input.TableauCount);
	}

	printf("Analzying tables\n");
	char* resultsImg = AnalyzeTables(input.ImgOutputPath, tables, input.TableauCount, input.TableauSize);

	// run the generated image with graph
	system(resultsImg);
}
