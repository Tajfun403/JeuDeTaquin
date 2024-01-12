#include <stdio.h>
#include "ArrayAnalyze.h"

int main() {
	char* path = "filename.txt";

    printf("%d",SolveTableau(LoadTableauFromFile(path)));

	return 0;
}
