#pragma once
#include "puzzle.h"
#include "fitness.h"

class sudokuFitness : public Fitness 
{
    public:
        int howFit(Puzzle &puz) const;
};