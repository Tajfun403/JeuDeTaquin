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
struct Tableau
{
	//size of set of randomly generated numbers, the size is given as an input
	int setSize; 

	// the number which will be used in creating the chart later
	float startingNr; 
	// set of randomly generated numbers, those will be used to generate a tabeleux
	float* set; 
	//stores the sizes of the rows
	int* sizesOfRows; 
	//I'll be tracking the size of rows
	int numberOfRows; 
	//2d array, THE Young Tabelau
	float** tableau; 

};
//resizes one row and changes the size variable
float* ResizeRow(float* row, int* size)
{
	row = (float*)realloc(row, (*size + 1) * sizeof(float));
	*size++;
	return row;
}
//resizes tableau, it means adds new rows and changes the row counter variable
float** ResizeTableau(float** tableau, int* numberOfRows)
{
	tableau = (float**)realloc(tableau, (*numberOfRows + 1) * sizeof(float*));
	*numberOfRows++;
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
float* FindThe2ndMaxElement(float* row, float newElement, int rowSize)
{
	float currentMax = -1.0;
	float maxAddresValue = -1.0;
	// we'll have to delete the found element from the row later
	float* maxAddress = &maxAddresValue; 
	for (int i = 0; i < rowSize; i++)
	{
		// it can't be bigger than the new number
		if (row[i] > currentMax && row[i] < newElement) 
		{
			currentMax = row[i];
			maxAddress = &currentMax;
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
	//this is the biggest from smaller than new, it will be thrown a row higher
	float thrownOutElement; 
	// if you find something smaller then replace the smaller number with current and throw smaller to next row
	// if not, just place the number at the beggining of the row
	addressToReplace = FindThe2ndMaxElement(row, element, *rowSize);
	
	if (addressToReplace != NULL)
	{
		thrownOutElement = *addressToReplace;
		*elementToThrowOut = thrownOutElement;
		*addressToReplace = element;
	}
	// if not
	else 
	{
		row = ResizeRow(row, rowSize);
		row[*rowSize - 1] = element;
		//means none in that case
		*elementToThrowOut = -1.0; 
	}
	return row;

}