#include <stdio.h>
#include <stdlib.h>
#include "TableauGen.h"

main()
{
	struct Tableau tab;
	tab.startingNr = 0.23;
	tab.setSize = 9;
	tab.numberOfRows = 0;
	tab.set = (float*)malloc(tab.setSize * sizeof(float));
	tab.set[0] = 0.23;


	/*float sett[] = {.23, .35,.235,.23,.325,.876,.54,.8,.976,.45,.35};
	for (int i = 0; i < tab.setSize; i++)
	{
		tab.set[i] = sett[i];
	}*/
	//GenerateRandomSet(tab.set, tab.setSize);
	TableauGeneratingProcess(&tab);
	SaveTableau(tab);


	return 0;
}