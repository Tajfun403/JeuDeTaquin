#pragma once
#include <stdbool.h>
#include "UserInputStruct.h"

struct UserInput TakeUserInput(int argc, char* argv[]);
struct UserInput ReadUserInputFromArgs(int argc, char* argv[]);
struct UserInput ReadUserInputFromPrompts();