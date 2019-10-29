//this file is based on rtttl_player.cpp but is adapted by Tobias van den Hoogen so that it will create a cpp file with the right note calls 
#ifndef _MELODY_HPP
#define _MELODY_HPP
#include "note_player.hpp"
// an abstract melody
class melody : public note_player{
public:
   virtual void play( note_player & p );
};

#endif