# JeuDeTaquin

## Overview
This project runs Jeu de Taquin algorithm on a set of auto-generated Young Tableaux, then outputs a graph of relationship between the tableau's first element, and (X+Y) location of the reached element.

## Details
The program is separated into three distinctive stages:
- Generate a set amount of Young Tableaux, each of them having a set amount of items - with first item being an evenly-spaced number from range [0..1], and the rest being randomized.
- Run all of them through Jeu De Taquin algorithm.
- Generate a gnuplot graph, with X-axis being the value of the first item of each tableau, and Y-axis line representing a 10%-moving-average of sum of X and Y indices of the item which Jeu De Taquin algorithm had reached.

Both generation and analysis are multithreaded using Windows API.
Generated tableaux can be saved to / loaded from files.

## Requirements
- Windows 10 or higher
- [gnuplot](http://www.gnuplot.info/download.html) pre-installed, either inside exe's dir or added to PATH variable

## Usage
         JeuDeTaquin <--tableauSize size --tableauCount count | --inputPath path> [ (optional args) ]

         -s, --tableauSize size          - amount of items in each tableau. Only if inputPath was not specified
         -c, --tableauCount count        - amount of tableaus. Only if inputPath was not specified
         -i, --inputPath path            - a path to directory with generated tables, if they should be loaded
        [-o, --tablesOutputPath path]    - if specified - a path to directory to save the generated tables in
                                           otherwise, tables will be kept in memory only
        [-img, --imgOutputPath path]     - if specified - a path to save the generated graph to
                                           otherwise, graph will be saved in "graph.png" file next to exe's dir
        [-h, --help]                     - prints this help message

If ran without any arguments, interactive input will be ran, where the respective args are provided as answers to questions.
(image)

## Example output
(image)