#pragma once

#include "GraphItem.h"

/// <summary>
/// PRIVATE: add moving-averages to a set of GraphItems
/// </summary>
/// <param name="arr">An array of GraphItems</param>
/// <param name="n">count</param>
void SetAverages(struct GraphItem* arr, int n);

/// <summary>
/// Generate a GNUPlot database of GraphItems
/// </summary>
/// <param name="arr">An array of GraphItems</param>
/// <param name="n">count</param>
/// <returns>Name of a generated database file</returns>
char* GenerateDB(struct GraphItem* arr, int n);

/// <summary>
/// Generate a GNUPlot graph
/// </summary>
/// <param name="arr">An array of GraphItems</param>
/// <param name="n">count</param>
/// <param name="imgPath">Path where the resulting image will be saved</param>
/// <param name="tableSize">Amount of items that existed in each table</param>
/// <returns>Path of generated image</returns>
char* GenerateGraph(struct GraphItem* arr, int n, char* imgPath, int tableSize);
