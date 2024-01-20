#pragma once
#include <stdbool.h>
#include "UserInputStruct.h"

/// <summary>
/// Obtain input from the user; automatically either reads content of args list, or asks the user for them if they are missing.
/// </summary>
/// <param name="returnInput">A pointer to returnInput where the filled input will be put</param>
/// <param name="argc">Command line args count</param>
/// <param name="argv">Command line args values</param>
/// <returns>Whether the input was taken sucessfully</returns>
bool TakeUserInput(struct UserInput* returnInput, int argc, char* argv[]);

/// <summary>
/// Obtain user input from provided command line args.
/// </summary>
/// <param name="returnInput">A pointer to returnInput where the filled input will be put</param>
/// <param name="argc">Command line args count</param>
/// <param name="argv">Command line args values</param>
/// <returns>Whether the input was taken sucessfully</returns>
bool ReadUserInputFromArgs(struct UserInput* returnInput, int argc, char* argv[]);

/// <summary>
/// Validivies user input
/// </summary>
/// <param name="input">User input</param>
/// <returns>Whether the user input is valid</returns>
bool ValidateUserInput(struct UserInput* input);

/// <summary>
/// Obtain input by interactively ask the user to provide it
/// </summary>
/// <param name="returnInput">A pointer to returnInput where the filled input will be put</param>
/// <returns>Whether the input was taken sucessfully</returns>
bool ReadUserInputFromPrompts(struct UserInput* returnInput);

/// <summary>
/// True if a path to existing tables which should be used was passed.
/// </summary>
/// <param name="input">User input</param>
/// <returns></returns>
bool ShouldUseExistingTables(struct UserInput input);

/// <summary>
/// Print explanations of command line args to standard output.
/// </summary>
void DrawUsage(void);