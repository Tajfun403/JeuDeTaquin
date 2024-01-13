#include <stdio.h>
#include <stdlib.h>
#include "../ArrayGen/TableauStructure.h"
#include "ArrayAnalyze.h"

struct Tableau LoadTableauFromFile(char* filePath) {

	struct Tableau tableau;
	tableau.numberOfRows = -1;
	tableau.sizesOfRows = NULL;
	tableau.startingNr = -1;
	tableau.tableau = NULL;

	FILE* fptr = fopen(filePath, "r");

	if (fptr == NULL) {
		//printf("Not able to open the file.");
		return tableau;
	}
	//read starting number,number of rows and max lenght of row
	int n = 0, m = 0;
	fscanf(fptr, "%f %d %d ", &tableau.startingNr, &n, &m);//note:  "%f %d %d" breaks rest of code (needs space after %d)
	//printf("%f %d %d \n",tableau.startingNr,n,m);

	float** arr = (float**)malloc((n) * sizeof(float*));

	char* line = malloc(18 * m);//sizeof(char) is always 1, and... m is the number of doubles and every double has many digits.. so assuming constant number of digits per double we need to multiply by some constant

	int* endarr = malloc(n * sizeof(int));

	//read from file and input into array
	int r = n;//rows
	endarr[n] = -1;
	while (fgets(line, 18 * m, fptr) != NULL) {

		//printf("The line is: %s\n", line);
		   //...
		//printf("and the values are: ");
		r--;
		int j = 0, numb = 0;
		while (line[j] != 0) {
			if (line[j] == ';')numb++;
			j++;
		}
		arr[r] = (float*)malloc((numb) * sizeof(float));
		endarr[r] = numb - 1;//remember where every row ends
		j = 0;
		for (int i = 0, k = 0;line[i] != 0;++i) {
			if (line[i] == ';') {
				line[i] = 0;
				arr[r][j] = atof(line + k);
				//printf("%lf ", arr[r][j]);
				k = i + 1;
				j++;
			}
		}
		//  printf("\n\n");
	}
	//deallocate what wont be used
	free(line);

	//set the rest of tableau values
	tableau.numberOfRows = n;
	tableau.sizesOfRows = endarr;
	tableau.tableau = arr;


	return tableau;
}
int SolveTableau(struct Tableau tableau) {

	int i = 0, j = 0, res;
	while (1) {
		///  printf("%lf ", arr[i][j]);
		 //end of arr
		if (tableau.sizesOfRows[i + 1] < j && j == tableau.sizesOfRows[i]) {
			res = i + j;
			break;
		}
		//up if arr[i+1] exists and we can't go right or up is greater than right
		else if ((tableau.sizesOfRows[i + 1] >= j) && (j == tableau.sizesOfRows[i] || tableau.tableau[i + 1][j] > tableau.tableau[i][j + 1])) {
			i++;
		}
		//right
		else j++;
	}

	for (int i = 0;i < tableau.numberOfRows + 1;++i) {

		free(tableau.tableau[i]);
	}

	free(tableau.tableau);
	free(tableau.sizesOfRows);

	return res;
}