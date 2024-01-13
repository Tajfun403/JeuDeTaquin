// JeuDeTaquin.cpp : Defines the entry point for the application.
//

#include "JeuDeTaquin.h"
#include "UserInputStruct.h"
#include "UserInput.h"
#include "UserInput.c"
#include "BatchRunners.c"

int main(int argc, char* argv[])
{
	struct UserInput input = TakeUserInput(argc, argv);
	if (!input.bValid) {
		printf("Could not read input!\n");
		printf("Exception body: %s!\n", input.ErrorInfo);
	}

	char* TablesDir;
	if (!ShouldUseExistingTables(input)) {
		// TablesDir = GenerateTables(input.TableauSize, input.TableauCount);
	}
	else {
		TablesDir = input.InputPath;
	}

	// TODO analyze tables - multithreading
	// char* resultsImg = AnalyzeTables(TablesDir);

	// TODO draw the graph

	// TODO ask user if they wanna the tables?
	// TODO output performance info
}
