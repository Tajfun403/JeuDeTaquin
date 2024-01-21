#pragma once
#include "../../ArrayGen/TableauStructure.h"

/// <summary>
/// A tuple with information for saving each array
/// </summary>
struct SaveData {
	/// <summary>
	/// A tableau
	/// </summary>
	struct Tableau* tableau;

	/// <summary>
	/// Path to base directory tableau will be saved in
	/// </summary>
	char* basePath;

	/// <summary>
	/// Tableau index which will be included in the file name
	/// </summary>
	int index;

	/// <summary>
	/// Count of digits to include in the file name - to help with sorting
	/// </summary>
	int digitsCount;
};
