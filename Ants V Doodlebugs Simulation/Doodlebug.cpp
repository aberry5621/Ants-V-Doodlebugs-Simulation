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
Doodlebug::Doodlebug(char p_symbol) { setSymbol(p_symbol);}
// initializes with preload constructor to set symbol
Doodlebug::Doodlebug(string p_name, vector<vector<WorldBlock<Organism> *>> p_map) : Doodlebug('D') {
    this->setName(p_name);
    this->setMapPointer(p_map);
}

void Doodlebug::tryToEatBug() {
    // detect bug type in move to spot
    int bug_type_id = getOtherBugTypeId();
    if (bug_type_id == 1) {
        // another doodlebug, do nothing or maybe breed
    } else if (bug_type_id == 2) {
        // eat the ant
        this->transplantOnMap();
    }
}

void Doodlebug::move() {
    cout << "A Doodlebug is moving!\n";
    // set the move to coordingates
    this->setMoveCoords();
    // check the move to coordinates
    int move_status = checkMoveCoords();
    
    switch (move_status) {
        case 1:
            // space is valid and empty, move to it
            cout << "Space is empty, move to it!\n";
            this->transplantOnMap();
            break;
        case 2:
            // space is valid and occupied, try to eat it
            cout << "Spot is occupied, try to eat it!\n";
            this->tryToEatBug();
            break;
        case 3:
            // TODO: possibly try to breed with it or something
            break;
        default:
            break;
    }
    
}
