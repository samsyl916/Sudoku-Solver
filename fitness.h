#ifndef FITNESS_H_
#define FITNESS_H_
//abstract class type
#include "puzzle.h"
using namespace std;

class Fitness 
{
    public:
        virtual int howFit(Puzzle& puz) const = 0;
};

#endif	// FITNESS_H_