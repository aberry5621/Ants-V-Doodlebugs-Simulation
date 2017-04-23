//
//  WorldBlockTemplate.hpp
//  Ants V Doodlebugs Simulation
//
//  Created by ax on 4/23/17.
//  Copyright © 2017 COMP235. All rights reserved.
//

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
