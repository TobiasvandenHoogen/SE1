//File made by Tobias van den Hoogen 

#ifndef NOTE_PLAYER_PC_HPP
#define NOTE_PLAYER_PC_HPP
#include <iostream>

#include "note_player.hpp"

class note_player_pc : public note_player{
public:
//play notes on terminal
void play( const note & n  ){
     std::cout << n.frequency << std::endl;
}
};

#endif