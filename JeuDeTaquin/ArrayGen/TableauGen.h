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
		//it'll be useful for throwing replaced element to the next row
		float nextElementValue = -1.0;
		float* nextElement = &nextElementValue;
		while (isThereAnyElementLeft != 0)
		{
			//resize tableau if its to small
			if (tableau->numberOfRows < currentRow)
			{
				tableau->tableau = ResizeTableau(tableau->tableau, &(tableau->numberOfRows));
			}
			tableau->tableau[currentRow] = ThrowElementToRow(tableau->tableau[currentRow], tableau->set[element], &(tableau->sizesOfRows[currentRow]), nextElement);
			//if theres no element to throw (when the new element is the smallest), we can go to the next element of set
			if (*nextElement == -1.0) 
			{
				isThereAnyElementLeft = 0;
			}
			//if theres a element to throw to next row
			else
			{
				currentRow++;
			}
		}
		free(nextElement);
	}
}