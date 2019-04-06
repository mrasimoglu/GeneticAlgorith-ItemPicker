#pragma once
#include"shared.h"

class Brain
{
public:
	Brain();
	~Brain() { };

	Chromosome chromosome;

	inline void mutate(double chance) {
		double random;
		for (int i = 0; i < chromosomelength; i++)
		{
			random = dist(mersenne_engine);
			if (random < chance)
			{
				chromosome[i] = dist(mersenne_engine) * 4 + 1;
			}
		}
			
	};
	inline Brain *clone() {
		Brain *newone = new Brain();
		newone->chromosome = chromosome;
		return  newone;
	};
	
};

