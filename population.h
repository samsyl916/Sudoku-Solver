// Created by Patrick Banez
// Date: 5/28/2022
//
// An interface for a container of Puzzle objects. The interface does not
// specify how the Puzzles will be stored.

#ifndef POPULATION_H_
#define POPULATION_H_

#include <queue>
#include "puzzle.h"
#include "reproduction.h"
#include "fitness.h"

class Population {
    public:
        //  Default constructor
        //  Sets the initial size of the population to 0.
        Population() : size(0) {};

        //  4 Parameter constructor
        //  Creates the first generation of Puzzles.
        //  @param  the size of the Population
        //  @param  the number of generations to create
        //  @param  an unsolved Puzzle
        //  @param  a Reproduction object to create Puzzles
        //  @param  a Fitness object score each Puzzle
        Population(int amount, int generations, Puzzle&,
                    Reproduction&, Fitness&) : size(amount), gens(generations)
        {};

        //  Eliminates the <cullPerc>% least fit members of a generation.
        virtual  void cull() = 0;

        //  Produces a new generation of <size> amount of Puzzles based on the
        //  given Puzzle.
        //  @param  a Puzzle to base the new generation of Puzzles on
        //  @param  a Reproduction object to create Puzzles
        //  @param  a Fitness object to score each Puzzle
        virtual void newGeneration(const Puzzle&,
                                   Reproduction&,
                                   Fitness&
                                  ) {};

        //  Returns the best fit Puzzle in the current generation.
        virtual const Puzzle& bestFitness() const = 0;

        //  Returns the Puzzle with the highest fitness.
        virtual const Puzzle& bestIndividual() const = 0;

        //  Sets the size of the Population.
        //  @param  the Population's size
        void setSize(int amount) { size = amount; };

        //  Returns the size of the Population.
        //  @return the Population's size
        int getSize() { return size; };

        //  Sets the number of generations of the Population.
        //  @param  the number of generations for the Population
        void setGens(int amount) { gens = amount; };

        //  Returns the number of generations of the Population.
        //  @return the number of generations of the Population
        int getGens() { return size; };

    protected:
        //=====================================================================
        //                          MEMBER VARIABLES
        //=====================================================================
        int size;   // amount of Puzzles in the Population
        int gens;   // number of generations to create

        // percentage of least fit members of a generation to eliminate
        double cullPerc;

};

#endif	// POPULATION_H_