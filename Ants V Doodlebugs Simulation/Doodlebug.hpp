/* Ants V Doodlebugs Simulation
 *
 File: Doodlebug.hpp
 Created by Alex on 4/20/17.
 Compiler: Apple LLVM 8.1
 Files: Doodlebug.cpp
 
 Class Declaration: Doodlebug
 
 ACCESSORS
 ---------
 
 MUTATORS
 --------
 
 void tryToEatBug();
 Precondition:
 Postcondition: Resets hunger level to 0, increments ants_eaten counter by 1, calls move to relocate Doodlebug to new map coordinates
 
 void move();
 Precondition:
 Postcondition: Doodlebug is repositioned on world map, assigned new position coordinates, increments hunger and age, call die() if too hungry or old
 
 *
 */

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
    virtual void move();
private:
    int m_bug_type_id;
    int m_ants_eaten;
    int m_hunger = 0;
};

#endif /* Doodlebug_hpp */
