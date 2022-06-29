#include "sudokuFactory.h"
#include "sudokuFitness.h"

SudokuFactory::SudokuFactory()
{
    repro = new SudokuOffspring();
    fit = new sudokuFitness();
}

Sudoku& SudokuFactory::createPuzzle()
{
    Sudoku* newSudoku = new Sudoku();
    return *newSudoku;
}

void SudokuFactory::setOriginal(Sudoku& sudoku)
{
    original = &sudoku;
}

const Sudoku& SudokuFactory::getOriginal()
{
    return *dynamic_cast<Sudoku*>(original);
}

void SudokuFactory::setPop(SudokuPopulation& newPop)
{
    population = &newPop;
}

SudokuPopulation& SudokuFactory::getPop()
{
    return *dynamic_cast<SudokuPopulation*>(population);
}

void SudokuFactory::setFit(sudokuFitness& newFit)
{
    fit = &newFit;
}

sudokuFitness& SudokuFactory::getFit()
{
    return *dynamic_cast<sudokuFitness*>(fit);
}

void SudokuFactory::setRepro(SudokuOffspring& newRepro)
{
    repro = &newRepro;
}

SudokuOffspring& SudokuFactory::getRepro()
{
    return *dynamic_cast<SudokuOffspring*>(repro);
}