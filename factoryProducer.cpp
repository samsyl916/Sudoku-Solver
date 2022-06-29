#include "factoryProducer.h"
#include "sudokuFactory.h"

PuzzleFactory* FactoryProducer::getFactory()
{
    SudokuFactory* factory = new SudokuFactory();
    return factory;
}