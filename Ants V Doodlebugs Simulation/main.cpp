//
//  main.cpp
//  Ants V Doodlebugs Simulation
//
//  Created by ax on 4/19/17.
//  Copyright © 2017 COMP235. All rights reserved.
//

#include "WorldBlockTemplate.hpp"
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


bool checkMapCoordsInBounds(vector<vector<WorldBlock<Organism> *>> map,int world_size_x, int world_size_y, Coordinates loc);
bool checkMapCoordsOccupied(vector<vector<WorldBlock<Organism> *>> map,int world_size_x, int world_size_y, Coordinates loc);

// world reference, coords old, coords new, bug poinger
void moveBugs(vector<vector<WorldBlock<Organism> *>> vWorldMapMatrix, char bugType);

void printWorldMap(vector<vector<WorldBlock<Organism> *>>);

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
    
    vector<vector<WorldBlock<Organism> *>> vWorldMapMatrix;
    WorldBlock<Organism> * tmpWorldBlockPtr;
    
    // store x y WorldMap size in WorldMap size member variables
    
    vWorldMapMatrix.resize(WORLD_SIZE_X);
    
    for (int i = 0; i < WORLD_SIZE_X; i++) {
        vWorldMapMatrix[i] = vector<WorldBlock<Organism> *>(WORLD_SIZE_Y);
    }
    // fill each row / col with a new world block
    for (int row = 0; row < vWorldMapMatrix.size(); row++) {
        for (int col = 0; col < vWorldMapMatrix[row].size(); col++) {
            vWorldMapMatrix[row][col] = (new WorldBlock<Organism>);
            vWorldMapMatrix[row][col]->pos_x = row;
            vWorldMapMatrix[row][col]->pos_y = col;
        }
    }


    
    Doodlebug dbug("Dave", vWorldMapMatrix);
    dbug.getName();
    
    vWorldMapMatrix[2][2]->occupantPtr = &dbug;
    vWorldMapMatrix[2][2]->bOccupied = true;
    dbug.setCoords(2, 2);
    
    // make ants with pointers and new
    
    // create ant with ant pointer so can eat and delete maybe

    Ant * antPtr;
    antPtr = new Ant("Andy", vWorldMapMatrix);
    vWorldMapMatrix[2][3]->occupantPtr = antPtr;
    vWorldMapMatrix[2][3]->bOccupied = true;
    antPtr->setCoords(2, 3);

    antPtr = new Ant();
    antPtr->setName("Adam");
    antPtr->setSymbol('A');
    antPtr->setBugTypeId(2);
    antPtr->setMapPointer(vWorldMapMatrix);
    vWorldMapMatrix[3][3]->occupantPtr = antPtr;
    vWorldMapMatrix[3][3]->bOccupied = true;
    antPtr->setCoords(3, 3);

    printWorldMap(vWorldMapMatrix);

    // control loop
    // simulate time
    // step forward when user presses enter key
    bool stepforth = true;
    int it_count = 1;
    do {
        cout << "CONTROL LOOP ITERATION #"  << it_count << endl;

        
        cout << "Moving bugs around...\n";

        
        // move doodlebugs first
        moveBugs(vWorldMapMatrix, 'D');
        
        printWorldMap(vWorldMapMatrix); // show me the move!
        
        
        moveBugs(vWorldMapMatrix, 'A');

        
        printWorldMap(vWorldMapMatrix); // show me the move!
        
        
        // user choice
        cout << "OPTIONS: [f]orward [r]ead cell [q]uit" << endl;
        char usr_input = ' ';
        std::cin >> usr_input;
        if (usr_input == 'f') {
            // only count iteration if moving forward in time
            it_count++;
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

void moveBugs(vector<vector<WorldBlock<Organism> *>> vWorldMapMatrix, char bugType) {
    // print the grid with row and column counts
    cout << "Moving bugs * * * * * * * * *" << endl;
    for (int row = 1; row < vWorldMapMatrix.size(); row++) {
        for (int col = 1; col < vWorldMapMatrix[row].size(); col++) {
            Organism * tmpBugPtr;
            if (vWorldMapMatrix[row][col]->occupantPtr != nullptr) {
                tmpBugPtr = vWorldMapMatrix[row][col]->occupantPtr;
                // get time since moved
                cout << "Bug named "  << tmpBugPtr->getName() << " ";
                cout << "Bug type "  << tmpBugPtr->getSymbol() << " ";
                // if the bug time since moved is more than 0
                if (tmpBugPtr->getSymbol() == bugType && tmpBugPtr->getTimeSinceMoved() > 0) {
                    cout << "has not moved in "  << tmpBugPtr->getTimeSinceMoved() << " iterations. ";
                    // move the bug
                    cout << "So attempting to move now. \n";
                    tmpBugPtr->move();
                    // reset time since moved to 0
                    tmpBugPtr->resetTimeSinceMoved();
                } else {
                    cout << "just moved "  << tmpBugPtr->getTimeSinceMoved() << " iterations ago.\n";
                    tmpBugPtr->incrementTimeSinceMoved();
                }

            }
            
        }
    }
}

void printWorldMap(vector<vector<WorldBlock<Organism> *>> vWorldMapMatrix) {
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
    }
}


