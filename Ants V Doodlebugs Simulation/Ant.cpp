//
//  Ant.cpp
//  Ants V Doodlebugs Simulation
//
//  Created by ax on 4/20/17.
//  Copyright © 2017 COMP235. All rights reserved.
//

#include "Ant.hpp"
#include <iostream>
using std::cout;
using std::endl;

Ant::Ant()  {/* blank constructor */}

// preload constrcutor
Ant::Ant(char p_symbol, int p_bug_type_id) {
    setSymbol(p_symbol);
    setBugTypeId(p_bug_type_id);
}
// initializes with preload constructor to set symbol
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
    cout << "An Ant is moving!\n";
    // set the move to coordingates
    this->setMoveCoords();
    // check the move to coordinates
    int move_status = checkMoveCoords();
    
    switch (move_status) {
        case 1:
            // space is valid and empty, move to it
            cout << "Space is empty, move to it!\n";
            transplantOnMap();
            break;
        case 2:
            // space is valid and occupied, try to eat it
            cout << "Spot is occupied; ants can't eat other bugs!\n";
            break;
        case 3:
            // TODO: possibly try to breed with it or something
            break;
        default:
            break;
    }
    
}

