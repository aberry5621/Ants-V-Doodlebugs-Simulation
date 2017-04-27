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
    Doodlebug(char p_symbol, int p_bug_type_id);
    Doodlebug(string p_name, vector<vector<WorldBlock<Organism> *>> p_map);
    ~Doodlebug();
    
    void tryToEatBug();
    // move and eat or just move
    virtual void move();
    
private:
    int m_bug_type_id;
    int m_ants_eaten;
    int m_hunger = 0;
};

#endif /* Doodlebug_hpp */
