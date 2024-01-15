#pragma once
/// <summary>
/// Saves one tab to a separate file
/// FILE STRUCTURE:
/// 1st line: Magic number
/// 2nd line: how many rows\n
/// 3rd line: length od the longest row\n
/// rest: tableau
/// </summary>
/// <param name="tab"></param>
/// <param name="path"></param>
void SaveTableau(struct Tableau tab, char path[]);
/// <summary>
/// Prints single row
/// </summary>
/// <param name="row"></param>
/// <param name="size"></param>
void PrintRow(float row[], int size);
/// <summary>
/// Prints all the tableau
/// </summary>
/// <param name="tab"></param>
void PrintTableau(struct Tableau tab);
/// <summary>
/// Main generating process
/// </summary>
/// <param name="startingNum"></param>
/// <param name="setSize"></param>
/// <returns></returns>
struct Tableau* GenerateTableau(double startingNum, int setSize);
