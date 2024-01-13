#pragma once
/// <summary>
/// Generate tables to a directory.
/// </summary>
/// <param name="size"></param>
/// <param name="count"></param>
/// <returns>Path to directory with generated tables</returns>
char* GenerateTables(int size, int count);

/// <summary>
/// Analyze all tables from a directory and outout a GNUPLOT graph.
/// </summary>
/// <param name="source">Path to directory with tables to analyze</param>
/// <returns>Path to an image containing the images</returns>
char* AnalyzeTables(char* source);