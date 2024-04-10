#ifndef _CITY_H
#define _CITY_H

#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

class Organism;

const int GRID_WIDTH = 20;
const int GRID_HEIGHT = 20;

class City
{
protected:
	Organism *grid[GRID_HEIGHT][GRID_WIDTH];

public:
	City();
	virtual ~City();

	Organism *getOrganism( int x, int y );
	void setOrganism( Organism *organism, int x, int y );

	void spawnOrganisms(int, int);

	virtual void turn();
	void reset();
	int countOrganisms(char) const;
	bool hasDiversity() const;

	friend ostream& operator<<( ostream &os, City &city );

private:
	void spawnHuman();
	void spawnZombie();
};

#endif

