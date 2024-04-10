//
// Created by W0068332 on 11/21/2021.
//
//Example main.cpp
//This supposes that city->step() calls the move method of each organism in the city
//in a single pass causing each to perform all tasks that it can.

#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include "inc/Organism.h"
#include "inc/City.h"
#include "inc/GameSpecs.h"
#include "inc/Human.h"
#include "inc/Zombie.h"

using namespace std;

void ClearScreen()
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

void messageColor(int c) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, c);
}

int main() {
    City *city = new City();
    chrono:: milliseconds const interval(INTERVAL);

    city->spawnOrganisms(15, 3);
    int generation = 1;

    do {
        this_thread::sleep_for(interval);
        ClearScreen();

        if (generation != 1) {
            city->turn();
            city->reset();
        }

        int numHumans = city->countOrganisms('H');
        int numZombies = city->countOrganisms('Z');

        cout << *city;

        cout << endl;

        if (numHumans != 0 && numZombies != 0) {
            messageColor(9);
            cout << "GENERATION: " << generation << endl;
            cout << endl;
            messageColor(10);
            cout << "HUMANS: " << numHumans << endl;
            messageColor(12);
            cout << "ZOMBIES: " << numZombies << endl;
        }
        else {
            messageColor(12);
            cout << "EXTINCTION!" << endl;
            cout << endl;
            messageColor(9);
            cout << "GENERATION: " << generation << endl;
            cout << endl;

            if (numHumans == 0) {
                messageColor(5);
            }
            else {
                messageColor(10);
            }
            cout << "HUMANS: " << numHumans << endl;

            if (numZombies == 0) {
                messageColor(5);
            }
            else {
                messageColor(12);
            }
            cout << "ZOMBIES: " << numZombies << endl;
        }
        generation++;
    } while (city->hasDiversity());

    delete city;

    return 0;
}

