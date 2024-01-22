#pragma once
#include "../ArrayGen/TableauStructure.h"

/// <summary>
/// Generate tables to an array in memory
/// </summary>
/// <param name="size">Amount of items in each table</param>
/// <param name="count">Amount of tables</param>
/// <returns>An array of generated tables</returns>
struct Tableau** GenerateTables(int size, int count);

/// <summary>
/// Analyze all tables from an array and output a GNUPLOT graph.
/// </summary>
/// <param name="imgPath">Path for saving the results image</param>
/// <param name="tableaus">Array of tables</param>
/// <param name="n">Count of tables</param>
/// <param name="tableSize">Amount of items that existed in each table</param>
/// <returns>Path to an image containing the images</returns>
char* AnalyzeTables(char* imgPath, struct Tableau** tableaus, int n, int tableSize);

/// <summary>
/// Save an array of tableaus to files
/// </summary>
/// <param name="path">Directory to save tableaus in</param>
/// <param name="arr">Array of tableaus</param>
/// <param name="n">Count of tables</param>
void SaveTableaus(char* path, struct Tableau** arr, int n);

/// <summary>
/// Load all tables from a directory
/// </summary>
/// <param name="path">Directory to load the tables from</param>
/// <param name="n">RETURNS: count of items</param>
/// <returns>An array of loaded tables</returns>
struct Tableau** LoadTableaus(char* path, int* n);

/// <summary>
/// Print all tables to standard output.
/// </summary>
/// <param name="tableaus">Array of tables</param>
/// <param name="n">Count of tables</param>
void PrintTables(struct Tableau** tableaus, int n);

/// <summary>
/// Get count of all items in a tableau
/// </summary>
/// <param name="t">A tableau to count items fof</param>
/// <returns>Count of all items in the tableau</returns>
int GetTableauSize(struct Tableau* t);
