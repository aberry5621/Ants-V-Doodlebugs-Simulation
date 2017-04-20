//
//  Organism.hpp
//  Ants V Doodlebugs Simulation
//
//  Created by ax on 4/19/17.
//  Copyright © 2017 COMP235. All rights reserved.
//

#ifndef Organism_hpp
#define Organism_hpp

#include <string>
using std::string;

class Organism {
    
public:
    // default constructor
    Organism();
    // primary constructor
    Organism(string p_name);
    
    // getters
    void getName();
    char getSymbol();
    
    // setters
    void setCoords(int p_x_coord, int p_y_coord);
    void setName(string p_name);
    void setSymbol(char p_symbol);
    
    // mutators
    int getMoveDirection();

private:
    int m_x_coord = 0;
    int m_y_coord = 0;
    string m_name = "Bob";
    int m_age = 0;
    char m_symbol = 'O';
};

#endif /* Organism_hpp */
