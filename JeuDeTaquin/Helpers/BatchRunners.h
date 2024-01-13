#pragma once
/// <summary>
/// Generate tables to a directory.
/// </summary>
/// <param name="size"></param>
/// <param name="count"></param>
/// <returns>An array of generated tables</returns>
struct Tableau** GenerateTables(int size, int count);

/// <summary>
/// Analyze all tables from an array and output a GNUPLOT graph.
/// </summary>
/// <param name="imgPath">Path for saving the results image</param>
/// <param name="tableaus">Array of tables</param>
/// <param name="n">Count of tables</param>
/// <returns>Path to an image containing the images</returns>
char* AnalyzeTables(char* imgPath, struct Tableau** tableaus, int n);

/// <summary>
/// Save an array of tableaus to files
/// </summary>
/// <param name="path">Directory to save tableaus in</param>
/// <param name="arr">Array of tableaus</param>
/// <param name="n">Count of tables</param>
void SaveTableaus(char* path, struct Tableaus** arr, int n);

/// <summary>
/// Load all tables from a directory
/// </summary>
/// <param name="path">Directory to save tableaus in</param>
/// <param name="n">RETURNS: count of items</param>
/// <returns>An array of loaded tables</returns>
struct Tableau** LoadTableaus(char* path, int* n);
