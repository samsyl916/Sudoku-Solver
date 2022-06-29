#ifndef FACTORY_PRODUCER_H_
#define FACTORY_PRODUCER_H_

#include "puzzleFactory.h"

class FactoryProducer {
    public:
        // Creates and returns a new instance of Puzzle
        // @return  an instance of Puzzle
        virtual PuzzleFactory* getFactory();
};

#endif  // FACTORY_PRODUCER_H_