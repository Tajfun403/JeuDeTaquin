﻿# CMakeList.txt : CMake project for JeuDeTaquin, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (JeuDeTaquin "JeuDeTaquin.c"
	"JeuDeTaquin.h"
	"Graph/GraphItem.h"
	"Graph/Graph.h"
	"Graph/Graph.c"
	"ArrayGen/TableauGen.c"
	"ArrayGen/TableauGen.h"
	"ArrayGen/TableauStructure.c"
	"ArrayGen/TableauStructure.h"
	"ArrayGen/RandomSetStruct.h"
	"ArrayAnalyze/ArrayAnalyze.c"
	"ArrayAnalyze/ArrayAnalyze.h"
	"Helpers/UserInputStruct.h"
	"Helpers/UserInput.h"
	"Helpers/UserInput.c"
	"Helpers/MultithreadHelper.h"
	"Helpers/MultithreadHelper.c"
	"Helpers/BatchRunners.h"
	"Helpers/BatchRunners.c"
	"Helpers/Exceptions.h"
	"Helpers/Exceptions.c"
	"Helpers/BatchRunners/Generate.h"
	"Helpers/BatchRunners/Generate.c"
	"Helpers/BatchRunners/GenerateData.h"
	"Helpers/BatchRunners/Analyze.h"
	"Helpers/BatchRunners/Analyze.c"
	"Helpers/Clock.h"
	"Helpers/Clock.c"
	"Helpers/ProjectRequirements.h"
	"Helpers/Version.h"
	"Helpers/BatchRunners/Load.h"
	"Helpers/BatchRunners/Save.c"
	"Helpers/BatchRunners/SaveData.h"
	"Helpers/BatchRunners/Load.c"
	"Helpers/BatchRunners/Save.h")


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET JeuDeTaquin PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
