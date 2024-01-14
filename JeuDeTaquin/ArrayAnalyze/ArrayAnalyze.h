#pragma once

#include "../ArrayGen/TableauStructure.h"

struct Tableau* LoadTableauFromFile(char* filePath);

int SolveTableau(struct Tableau* tableau);
