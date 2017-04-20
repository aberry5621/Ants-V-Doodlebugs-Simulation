//
//  Organism.cpp
//  Ants V Doodlebugs Simulation
//
//  Created by ax on 4/19/17.
//  Copyright © 2017 COMP235. All rights reserved.
//

#include "Organism.hpp"
#include <iostream>
using std::cout;
using std::endl;

Organism::Organism() {
    cout << "Constructing an organiszm.\n";
}

Organism::Organism(string p_name) {
    cout << "Constructing an organiszm with params.\n";
    m_name = p_name;
}

void Organism::setCoords(int p_x_coord, int p_y_coord) {
    m_x_coord = p_x_coord;
    m_y_coord = p_y_coord;
}

void Organism::setName(string p_name) {
     m_name = p_name;
}

void Organism::setSymbol(char p_symbol) {
    m_symbol = p_symbol;
}

void Organism::getName() {
    cout << "This bug's name is " << m_name << "\n";
}

char Organism::getSymbol() {
    return this->m_symbol;
}
