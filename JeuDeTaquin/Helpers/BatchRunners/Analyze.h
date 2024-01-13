#pragma once

/// <summary>
/// PRIVATE: relays table analysis to a multithreaded system
/// </summary>
char* AnalyzeTablesMultiThreaded(char* imgPath, struct Tableau** tableaus, int n);

/// <summary>
/// PRIVATE: a function to be ran on every input item, for multithreaded process
/// </summary>
/// <param name="input">Pointer to a struct Tableau*</param>
/// <returns>Pointer to a solution pair: struct GraphItem*</returns>
void* AnalyzeTable_Thread(void* input);
