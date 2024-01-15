#pragma once

/// <summary>
/// PRIVATE: relays table analysis to a multithreaded system
/// </summary>
/// <param name="imgPath">Path for saving the results image</param>
/// <param name="tableaus">Array of tables</param>
/// <param name="n">Count of tables</param>
/// <param name="tableSize">Amount of items that existed in each table</param>
/// <returns>Path to an image containing the images</returns>
char* AnalyzeTablesMultiThreaded(char* imgPath, struct Tableau** tableaus, int n, int tableSize);

/// <summary>
/// PRIVATE: a function to be ran on every input item, for multithreaded process
/// </summary>
/// <param name="input">Pointer to a struct Tableau*</param>
/// <returns>Pointer to a new struct GraphItem, filled with X and Y values.</returns>
void* AnalyzeTable_Thread(void* input);
