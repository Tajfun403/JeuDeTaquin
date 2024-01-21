#pragma once
#include "../../ArrayGen/TableauStructure.h"

/// <summary>
/// A tuple with information for saving each array
/// </summary>
struct SaveData {
	struct Tableau* tableau;
	char* basePath;
	int index;
};
