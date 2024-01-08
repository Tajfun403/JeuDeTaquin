#include <stdio.h>
#include <stdlib.h>
#include "TableauGen.h"
#include "RandomSetStruct.h"
#include "TableauStructure.h"

main()
{
	struct Tableau tab;
	struct RandomSet rset;
	tab.startingNr = 0.23;
	rset.setSize = 9;
	tab.numberOfRows = 0;
	rset.set = (float*)malloc(rset.setSize * sizeof(float));
	rset.set[0] = tab.startingNr;


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