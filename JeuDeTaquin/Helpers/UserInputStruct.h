#pragma once
#include <stdbool.h>

/// <summary>
/// Provides user's input data necessary to generate tables.
/// </summary>
struct UserInput {
	/// <summary>
	/// Amount of elements in each tableau
	/// </summary>
	int TableauSize;

	/// <summary>
	/// Amount of tableaus
	/// </summary>
	int TableauCount;

	/// <summary>
	/// OPTIONAL: path to load tableaus from
	/// </summary>
	char* InputPath;

	/// <summary>
	/// OPTIONAL: path to save the generated tables to
	/// </summary>
	char* TablesOutputPath;

	/// <summary>
	/// OPTIONAL: path to save the generated image to
	/// </summary>
	char* ImgOutputPath;
	
	/// <summary>
	/// OPTIONAL: if true, print tables before analyzing them
	/// </summary>
	bool bPrintTables;
};