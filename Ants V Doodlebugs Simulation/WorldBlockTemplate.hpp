//
//  WorldBlockTemplate.hpp
//  Ants V Doodlebugs Simulation
//
//  Created by ax on 4/23/17.
//  Copyright © 2017 COMP235. All rights reserved.
//
//File: fuelAndMileage.h
//Names: Mia Chia
//Compiler: MS Visual C++ 2015
//Files: fuelAndMileage.cpp
//Date: 1/26/2017
//Class Declaration: Odometer
//
//ACCESSOR
//getGallonsUsed();
//Postcondition: returns gallons consumed in a single trip
//
//MUTATORS
//void reset();
//postcondition: Odometer meter reading (miles driven) is set to 0
//void setMPG(double p_MPG);
//precondition: p_MPG > 0
//postcondition: the fuel efficiency is set using p_MPG
//void setMilesDriven(double p_miles);
//Precondition: p_miles >= 0
//Postcondition: p_miles is assigned to total miles travelled

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
