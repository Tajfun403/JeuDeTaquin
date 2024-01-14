#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TableauStructure.h"
#include "RandomSetStruct.h"
#include <math.h>
#include <stdbool.h>
#define MAXDIGITS 10
#define DIGITS_OF_STARTING_NUMBERS 2
#define LOCALISATION ""


//Generating + debugging and testing tools

// Saves one tab to a separate file
/*
FILE STRUCTURE:
1st line: how many rows\n
2nd line: length od the longest row\n
rest: tableau
*/
void SaveTableau(struct Tableau tab)
{
	//Some functions as sprints and fopen etc wont work in VS, so i have to use safe versions
	/* We want to have an ordered files naming system.I think the best names will be the first numbers,
	as we will create the chart according to them*/
	int idNumber = tab.startingNr * pow(10, DIGITS_OF_STARTING_NUMBERS);
	FILE* file;
	//Localization and name of the file
	char name[10];
	int last = tab.numberOfRows - 1;
	//sprintf(name, "%d.txt", idNumber);
	// We set the name of the file and its localization
	sprintf_s(name, 10, "%s0,%d.txt", LOCALISATION, idNumber);

	//file = fopen(name, "a");
	fopen_s(&file, name, "a");
	fprintf_s(file, "%i\n", tab.numberOfRows); // first line - how many rows there are
	fprintf_s(file, "%i\n", tab.sizesOfRows[0]); //second line - length of the longest row, the first is always the longest
	for (int row = last; row >= 0; row--)
	{
		for (int number = 0; number < tab.sizesOfRows[row]; number++)
		{
			fprintf_s(file, "%f;", tab.tableau[row][number]);
		}
		fprintf_s(file, "\n");

	}
	fclose(file);
}

void PrintRow(float row[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%f", row[i]);
	}
}
void PrintTableau(struct Tableau tab)
{
	for (int i = 0; i < tab.numberOfRows; i++)
	{
		for (int j = 0; j < tab.sizesOfRows[i]; j++)
		{
			printf("%f", tab.tableau[i][j]);
		}
		printf("\n");
	}
	printf("\n \n \n");
}


struct Tableau* GenerateTableau(double startingNum, int setSize)
{
	struct Tableau* tableau = malloc(sizeof(struct Tableau));
	float* randomSet = (float*)malloc(sizeof(float) * setSize);
	tableau->startingNr = startingNum;
	randomSet[0] = startingNum;
	GenerateRandomSet(randomSet, setSize);
	for (int element = 0; element < setSize; element++)
	{
		int currentRow = 0;
		bool isThereAnyElementLeft = true;
		float nextElementValue = randomSet[element];
		float* nextElement = &nextElementValue;
		while (isThereAnyElementLeft != 0)
		{
			//printf("Current row: %i \n", currentRow);
			// <= because if we have 1 row, thats the row index: 0, and current row may be 1, row[1] doesnt exist
			if (tableau->numberOfRows <= currentRow)
			{
				//printf("%i", currentRow);
				//printf("%i", tableau->numberOfRows);
				tableau->tableau = ResizeTableau(tableau->tableau, &(tableau->numberOfRows));
				tableau->sizesOfRows = ResizeSizesArray(tableau->sizesOfRows, tableau->numberOfRows);
			}
			//printf("STAGE\n");
			//PrintTableau(*tableau);
			tableau->tableau[currentRow] = ThrowElementToRow(tableau->tableau[currentRow], nextElementValue, &(tableau->sizesOfRows[currentRow]), nextElement);

			if (*nextElement == -1.0) //if theres no element to throw, we can go to the next element of set
			{
				isThereAnyElementLeft = false;
			}//if theres a element to throw to next row
			else
			{
				currentRow++;
			}
			//assert(nextElement != NULL);
			// PrintTableau(*tableau);
		}

	}
	return tableau;
}