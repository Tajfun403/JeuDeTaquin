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
/// <param name="row">A row, an array to resize</param>
/// <param name="size">Pointer to the size variable of the row</param>
/// <returns>Resized row</returns>
float* ResizeRow(float* row, int* size);
/// <summary>
/// Resizes an array which holds the sizes
/// </summary>
/// <param name="sizes">Array which will be resized</param>
/// <param name="currentRowsCounter">Size of that array</param>
/// <returns>Resized array</returns>
int* ResizeSizesArray(int* sizes, int currentRowsCounter);
/// <summary>
/// Resizes 2D array called Tableau 
/// </summary>
/// <param name="tableau">The 2D array tableau, an element of the struct Tableau</param>
/// <param name="numberOfRows">number of rows</param>
/// <returns>2D array of floats which will be the new tableau</returns>
float** ResizeTableau(float** tableau, int* numberOfRows);
/// <summary>
/// Generates random set
/// </summary>
/// <param name="set">Array which contains the set</param>
/// <param name="size">Size of set</param>
void GenerateRandomSet(float set[], int size);
/// <summary>
/// Calculates difference between n numbers in range (0,1) 
/// </summary>
/// <param name="howMany">How many number should there be in the range of (0,1)</param>
/// <returns>The difference variable</returns>
float CalculateDelta(int howMany);
/// <summary>
/// Generates starting numbers from Delta, the starting numbers used in creating the graph
/// </summary>
/// <param name="delta">Difference between numbers calculated in CalculateDelta function</param>
/// <param name="howManyNumbers">How many numbers to generate</param>
/// <returns>Generated array of the generated numbers</returns>
float* GenerateStartingNumbers(float delta, int howManyNumbers);
/// <summary>
/// Finds the 2nd max element in a row
/// </summary>
/// <param name="row">Row where we need to find the element</param>
/// <param name="newElement">Element to put in the place of the old</param>
/// <param name="rowSize">Size of the row</param>
/// <returns>Updated row</returns>
float* FindThe2ndMaxElement(float* row, float newElement, int* rowSize);

/// <summary>
/// In the tableau generating process, it throws the 2nd max element to the next row
/// </summary>
/// <param name="row">Row where we throw the element</param>
/// <param name="element">Element to throw to the current row</param>
/// <param name="rowSize">Size of the row</param>
/// <param name="elementToThrowOut">Pointer to an element to throw to the next row</param>
/// <returns></returns>
float* ThrowElementToRow(float* row, float element, int* rowSize, float* elementToThrowOut);


