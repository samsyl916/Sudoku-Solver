#ifndef SUDOKUOFFSPRING_H_
#define SUDOKUOFFSPRING_H_

#include <iostream>
#include "sudoku.h"
#include "puzzle.h"
#include "reproduction.h"

class SudokuOffspring : public Reproduction {
public:
    SudokuOffspring();
    Sudoku& MakeOffSpring(const Puzzle& puz);

private:
    double mutationRate_ = 0.05;
    int randNum0_;
    int randNum1_;
    int randNum2_;
    int randNum3_;
};

#endif	// SUDOKUOFFSPRING_H_