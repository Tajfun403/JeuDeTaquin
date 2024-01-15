#pragma once

void SaveTableau(struct Tableau tab, char path[]);
void PrintRow(float row[], int size);
void PrintTableau(struct Tableau tab);
struct Tableau* GenerateTableau(double startingNum, int setSize);
