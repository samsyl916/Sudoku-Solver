// A Sudoku puzzle is a 9x9 grid of spaces with each space containing a number
// from 1 to 9. A perfectly solved (fitScore = 0) Sudoku will have exactly 1
// copy of a number for each row, column and 3x3 grid. The first 3x3 grid
// starts from the upper left corner of the puzzle and then the rest of the
// 9x9 grid is sectioned off to the right and below the first 3x3 grid.

#ifndef SUDOKU_H_
#define SUDOKU_H_

#include <fstream>
#include <queue>
#include <vector>
#include "puzzle.h"


class Sudoku : public Puzzle {
    public:
        // Used for priority queue comparison of Sudoku fitness scores
        struct cmpFit {
            bool operator()(const Sudoku& a, const Sudoku& b)
            {
                // return true if a comes before b, false otherwise
                return a.getFitness() > b.getFitness();
            }
        };

        //  Default constructor
        //  Initializes all spaces of the Sudoku puzzle to 0's.
        Sudoku() : spaces{0} {};
        
        //  Overloaded constructor
        //  Initializes all spaces of the Sudoku puzzle to the given values.
        //  @param  9-by-9 int array
        Sudoku(int[][9]);

        // Destructor
        ~Sudoku();

        //  Reads a puzzle in compact text format. The format consists of a
        //  sequence of 81 digits, as ASCII text, each corresponding to the
        //  contents of one square in the puzzle grid, in row-major order
        //  (i.e., starting at the upper left corner, reading across each row
        //  and then continuing with the next row, ending at the bottom right
        //  corner). Blank (variable) squares are represented with zeros; fixed
        //  squares of course have non-zero values.
        //  @parameter  ostream to take in puzzle
        //  @parameter  Sudoku with spaces to fill
        //  @return     ostream
        friend std::ostream& operator<<(std::ostream&, const Sudoku&);

        //  Overload operator>>()
        //  Produces a "human friendly" output as formatted text. Output a
        //  puzzle as 13 lines of text, with each line either being a separator
        //  or one containing the numbers in a row of the puzzle separated by
        //  single spaces. Use the '|', '+', and '-' characters to separate
        //  3-by-3 blocks (so, each line of output should be 25 printing
        //  characters long: 9 digits, 12 spaces, and 4 '|' for "non-divider"
        //  lines and 21 '-' and 4 '+' for "divider" lines).
        //  @param  ostream to output the Sudoku
        //  @param  Sudoku to output
        //  @return ostream
        friend std::istream& operator>>(std::istream&, Sudoku&);

        //  Overload operator<
        //  Compares fitness scores of 2 Sudoku Puzzles.
        //  @param  Sudoku on the left of the operator
        //  @param  Sudoku on the right of the operator
        //  @return true if left's score is lesser than right's score
        //          false otherwise
        friend bool operator<(Sudoku&, Sudoku&);

        //  Overload operator>
        //  Compares fitness scores of 2 Sudoku Puzzles.
        //  @param  Sudoku on the left of the operator
        //  @param  Sudoku on the right of the operator
        //  @return true if left's score is greater than right's score
        //          false otherwise
        friend bool operator>(Sudoku&, Sudoku&);
        
        //  Overload operator==
        //  Compares fitness scores of 2 Sudoku Puzzles.
        //  @param  Sudoku on the left of the operator
        //  @param  Sudoku on the right of the operator
        //  @return true if left's score is equal to right's score
        //          false otherwise
        friend bool operator==(Sudoku&, Sudoku&);

        //  Overload operator=
        //  Sets this Sudoku's spaces equal to the given Sudoku's spaces
        //  @param  a Sudoku to copy from
        void operator=(const Sudoku&);

        //  Returns the number at the given row and column of the Sudoku puzzle.
        //  @param  row
        //  @param  column
        //  @return the number at the [row][column] of the Sudoku puzzle
        int getSpace(int, int) const;
        
        //  Sets the given row and column of the Sudoku puzzle to the given
        //  value.
        //  @param  row
        //  @param  column
        //  @param  value
        //  @return the number at the [row][column] of the Sudoku puzzle
        void setSpace(int, int, int);

        //  Gets the fitness score of the Sudoku Puzzle
        //  @return a fitness score
        int getFitness() const;
        
        //  Sets the fitness score of the Sudoku Puzzle
        //  @param  a fitness score
        void setFitness(int);

    private:
        //=====================================================================
        //                          MEMBER VARIABLES
        //=====================================================================
        int spaces[9][9];   // Fixed 9-by-9 grid
        
        // Maximum amount of input characters
        static const int MAX_INPUT_SIZE = 81;

        // Default Sudoku puzzle to solve
        const std::string DEFAULT_SUDOKU = "MySudoku.txt";
        
        //=====================================================================
        //                          MEMBER FUNCTIONS
        //=====================================================================
        // Fills the spaces of the Sudoku with the string input.
        // @param   A string with length of up to 81 contatining characters
        //          from 0 to 9
        void fillSpaces(const std::string);
};

#endif  // SUDOKU_H_