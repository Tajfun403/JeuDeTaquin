#pragma once

// A switch between optimized (with real life sense) andquestionable
// function implementations, as the latter were forced by some of uni's project requirements
// CURRENTLY AFFECTS: 
// ArrayAnalyze/ArrayAnalyze.c -> SolveTableau (in-place vs recursion)
// ArrayGen/TableauStructure.c -> FindThe2ndMaxElement (linear search vs qsort)

// #define UNOPTIMAL_PROJECT_REQUIREMENTS