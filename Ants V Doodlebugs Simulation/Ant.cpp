/* Ants V Doodlebugs Simulation
 *
 File: Ant.cpp
 Created by Alex on 4/20/17.
 Compiler: Apple LLVM 8.1
 Files: Ant.hpp
 Class Implemented: Ant
 *
 */

#include "Ant.hpp"
#include <iostream>
#include <string>
using namespace std;

Ant::Ant()  {/* blank constructor */}

// Preload constrcutor
Ant::Ant(char p_symbol, int p_bug_type_id) {
    setSymbol(p_symbol);
    setBugTypeId(p_bug_type_id);
}
// Initializes with preload constructor to set symbol
Ant::Ant(string p_name, vector<vector<WorldBlock<Organism> *>> p_map) : Ant('A',2) {
    this->setName(p_name);
    this->setMapPointer(p_map);
}

Ant::~Ant() {
    cout << "Ant deleted!\n";
}

void Ant::die() {
    cout << "Ant die called!\n";
    delete this;
}

void Ant::move() {
    this->setMoveCoords();
    int move_status = checkMoveCoords();
    switch (move_status) {
        case 1:
            // space is valid and empty, move to it
            transplantOnMap();
            break;
        case 2:
            // space is valid and occupied, try to eat it
            // cout << "Spot is occupied; ants can't eat other bugs!\n";
            break;
        case 3:
            // TODO: possibly try to breed with it or something
            break;
        default:
            break;
    }
    this->incrementAge();
    // Breeding
    int cur_age = this->getAge();
    if (cur_age % 3 == 0) {
        // lived for 3 time cycles, breed
        Coordinates spawnLoc = this->getSpawnCoordinates();
        if (spawnLoc.x == -999) {
            // do not spawn, no space
        } else {
            Ant * antPtr;
            string ant_name = "antSpawn" + to_string(getIterationCount()) + to_string(spawnLoc.x) + to_string(spawnLoc.y);
            vector<vector<WorldBlock<Organism> *>> map = getMapRef();
            antPtr = new Ant(ant_name, map);
            map[spawnLoc.x][spawnLoc.y]->occupantPtr = antPtr;
            map[spawnLoc.x][spawnLoc.y]->bOccupied = true;
            map[spawnLoc.x][spawnLoc.y]->occupantPtr->setCoords(spawnLoc.x, spawnLoc.y);
        }
    }
    
}










