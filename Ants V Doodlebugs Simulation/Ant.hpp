/* Ants V Doodlebugs Simulation
 *
 File: Ant.hpp
 Created by Alex on 4/20/17.
 Compiler: Apple LLVM 8.1
 Files: Ant.cpp
 
 Class Declaration: Ant
 
 ACCESSORS
 ---------
 
 MUTATORS
 --------
 void move();
 Precondition:
 Postcondition: Ant is repositioned on world map, assigned new position coordinates, and incremented in age
 
 void die();
 Precondition: 
 Postcondition: Ant object is deleted from memory
 
 *
 */

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
        virtual void move();
        void die();
private:
    int m_bug_type_id;
};

#endif /* Ant_hpp */
