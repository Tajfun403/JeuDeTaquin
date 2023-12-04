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
	GenerateRandomSet(tab.set, tab.setSize);

	TableauGeneratingProcess(&tab);

	PrintTableau(tab);

	return 0;
}