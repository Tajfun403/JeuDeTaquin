#pragma once
#include <stdbool.h>
#include "UserInputStruct.h"

/// <summary>
/// Obtain input from the user; automatically either reads content of args list, or asks the user for them if they are missing.
/// </summary>
/// <param name="argc">Command line args count</param>
/// <param name="argv">Command line args values</param>
/// <returns>Filled UserInput</returns>
struct UserInput TakeUserInput(int argc, char* argv[]);

/// <summary>
/// Obtain user input from provided command line args.
/// </summary>
/// <param name="argc">Command line args count</param>
/// <param name="argv">Command line args values</param>
/// <returns>Filled UserInput</returns>
struct UserInput ReadUserInputFromArgs(int argc, char* argv[]);

/// <summary>
/// Obtain input by interactively ask the user to provide it
/// </summary>
/// <returns>Filled UserInput</returns>
struct UserInput ReadUserInputFromPrompts();

/// <summary>
/// True if a path to existing tables which should be used was passed.
/// </summary>
/// <param name="input"></param>
/// <returns></returns>
bool ShouldUseExistingTables(struct UserInput input);

/// <summary>
/// Print explanations of command line args to standard output.
/// </summary>
void DrawUsage(void);