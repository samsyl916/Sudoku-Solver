#ifndef PUZZLEFACTORY_H_
#define PUZZLEFACTORY_H_

#include "reproduction.h"
#include "puzzle.h"
#include "population.h"
#include "fitness.h"

class PuzzleFactory {
    public:
        // Uses a Population and Reproduction object to create a new puzzle
        // @return  A new instance of Puzzle
        virtual Puzzle& createPuzzle() = 0;

    protected:
        Puzzle* original;        // The original Puzzle
        Population* population;  // The Population of Puzzles
        Reproduction* repro; // Used to create new Puzzles
        Fitness* fit;   // Used to score Puzzles
};

#endif	// PUZZLEFACTORY_H_