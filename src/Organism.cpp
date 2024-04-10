//
// Created by W0470395 on 2023-12-11.
//

#include <vector>
#include <iostream>
#include <windows.h>
#include <conio.h>
#include "../inc/Organism.h"
#include "../inc/City.h"

using namespace std;

Organism::Organism() {
    x = 0;
    y = 0;
    type = '-';
    moved = false;
    city = nullptr;
}

Organism::Organism(City *cityToUse, int xcoord, int ycoord) {
    x = xcoord;
    y = ycoord;
    city = cityToUse;
    type = '-';
}

Organism::~Organism() {

}


void Organism::move() {

}

void Organism::turn() {

}

void Organism::reset() {
    moved = false;

}



ostream& operator<<(ostream &os, Organism *organism) {
    const char typeToPrint = organism->type;
    if (typeToPrint == 'H') {
        organism->color(10);
        os << "H ";
    }
    else if (typeToPrint == 'Z') {
        organism->color(12);
        os << "Z ";
    }
    else if (typeToPrint == '-') {
        organism->color(2);
        os << "- ";
    }
    return os;
}

char Organism::getType() {
    return type;
}



void Organism::color(int c) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, c);
}

void Organism::getPosition() {

}

vector<pair<int, int>> Organism::getUnoccupiedNeighbors() const {
    return {};
}

