//
//  Doodlebug.cpp
//  Ants V Doodlebugs Simulation
//
//  Created by ax on 4/20/17.
//  Copyright © 2017 COMP235. All rights reserved.
//

#include "Doodlebug.hpp"
#include <iostream>
using std::cout;
using std::endl;

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
        // cout << "Other bug type id is 0: " << bug_type_id << "\n";
    } else if (bug_type_id == 1) {
        // cout << "Other bug type id is 1: " << bug_type_id << "\n";
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
        
        m_hunger = 0;
        m_ants_eaten++;
        
        // move to the newly empty spot
        this->transplantOnMap();
        
    } else {
        // bug type ID error
        cout << "ERR: bug type id errror!\n";
        exit(1);
    }
}

void Doodlebug::move() {
    // cout << "A Doodlebug is moving!\n";
    // set the move to coordingates
    this->setMoveCoords();
    // check the move to coordinates
    int move_status = checkMoveCoords();
    
    switch (move_status) {
        case 1:
            // space is valid and empty, move to it
            // cout << "Space is empty, move to it!\n";
            this->transplantOnMap();
            break;
        case 2:
            // space is valid and occupied, try to eat it
            // cout << "Spot is occupied, try to eat it!\n";
            this->tryToEatBug();
            break;
        case 3:
            // TODO: possibly try to breed with it or something
            break;
        default:
            break;
    }
    
    // hunger increment and check
    m_hunger++;
    cout << "This bug hunger level is: " << m_hunger << endl;
    
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
    
}




