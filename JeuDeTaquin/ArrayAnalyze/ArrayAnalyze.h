#pragma once

#include "../ArrayGen/TableauStructure.h"

/// <summary>
/// Loads tableau from file
/// </summary>
/// <param name="filePath">Path to file containing tableau</param>
/// <returns>Loaded tableau</returns>
struct Tableau* LoadTableauFromFile(char* filePath);

/// <summary>
/// Solves Young Tableau
/// </summary>
/// <param name="tableau">Tableau to solve</param>
/// <returns>The sum of row and column on which the game ended </returns>
int SolveTableau(struct Tableau* tableau);
