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

struct Coordinates {
    int x;
    int y;
};

class Organism {
    
public:
    // default constructor
    Organism();
    // primary constructor
    Organism(string p_name);
    
    // getters
    string getName();
    char getSymbol();
    Coordinates getCoords();
    Coordinates getMoveCoords();
    void checkMoveDirection();
    
    // setters
    void setName(string p_name);
    void setSymbol(char p_symbol);
    void setCoords(int p_x_coord, int p_y_coord);
    
    // mutators
    

private:
    Coordinates m_gridloc;
    string m_name = "Bob";
    int m_age = 0;
    char m_symbol = 'O';
};

#endif /* Organism_hpp */
