// Created by:  Patrick Banez
// Date:        5/27/2022
// An interface for any puzzle to be used by the Genetic Algorithm framework.

#ifndef PUZZLE_H_
#define PUZZLE_H_

#include <iostream>

class Puzzle {
    public:

        //  Overload operator<<()
        //  Reads in a puzzle and fills the spaces of the puzzle from the input.
        //  @parameter  ostream to take in the puzzle
        //  @parameter  Puzzle with spaces to fill
        //  @return     ostream
        friend std::ostream& operator<<(std::ostream&, const Puzzle&);

        //  Overload operator>>()
        //  Produces a "human friendly" output of the puzzle as formatted text.
        //  @parameter  ostream to output the puzzle
        //  @parameter  Puzzle to output
        //  @return     ostream
        friend std::istream& operator>>(std::istream&, Puzzle&);

        //  Returns the number at the given row and column of the Puzzle.
        //  @param  row
        //  @param  column
        //  @return the number at the [row][column] of the Puzzle
        virtual int getSpace(int, int) const = 0;

        //  Gets the fitness score of the Sudoku Puzzle
        //  @return a fitness score
        virtual int getFitness() const = 0;
        
        //  Sets the fitness score of the Sudoku Puzzle
        //  @param  a fitness score
        virtual void setFitness(int) = 0;
    
    protected:
        // Fitness score, the lower the better with 0 being perfect (solved)
        int fitScore;
};

#endif	//PUZZLE_H_