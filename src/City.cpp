//
// Created by W0470395 on 2023-12-11.
//
#include <iostream>
#include <windows.h>
#include <conio.h>
#include "../inc/City.h"

#include "../inc/EmptySpace.h"
#include "../inc/Organism.h"
#include "../inc/Human.h"
#include "../inc/Zombie.h"

using namespace std;

City::City() {
    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            grid[i][j] = new EmptySpace(this, j, i);
        }
    }
}

City::~City() {
    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            delete grid[i][j];
        }
    }
}

void City::spawnOrganisms(int numHumans, int numZombies) {
    srand(static_cast<unsigned>(time(0))); // Seed for random number generation

    for (int i = 0; i < numHumans; ++i) {
        spawnHuman();
    }

    for (int i = 0; i < numZombies; ++i) {
        spawnZombie();
    }
}


ostream& operator<<(ostream &os, City &city) {
    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            os << city.grid[i][j] << " ";
        }

        os << endl;
    }
    return os;
}

void City::reset() {
    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            Organism* organism = grid[i][j];
            if (organism != nullptr) {
                if (organism->getType() == 'H' || organism->getType() == 'Z') {
                    organism->reset();
                }
            }
        }
    }
}

void City::turn() {
    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            Organism* organism = grid[i][j];
            organism->turn();
        }
    }
}

void City::spawnHuman() {
    int x, y;

    do {
        x = rand() % GRID_WIDTH;
        y = rand() % GRID_HEIGHT;
    } while (grid[y][x]->getType() != '-');

    delete grid[y][x];
    grid[y][x] = new Human(this, x, y);
}

void City::spawnZombie() {
    int x, y;

    do {
        x = rand() % GRID_WIDTH;
        y = rand() % GRID_HEIGHT;
    } while (grid[y][x]->getType() != '-');

    delete grid[y][x];
    grid[y][x] = new Zombie(this, x, y);
}


int City::countOrganisms(char type) const {
    int count = 0;

    for (int i = 0; i < GRID_HEIGHT; ++i) {
        for (int j = 0; j < GRID_WIDTH; ++j) {
            if (grid[i][j]->getType() == type) {
                ++count;
            }
        }
    }

    return count;
}

bool City::hasDiversity() const {
    bool hasHumans = false;
    bool hasZombies = false;

    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            Organism* organism = grid[i][j];
            if (organism != nullptr) {
                if (organism->getType() == 'H') {
                    hasHumans = true;
                }
                else if (organism->getType() == 'Z') {
                    hasZombies = true;
                }
            }
        }
    }

    return hasHumans && hasZombies;
}


void City::setOrganism(Organism* organism, int x, int y) {
    grid[y][x] = organism;
}

Organism* City::getOrganism(int x, int y) {
    Organism* organism = grid[y][x];

    return organism;
}

