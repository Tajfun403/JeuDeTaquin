#pragma once
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
	float startingNr; // the number which will be used in creating the chart later
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

/// <summary>
/// Resizes a single row
/// </summary>
/// <param name="row"></param>
/// <param name="size"></param>
/// <returns></returns>
float* ResizeRow(float* row, int* size);
/// <summary>
/// Resizes an array which holds the sizes
/// </summary>
/// <param name="sizes"></param>
/// <param name="currentRowsCounter"></param>
/// <returns></returns>
int* ResizeSizesArray(int* sizes, int currentRowsCounter);
/// <summary>
/// Resizes 2D array called Tableau 
/// </summary>
/// <param name="tableau"></param>
/// <param name="numberOfRows"></param>
/// <returns></returns>
float** ResizeTableau(float** tableau, int* numberOfRows);
/// <summary>
/// Generates random set
/// </summary>
/// <param name="set"></param>
/// <param name="size"></param>
void GenerateRandomSet(float set[], int size);
/// <summary>
/// Calculates difference between n numbers in range (0,1) 
/// </summary>
/// <param name="howMany"></param>
/// <returns></returns>
float CalculateDelta(int howMany);
/// <summary>
/// Generates starting numbers from Delta, the starting numbers used in creating the graph
/// </summary>
/// <param name="delta"></param>
/// <param name="howManyNumbers"></param>
/// <returns></returns>
float* GenerateStartingNumbers(float delta, int howManyNumbers);
/// <summary>
/// Finds the 2nd max element in a row
/// </summary>
/// <param name="row"></param>
/// <param name="newElement"></param>
/// <param name="rowSize"></param>
/// <returns></returns>
float* FindThe2ndMaxElement(float* row, float newElement, int* rowSize);

/// <summary>
/// In the tableau generating process, it throws the 2nd max element to the next row
/// </summary>
/// <param name="row"></param>
/// <param name="element"></param>
/// <param name="rowSize"></param>
/// <param name="elementToThrowOut"></param>
/// <returns></returns>
float* ThrowElementToRow(float* row, float element, int* rowSize, float* elementToThrowOut);


