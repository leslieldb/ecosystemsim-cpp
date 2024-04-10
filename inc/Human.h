#ifndef _Human_H
#define _Human_H

#include "Organism.h"

class Human : public Organism
{
	int recruitCounter;

public:
	Human(); 
	Human( City *city, int, int );
	virtual ~Human();

	void turn() override;

	void move() override;
	void recruit();

	vector<pair<int, int>> getUnoccupiedNeighbors() const override;
};

#endif
