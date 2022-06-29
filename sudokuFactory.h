#ifndef SUDOKU_FACTORY_H_
#define SUDOKU_FACTORY_H_

#include "puzzleFactory.h"
#include "SudokuOffspring.h"
#include "sudokuPopulation.h"
#include "sudokuFitness.h"
#include "sudoku.h"

class SudokuFactory : public PuzzleFactory {
    public:
        // Constructor
        // Intializes the reproduction and fitness pointers
        SudokuFactory();

        // Creates and returns a new Sudoku object
        Sudoku& createPuzzle();

        // Sets the original Sudoku object
        // @param   a Sudoku object
        void setOriginal(Sudoku&);
        
        // Gets the original Sudoku object
        // @return   the original Sudoku
        const Sudoku& getOriginal();

        // Sets the Population object
        // @param   a SudokuPopulation object
        void setPop(SudokuPopulation&);
        
        // Gets the Population object
        // @return   SudokuPopulation object
        SudokuPopulation& getPop();

        // Sets the sudokuFitness object
        // @param   a sudokuFitness object
        void setFit(sudokuFitness&);
        
        // Gets the sudokuFitness object
        // @return   the sudokuFitness object
        sudokuFitness& getFit();

        // Sets the Reproduction object
        // @param   a SudokuOffspring object
        void setRepro(SudokuOffspring&);
        
        // Gets the Reproduction object
        // @return   the the SudokuOffspring object
        SudokuOffspring& getRepro();
};

#endif  // SUDOKU_FACTORY_H_