//Nathan Koplitz
#include "sudokuFitness.h"
#include "sudoku.h"
#include <vector>
#include <set>
#include <algorithm> 
using namespace std;


int sudokuFitness::howFit(Puzzle &puz) const //returns the Fitness Score of the puzzle and stores that to each Sudoku
{
    int fScore = 0;
    for (int row = 0; row < 9; row++) //counting duplicates in the rows
    {
        int arr[9];
        for (int i = 0; i < 9; i++)
        {
            arr[i] = puz.getSpace(0, i);  //store row in array
        }
        vector<int> vec (arr, arr + 9); //moving to an array
        sort(vec.begin(), vec.end()); //sorts the row 
        for (int x = 0; x < 8; x++)
        {
            if (vec[x] == vec[x + 1]) //checks for duplicates, if found, increasing the fScore
                fScore++;
        }
    }

    for (int col = 0; col < 9; col++) //Counting duplicates in the columns
    {
        int arr2[9];
        for (int z = 0; z < 9; z++)
        {
            arr2[z] = puz.getSpace(z, 0); //Stores each column
        }
        vector<int> vec2 (arr2, arr2 + 9);
        sort(vec2.begin(), vec2.end());
        for (int y = 0; y < 8; y++)
        {
            if (vec2[y] == vec2[y + 1]) //If duplicates, increase fitnessScore
                fScore++;
        }
    }

    for (int row = 0; row < 9; row += 3) //Checks for duplicates in the 3x3 blocks
    {
        for (int col = 0; col < 9; col += 3)
        {
            set<int> set1;
            for(int r = row; r < row + 3; r++)
            {
                for(int c = col; c < col + 3; c++)
                {
                    if(set1.insert(puz.getSpace(r, c)).second == false)
                        fScore++;
                } 
            }
        }  
    }  
    return fScore;
}