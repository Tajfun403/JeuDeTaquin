#include <stdio.h>
#include <stdlib.h>
#include <TableauStructure.h>
#include <TableauGen.h>

main()
{
	struct Tableau tab;
	tab.startingNr = 0.1f;
	tab.setSize = 10;
	tab.numberOfRows = 0;
	SetUpTableau(&tab);

	GenerateRandomSet(tab.set, tab.setSize);
	for (int i = 0; i < tab.setSize; i++)
	{
		printf("%f", tab.set[i]);
	}

	TableauGeneratingProcess(&tab);

	PrintTableau(tab);

	return 0;
}