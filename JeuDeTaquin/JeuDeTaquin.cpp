// JeuDeTaquin.cpp : Defines the entry point for the application.
//

#include "JeuDeTaquin.h"
#include "UserInputStruct.h"
#include "UserInput.h"
#include "UserInput.c"

int main(int argc, char* argv[])
{
	struct UserInput input = TakeUserInput(argc, argv);
	if (!input.bValid) {
		printf("Could not read input!\n");
		printf("Exception body: %s!\n", input.ErrorInfo);
		int b = 2;
	}
}
