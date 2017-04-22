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
using std::cin;

Organism::Organism() {
    cout << "Constructing an organiszm.\n";
}

Organism::Organism(string p_name) {
    cout << "Constructing an organiszm with params.\n";
    m_name = p_name;
}

string Organism::getName() {
    return m_name;
}

char Organism::getSymbol() {
    return this->m_symbol;
}

Coordinates Organism::getCoords() {
    return this->m_gridloc;
}

void Organism::setName(string p_name) {
     m_name = p_name;
}

void Organism::setSymbol(char p_symbol) {
    m_symbol = p_symbol;
}

void Organism::setCoords(int p_x_coord, int p_y_coord) {
    m_gridloc.x = p_x_coord;
    m_gridloc.y = p_y_coord;
}

int Organism::getMoveDirection() {
    cout << "An Organism is moving!\n";
    // get current position x, y coords on grid
    int c_x = m_gridloc.x; // this bugs x pos
    int c_y = m_gridloc.x; // this bugs y pos
    cout << "Current loc: " << c_x << "," << c_y << "\n";
    
    cout << "Enter move direction [1] LEFT, [2] UP, [3] RIGHT, [4] DOWN: ";
    int dir = 0;
    cin >> dir;
    
    switch (dir) {
        case 1:
            // left
            cout << "Going LEFT! \n";
            dir = 1;
            break;
        case 2:
            // up
            cout << "Going UP! \n";
            dir = 2;
            break;
        case 3:
            // right
            cout << "Going RIGHT! \n";
            dir = 3;
            break;
        case 4:
            // down
            cout << "Going DOWN! \n";
            dir = 4;
            break;
        default:
            break;
    }
    return dir;
}



















