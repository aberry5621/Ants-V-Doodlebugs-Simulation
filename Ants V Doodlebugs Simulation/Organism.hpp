//
//  Organism.hpp
//  Ants V Doodlebugs Simulation
//
//  Created by ax on 4/19/17.
//  Copyright © 2017 COMP235. All rights reserved.
//

#ifndef Organism_hpp
#define Organism_hpp

#include "WorldBlockTemplate.hpp"

#include <vector>
#include <string>
using std::vector;
using std::string;

struct Coordinates {
    int x;
    int y;
};

class Organism {
    
public:
    // default constructor
    Organism();
    // primary constructor
    Organism(string p_name, vector<vector<WorldBlock<Organism> *>> p_map);
    
    // getters
    int getBugTypeId();
    string getName();
    char getSymbol();
    Coordinates getCoords();
    int checkMoveCoords();
    
    // setters
    void setName(string p_name);
    // setAge
    void setSymbol(char p_symbol);
    void setMapPointer(vector<vector<WorldBlock<Organism> *>> p_map);
    void setCoords(int p_x_coord, int p_y_coord);
    void setMoveCoords();
    
    void move();
    
    // mutators
    
private:
    int m_bug_type_id = 0;
    string m_name = "Anonymous Bug";
    int m_age = 0;
    char m_symbol = 'O';
    Coordinates m_cur_coords;
    Coordinates m_mov_coords;
    vector<vector<WorldBlock<Organism> *>> m_map;
};

#endif /* Organism_hpp */
