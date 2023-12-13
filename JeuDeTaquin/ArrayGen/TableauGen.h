#include <stdio.h>
#include <stdlib.h>
#include "TableauStructure.h"


//Generating + debugging and testing tools
void SaveTableau()
{

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
}


void TableauGeneratingProcess(struct Tableau* tableau)
{
	GenerateRandomSet(tableau->set, tableau->setSize);
	for (int element = 0; element < tableau->setSize; element++)
	{
		int currentRow = 0;
		int isThereAnyElementLeft = 1;
		float nextElementValue = -1.0;
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
			tableau->tableau[currentRow] = ThrowElementToRow(tableau->tableau[currentRow], tableau->set[element], &(tableau->sizesOfRows[currentRow]), nextElement);
			if (*nextElement == -1.0) //if theres no element to throw, we can go to the next element of set
			{
				isThereAnyElementLeft = 0;
			}//if theres a element to throw to next row
			else
			{
				currentRow++;
			}
			//assert(nextElement != NULL);
		}
	}
}
//ERROR, NEXT ELEMENT IS ALWAYS 0 BRUH -> max is not being found -> rowSize in ThrowElement is always 0