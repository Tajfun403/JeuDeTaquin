#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../ArrayGen/TableauStructure.h"
#include "ArrayAnalyze.h"
#include "../Helpers/ManagmentRequirements.h"
#include "..\Helpers\Version.h"
#include "..\Helpers\Exceptions.h"

struct Tableau* LoadTableauFromFile(char* filePath) {

	struct Tableau* tableau = malloc(sizeof(struct Tableau));
	tableau->numberOfRows = -1;
	tableau->sizesOfRows = NULL;
	tableau->startingNr = -1;
	tableau->tableau = NULL;

	FILE* fptr = fopen(filePath, "r");
	
	if (fptr == NULL) {
		LOG_ERROR("Couldn't open the file!");
		return NULL;
	}
	// read: magic, version, starting number, number of rows and max lenght of row
	int n = 0, m = 0;
	char magic[100], version[100];
	fscanf(fptr, "%s %s %f %d %d ", magic, version, &tableau->startingNr, &n, &m); // note:  "%f %d %d" breaks rest of code (needs space after %d)
	if (strcmp(magic, MAGIC)) {
		LOG_ERROR("MAGIC header does not match!\n");
		return NULL;
	}
	else if (strcmp(version, VERSION)) {
		LOG_ERROR("This file comes from another version of the program and cannot be read!\n");
		return NULL;
	}
	
	// printf("%f %d %d \n", tableau.startingNr, n, m);

	float** arr = (float**)malloc((n) * sizeof(float*));

	char* line = malloc(18 * m); // sizeof(char) is always 1, and... m is the number of doubles and every double has many digits.. so assuming constant number of digits per double we need to multiply by some constant

	int* endarr = malloc((n+1) * sizeof(int));

	// checking if the magic number is correct
	fgets(line, 18 * m, fptr);
	if (line == MAGIC)
	{
		// read from file and input into array
		int r = n; //rows
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
			endarr[r] = numb - 1; // remember where every row ends
			j = 0;
			for (int i = 0, k = 0; line[i] != 0; ++i) {
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
		// deallocate what wont be used
		free(line);

		// set the rest of tableau values
		tableau->numberOfRows = n;
		tableau->sizesOfRows = endarr;
		tableau->tableau = arr;

		return tableau;
	}
}

#ifdef UNOPTIMAL_MANAGMENT_REQUIREMENTS
//
int SolveTableau(struct Tableau* tableau) {

    return SolveTableauRecursively(tableau, 0, 0);
}
int SolveTableauRecursively(struct Tableau* tableau, int i, int j){
    int res = -1;
	while (1) {
		///  printf("%lf ", arr[i][j]);
		 //end of arr
		if (tableau->sizesOfRows[i + 1] < j && j == tableau->sizesOfRows[i]) {
			res = i + j;
			break;
		}
		//up if arr[i+1] exists and we can't go right or up is greater than right
		else if ((tableau->sizesOfRows[i + 1] >= j) && (j == tableau->sizesOfRows[i] || tableau->tableau[i + 1][j] > tableau->tableau[i][j + 1])) {
			return SolveTableauRecursively(tableau, i+1, j);
		}
		//right
		else return SolveTableauRecursively(tableau, i, j+1);
	}
    //free memory only once
    if (res != -1){
       for (int i = 0; i < tableau->numberOfRows; ++i) {
            free(tableau->tableau[i]);
        }

        free(tableau->tableau);
        free(tableau->sizesOfRows);
    }

	return res;
}

#else
int SolveTableau(struct Tableau* tableau) {

	int i = 0, j = 0, res;
	while (true) {
		///  printf("%lf ", arr[i][j]);
		 //end of arr
		if (tableau->sizesOfRows[i + 1] < j && j == tableau->sizesOfRows[i]) {
			res = i + j;
			break;
		}
		//up if arr[i+1] exists and we can't go right or up is greater than right
		else if ((tableau->sizesOfRows[i + 1] >= j) && (j == tableau->sizesOfRows[i] || tableau->tableau[i + 1][j] > tableau->tableau[i][j + 1])) {
			i++;
		}
		//right
		else j++;
	}

	for (int i = 0; i < tableau->numberOfRows; ++i) {
		free(tableau->tableau[i]);
	}

	free(tableau->tableau);
	free(tableau->sizesOfRows);

	return res;
}
#endif
