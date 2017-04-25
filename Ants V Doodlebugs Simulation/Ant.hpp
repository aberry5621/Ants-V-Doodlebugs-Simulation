//
//  Ant.hpp
//  Ants V Doodlebugs Simulation
//
//  Created by ax on 4/20/17.
//  Copyright © 2017 COMP235. All rights reserved.
//

#ifndef Ant_hpp
#define Ant_hpp

#include "Organism.hpp"
#include <string>

class Ant : public Organism {
public:
        Ant();
        Ant(char p_symbol, int p_bug_type_id);
        Ant(string p_name, vector<vector<WorldBlock<Organism> *>> p_map);
        ~Ant();
    

    
        // just move
        virtual void move();
    
        // die
        void die();
    
private:
    int m_bug_type_id;
};

#endif /* Ant_hpp */
