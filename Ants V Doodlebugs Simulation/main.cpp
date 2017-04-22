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
// world block structs
struct WorldBlock {
    int pos_x = 0;
    int pos_y = 0;
    bool bOccupied = false;
    Organism * occupantPtr;
};

bool checkMapCoordsInBounds(vector<vector<WorldBlock *>> map,int world_size_x, int world_size_y, Coordinates loc);
bool checkMapCoordsOccupied(vector<vector<WorldBlock *>> map,int world_size_x, int world_size_y, Coordinates loc);
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

    //WorldMap SimWorld(WORLD_SIZE, WORLD_SIZE);
    
    // populate world
    Organism bug("Sam");
    bug.getName();
    // place Sam
    vWorldMapMatrix[0][0]->occupantPtr = &bug;
    vWorldMapMatrix[0][0]->bOccupied = true;
    bug.setCoords(0, 0);
    Coordinates thisBugsSpot = bug.getCoords();
    cout << "Getting coords for: " << bug.getName() << "\n";
    cout << thisBugsSpot.x << "," << thisBugsSpot.y << "\n";
    
    Doodlebug dbug("Dave");
    dbug.getName();
    
    vWorldMapMatrix[0][1]->occupantPtr = &dbug;
    vWorldMapMatrix[0][1]->bOccupied = true;

    Ant ant("Andy");

    vWorldMapMatrix[3][3]->occupantPtr = &ant;
    vWorldMapMatrix[3][3]->bOccupied = true;
    
    printWorldMap(vWorldMapMatrix);
    
    
    
    
    // control loop
    // simulate time
    // step forward when user presses enter key
    bool stepforth = true;
    int iterationCount = 1;
    do {
        cout << "CONTROL LOOP ITERATION #"  << iterationCount << endl;
        
        // do loop stuff here
        
        // move bugs
        
        cout << "Moving bugs around...\n";
        
        // select / choose / manipulate / invoke bug to be moved
        
        // bug chooses a move direction
        
        // bug checks the move direction
        Coordinates mov_coords = bug.getMoveCoords();
        // check map location
        
        // is it on the map?
        bool inbounds = checkMapCoordsInBounds(vWorldMapMatrix, WORLD_SIZE_X, WORLD_SIZE_Y, mov_coords);
        
        // is it an open spot or is it occupied?
        bool occupied = checkMapCoordsOccupied(vWorldMapMatrix, WORLD_SIZE_X, WORLD_SIZE_Y, mov_coords);
        
        // if it is free / open
        
        if (inbounds && !occupied) {
            cout << "In bounds and not occupied. Ready to move bug to loc.\n";
        } else {
            cout << "NOT In bounds OR occupied. NOT Ready to move bug to loc.\n";
        }
        
        // move there
        Coordinates old_coords = bug.getCoords(); // get old coords first
        // point new cooords to bug
        vWorldMapMatrix[mov_coords.x][mov_coords.y]->occupantPtr = &bug;
        vWorldMapMatrix[mov_coords.x][mov_coords.y]->bOccupied = true;
        bug.setCoords(mov_coords.x, mov_coords.y);
        // set old coordinates to fresh world block
        vWorldMapMatrix[old_coords.x][old_coords.y] = (new WorldBlock);
        vWorldMapMatrix[old_coords.x][old_coords.y]->pos_x = old_coords.x;
        vWorldMapMatrix[old_coords.x][old_coords.y]->pos_y = old_coords.y;
        vWorldMapMatrix[old_coords.x][old_coords.y]->bOccupied = false;
        
        printWorldMap(vWorldMapMatrix); // show me the move!
        
        // if it is occupied
        // if  bug can eat what's there
        // eat it
        // if bug can't eat it
        // stay put
        
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

bool checkMapCoordsInBounds(vector<vector<WorldBlock *>> map, int world_size_x, int world_size_y, Coordinates loc) {
    // inbounds?
    bool inbounds = false;
    if ((loc.x >= 0 && loc.x < world_size_x) && (loc.y >= 0 && loc.y < world_size_y)) {
        inbounds = true;
    }
    return inbounds;
}

bool checkMapCoordsOccupied(vector<vector<WorldBlock *>> map, int world_size_x, int world_size_y, Coordinates loc) {
    bool occupied = false;
    bool inbounds = checkMapCoordsInBounds(map, world_size_x, world_size_y, loc);
    if (inbounds) {
        cout << "Map check shows loc is in bounds.\n";
        // only check if occupied while in bounds. otherwise access error
        occupied = map[loc.x][loc.y]->bOccupied;
        if (occupied) {
            cout << "Map check shows loc is occupied.\n";
        } else {
            cout << "Map check shows loc is UNoccupied.\n";
        }
    } else {
        cout << "Map check shows loc is NOT in bounds.\n";
    }
    return occupied;
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
    }
}


