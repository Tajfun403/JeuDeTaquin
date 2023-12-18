#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//All the functions that will be used in generating process
//As we operate on numbers from range [0,1] I'll be using -1f as empty cell



/*
	WARNING
	In this programme we will be using the french notation so the rows will be numbered in that order.
	  0 1 2
	3[]
	2[]
	1[][]
	0[][][]
	Therefore the cell [0][0] is in the down-left corner
	*/
struct Tableau {
	int setSize; //size of set of randomly generated numbers, the size is given as an input

	float startingNr; // the number which will be used in creating the chart later
	float* set; // set of randomly generated numbers, those will be used to generate a tabeleux
	int* sizesOfRows; //stores the sizes of the rows
	int numberOfRows; //I'll be tracking the size of rows

	float** tableau; //2d array, THE Young Tabelau

};

/*MASSIVE WARNING
For a while ill be using these 3 resize functions in that way:
function returns pointer to some array
i copy that array itd
why?
because i want to move on and ill repair it later*/

float* ResizeRow(float* row, int* size)
{
	if (*size > 0)
	{
		row = (float*)realloc(row, (*size + 1) * sizeof(float));
		*size = *size + 1;
	}
	else
	{
		row = (float*)malloc(1 * sizeof(float));
		*size = 1;
		printf("Im here %i \n", *size);
	}
	return row;
}
int* ResizeSizesArray(int* sizes, int currentRowsCounter)
{
	//printf("%p \n", sizes);
	if (currentRowsCounter > 1)
	{
		sizes = (int*)realloc(sizes, (currentRowsCounter * sizeof(int)));
	}
	else
	{
		sizes = (int*)malloc(1 * sizeof(int));
	}
	//printf("%p \n", sizes);
	return sizes; //works fine till this line
}
float** ResizeTableau(float** tableau, int* numberOfRows)
{
	if (*numberOfRows > 0)
	{
		tableau = (float**)realloc(tableau, (*numberOfRows + 1) * sizeof(float*));
		*numberOfRows++;

	}
	else
	{
		tableau = (float**)malloc(1 * sizeof(float*));
		*numberOfRows = 1;
	}
	return tableau;
}

// functions won't be taking whole struct as arguments because there will be different types of young tabeleu later
void GenerateRandomSet(float set[], int size)
{
	srand(time(NULL));
	for (int i = 1; i < size; i++)
	{
		float randomNr = (float)rand() / (float)RAND_MAX;
		set[i] = randomNr;
	}
}
//For example: if you want to have 10 numbers between 0 and 1 it will return 0.1
float CalculateDelta(int howMany)
{
	return (float)(1.0 / howMany);
}
float* GenerateStartingNumbers(float delta, int howManyNumbers)
{
	float* setOfStartingNumbers;
	setOfStartingNumbers = (float*)malloc(howManyNumbers * sizeof(float));
	float currentElement = 0.0;
	for (int i = 0; i <= howManyNumbers; i++)
	{
		setOfStartingNumbers[i] = currentElement;
		currentElement += delta;
	}
	return setOfStartingNumbers;
}


//float max is recently added number, we are looking for the biggest from smaller than the new
// i'm using "number" and "element" synonymously here
float* FindThe2ndMaxElement(float* row, float newElement, int* rowSize)
{
	float currentMax = -1.0;

	float* maxAddress = NULL; // we'll have to delete the found element from the row later
	if (*rowSize <= 0)
	{
		return NULL;
	}
	for (int i = 0; i < *rowSize; i++)
	{
		if (row[i] > currentMax && row[i] < newElement) // it can't be bigger than the new number
		{

			currentMax = row[i];
			maxAddress = &row[i];
		}
	}
	if (currentMax > 0)
	{
		return maxAddress;
	}
	else
	{
		return NULL;
	}
}

//we are putting the newest element at the beggining of the row
float* ThrowElementToRow(float* row, float element, int* rowSize, float* elementToThrowOut)
{
	float* addressToReplace;
	float thrownOutElement; //this is the biggest from smaller than new, it will be thrown a row higher
	addressToReplace = FindThe2ndMaxElement(row, element, rowSize);
	// if you find something smaller then replace the smaller number with current and throw smaller to next row
	// if not, just place the number at the beggining of the row
	if (addressToReplace != NULL)
	{
		thrownOutElement = *addressToReplace;
		*elementToThrowOut = thrownOutElement;
		*addressToReplace = element;
	}
	else // if not
	{
		row = ResizeRow(row, rowSize);
		row[(*rowSize) - 1] = element;
		*elementToThrowOut = -1.0; //means none

	}
	return row;

}
//ERROR now the rowsize is cosmic
