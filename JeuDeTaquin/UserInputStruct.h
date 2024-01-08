#pragma once
#include <stdbool.h>

struct UserInput {
	int TableauSize;
	int TableauCount;
	char* InputPath;
	bool bValid;
	char* ErrorInfo;
};