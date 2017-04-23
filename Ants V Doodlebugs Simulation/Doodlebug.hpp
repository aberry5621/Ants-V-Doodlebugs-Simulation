//
//  Doodlebug.hpp
//  Ants V Doodlebugs Simulation
//
//  Created by ax on 4/20/17.
//  Copyright © 2017 COMP235. All rights reserved.
//

#ifndef Doodlebug_hpp
#define Doodlebug_hpp

#include "Organism.hpp"
#include <string>

class Doodlebug : public Organism {

public:
    Doodlebug();
    Doodlebug(char p_symbol);
    Doodlebug(string p_name, vector<vector<WorldBlock<Organism> *>> p_map);
    
    void tryToEatBug();
    // move and eat or just move
    virtual void move();
    
private:
    int m_bug_type_id = 1;
    int m_ants_eaten = 0;
};

#endif /* Doodlebug_hpp */
