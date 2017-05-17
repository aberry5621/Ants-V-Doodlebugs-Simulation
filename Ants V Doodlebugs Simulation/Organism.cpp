/* Ants V Doodlebugs Simulation
 *
 File: Organism.cpp
 Created by Alex on 4/19/17.
 Compiler: Apple LLVM 8.1
 Files: Organism.hpp
 Class Implemented: Organism
 *
 */

#include "Organism.hpp"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

// CONSTRUCTORS
Organism::Organism() {
    // cout << "Constructing an organiszm.\n";
    // start bugs with a count of 1
    this->incrementTimeSinceMoved();
}

Organism::Organism(string p_name, vector<vector<WorldBlock<Organism> *>> p_map) {
    cout << "Constructing an organiszm with params.\n";
    m_name = p_name;
    m_map = p_map;
}

Organism::~Organism() {
        cout << "Organism deleted!\n";
}

// GETTERS
int Organism::getBugTypeId() {
    return m_bug_type_id;
}

string Organism::getName() {
    return m_name;
}

int Organism::getAge() {
    return m_age;
}

char Organism::getSymbol() {
    return this->m_symbol;
}

Coordinates Organism::getCoords() {
    return this->m_cur_coords;
}

Coordinates Organism::getMoveCoords() {
    return this->m_mov_coords;
}

int Organism::checkMoveCoords() {
    // move status code
    int move_status_code = 0;
    // 0: no state recorded
    // 1: empty space,
    // 2: not empty, occupied by something
    // 3: ???
    bool inbounds = false;
    bool occupied = false;
    // check if move to coords are in bounds
    if ((m_mov_coords.x >= 0 && m_mov_coords.x < m_map.size()) && (m_mov_coords.y >= 0 && m_mov_coords.y < m_map[0].size())) {
        inbounds = true;
    }
    // empty or occupied
    if (inbounds) {
        occupied = m_map[m_mov_coords.x][m_mov_coords.y]->bOccupied;
        if (!occupied) {
            move_status_code = 1;
        } else {
            move_status_code = 2;
        }
    }
    return move_status_code;
}

int Organism::checkSpawnCoords(Coordinates p_trgt_coords) {
    // move status code
    int spawn_status_code = 0;
    // 0: no state recorded, block full or off the map
    // 1: empty space, move to-able
    bool inbounds = false;
    bool occupied = false;
    // check if move to coords are in bounds
    if ((p_trgt_coords.x >= 0 && p_trgt_coords.x < m_map.size()) && (p_trgt_coords.y >= 0 && p_trgt_coords.y < m_map[0].size())) {
        inbounds = true;
    }
    // empty or occupied
    if (inbounds) {
        occupied = m_map[p_trgt_coords.x][p_trgt_coords.y]->bOccupied;
        if (!occupied) {
            spawn_status_code = 1;
        }
    }
    return spawn_status_code;
}

Coordinates Organism::getSpawnCoordinates() {
    // FIND EMPTY SPAWN COORDS TO BREED INTO
    // DETECT SURROUNDING EMPTY BLOCKS
    // get current coordinates
    int c_x = m_cur_coords.x; // this bugs x pos
    int c_y = m_cur_coords.y; // this bugs y pos
    // provide storage for target coordinates
    Coordinates tmp_trgt_coords;
    Coordinates tmp_spawn_coords;
    tmp_trgt_coords.x = -999;
    tmp_trgt_coords.y = -999;
    // open blocks array L, U, R, D
    int open_blocks[] = {0, 0, 0, 0};
    for (int i = 0; i < 4; i++) {
        switch (i) {
            case 0:
                // left
                // cout << "Check LEFT! \n";
                tmp_trgt_coords.x = c_x;
                tmp_trgt_coords.y = c_y-1;
                open_blocks[i] = checkSpawnCoords(tmp_trgt_coords);
                break;
            case 1:
                // up
                // cout << "Going UP! \n";
                tmp_trgt_coords.x = c_x-1;
                tmp_trgt_coords.y = c_y;
                open_blocks[i] = checkSpawnCoords(tmp_trgt_coords);
                break;
            case 2:
                // right
                // cout << "Going RIGHT! \n";
                tmp_trgt_coords.x = c_x;
                tmp_trgt_coords.y = c_y+1;
                open_blocks[i] = checkSpawnCoords(tmp_trgt_coords);
                break;
            case 3:
                // down
                // cout << "Going DOWN! \n";
                tmp_trgt_coords.x = c_x+1;
                tmp_trgt_coords.y = c_y;
                open_blocks[i] = checkSpawnCoords(tmp_trgt_coords);
                break;
            default:
                break;
        }
    }
    bool at_least_one_open_spot = false;
    int idx = 0;
    while (idx < 4) {
        //cout << "while loop mon "<< idx <<  " \n";
        if (open_blocks[idx] > 0) {
            at_least_one_open_spot = true;
        }
        idx++;
    }
    // cout << "escaped the while loop \n";
    // try catch to make sure there is an open spot to breed
    try {
        if (at_least_one_open_spot) {
            
            // CHOOSE RANDOM EMPTY NEARBY BLOCK TO SPAWN
            // random selection of open blocks in array
            bool random_spawn_loc_found = false;
            int rand_spawn_loc_idx = NULL;
            while (!random_spawn_loc_found) {
                rand_spawn_loc_idx = 0 + rand() % 4;
                if (open_blocks[rand_spawn_loc_idx] == 1) {
                    random_spawn_loc_found = true;
                }
            }
            // translate open block direction to spawn coords
            // L U R D == 0 1 2 3
            switch (rand_spawn_loc_idx) {
                case 0:
                    // left
                    // cout << "Spawn LEFT! \n";
                    tmp_spawn_coords.x = c_x;
                    tmp_spawn_coords.y = c_y-1;
                    break;
                case 1:
                    // up
                    // cout << "Spawn UP! \n";
                    tmp_spawn_coords.x = c_x-1;
                    tmp_spawn_coords.y = c_y;
                    break;
                case 2:
                    // right
                    // cout << "Spawn RIGHT! \n";
                    tmp_spawn_coords.x = c_x;
                    tmp_spawn_coords.y = c_y+1;
                    break;
                case 3:
                    // down
                    // cout << "Spawn DOWN! \n";
                    tmp_spawn_coords.x = c_x+1;
                    tmp_spawn_coords.y = c_y;
                    break;
                default:
                    break;
            }

        } else {
            throw 0;

        }
    } catch (int e) {
        // cout << e << " - NOT Okay to breed I guess\n";
        // set temp spawn coords to -999 to indicate no
        // spawn locaiton available - this is a weak check.
        tmp_spawn_coords.x = -999;
        tmp_spawn_coords.y = -999;
        return tmp_spawn_coords;

    }
    return tmp_spawn_coords;
}

int Organism::getTimeSinceMoved() {
    return this->m_time_since_moved;
}

int Organism::getIterationCount() {
    return this->m_iteration_count;
}

int Organism::getOtherBugTypeId() {
    return m_map[m_mov_coords.x][m_mov_coords.y]->occupantPtr->getBugTypeId();
}

vector<vector<WorldBlock<Organism> *>> Organism::getMapRef() {
    return m_map;
}

// SETTERS
void Organism::setName(string p_name) {
     m_name = p_name;
}

void Organism::setBugTypeId(int p_bug_type_id) {
    m_bug_type_id = p_bug_type_id;
}

void Organism::setSymbol(char p_symbol) {
    m_symbol = p_symbol;
}

void Organism::setMapPointer(vector<vector<WorldBlock<Organism> *>> p_map) {
    m_map = p_map;
}

void Organism::setCoords(int p_x_coord, int p_y_coord) {
    m_cur_coords.x = p_x_coord;
    m_cur_coords.y = p_y_coord;
}

void Organism::setMoveCoords() {
    // get current position x, y coords on grid
    int c_x = m_cur_coords.x; // this bugs x pos
    int c_y = m_cur_coords.y; // this bugs y pos
    int dir = 1 + rand() % 4;
    switch (dir) {
        case 1:
            // left
            m_mov_coords.x = c_x;
            m_mov_coords.y = --c_y;
            break;
        case 2:
            // up
            m_mov_coords.x = --c_x;
            m_mov_coords.y = c_y;
            break;
        case 3:
            // right
            m_mov_coords.x = c_x;
            m_mov_coords.y = ++c_y;
            break;
        case 4:
            // down
            m_mov_coords.x = ++c_x;
            m_mov_coords.y = c_y;
            break;
        default:
            break;
    }
}

void Organism::transplantOnMap() {
    // this is the bug that wants to move
    Organism * tmpOrgPtr;
    tmpOrgPtr = m_map[m_cur_coords.x][m_cur_coords.y]->occupantPtr;
    
    Coordinates tmp_cur_coords = this->getCoords();
    
    // point move to coords pointer to point at the bug that
    // want to move
    m_map[m_mov_coords.x][m_mov_coords.y]->occupantPtr = tmpOrgPtr;
    m_map[m_mov_coords.x][m_mov_coords.y]->bOccupied = true;
    m_map[m_mov_coords.x][m_mov_coords.y]->occupantPtr->setCoords(m_mov_coords.x, m_mov_coords.y);
    // set old coords to blank
    m_map[tmp_cur_coords.x][tmp_cur_coords.y]->occupantPtr = nullptr;
    m_map[tmp_cur_coords.x][tmp_cur_coords.y]->bOccupied = false;
}

void Organism::move() {
    cout << "A organizm is moving!\n";
    // set the move to coordingates
    this->setMoveCoords();
    // check the move to coordinates
    int move_status = checkMoveCoords();
    
    switch (move_status) {
        case 1:
            // space is valid and empty, move to it
            this->transplantOnMap();
            break;
        case 2:
            // space is valid and occupied, try to eat it
            break;
        case 3:
            // TODO: possibly try to breed with it or something
            break;
        default:
            break;
    }
    // nested increment age after moving / eating happens
    this->incrementAge();
    this-m_iteration_count++;

}

void Organism::incrementTimeSinceMoved() {
    this->m_time_since_moved++;
}

void Organism::resetTimeSinceMoved() {
    this->m_time_since_moved = 0;
}

void Organism::incrementAge() {
    this->m_age++;
}

void Organism::die() {
    // cout << "Organism die called!\n";
}

















