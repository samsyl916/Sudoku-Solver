// Created by:  Patrick Banez
// Date:        5/29/2022
//

#include "sudokuPopulation.h"

SudokuPopulation::SudokuPopulation(
                                    int amount,
                                    int generations,
                                    Sudoku& puzzle,
                                    SudokuOffspring& repro,
                                    sudokuFitness& fit
                                  )
{
    original = &puzzle;
    for(int row = 0; row < 9; row++)
    {
        for(int col = 0; col < 9; col++)
        {
            if(puzzle.getSpace(row,col) == 0)
            {
                int randNum = 1 + (rand() % 9);
                puzzle.setSpace(row, col, randNum);
            }
        }
    }
    puzzle.setFitness(fit.howFit(puzzle));
    size = amount;
    gens = generations;
    newGeneration(*dynamic_cast<Sudoku*>(original), repro, fit);
}

SudokuPopulation::~SudokuPopulation()
{
}

void SudokuPopulation::cull()
{
    queue<Sudoku> temp;

    // store the top fit puzzles in the temp queue
    for(int i = 0; i < size - (size * cullPerc); i++)
    {
        temp.push(minHeap.top());
        minHeap.pop();
    }
    while(!minHeap.empty()) // empty the minHeap
    {
        minHeap.pop();
    }
    while(!temp.empty()) // return the top fit puzzles to minHeap
    {
        minHeap.push(temp.front());
        temp.pop();
    }
};

void SudokuPopulation::newGeneration(
                                     const Sudoku& parent,
                                     SudokuOffspring& repro,
                                     sudokuFitness& fit
                                    )
{
    while(minHeap.size() < size)
    {
        Sudoku* sudoku = dynamic_cast<Sudoku*>(&(repro.MakeOffSpring(parent)));
        sudoku->setFitness(fit.howFit(*sudoku));
        minHeap.push(*sudoku);
    }
}


const Sudoku& SudokuPopulation::bestFitness() const
{
    const Sudoku* best = &(minHeap.top());
    return *best;
}

const Sudoku& SudokuPopulation::bestIndividual() const
{
    return bestFitness();
}