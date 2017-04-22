//
//  WorldMap.cpp
//  Ants V Doodlebugs Simulation
//
//  Created by ax on 4/20/17.
//  Copyright © 2017 COMP235. All rights reserved.
//

#include "WorldMap.hpp"
#include <vector>
#include <iostream>
using namespace std;

WorldMap::WorldMap() {
    // empty default constructor
}
// construct world map object
WorldMap::WorldMap(int p_size_x, int p_size_y) {
    // store x y WorldMap size in WorldMap size member variables
    m_size_x = p_size_x;
    m_size_y = p_size_y;
    
    vWorldMapMatrix.resize(p_size_x);
    
    for (int i = 0; i < p_size_x; i++) {
        vWorldMapMatrix[i] = vector<WorldBlock *>(p_size_x);
    }
    // fill each row / col with a new world block
    for (int row = 0; row < vWorldMapMatrix.size(); row++) {
        for (int col = 0; col < vWorldMapMatrix[row].size(); col++) {
            vWorldMapMatrix[row][col] = (new WorldBlock);
            vWorldMapMatrix[row][col]->pos_x = row;
            vWorldMapMatrix[row][col]->pos_y = col;
        }
    }
}

bool WorldMap::blockIsOccupied(int p_x, int p_y) {
    bool tBool = false;
    if ((p_x >= 0 && p_x < m_size_x) && (p_y >= 0 && p_y < m_size_y)) {
        tmpWorldBlockPtr = vWorldMapMatrix[p_x][p_y];
        if (tmpWorldBlockPtr->bOccupied) {
            tBool = true;
        }
    } else {
        cout << "ERROR: cellIsOccupied check outside grid bounds! ";
    }
    return tBool;
}

// set cell pointer
void WorldMap::setCellPointer(int p_x, int p_y, Organism * bugPtr, bool p_occupy) {
    vWorldMapMatrix[p_x][p_y]->occupantPtr = bugPtr;
    vWorldMapMatrix[p_x][p_y]->bOccupied = p_occupy;
    bugPtr->setCoords(p_x, p_y);
}

void WorldMap::clearCell(int p_x, int p_y) {
    vWorldMapMatrix[p_x][p_y] = new WorldBlock();
    // point cell x, y to it
    vWorldMapMatrix[p_x][p_y]->pos_x = p_x;
    vWorldMapMatrix[p_x][p_y]->pos_y = p_y;
    
}

void WorldMap::putBugOnMap(Organism * bugPtr) {
    // find an unoccupied random block
    bool blockUnoccupied = false;
    while (!blockUnoccupied) {
        int gen_x = WorldMap::get_rand(0, m_size_x);
        int gen_y = WorldMap::get_rand(0, m_size_y);
        cout << "Checking if " << gen_x << "," << gen_y << " is occupied.\n";
        if (WorldMap::blockIsOccupied(gen_x, gen_y)) {
            cout << "Block is occupied! :(\n";
        } else {
            cout << "Found a free block! :)\n";
            setCellPointer(gen_x, gen_y, bugPtr, true);
            blockUnoccupied = true;
        }
    }
}

void WorldMap::moveBugsOnMap() {
    cout << "World map move bugs called.\n";
    
    for (int row = 0; row < vWorldMapMatrix.size(); row++) {
        for (int col = 0; col < vWorldMapMatrix[row].size(); col++) {
            cout << "matrix loc: " << row << "," << col << " - ";
            if (blockIsOccupied(row, col)) {
                cout << " bug present here" << "\n";
                // call bug's move method
                int move_direction = vWorldMapMatrix[row][col]->occupantPtr->getMoveDirection();
                
            }
            cout << "\n";
        }
    }
}

void WorldMap::printWorldMapSize() {
    cout << "WorldMap X Size: " << vWorldMapMatrix.size() << endl;
    cout << "WorldMap Y Size: " << vWorldMapMatrix[0].size() << endl;
    
}

void WorldMap::printWorldMap() {
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


int WorldMap::get_rand(int lb, int ub) {
    
    return lb + rand() % (ub - lb + 1);
}

