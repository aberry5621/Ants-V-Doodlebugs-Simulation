/* Ants V Doodlebugs Simulation
 *
 File: main.cpp
 Created by Alex on 4/19/17.
 Compiler: Apple LLVM 8.1
 Files:
 WorldBlockTemplate.hpp,
 Organism.hpp, Organism.cpp
 Ant.hpp, Ant.cpp
 Doodlebug.hpp, Doodlebug.cpp
 Purpose: Demonstrate library implementations of classes Organism, Ant and Doodlebug
 *
 */

#include "WorldBlockTemplate.hpp"
#include "Organism.hpp"
#include "Ant.hpp"
#include "Doodlebug.hpp"
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
using namespace std;

// MAIN FUNCTION DECLARATIONS

// Control functions
void stepConfirmMessage();
void readCoords();
void quitSimulation();
int get_rand(int p_lb, int p_ub);

// Utility functions
void countBugs(vector<vector<WorldBlock<Organism> *>> vWorldMapMatrix);
bool checkMapCoordsInBounds(vector<vector<WorldBlock<Organism> *>> map,int world_size_x, int world_size_y, Coordinates loc);
bool checkMapCoordsOccupied(vector<vector<WorldBlock<Organism> *>> map,int world_size_x, int world_size_y, Coordinates loc);
void moveBugs(vector<vector<WorldBlock<Organism> *>> vWorldMapMatrix, char bugType);
void printWorldMap(vector<vector<WorldBlock<Organism> *>>);

// Data structure for counting bugs
struct BugCount {
    int num_ants = 0;
    int num_dbugs = 0;
};

// MAIN PROGRAM LOOP
int main() {
    cout << "Ants V Doodlebugs Simulation!\n"; // Condole title
    srand(static_cast<int>(time(0)));// Random seed
    // INITIALIZE WORLD CONSTANTS
    const int WORLD_SIZE_X = 20;
    const int WORLD_SIZE_Y = 20;
    const int QTY_ANTS = 100;
    const int QTY_DBUGS = 5;
    
    // CREATE WORLD MAP
    vector<vector<WorldBlock<Organism> *>> vWorldMapMatrix;
    vWorldMapMatrix.resize(WORLD_SIZE_X);
    for (int i = 0; i < WORLD_SIZE_X; i++) {
        vWorldMapMatrix[i] = vector<WorldBlock<Organism> *>(WORLD_SIZE_Y);
    }
    
    // fill each row / col with a new world block
    for (int row = 0; row < vWorldMapMatrix.size(); row++) {
        for (int col = 0; col < vWorldMapMatrix[row].size(); col++) {
            vWorldMapMatrix[row][col] = (new WorldBlock<Organism>);
            vWorldMapMatrix[row][col]->occupantPtr = nullptr;
            vWorldMapMatrix[row][col]->pos_x = row;
            vWorldMapMatrix[row][col]->pos_y = col;
        }
    }
    
    // FILL WORLD WITH ANTS
    int antsSpawned = 0;
    while (antsSpawned < QTY_ANTS) {
        int r_x = get_rand(0,WORLD_SIZE_X-1);
        int r_y = get_rand(0,WORLD_SIZE_Y-1);
        if (vWorldMapMatrix[r_x][r_y]->occupantPtr == nullptr) {
            Ant * antPtr;
            string ant_name = "antnon" + to_string(antsSpawned);
            antPtr = new Ant(ant_name, vWorldMapMatrix);
            vWorldMapMatrix[r_x][r_y]->occupantPtr = antPtr;
            vWorldMapMatrix[r_x][r_y]->bOccupied = true;
            vWorldMapMatrix[r_x][r_y]->occupantPtr->setCoords(r_x, r_y);
            antsSpawned++;
            cout << "Populating Ant Number: " << antsSpawned << " ";
            cout << "at location " << r_x << "," << r_y << endl;
        }
    }
    
    // FILL WORLD WITH DOODLEBUGS
    int dbugsSpawned = 0;
    while (dbugsSpawned < QTY_DBUGS) {
        int r_x = get_rand(0,WORLD_SIZE_X-1);
        int r_y = get_rand(0,WORLD_SIZE_Y-1);
        if (vWorldMapMatrix[r_x][r_y]->occupantPtr == nullptr) {
            Doodlebug * dbugPtr;
            string dbug_name = "antnon" + to_string(dbugsSpawned);
            dbugPtr = new Doodlebug(dbug_name, vWorldMapMatrix);
            vWorldMapMatrix[r_x][r_y]->occupantPtr = dbugPtr;
            vWorldMapMatrix[r_x][r_y]->bOccupied = true;
            vWorldMapMatrix[r_x][r_y]->occupantPtr->setCoords(r_x, r_y);
            dbugsSpawned++;
            cout << "Populating Doodlebug Number: " << dbugsSpawned << " ";
            cout << "at location " << r_x << "," << r_y << endl;
        }
    }
    
    // Control loop to simulate time
    bool stepforth = true;
    int it_count = 0;
    do {
        cout << "CONTROL LOOP ITERATION #"  << it_count << endl;
        if (it_count > 0) {
            // move doodlebugs first
            moveBugs(vWorldMapMatrix, 'D');
            // then move ants
            moveBugs(vWorldMapMatrix, 'A');
        }
        countBugs(vWorldMapMatrix);
        printWorldMap(vWorldMapMatrix); // show me the move!
        // user choice
        cout << "OPTIONS: [f]orward or [q]uit" << endl;
        char usr_input = ' ';
        cin >> usr_input;
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

int get_rand(int lb, int ub) {
    return lb + rand() % (ub - lb + 1);
}

void moveBugs(vector<vector<WorldBlock<Organism> *>> vWorldMapMatrix, char bugType) {
    // print the grid with row and column counts
    for (int row = 0; row < vWorldMapMatrix.size(); row++) {
        for (int col = 0; col < vWorldMapMatrix[row].size(); col++) {
            Organism * tmpBugPtr;
            if (vWorldMapMatrix[row][col]->occupantPtr != nullptr) {
                tmpBugPtr = vWorldMapMatrix[row][col]->occupantPtr;
                // if the bug time since moved is more than 0
                if (tmpBugPtr->getSymbol() == bugType && tmpBugPtr->getTimeSinceMoved() > 0) {
                    // move the bug
                    tmpBugPtr->move();
                    // reset time since moved to 0
                    tmpBugPtr->resetTimeSinceMoved();
                } else {
                    tmpBugPtr->incrementTimeSinceMoved();
                }
            }
        }
    }
}

void countBugs(vector<vector<WorldBlock<Organism> *>> vWorldMapMatrix) {
    BugCount current_count;
    for (int row = 0; row < vWorldMapMatrix.size(); row++) {
        for (int col = 0; col < vWorldMapMatrix[row].size(); col++) {
            if (! (vWorldMapMatrix[row][col]->occupantPtr == nullptr) && vWorldMapMatrix[row][col]->bOccupied) {
                char creature_symbol = vWorldMapMatrix[row][col]->occupantPtr->getSymbol();
                if (creature_symbol == 'A') {
                    current_count.num_ants++;
                } else if (creature_symbol == 'D') {
                    current_count.num_dbugs++;
                }
            }
        }
    }
    
    cout << "Ants:" << current_count.num_ants << "\n";
    cout << "Doodlebugs:" << current_count.num_dbugs << "\n";
}

void printWorldMap(vector<vector<WorldBlock<Organism> *>> vWorldMapMatrix) {
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


