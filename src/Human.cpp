//
// Created by W0470395 on 2023-12-11.
//

#include <vector>
#include <chrono>
#include <algorithm>
#include <random>
#include "../inc/Human.h"
#include "../inc/City.h"
#include "../inc/EmptySpace.h"

using namespace std;

Human::Human() {
    type = 'H';
    recruitCounter = 0;
}

Human::Human(City *cityToUse, int xcoord, int ycoord) {
    x = xcoord;
    y = ycoord;
    type = 'H';
    city = cityToUse;
    recruitCounter = 0;
}

Human::~Human() {

}


void Human::turn() {
    if (!moved) {
        move();
        recruitCounter += 1;
        if (recruitCounter == 3) {
            recruit();
        }
    }
    moved = true;
}

void Human::move() {
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
}

vector<pair<int, int>> Human::getUnoccupiedNeighbors() const {
    vector<pair<int,int>> possibleMoves;

    if (y > 0 && city->getOrganism(x, y -1 )->getType() == '-') {
        possibleMoves.emplace_back(x, y - 1);
    }
    if (y < GRID_HEIGHT - 1 && city->getOrganism(x, y + 1)->getType() == '-') {
        possibleMoves.emplace_back(x, y + 1);
    }
    if (x > 0 && city->getOrganism(x - 1, y)->getType() == '-') {
        possibleMoves.emplace_back(x - 1, y);
    }
    if (x < GRID_WIDTH - 1 && city->getOrganism(x + 1, y)->getType() == '-') {
        possibleMoves.emplace_back(x + 1, y);
    }

    return possibleMoves;
}

void Human::recruit() {
    vector<pair<int,int>> moves = getUnoccupiedNeighbors();

    if (!moves.empty() && !moved) {
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        shuffle(moves.begin(),moves.end(),default_random_engine(seed));

        pair<int,int> selectedMove = moves[0];

        int newX = selectedMove.first;
        int newY = selectedMove.second;

        Human* newHuman = new Human(city, newX, newY);

        newHuman->moved = true;

        city->setOrganism(newHuman, newX, newY);
    }

    recruitCounter = 0;
}
