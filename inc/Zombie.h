#ifndef _Zombie_H
#define _Zombie_H

#include "Organism.h"

class Zombie : public Organism
{
	bool eaten;
	int breedCounter;
	int starveCounter;

public:
	Zombie();
	Zombie( City *city, int, int );
	virtual ~Zombie();

	void turn() override;

	void move() override;
	void eat();
	void breed();
	void starve();

	vector<pair<int, int>> getUnoccupiedNeighbors() const override;
	vector<pair<int,int>> getOccupiedNeighbors();
};

#endif
