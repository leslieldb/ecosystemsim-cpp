//
// Created by W0470395 on 2023-12-11.
//

#include <vector>
#include <chrono>
#include <algorithm>
#include <random>
#include "../inc/Zombie.h"
#include "../inc/City.h"
#include "../inc/EmptySpace.h"
#include "../inc/Human.h"

using namespace std;

Zombie::Zombie() {
    type = 'Z';
}

Zombie::Zombie(City *cityToUse, int xcoord, int ycoord) {
    x = xcoord;
    y = ycoord;
    type = 'Z';
    city = cityToUse;
    eaten = false;
    breedCounter = 0;
    starveCounter = 0;
}

Zombie::~Zombie() {

}



void Zombie::turn() {
    if (!moved) {
        eat();
        if (moved) {
            starveCounter = 0;
        }
        else {
            starveCounter += 1;
        }
        move();
        breedCounter += 1;
        if (breedCounter >= 8) {
            breed();
        }
        if (starveCounter == 3) {
            starve();
        }
    }
}

void Zombie::move() {
    vector<pair<int,int>> moves = getUnoccupiedNeighbors();

    if (!moves.empty() && !moved) {
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        shuffle(moves.begin(),moves.end(),default_random_engine(seed));

        pair<int,int> selectedMove = moves[0];

        city->setOrganism(new EmptySpace(), x, y);
        x = selectedMove.first;
        y = selectedMove.second;
        city->setOrganism(this, x, y);
    }

    moved = true;
}

void Zombie::eat() {
    vector<pair<int,int>> moves = getOccupiedNeighbors();

    if (!moves.empty() && !moved) {
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        shuffle(moves.begin(),moves.end(),default_random_engine(seed));

        pair<int,int> selectedMove = moves[0];

        city->setOrganism(new EmptySpace(), x, y);
        x = selectedMove.first;
        y = selectedMove.second;
        city->setOrganism(this, x, y);

        moved = true;
    }
}

void Zombie::breed() {
    vector<pair<int,int>> moves = getOccupiedNeighbors();

    if (!moves.empty()) {
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        shuffle(moves.begin(),moves.end(),default_random_engine(seed));

        pair<int,int> selectedMove = moves[0];

        int newX = selectedMove.first;
        int newY = selectedMove.second;

        Zombie* newZombie = new Zombie(city, newX, newY);

        newZombie->moved = true;

        city->setOrganism(newZombie, newX, newY);

        breedCounter = 0;
    }
}

vector<pair<int, int>> Zombie::getOccupiedNeighbors() {
    vector<pair<int,int>> possibleMoves;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int newX = x + i;
            int newY = y + j;

            if (newX >= 0 && newX < GRID_WIDTH && newY >= 0 && newY < GRID_HEIGHT && (i != 0 || j != 0) &&
                city->getOrganism(newX, newY)->getType() == 'H') {
                possibleMoves.emplace_back(newX, newY);
                }
        }
    }

    return possibleMoves;
}


vector<pair<int, int>> Zombie::getUnoccupiedNeighbors() const {
    vector<pair<int,int>> possibleMoves;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int newX = x + i;
            int newY = y + j;

            if (newX >= 0 && newX < GRID_WIDTH && newY >= 0 && newY < GRID_HEIGHT && (i != 0 || j != 0) &&
                city->getOrganism(newX, newY)->getType() == '-') {
                possibleMoves.emplace_back(newX, newY);
            }
        }
    }

    return possibleMoves;
}

void Zombie::starve() {
    city->setOrganism(new Human(city, x, y), x, y);
}
