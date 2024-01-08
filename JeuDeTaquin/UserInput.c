#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "UserInputStruct.h"
#include "UserInput.h"

struct UserInput TakeUserInput(int argc, char* argv[])
{
	if (argc <= 1)
		return ReadUserInputFromPrompts();
	else
		return ReadUserInputFromArgs(argc, argv);
}

struct UserInput ReadUserInputFromArgs(int argc, char* argv[]) {
	struct UserInput returnInput = { 0 };
	if (argc % 2 == 0) 
	{
		char* error = (char*)malloc(40);
		strcpy(error, "Non-even amount of args!");
		returnInput.ErrorInfo = error;
		returnInput.bValid = false;
		return returnInput;
	}
	// zeroth arg is always exe path
	for (int i = 1; i < argc; i += 2) {
		char* currHeader = argv[i];
		char* currVal = argv[i + 1];

		if (strcmp(currHeader, "--tableauSize")) {
			returnInput.TableauSize = atoi(currVal);
		}
		if (strcmp(currHeader, "--tableauCount")) {
			returnInput.TableauCount = atoi(currVal);
		}
		if (strcmp(currHeader, "--inputPath")) {
			returnInput.InputPath = currVal;
		}
	}
	returnInput.bValid = true;
	return returnInput;
}

struct UserInput ReadUserInputFromPrompts() {
	struct UserInput returnInput = {0};
	char buffer[100];
	int intBuffer;
	printf("Do you want to generate new table set [1] or reuse existing one [2]? [1/2]: ");
	scanf("%i", &intBuffer);
	if (intBuffer == 1) {
		printf("Size of each tableau (number of items): ");
		scanf("%i", &intBuffer);
		returnInput.TableauSize = intBuffer;
		printf("Count of tabeaus: ");
		scanf("%i", &intBuffer);
		returnInput.TableauCount = intBuffer;
	}
	else if (intBuffer == 2) {
		printf("Path to directory with tableaus:");
		scanf("%s", &buffer);
		returnInput.InputPath = buffer;
	}
	else {
		char* error = (char*)malloc(40);
		strcpy(error, "Invalid operation requested");
		returnInput.ErrorInfo = error;
		returnInput.bValid = false;
		return returnInput;
	}
	returnInput.bValid = true;
	return returnInput;
}