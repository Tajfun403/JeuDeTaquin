#pragma once
#include <stdbool.h>

/// <summary>
/// Provides user's input data necessary to generate tables.
/// </summary>
struct UserInput {
	int TableauSize;
	int TableauCount;
	char* InputPath;
	bool bValid;
	char* ErrorInfo;
};