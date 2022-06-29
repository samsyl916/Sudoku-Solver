#include <fstream>
#include <climits>
#include "sudoku.h"

using namespace std;

Sudoku::Sudoku(int values[][9])
{
    fitScore = INT_MAX;
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            spaces[i][j] = values[i][j];
        }
    }
}

Sudoku::~Sudoku()
{
    // no memory to deallocate
}

ostream& operator<<(ostream& output, const Sudoku& puzzle)
{
    // bottom and top border of 3-by-3 spaces
    string botTopBorder = "+-------+-------+-------+\n";

    // "human friendly" output of the Sudoku puzzle
    string puzStr = botTopBorder;
    
    int row = 0;    // current row in the Sudoku puzzle
    int col = 0;    // current column in the Sudoku puzzle

    // create the output
    while(row < 9 && col < 9)
    {
        // add side borders of 3-by-3 spaces
        if(col% 3 == 0)
        {
            puzStr.append("| ");
        }
        puzStr.append(to_string(puzzle.spaces[row][col]) + " ");
        col++;
        if(col % 9 == 0) {
            col = 0;
            row++;
            puzStr.append("|\n");
        }

        // add bottom and top border of 3-by-3 spaces
        if(row % 3 == 0 && col == 0)
        {
            puzStr.append(botTopBorder);
        }
    }

    return output << puzStr;
}

istream& operator>>(istream& input, Sudoku& puzzle)
{
    // store the input
    string puzzleString;
    input >> puzzleString;

    // get default puzzle file name
    if(puzzleString == "def") puzzleString = puzzle.DEFAULT_SUDOKU;

    string lastFour = "";
    // last 4 characters to check for ".txt"
    if(puzzleString.length() >= 4)
    {
        lastFour = puzzleString.substr(puzzleString.length() - 4,
                                       puzzleString.length() - 1
                                      );
    }

    // check if the input is the default Sudoku puzzle file,
    // if it is, fill the initial puzzle with the default Sudoku puzzle
    if(lastFour == ".txt") {
        // try opening the default Sudoku file
        ifstream file;
        try
        {
            file.open(puzzleString);
            puzzleString = "";      // clear puzzleString
            if(file.is_open())
            {
                // set puzzleString as the contents of the Sudoku file
                puzzleString = string((istreambuf_iterator<char>(file))
                                        , istreambuf_iterator<char>());
                puzzle.fillSpaces(puzzleString);
                file.close();
            }
        }
        // error opening the default Sudoku file
        catch(const std::exception& e)
        {
            std::cerr << "Error when reading the file: "
                      << puzzleString << e.what() << endl;
        }
        
    }
    // if not the default Sudoku puzzle file, fill the given puzzle with
    // the input puzzle
    else
    {
        puzzle.fillSpaces(puzzleString);
    }

    return input;
}

bool operator<(Sudoku& left, Sudoku& right)
{
    return left.fitScore < right.fitScore;
}

bool operator>(Sudoku& left, Sudoku& right)
{
    return left.fitScore > right.fitScore;
}

bool operator==(Sudoku& left, Sudoku& right)
{
    return left.fitScore == right.fitScore;
}

void Sudoku::operator=(const Sudoku& puzzle)
{
    for(int row = 0; row < 9; row++)
    {
        for(int col = 0; col < 9; col++)
        {
            spaces[row][col] = puzzle.getSpace(row, col);
        }
    }
}

int Sudoku::getSpace(int row, int col) const
{
    return spaces[row][col];
}

void Sudoku::setSpace(int row, int col, int val)
{
    spaces[row][col] = val;
}

int Sudoku::getFitness() const
{
    return fitScore;
}

void Sudoku::setFitness(int val)
{
    fitScore = val;
}

void Sudoku::fillSpaces(string input)
{
    int row = 0;    // current row of insertion
    int col = 0;    // current column of insertion
    int number = 0; // converted char to int
    int maxInput = MAX_INPUT_SIZE;

    // fill the spaces of the given Sudoku puzzle with the input
    for(char inputNum : input)
    {
        // if the space at (row, col) is empty (0), then replace it with
        // the character from the input
        if(spaces[row][col] == 0)
        {
            number = inputNum - '0';    // char to int
            if(0 <= number && number <= 9) // add valid characters (0 to 9)
            {
                spaces[row][col] = number;
                col++;
            }
            else
            {
                col++;
            }
            if(col % 9 == 0) { // go to a new row after reaching the 9th column
                col = 0;
                row++;
            }
        }
        maxInput--;
        if(maxInput == 0) break;
    }
}