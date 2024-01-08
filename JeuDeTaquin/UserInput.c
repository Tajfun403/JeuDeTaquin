#include <stdbool.h>
#include <string.h>
#include <stdio.h>
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
	struct UserInput returnInput; {};
	if (argc % 2 == 0) 
	{
		returnInput.ErrorInfo = "Non-even amount of args!";
		returnInput.bValid = false;
		return returnInput;
	}
	// zeroth arg is always exe path
	for (int i = 1; i < argv; i += 2) {
		char* currHeader = argv[i];
		char* currVal = argv[i + 1];

		if (strcmp(currHeader, "--tableauSize")) {
			returnInput.TableuSize = atoi(currVal);
		}
		if (strcmp(currHeader, "--tableauCount")) {
			returnInput.TableuCount = atoi(currVal);
		}
		if (strcmp(currHeader, "--inputPath")) {
			returnInput.InputPath = currVal;
		}
	}
	returnInput.bValid = true;
	return returnInput;
}

struct UserInput ReadUserInputFromPrompts() {
	struct UserInput returnInput; {};
	char buffer[100];
	int intBuffer;
	printf("Do you want to generate new table set [1] or reuse existing one [2]? [1/2]: ");
	scanf("%i", &buffer);
	intBuffer = atoi(buffer);
	if (intBuffer == 1) {
		printf("Size of each tableau (number of items): ");
		scanf("%i", &buffer);
		returnInput.TableuSize = atoi(buffer);
		printf("Count of tabeaus: ");
		scanf("%i", &buffer);
		returnInput.TableuCount = atoi(buffer);
	}
	else if (intBuffer == 2) {
		printf("Path to directory with tableaus:");
		scanf("%s", &buffer);
		returnInput.InputPath = buffer;
	}
	else {
		returnInput.ErrorInfo = "Invalid operation requested";
		returnInput.bValid = false;
		return returnInput;
	}
	returnInput.bValid = true;
	return returnInput;
}