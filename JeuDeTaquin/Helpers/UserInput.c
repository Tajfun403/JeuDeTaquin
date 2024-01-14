#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "UserInputStruct.h"
#include "UserInput.h"
#include "Exceptions.h"

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
		if (strcmp(currHeader, "--tablesOutputPath")) {
			returnInput.TablesOutputPath = currVal;
		}
		if (strcmp(currHeader, "--imgOutputPath")) {
			returnInput.ImgOutputPath = currVal;
		}
	}
	returnInput.bValid = true;
	return returnInput;
}

struct UserInput ReadUserInputFromPrompts() {
	struct UserInput returnInput = {0};
	char buffer[100];
	int intBuffer;
#pragma region Generate or take tables
	printf("Do you want to generate new table set [1] or reuse existing one [2]? [1/2]: ");
	scanf("%i", &intBuffer);
	if (intBuffer == 1) {
		printf("Size of each tableau (number of items): ");
		scanf("%i", &intBuffer);
		returnInput.TableauSize = intBuffer;
		printf("Count of tabeaus: ");
		scanf("%i", &intBuffer);
		returnInput.TableauCount = intBuffer;

#pragma region Save tables
		printf("Do you want to save tables [1] or keep them in memory only [2]? [1/2]: ");
		scanf("%i", &intBuffer);
		if (intBuffer == 1) {
			printf("Provide path to save the tables in: ");
			scanf("%s", &buffer);
			returnInput.TablesOutputPath = (char*)malloc(100);
			strcpy(returnInput.TablesOutputPath, buffer);
		}
#pragma endregion
	}
	else if (intBuffer == 2) {
		printf("Path to directory with tableaus:");
		scanf("%s", &buffer);
		returnInput.InputPath = (char*)malloc(100);
		strcpy(returnInput.InputPath, buffer);
	}
	else {
		LOG_ERROR("Invalid operation requested");
		char* error = (char*)malloc(40);
		strcpy(error, "Invalid operation requested");
		returnInput.ErrorInfo = error;
		returnInput.bValid = false;
		return returnInput;
	}
#pragma endregion

	returnInput.bValid = true;
	return returnInput;
}

bool ShouldUseExistingTables(struct UserInput input) {
	return input.InputPath != NULL;
}

void DrawUsage(void)
{
	printf("Jeu de Taquin (C) 2024");
	printf("Usage: ");
	printf("\t--tableauSize size\t - amount of items in each tableau. Only if inputPath was not specified");
	printf("\t--tableauCount count\t - amount of tableaus. Only if inputPath was not specified");
	printf("\t--inputPath path\t - if specified - a path to directory with generated tables");
	printf("\t[--tablesOutputPath path]\t - if specified - a path to directory to save the generated tables in");
	printf("\t                \t - otherwise, tables will be kept in memory only");
	printf("\t[--imgOutputPath path]\t - if specified - a path to save the generated graph to");
	printf("\t                \t - otherwise, graph will be saved in a random file");
}
