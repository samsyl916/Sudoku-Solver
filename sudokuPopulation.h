// Created by:  Patrick Banez
// Date:        5/28/2022
//
// A SudokuPopulation implements the Population interface and is a container
// for Sudoku Puzzles.

#ifndef SUDOKU_POPULATION_H_
#define SUDOKU_POPULATION_H_

#include "population.h"
#include "sudoku.h"
#include "SudokuOffspring.h"
#include "sudokuFitness.h"

class SudokuPopulation : public Population {
    public:
        //  4 Parameter constructor
        //  Creates the first generation of Puzzles.
        //  @param  the size of the Population
        //  @param  the number of generations to create
        //  @param  an unsolved Puzzle
        //  @param  a Reproduction object to create Puzzles
        //  @param  a Fitness object score each Puzzle
        SudokuPopulation(int, int, Sudoku&,
                         SudokuOffspring&,
                         sudokuFitness&
                        );

        //  Destructor
        //  Deallocates the array of SudokuPuzzles
        ~SudokuPopulation();

        //  Eliminates the <cullPerc>% least fit members of a generation.
        void cull();

        //  Produces a new generation of <size> amount of Puzzles based on the
        //  given Puzzle.
        //  @param  a Puzzle to base the new generation of Puzzles on
        //  @param  a Reproduction object to create Puzzles
        //  @param  a Fitness object to score each Puzzle
        void newGeneration(const Sudoku&,
                           SudokuOffspring&,
                           sudokuFitness&
                          );

        //  Returns the best fit Puzzle in the current generation.
        //  @return the best fit scored Puzzle for the current generation
        const Sudoku& bestFitness() const;

        //  Returns the Puzzle with the best fitness.
        //  @return the best fit scored Puzzle
        const Sudoku& bestIndividual() const;

        //  Returns the minimum heap of Sudoku Puzzles
        //  @return minimum heap of Sudoku Puzzles
        std::priority_queue<Sudoku, std::vector<Sudoku>, Sudoku::cmpFit>&
            getHeap() { return minHeap; };
        
    private:
        // min heap for the top fitness scored Sudoku Puzzles
        std::priority_queue<Sudoku, std::vector<Sudoku>, Sudoku::cmpFit> minHeap;

        // the percentage of Puzzles to remove from Population
        const double cullPerc = 0.9;
        
        // the original Sudoku Puzzle
        Sudoku* original;
};

#endif  // SUDOKU_POPULATION_H_