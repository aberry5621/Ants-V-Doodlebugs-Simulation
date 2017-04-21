//
//  WorldMap.hpp
//  Ants V Doodlebugs Simulation
//
//  Created by ax on 4/20/17.
//  Copyright © 2017 COMP235. All rights reserved.
//

#ifndef WorldMap_hpp
#define WorldMap_hpp

#include "Organism.hpp"

#include <vector>
using std::vector;

struct WorldBlock {
    int pos_x = 0;
    int pos_y = 0;
    bool bOccupied = false;
    Organism * occupantPtr;
};

class WorldMap {
public:
    WorldMap();
    // construct world map object
    WorldMap(int p_size_x, int p_size_y);
    
    // check if cell is occupied
    bool blockIsOccupied(int p_x, int p_y);
    
    // check what is in the cell
    char checkCellContents(int p_x, int p_y);
    
    // set cell pointer
    void setCellPointer(int p_x, int p_y, Organism * bugPtr, bool p_occupy);
    
    // clear cell
    void clearCell(int p_x, int p_y);
    
    // try to put a bug on the map
    void putBugOnMap(Organism * bugPtr);
    
    void moveBugsOnMap();
    
    // print out size of WorldMap
    void printWorldMapSize();
    
    // print out contents of the WorldMap
    void printWorldMap();
    
    int get_rand(int lb, int ub);
    
private:
    vector<vector<WorldBlock *>> vWorldMapMatrix;
    WorldBlock * tmpWorldBlockPtr;
    int m_size_x;
    int m_size_y;
};

#endif /* WorldMap_hpp */
