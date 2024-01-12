#include "TableauStructure.h"
#ifndef ARRAYANALYZE_H_INCLUDED
#define ARRAYANALYZE_H_INCLUDED

struct Tableau LoadTableauFromFile(char* filePath);

int SolveTableau(struct Tableau tableau);

#endif // ARRAYANALYZE_H_INCLUDED
