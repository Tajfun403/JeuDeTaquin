#pragma once
#include <stdlib.h>
#include "../../Graph/GraphItem.h"
#include "../../ArrayGen/TableauStructure.h"
#include "../../ArrayGen/TableauGen.h"
#include <stdbool.h>
#include "../../ArrayAnalyze/ArrayAnalyze.h"
#include "Windows.h"
#include "../Exceptions.h"
#include "stdio.h"
#include "../Clock.h"
#include "SaveData.h"

/// <summary>
/// PRIVATE: relay saving to a single threaded system
/// </summary>
/// <param name="path">Directory to load the tables from</param>
/// <param name="n">RETURNS: count of items</param>
/// <returns>An array of loaded tables</returns>
struct Tableau** LoadTableausSingleThread(char* path, int* n);

/// <summary>
/// PRIVATE: relay saving to a multi threaded system
/// </summary>
/// <param name="path">Directory to load the tables from</param>
/// <param name="n">RETURNS: count of items</param>
/// <returns>An array of loaded tables</returns>
struct Tableau** LoadTableausMultiThread(char* path, int* n);

/// <summary>
/// PRIVATE: a function to be ran on every input item, for multithreaded process
/// </summary>
/// <param name="input">Pointer to a file path</param>
/// <returns>Pointer to a loaded struct Tableau</returns>
void* LoadTable_Thread(void* input);
