//
//  Doodlebug.cpp
//  Ants V Doodlebugs Simulation
//
//  Created by ax on 4/20/17.
//  Copyright © 2017 COMP235. All rights reserved.
//

#include "Doodlebug.hpp"

Doodlebug::Doodlebug() {/* blank constructor */}

// preload constructor
Doodlebug::Doodlebug(char p_symbol) { setSymbol(p_symbol);}
// initializes with preload constructor to set symbol
Doodlebug::Doodlebug(string p_name, vector<vector<WorldBlock<Organism> *>> p_map) : Doodlebug('D') {
    this->setName(p_name);
    this->setMapPointer(p_map);
}
