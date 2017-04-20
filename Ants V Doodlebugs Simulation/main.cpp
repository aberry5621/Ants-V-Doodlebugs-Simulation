//
//  main.cpp
//  Ants V Doodlebugs Simulation
//
//  Created by ax on 4/19/17.
//  Copyright © 2017 COMP235. All rights reserved.
//

#include "Organism.hpp"
#include "Ant.hpp"
#include "Doodlebug.hpp"

#include <iostream>
#include <string>
#include <ctime>
#include <vector>
using namespace std;


// MAIN PROGRAM DECLARATIONS
// control functions
void stepConfirmMessage();
void readCoords();
void quitSimulation();

struct WorldBlock {
    int pos_x = 0;
    int pos_y = 0;
    bool bOccupied = false;
    Organism * occupantPtr;
};

void printWorldMap(vector<vector<WorldBlock *>>);

int main() {
    // insert code here...
    std::cout << "Ants V Doodlebugs Simulation!\n";
    
    // RANDOM SEED
    srand(static_cast<int>(time(0)));
    
    // INITIALIZE WORLD CONSTANTS
    const int WORLD_SIZE_X = 20;
    const int WORLD_SIZE_Y = 20;
    const int QTY_ANTS = 1;
    
    // create world
    
    vector<vector<WorldBlock *>> vWorldMapMatrix;
    WorldBlock * tmpWorldBlockPtr;
    
    // store x y WorldMap size in WorldMap size member variables
    
    vWorldMapMatrix.resize(WORLD_SIZE_X);
    
    for (int i = 0; i < WORLD_SIZE_X; i++) {
        vWorldMapMatrix[i] = vector<WorldBlock *>(WORLD_SIZE_Y);
    }
    // fill each row / col with a new world block
    for (int row = 0; row < vWorldMapMatrix.size(); row++) {
        for (int col = 0; col < vWorldMapMatrix[row].size(); col++) {
            vWorldMapMatrix[row][col] = (new WorldBlock);
            vWorldMapMatrix[row][col]->pos_x = row;
            vWorldMapMatrix[row][col]->pos_y = col;
        }
    }

    printWorldMap(vWorldMapMatrix);
    
    
    //WorldMap SimWorld(WORLD_SIZE, WORLD_SIZE);
    
    // populate world
//    Organism bug("Sam");
//    
//    bug.getName();
//    
//    SimWorld.putBugOnMap(&bug);
//    
//    
//    
//    Doodlebug dbug("Dave");
//    
//    dbug.getName();
//    
//    SimWorld.putBugOnMap(&dbug);
//    
//    
//    
//    Ant ant("Andy");
//    
//    ant.getName();
//    
//    SimWorld.putBugOnMap(&ant);
//    
//    
//    cout << "Moving bugs around...\n";
//    bug.move();
//    ant.move();
//    dbug.move();
    
    // control loop
    // simulate time
    // step forward when user presses enter key
    bool stepforth = true;
    int iterationCount = 1;
    do {
        cout << "CONTROL LOOP ITERATION #"  << iterationCount << endl;
        
        // do loop stuff here
        
        // SimWorld.printWorldMap();
        
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

// MAIN PROGRAM FUNCITON DEFINITIONS
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

void printWorldMap(vector<vector<WorldBlock *>> vWorldMapMatrix) {
    // print the grid with row and column counts
    cout << "Printing the WorldMap * * * * * * * * *" << endl;
    for (int row = 0; row < vWorldMapMatrix.size(); row++) {
        if (row == 0) {
            for (int col = 0; col < vWorldMapMatrix[row].size()+1; col++) {
                if (col == 0) {
                    cout << "   ";
                } else {
                    if (col < 11) {
                        cout << "0" << col-1 << " ";
                    } else {
                        cout << col-1 << " ";
                    }
                }
            }
            cout << "\n";
        }
        for (int col = 0; col < vWorldMapMatrix[row].size(); col++) {
            if (col == 0) {
                if (row < 10) {
                    cout << "0" << row << " ";
                } else {
                    cout << row << " ";
                }
            }
            if (vWorldMapMatrix[row][col]->bOccupied) {
                cout << "[" << vWorldMapMatrix[row][col]->occupantPtr->getSymbol() << "]";
            } else {
                cout << "[ ]";
            }
        }
        cout << "\n";
    }}


