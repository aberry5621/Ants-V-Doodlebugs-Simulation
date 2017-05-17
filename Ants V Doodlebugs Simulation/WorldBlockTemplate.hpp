/* Ants V Doodlebugs Simulation
 *
 File: WorldBlockTemplate.hpp
 Created by Alex on 4/23/17.
 Compiler: Apple LLVM 8.1
 Files:
 
 Struct Declaration: WorldBlockTemplate
 
 *
 */

#ifndef WorldBlockTemplate_hpp
#define WorldBlockTemplate_hpp

template <class T>
struct WorldBlock {
    int pos_x = 0;
    int pos_y = 0;
    bool bOccupied = false;
    T * occupantPtr;
};

#endif /* WorldBlockTemplate_hpp */
