//
//  main.cpp
//  Ants V Doodlebugs Simulation
//
//  Created by ax on 4/19/17.
//  Copyright © 2017 COMP235. All rights reserved.
//
#include "WorldMap.hpp"
#include "Organism.hpp"
#include "Ant.hpp"
#include "Doodlebug.hpp"
#include <iostream>
#include <string>
#include <ctime>
using std::string;
using std::cout;
using std::cin;
using std::endl;


// control functions
void stepConfirmMessage();
void readCoords();
void quitSimulation();

int main() {
    // insert code here...
    std::cout << "Ants V Doodlebugs Simulation!\n";
    
    // RANDOM SEED
    srand(static_cast<int>(time(0)));
    
    // INITIALIZE WORLD CONSTANTS
    const int WORLD_SIZE = 20;
    const int QTY_ANTS = 1;
    
    // create world
    WorldMap SimWorld(WORLD_SIZE, WORLD_SIZE);
    
    // populate world
    Organism bug("Sam");
    
    bug.getName();
    
    SimWorld.putBugOnMap(&bug);
    
    Doodlebug dbug("Dave");
    
    dbug.getName();
    
    SimWorld.putBugOnMap(&dbug);
    
    Ant ant("Andy");
    
    ant.getName();
    
    SimWorld.putBugOnMap(&ant);
    
    
//    cout << "Moving bugs around...\n";
//    bug.move();
//    ant.move();
//    dbug.move();
    
    
    SimWorld.moveBugsOnMap();
    
    // control loop
    // simulate time
    // step forward when user presses enter key
    bool stepforth = true;
    int iterationCount = 1;
    do {
        cout << "CONTROL LOOP ITERATION #"  << iterationCount << endl;
        
        // do loop stuff here
        
        SimWorld.printWorldMap();
        
        // user choice
        cout << "OPTIONS: [f]orward [r]ead cell [q]uit" << endl;
        char usr_input = ' ';
        std::cin >> usr_input;
        if (usr_input == 'f') {
            // only count iteration if moving forward in time
            iterationCount++;
            stepConfirmMessage();
        } else if (usr_input == 'r') {
            // read coord details
            // readCoords(SimBugWorld);
        } else if (usr_input == 'q') {
            quitSimulation();
        }
    } while (stepforth);
    
    return 0;
}

void stepConfirmMessage() {
    cout << "Stepping forward in time!" << endl;
}

void readCoords() {
    cout << "Read Cell Coords Placeholder!" << endl;
}

void quitSimulation() {
    cout << "Quitting, goodbye!" << endl;
    exit(1);
}




