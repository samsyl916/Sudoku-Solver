#ifndef REPRODUCTION_H_
#define REPRODUCTION_H_

#include <iostream>
#include "puzzle.h"

class Reproduction {
    public:
        virtual Puzzle& MakeOffSpring(const Puzzle& puz) = 0;
};

#endif	// REPRODUCTION_H_