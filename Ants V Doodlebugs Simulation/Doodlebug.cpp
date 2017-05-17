/* Ants V Doodlebugs Simulation
 *
 File: Doodlebug.cpp
 Created by Alex on 4/20/17.
 Compiler: Apple LLVM 8.1
 Files: Doodlebug.hpp
 Class Implemented: Doodlebug
 *
 */

#include "Doodlebug.hpp"
#include <iostream>
#include <string>
using namespace std;

Doodlebug::Doodlebug() {/* blank constructor */}

// preload constructor
Doodlebug::Doodlebug(char p_symbol, int p_bug_type_id) {
    setSymbol(p_symbol);
    setBugTypeId(p_bug_type_id);
}
// initializes with preload constructor to set symbol
Doodlebug::Doodlebug(string p_name, vector<vector<WorldBlock<Organism> *>> p_map) : Doodlebug('D',1) {
    this->setName(p_name);
    this->setMapPointer(p_map);
}

Doodlebug::~Doodlebug() {
    cout << "Doodlebug deleted!\n";
}

void Doodlebug::tryToEatBug() {
    // detect bug type in move to spot
    int bug_type_id = getOtherBugTypeId();
    if (bug_type_id == 0) {
        // Other bug type id is 0
    } else if (bug_type_id == 1) {
        // another doodlebug, do nothing or maybe breed
    } else if (bug_type_id == 2) {
        // (del)eat the ant
        Coordinates trgt_coords = getMoveCoords();
        vector<vector<WorldBlock<Organism> *>> tmp_map = getMapRef();
        // Point at victim ant
        Organism * tmpOrgPtr;
        tmpOrgPtr = tmp_map[trgt_coords.x][trgt_coords.y]->occupantPtr;
        // eat it / kill it
        tmpOrgPtr->die();
        tmpOrgPtr = nullptr;
        tmp_map[trgt_coords.x][trgt_coords.y]->occupantPtr = nullptr;
        tmp_map[trgt_coords.x][trgt_coords.y]->bOccupied = false;
        // reset hunger stats
        m_hunger = 0;
        m_ants_eaten++;
        // move to the newly empty spot
        this->transplantOnMap();
        
    } else {
        // bug type ID error TODO: make exception handler
        cout << "ERR: bug type id errror!\n";
        exit(1);
    }
}

void Doodlebug::move() {
    // set the move to coordingates
    this->setMoveCoords();
    // check the move to coordinates
    int move_status = checkMoveCoords();
    switch (move_status) {
        case 1:
            // space is valid and empty, move to it
            this->transplantOnMap();
            break;
        case 2:
            // space is valid and occupied, try to eat it
            this->tryToEatBug();
            break;
        case 3:
            // TODO: possibly try to breed with it or something
            break;
        default:
            break;
    }
    
    // didn't eat, increase hunger
    m_hunger++;
    
    if (m_hunger > 3) {
        // die
        // get this coordinates
        Coordinates this_coords = getCoords();
        vector<vector<WorldBlock<Organism> *>> tmp_map = getMapRef();
        // save this bug in a temp pointer
        // Point at itself so we can clear location
        Organism * tmpOrgPtr;
        tmpOrgPtr = tmp_map[this_coords.x][this_coords.y]->occupantPtr;
        // clear locaiton
        tmp_map[this_coords.x][this_coords.y]->occupantPtr = nullptr;
        tmp_map[this_coords.x][this_coords.y]->bOccupied = false;
        // delete this thing
        tmpOrgPtr->die();
        tmpOrgPtr = nullptr;
        
    }
    this->incrementAge();
    // breed
    int cur_age = this->getAge();
    if (cur_age % 8 == 0) {
        // lived for 8 time cycles, breed
        Coordinates spawnLoc = this->getSpawnCoordinates();
        if (spawnLoc.x == -999) {
            // do not spawn, no space
        } else {
            // yes spawn
            Doodlebug * dbugPtr;
            string dbug_name = "dbugSpawn" + to_string(getIterationCount()) + to_string(spawnLoc.x) + to_string(spawnLoc.y);
            vector<vector<WorldBlock<Organism> *>> map = getMapRef();
            dbugPtr = new Doodlebug(dbug_name, map);
            map[spawnLoc.x][spawnLoc.y]->occupantPtr = dbugPtr;
            map[spawnLoc.x][spawnLoc.y]->bOccupied = true;
            map[spawnLoc.x][spawnLoc.y]->occupantPtr->setCoords(spawnLoc.x, spawnLoc.y);
            // cout << "Spawning Doodlebug at location " << spawnLoc.x << "," << spawnLoc.y << endl;
        }
    }
    
}












