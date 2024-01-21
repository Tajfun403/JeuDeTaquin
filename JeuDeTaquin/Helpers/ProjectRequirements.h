#pragma once

// A switch between optimized (with real life sense) and highly questionable (no real life sense) 
// function implementations, as the latter were forced by uni's project requirements
// CURRENTLY AFFECTS: 
// ArrayAnalyze/ArrayAnalyze.c -> SolveTableau (in-place vs recursion)
// ArrayGen/TableauStructure.c -> FindThe2ndMaxElement (linear search vs qsort)

// #define UNOPTIMAL_PROJECT_REQUIREMENTS