#pragma once

/// <summary>
/// Represents a Young Tableau <para/>
/// The tables are represented in French notation, with rows numbered in that order.
/// </summary>
struct Tableau {
	/// <summary>
	/// Number of first element in randomset of the tableau
	/// </summary>
	float startingNr;

	/// <summary>
	/// Sizes of each rows
	/// </summary>
	int* sizesOfRows;

	/// <summary>
	/// Number of rows
	/// </summary>
	int numberOfRows;

	/// <summary>
	/// 2D Array, THE Young Tableau, with rows numbered in the order of French notation: <para/>
	///	_	0 1 2 <para/>
	/// 3[] <para/>
	///	2[] <para/>
	///	1[][] <para/>
	///	0[][][] <para/>
	///	Therefore the cell[0][0] is in the down - left corner <para/>
	/// </summary>
	float** tableau;

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


