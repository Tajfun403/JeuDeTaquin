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
/// <param name="path">Directory to save tableaus in</param>
/// <param name="arr">Array of tableaus</param>
/// <param name="n">Count of tables</param>
void SaveTableausSingleThread(char* path, struct Tableau** arr, int n);

/// <summary>
/// PRIVATE: relays table saving to a multithreaded system
/// </summary>
/// <param name="path">Directory to save tableaus in</param>
/// <param name="arr">Array of tableaus</param>
/// <param name="n">Count of tables</param>
void SaveTableausMultiThreaded(char* path, struct Tableau** arr, int n);

/// <summary>
/// PRIVATE: a function to be ran on every input item, for multithreaded process
/// </summary>
/// <param name="input">Pointer to a struct SaveData*</param>
/// <returns>Nothing (always returns NULL)</returns>
static void* SaveTable_Thread(void* input);
