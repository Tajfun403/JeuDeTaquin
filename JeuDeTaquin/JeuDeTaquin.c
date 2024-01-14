// JeuDeTaquin.cpp : Defines the entry point for the application.
//

#define MULTITHREAD

#include "JeuDeTaquin.h"
#include "Helpers/UserInputStruct.h"
#include "Helpers/UserInput.h"
#include "Helpers/BatchRunners.h"

int main(int argc, char* argv[])
{
	struct UserInput input = TakeUserInput(argc, argv);
	if (!input.bValid) {
		printf("Could not read input!\n");
		printf("Exception body: %s!\n", input.ErrorInfo);
	}

	struct Tableau* tables;
	if (!ShouldUseExistingTables(input)) {
		printf("Generating tables\n");
		tables = GenerateTables(input.TableauSize, input.TableauCount);
	}
	else {
		tables = LoadTableaus(input.InputPath, &input.TableauCount);
	}

	// TODO analyze tables - multithreading
	printf("Analzying tables\n");
	char* resultsImg = AnalyzeTables("file.png", tables, input.TableauCount);

	// TODO draw the graph

	// TODO ask user if they wanna the tables?
	// TODO output performance info
}
