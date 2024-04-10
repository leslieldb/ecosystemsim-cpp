#ifndef _Organism_H
#define _Organism_H

#include <vector>
#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

class City;

class Organism
{
protected:
	int x;
	int y;
	char type;
	bool moved;
	City *city;

public:
	Organism();
	Organism( City *city, int, int );
	virtual ~Organism();

	virtual void move();
	virtual void turn() = 0;
	void reset();

	void setPosition( int x, int y );
	void getPosition();
	char getType();
	void endTurn();
	bool isTurn();

	void color(int);

	friend ostream& operator<<( ostream &os, Organism *organism );

	virtual vector<pair<int, int>> getUnoccupiedNeighbors() const;

protected:
};

#endif
