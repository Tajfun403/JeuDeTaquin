#pragma once
/// <summary>
/// Saves one tab to a file <para/>
/// FILE STRUCTURE: <para/>
/// 1st line: Magic number <para/>
/// 2nd line: Version <para/>
/// 3rd line: Tableau starting num <para/>
/// 4th line: Rows count <para/>
/// 5th line: Length of the longest row <para/>
/// rest: tableau <para/>
/// </summary>
/// <param name="tab">Tableau to save</param>
/// <param name="path">Path to save the file in</param>
void SaveTableau(struct Tableau tab, char path[]);

/// <summary>
/// Prints single row
/// </summary>
/// <param name="row">Row to print</param>
/// <param name="size">Size of the row</param>
void PrintRow(float row[], int size);

/// <summary>
/// Prints all the tableau
/// </summary>
/// <param name="tab">Tableau to print</param>
void PrintTableau(struct Tableau tab);

/// <summary>
/// Main generating process
/// </summary>
/// <param name="startingNum">Starting number in the set</param>
/// <param name="setSize">Size of the set which will be used in generating the tableau</param>
/// <returns>Generated Young Tableau</returns>
struct Tableau* GenerateTableau(double startingNum, int setSize);
