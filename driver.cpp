// Driver for the Sudoku Solver program. The program takes in 2 command line
// arguments:
//      1.  the size of the population
//      2.  the maximum number of generations
// A sudoku puzzle is then read from cin and the first generation of
// puzzles is created. After the first generation of puzzles is created, the
// Genetic Algorithm iterations begin.
//      1. The Population is asked for the bestFitness, halting iterations if
//         a solution is found or if the maximum number of generations limit
//         is reached.
//      2. The Population is commanded to cull 90% of its puzzles.
//      3. The Population reproduces a new generation with a call to
//         newGeneration.

#include <iostream>
#include "sudoku.h"
#include "puzzle.h"
#include "puzzleFactory.h"
#include "sudokuFactory.h"
#include "factoryProducer.h"

using namespace std;

// testing Sudoku with array parameter constructor
void testingSudokuConstructor()
{
    ofstream saveFile2("BestFitSudoku2.txt");
    int testArr[9][9] = {0};
    // randomly fill test array
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            // random number from 0 to 9
            testArr[i][j] = (rand() % 9) + 1;
        }
    }
    Sudoku testSudoku(testArr);
    saveFile2 << testSudoku;
}

int main(int argc, char *argv[])
{
    if(argc < 3) {
        cerr << "Population size and number of generations were not entered."
                << endl;
        return -1;
    }

    // get the command line inputs of population size and number of generations
    int size = atoi(argv[1]);    // size of the population
    int gens = atoi(argv[2]);    // maximum number of generations

    // output text file for best fit scored Sudoku puzzle
    ofstream saveFile("BestFitSudoku.txt");

    // Create a FactoryProducer and get a PuzzleFactory. Then create a new
    // Puzzle to solve.
    FactoryProducer factProd;
    PuzzleFactory* puzFact = factProd.getFactory();
    SudokuFactory* sudFact = dynamic_cast<SudokuFactory*>(puzFact);

    // Create a Puzzle to solve
    Puzzle* puzzle = new Sudoku();
    Sudoku* sudoku = dynamic_cast<Sudoku*>(puzzle);
    string sudokuInput = "";
    cout << "Enter a Sudoku puzzle as 1 line of 81 digits from 0 to 9 "
         << "or enter a Sudoku file.\n(Enter \"def\" for the"
         << " default Sudoku puzzle.)"
         << endl;
    cin >> *sudoku;
    cout << "The puzzle you entered was:\n" << *sudoku << endl;

    // Create a Population of Puzzles to generate an answer
    Population* population = new SudokuPopulation(
                                                  size,
                                                  gens,
                                                  *sudoku,
                                                  sudFact->getRepro(),
                                                  sudFact->getFit()
                                                 );
    SudokuPopulation* sudPop = dynamic_cast<SudokuPopulation*>(population);
    cout << "Initially randomly filling the Sudoku:\n" << *sudoku
        << sudoku->getFitness() << endl << endl;

    // Add the new Population and original Puzzle to the Factory
    sudFact->setPop(*sudPop);
    sudFact->setOriginal(*sudoku);

    // Current best individual Sudoku in the Population
    const Sudoku* best = &(sudFact->getPop()).bestIndividual();
    cout << "The best Puzzle in the first generation:\n" << *best
        << "Fitness Score: " << best->getFitness() << endl << endl;

    // Create generations of puzzles to find a possible solution
    for(int i = 0; i < gens - 1; i++)
    {
        sudPop->cull();
        int curPopSize = sudPop->getHeap().size();
        // Store the top fit puzzles to create new generations from
        queue<const Sudoku*> topFit;
        for(int i = 0; i < curPopSize; i++)
        {
            topFit.push(&sudPop->getHeap().top());
            sudPop->getHeap().pop();
        }
        // Create new Sudoku Puzzles based on the top fit puzzles from the
        // previous generation. Check for a solved puzzle and cull if a
        // solution isn't found. Repeat until a solved puzzle is found or
        // until all the top fit puzzles are used.
        while(!topFit.empty())
        {
            const Sudoku* curPuz = topFit.front();
            topFit.pop();
            sudPop->newGeneration(*curPuz,
                                  sudFact->getRepro(),
                                  sudFact->getFit()
                                 );
            if(sudPop->getHeap().top().getFitness() == 0)
            {
                best = &sudPop->getHeap().top();
                break;
            }
        }
        best = &(sudFact->getPop()).bestFitness();
        cout << "The best Puzzle in generation " << (i+2) << ":\n" << *best
            << "Fitness Score: " << best->getFitness() << endl << endl;
    }

    // output the best fit Sudoku puzzle
    best = &(sudFact->getPop()).bestIndividual();
    saveFile << *best << "Fitness Score: " << best->getFitness() << endl;

    delete puzzle;
    delete population;
    delete puzFact;
    return 0;
}