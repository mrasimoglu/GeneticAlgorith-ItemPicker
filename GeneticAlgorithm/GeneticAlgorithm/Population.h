#pragma once
#include "shared.h"
#include "Individual.h"

class Population
{
public:
	/**
	 *   Random Bireylerden olu�an bir populasyon yarat�r
	 **/
	Population();
	/**
	 *   Bir Populasyondan Populasyon Yatar�r.
	 **/
	Population(Population*, Maze *);
	~Population() { std::for_each(individuals.begin(), individuals.end(), [](Individual *x) { delete x; }); };


	void calcFitness(Maze *m);
	void calcBest();
	Individual *best;
	Individual *randomSelect();
	Individual *crossOver(Individual *, Individual *);
	std::vector<Individual*> individuals;
};

