#pragma once

#include "GraphItem.h"

/// <summary>
/// PRIVATE: add moving-averages to a set of GraphItems
/// </summary>
/// <param name="arr">An array of GraphItem*-s</param>
/// <param name="n">count</param>
void SetAverages(struct GraphItem** arr, int n);

/// <summary>
/// Generate a GNUPlot database of GraphItems
/// </summary>
/// <param name="arr">An array of GraphItem*-s</param>
/// <param name="n">count</param>
/// <returns>Name of a generated database file</returns>
char* GenerateDB(struct GraphItem** arr, int n);

/// <summary>
/// Generate a GNUPlot graph
/// </summary>
/// <param name="arr">An array of GraphItem*-s</param>
/// <param name="n">count</param>
/// <param name="imgPath">Path where the resulting image will be saved</param>
/// <param name="tableSize">Amount of items that existed in each table</param>
/// <returns>Path of generated image</returns>
char* GenerateGraph(struct GraphItem** arr, int n, char* imgPath, int tableSize);

/// <summary>
/// Sort an array of GraphItems by their X-axis value if they are not sorted
/// </summary>
/// <param name="arr">An array of GraphItem*-s</param>
/// <param name="n">count</param>
void SortIfNotSorted(struct GraphItem** arr, int n);

/// <summary>
/// Compares the X-axis values of GraphItems
/// </summary>
/// <param name="a">First GraphItem to compare</param>
/// <param name="b">Second GraphItem to compare</param>
/// <returns>Standard comparison rules (a->X - b->X)</returns>
int Compaper(struct GraphItem* a, struct GraphItem* b);

/// <summary>
/// Checks whether all GraphItems are sorted ascending by their X-axis value
/// </summary>
/// <param name="arr">An array of GraphItem*-s</param>
/// <param name="n">count</param>
/// <returns>Whether all GraphItems are sorted ascending by their X-axis value</returns>
bool IsSorted(struct GraphItem** arr, int n);
