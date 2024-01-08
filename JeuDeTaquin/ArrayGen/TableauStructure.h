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

float* ResizeRow(float* row, int* size);
int* ResizeSizesArray(int* sizes, int currentRowsCounter);
float** ResizeTableau(float** tableau, int* numberOfRows);
void GenerateRandomSet(float set[], int size);
float CalculateDelta(int howMany);
float* GenerateStartingNumbers(float delta, int howManyNumbers);
float* FindThe2ndMaxElement(float* row, float newElement, int* rowSize);
float* ThrowElementToRow(float* row, float element, int* rowSize, float* elementToThrowOut);