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

// CONSTRUCTORS
Organism::Organism() {
    cout << "Constructing an organiszm.\n";
}

Organism::Organism(string p_name, vector<vector<WorldBlock<Organism> *>> p_map) {
    cout << "Constructing an organiszm with params.\n";
    m_name = p_name;
    m_map = p_map;
}

// GETTERS

int Organism::getBugTypeId() {
    return m_bug_type_id;
}

string Organism::getName() {
    return m_name;
}

char Organism::getSymbol() {
    return this->m_symbol;
}

Coordinates Organism::getCoords() {
    return this->m_cur_coords;
}

int Organism::checkMoveCoords() {
    // move status code
    int move_status_code = 0;
    // 0: no state recorded
    // 1: empty space,
    // 2: not empty, occupied by something
    // 3: ???
    bool inbounds = false;
    bool occupied = false;
    // check if move to coords are in bounds
    if ((m_mov_coords.x >= 0 && m_mov_coords.x < m_map.size()) && (m_mov_coords.y >= 0 && m_mov_coords.y < m_map[0].size())) {
        inbounds = true;
    }
    // empty or occupied
    if (inbounds) {
        occupied = m_map[m_mov_coords.x][m_mov_coords.y]->bOccupied;
        if (!occupied) {
            move_status_code = 1;
        } else {
            move_status_code = 2;
        }
    }
    return move_status_code;
}

// SETTERS
void Organism::setName(string p_name) {
     m_name = p_name;
}

void Organism::setSymbol(char p_symbol) {
    m_symbol = p_symbol;
}

void Organism::setMapPointer(vector<vector<WorldBlock<Organism> *>> p_map) {
    m_map = p_map;
}

void Organism::setCoords(int p_x_coord, int p_y_coord) {
    m_cur_coords.x = p_x_coord;
    m_cur_coords.y = p_y_coord;
}

void Organism::setMoveCoords() {
    cout << "Get move coords called!\n";
    // get current position x, y coords on grid
    int c_x = m_cur_coords.x; // this bugs x pos
    int c_y = m_cur_coords.y; // this bugs y pos
    cout << "Current loc: " << c_x << "," << c_y << "\n";
    // instead of random, manual direction entry
    cout << "Manually enter move direction [1] LEFT, [2] UP, [3] RIGHT, [4] DOWN: ";
    int dir = 0;
    cin >> dir;
    switch (dir) {
        case 1:
            // left
            cout << "Going LEFT! \n";
            m_mov_coords.x = c_x;
            m_mov_coords.y = --c_y;
            break;
        case 2:
            // up
            cout << "Going UP! \n";
            m_mov_coords.x = --c_x;
            m_mov_coords.y = c_y;
            break;
        case 3:
            // right
            cout << "Going RIGHT! \n";
            m_mov_coords.x = c_x;
            m_mov_coords.y = ++c_y;
            break;
        case 4:
            // down
            cout << "Going DOWN! \n";
            m_mov_coords.x = ++c_x;
            m_mov_coords.y = c_y;
            break;
        default:
            break;
    }
}

void Organism::move() {
    cout << "An Organism is moving!\n";
    // set the move to coordingates
    this->setMoveCoords();
    // check the move to coordinates
    int move_status = checkMoveCoords();
    Coordinates tmp_coords = this->getCoords();
    switch (move_status) {
        case 1:
            // space is valid and empty, move to it
            cout << "Space is empty, move to it!\n";

            // set move to coords to point at this bug
            m_map[m_mov_coords.x][m_mov_coords.y]->occupantPtr = this;
            m_map[m_mov_coords.x][m_mov_coords.y]->bOccupied = true;
            this->setCoords(m_mov_coords.x, m_mov_coords.y);
            // set old coords to blank
            m_map[tmp_coords.x][tmp_coords.y]->occupantPtr = nullptr;
            m_map[tmp_coords.x][tmp_coords.y]->bOccupied = false;
            
            break;
        case 2:
            // space is valid and occupied, try to eat it
            cout << "Spot is occupied, try to eat it!\n";
            break;
        case 3:
            // TODO: possibly try to breed with it or something
            break;
        default:
            break;
    }
    
}


















