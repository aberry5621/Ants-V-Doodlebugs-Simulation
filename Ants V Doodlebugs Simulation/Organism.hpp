/* Ants V Doodlebugs Simulation
 *
 File: Organism.hpp
 Created by Alex on 4/19/17.
 Compiler: Apple LLVM 8.1
 Files: Organism.cpp
 
 Class Declaration: Organism
 
 ACCESSORS
 ---------
 
 int getBugTypeId();
 Postcondition: retruns this Organism's type ID
 
 string getName();
 Postcondition: retruns this Organism's name
 
 int getAge();
 Postcondition: retruns this Organism's age
 
 char getSymbol();
 Postcondition: retruns this Organism's symbol
 
 Coordinates getCoords();
 Postcondition: retruns this Organism's current map coordinates
 
 Coordinates getMoveCoords();
 Postcondition: retruns this Organism's destination map coordinates
 
 int checkMoveCoords();
 Postcondition: retruns a status code reflecting state of destination coordinates for moving
 
 int checkSpawnCoords(Coordinates p_trgt_coords);
 Postcondition: retruns a status code reflecting state of destination coordinates for spawning
 
 Coordinates getSpawnCoordinates();
 Postcondition: retruns valid destination coordinates for spawning
 
 int getTimeSinceMoved();
 Postcondition: retruns number of clock ticks since moved
 
 int getIterationCount();
 Postcondition: retruns number of clock ticks since simulation began
 
 int getOtherBugTypeId();
 Postcondition: retruns ID of an Organism at given map coordinates
 
 vector<vector<WorldBlock<Organism> *>> getMapRef();
 Postcondition: retruns reference to map object in memory
 
 MUTATORS
 --------
 
 void setName(string p_name);
 Precondition:
 Postcondition: Organism name is stored in member variable
 
 void setBugTypeId(int p_bug_type_id);
 Precondition:
 Postcondition: Organism type ID is stored in member variable
 
 void setSymbol(char p_symbol);
 Precondition:
 Postcondition: Organism symbol is stored in member variable
 
 void setMapPointer(vector<vector<WorldBlock<Organism> *>> p_map);
 Precondition:
 Postcondition: Organism reference to world map is stored in member variable
 
 void setCoords(int p_x_coord, int p_y_coord);
 Precondition:
 Postcondition: Organism current map coordinates stored in member variable
 
 void setMoveCoords();
 Precondition:
 Postcondition: Organism destination map coordinates stored in member variable
 
 void transplantOnMap();
 Precondition:
 Postcondition: Organism current map coordinates swapped for destination map coordinates
 
 virtual void move();
 Precondition: Valid destination coordinates
 Postcondition: Organism age and simulation iteration count incremented
 
 void incrementTimeSinceMoved();
 Precondition:
 Postcondition: Increment time since moved by 1
 
 void resetTimeSinceMoved();
 Precondition:
 Postcondition: Reset time since moved to 0
 
 void incrementAge();
 Precondition:
 Postcondition: Increment age by 1
 
 void die();
 Precondition:
 Postcondition: Object is deleted from memory
 
 *
 */

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
    Organism();
    Organism(string p_name, vector<vector<WorldBlock<Organism> *>> p_map);
    ~Organism();
    // GETTERS
    int getBugTypeId();
    string getName();
    int getAge();
    char getSymbol();
    Coordinates getCoords();
    Coordinates getMoveCoords();
    int checkMoveCoords();
    int checkSpawnCoords(Coordinates p_trgt_coords);
    Coordinates getSpawnCoordinates();
    int getTimeSinceMoved();
    int getIterationCount();
    int getOtherBugTypeId();
    vector<vector<WorldBlock<Organism> *>> getMapRef();
    // SETTERS
    void setName(string p_name);
    void setBugTypeId(int p_bug_type_id);
    void setSymbol(char p_symbol);
    void setMapPointer(vector<vector<WorldBlock<Organism> *>> p_map);
    void setCoords(int p_x_coord, int p_y_coord);
    void setMoveCoords();
    void transplantOnMap();
    virtual void move();
    void incrementTimeSinceMoved();
    void resetTimeSinceMoved();
    void incrementAge();
    void die();
    
private:
    int m_bug_type_id = 0;
    string m_name = "Anonymous Bug";
    int m_age = 0;
    char m_symbol = 'O';
    int m_time_since_moved;
    int m_iteration_count = 1;
    Coordinates m_cur_coords;
    Coordinates m_mov_coords;
    vector<vector<WorldBlock<Organism> *>> m_map;
};

#endif /* Organism_hpp */
