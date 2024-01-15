#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "UserInputStruct.h"
#include "UserInput.h"
#include "Exceptions.h"
#include "ManagmentRequirements.h"

bool TakeUserInput(struct UserInput* returnInput, int argc, char* argv[])
{
	if (argc <= 1)
		return ReadUserInputFromPrompts(returnInput) && ValidateUserInput(returnInput);
	else
		return ReadUserInputFromArgs(returnInput, argc, argv) && ValidateUserInput(returnInput);
}

bool ReadUserInputFromArgs(struct UserInput* returnInput, int argc, char* argv[]) {
	if (returnInput == NULL) {
		returnInput = malloc(sizeof(struct UserInput));
	}
	// zero all properties
	// *returnInput = (struct UserInput){ 0 };
	bool bUnparsedArgsPresent = false;
	// zeroth arg is always exe path
	// expect help command
	if (argc == 2) {
		char* currHeader = argv[1];
		// no idea why it does not match ¯\_(ツ)_/¯
		if (strcmp(currHeader, "--help")) {
			DrawUsage();
			return false;
		}
		else {
			DrawUsage();
			return false;
		}
	}
	if (argc % 2 != 1) {
		// non-even amount of non-exe args! Something is off
		LOG_ERROR("Amount of headers and values do not match!\n");
		return returnInput;
	}
	for (int i = 1; i < argc; i += 2) {
		char* currHeader = argv[i];
		char* currVal = argv[i + 1];

		if (strcmp(currHeader, "--tableauSize")) {
			returnInput->TableauSize = atoi(currVal);
		}
		else if (strcmp(currHeader, "--tableauCount")) {
			returnInput->TableauCount = atoi(currVal);
		}
		else if (strcmp(currHeader, "--inputPath")) {
			returnInput->InputPath = currVal;
		}
		else if (strcmp(currHeader, "--tablesOutputPath")) {
			returnInput->TablesOutputPath = currVal;
		}
		else if (strcmp(currHeader, "--imgOutputPath")) {
			returnInput->ImgOutputPath = currVal;
		}
		else if (strcmp(currHeader, "--help")) {
			DrawUsage();
			return returnInput;
		}
		else {
			bUnparsedArgsPresent = true;
			LOG_WARNING("Could not parse some arguments!\n");
			DrawUsage();
		}
	}
	return true;
}

bool ValidateUserInput(struct UserInput* input) {
	if (input == NULL)
		return (LOG_ERROR("Input is null!\n"), false);
	if (!ShouldUseExistingTables(*input)) {
		// we read if provided table sizes / count make senseW
		// utilizing comma operator
		// note: utilizing comma operator somewhere was forced by the specifications
		// it's just not... that awful here
		if (input->TableauCount == 0)
			return (LOG_ERROR("Tableau count not provided correctly, and no source specified.\n"), false);
		else if (input->TableauSize == 0)
			return (LOG_ERROR("Tableau size not provided correctly, and no source specified.\n"), false);
		else if (input->TableauCount < 1)
			return (LOG_ERROR("Tableau count smaller than one!\n"), false);
		else if (input->TableauSize < 1)
			return (LOG_ERROR("Tableau size smaller than one!\n"), false);
	}
	else {
		// soo user should provide a path
	}
	return true;
}

bool ReadUserInputFromPrompts(struct UserInput* returnInput) {
	if (returnInput == NULL) {
		returnInput = malloc(sizeof(struct UserInput));
	}
	// zero all properties
	// *returnInput = (struct UserInput){ 0 };
	char buffer[255];
	int intBuffer;
#pragma region Generate or take tables
	printf("Do you want to generate new table set [1] or reuse existing one [2]? [1/2]: ");
	scanf("%i", &intBuffer);
	if (intBuffer == 1) {
		printf("Size of each tableau (number of items): ");
		scanf("%i", &intBuffer);
		returnInput->TableauSize = intBuffer;
		printf("Count of tabeaus: ");
		scanf("%i", &intBuffer);
		returnInput->TableauCount = intBuffer;

#pragma region Save tables
		printf("Do you want to keep tables in memory only [1] or save them [2]? [1/2]: ");
		scanf("%i", &intBuffer);
		if (intBuffer == 2) {
			printf("Provide path to save the tables in: ");
			scanf("%s", &buffer);
			returnInput->TablesOutputPath = (char*)malloc(100);
			strcpy(returnInput->TablesOutputPath, buffer);
		}
		else if (intBuffer != 1) {
			LOG_ERROR("Invalid operation requested!\n");
			return false;
		}
#pragma endregion
	}
	else if (intBuffer == 2) {
		printf("Path to directory with tableaus:");
		scanf("%s", &buffer);
		returnInput->InputPath = (char*)malloc(100);
		strcpy(returnInput->InputPath, buffer);
	}
	else {
		LOG_ERROR("Invalid operation requested!\n");
		return false;
	}
#pragma endregion
#pragma region Save image
	printf("Do you want to save output image to default location [1] or specify a path [2]? [1/2]: ");
	scanf("%i", &intBuffer);
	if (intBuffer == 2) {
		printf("Provide path the new image: ");
		scanf("%s", &buffer);
		returnInput->ImgOutputPath = (char*)malloc(100);
		strcpy(returnInput->ImgOutputPath, buffer);
	}
	else if (intBuffer != 1) {
		LOG_ERROR("Invalid operation requested!\n");
		return false;
	}
#pragma endregion
	return true;
}

bool ShouldUseExistingTables(struct UserInput input) {
	return input.InputPath != NULL;
}

void DrawUsage(void)
{
	printf("Jeu de Taquin (C) 2024\n");
	printf("Usage: \n");
	printf("\t--tableauSize size\t - amount of items in each tableau. Only if inputPath was not specified\n");
	printf("\t--tableauCount count\t - amount of tableaus. Only if inputPath was not specified\n");
	printf("\t--inputPath path\t - if specified - a path to directory with generated tables\n");
	printf("\t[--tablesOutputPath path]\t - if specified - a path to directory to save the generated tables in\n");
	printf("\t                \t  otherwise, tables will be kept in memory only\n");
	printf("\t[--imgOutputPath path]\t - if specified - a path to save the generated graph to\n");
	printf("\t                \t  otherwise, graph will be saved in a random file\n");
}
