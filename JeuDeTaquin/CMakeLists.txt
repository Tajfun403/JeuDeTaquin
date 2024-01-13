# CMakeList.txt : CMake project for JeuDeTaquin, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (JeuDeTaquin "JeuDeTaquin.cpp"
	"JeuDeTaquin.h"
	"Graph/GraphItem.h"
	"Graph/Graph.h"
	"Graph/Graph.c"
	"ArrayGen/TableauGen.c"
	"ArrayGen/TableauGen.h"
	"ArrayGen/TableauStructure.c"
	"ArrayGen/TableauStructure.c"
	"ArrayGen/RandomSetStruct.h"
	"ArrayAnalyze/ArrayAnalyze.c"
	"ArrayAnalyze/ArrayAnalyze.h"
	"UserInputStruct.h"
	"UserInput.h"
	"UserInput.c"
	"MultithreadHelper.h"
	"MultithreadHelper.c"
	"BatchRunners.h"
	"BatchRunners.c"
	"Exceptions.h"
	"Exceptions.c" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET JeuDeTaquin PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
