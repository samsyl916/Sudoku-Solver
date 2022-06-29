#include <algorithm>
#include <iostream>
#include <vector>
#include "puzzle.h"
#include "SudokuOffspring.h"
#include "sudoku.h"

using namespace std;

SudokuOffspring::SudokuOffspring() {}

Sudoku& SudokuOffspring::MakeOffSpring(const Puzzle& puz) {
    // generate a random number
    srand( time(0) ); 
	randNum0_ = rand() % 10;
    randNum1_ = rand() % 10;
    randNum2_ = rand() % 10;
    randNum3_ = rand() % 10;
    // randomly select a row then store into an array
    vector<int> rowArray;
    for (int i = 0; i < 9; i++) {
        rowArray.push_back(puz.getSpace(randNum0_, i));
    }  
    // randomly select a column then store into an array
    vector<int> columnArray;
    for (int i = 0; i < 9; i++) {
        columnArray.push_back(puz.getSpace(i, randNum1_));
    }  
    // randomly swap two numbers in the Sudoku
    swap(rowArray[randNum2_], columnArray[randNum3_]);
    
    // update puzzle
    // update row
    Sudoku* newSudoku = new Sudoku();
    // copy the parent's spaces into the new sudoku
    for(int row = 0; row < 9; row++)
    {
        for(int col = 0; col < 9; col++)
        {
            newSudoku->setSpace(row, col, puz.getSpace(row, col));
        }
    }
    for (int i = 0; i < rowArray.size(); i++) {
        newSudoku->setSpace(randNum0_, i, rowArray[i]);
    }
    // update column
    for (int i = 0; i < rowArray.size(); i++) {
        newSudoku->setSpace(i, randNum1_, columnArray[i]);
    }
    return *newSudoku;
}