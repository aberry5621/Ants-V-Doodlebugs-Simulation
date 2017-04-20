//
//  Ant.cpp
//  Ants V Doodlebugs Simulation
//
//  Created by ax on 4/20/17.
//  Copyright © 2017 COMP235. All rights reserved.
//

#include "Ant.hpp"

Ant::Ant()  {/* blank constructor */}

// preload constrcutor
Ant::Ant(char p_symbol) { setSymbol(p_symbol); }
// initializes with preload constructor to set symbol
Ant::Ant(string p_name) : Ant('A') {
    this->setName(p_name);
}

