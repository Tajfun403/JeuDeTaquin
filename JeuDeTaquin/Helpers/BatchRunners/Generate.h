#pragma once

/// <summary>
/// PRIVATE: relays table analysis to a singlethreaded system
/// </summary>
struct Tableau** GenerateTablesSingleThread(int size, int count);

/// <summary>
/// PRIVATE: relays table analysis to a multithreaded system
/// </summary>
struct Tableau** GenerateTablesMultiThread(int size, int count);

/// <summary>
/// PRIVATE: a function to be ran on every input item, for multithreaded process
/// </summary>
/// <param name="input">A struct GenData*, which is a tuple(startingNum, size)</param>
/// <returns>Pointer to a generated struct Tableau*</returns>
void* GenTable_Thread(void* input);
