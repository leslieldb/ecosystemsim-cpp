//
// Created by phldb on 2023-12-13.
//

#include <vector>
#include <chrono>
#include <algorithm>
#include <random>
#include <iostream>
#include <windows.h>
#include <conio.h>
#include "../inc/EmptySpace.h"
#include "../inc/Organism.h"

using namespace std;

EmptySpace::EmptySpace() {
    type = '-';
}

EmptySpace::EmptySpace(City* cityToUse, int xcoord, int ycoord) {
    x = xcoord;
    y = ycoord;
    type = '-';
    city = cityToUse;

}

EmptySpace::~EmptySpace() {

}


void EmptySpace::turn() {

}


