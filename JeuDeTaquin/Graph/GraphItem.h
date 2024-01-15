#pragma once

/// <summary>
/// A struct to represent one point on the graph
/// </summary>
struct GraphItem {
    /// <summary>
    /// X-axis index: starting num of the table
    /// </summary>
    float X;

    /// <summary>
    /// Y-axis item: sum of column + row of the result
    /// </summary>
    int Y;

    /// <summary>
    /// Moving average of Y. Should be filled from SetAverages() function
    /// </summary>
    double Avg;

    /// <summary>
    /// Current sum of nearby neighbords. Used for generating moving average.
    /// </summary>
    int currSum;

    /// <summary>
    /// Current range of the moving average. Gets smaller near borders
    /// </summary>
    int currRange;
};