#ifndef NOTE_PLAYER_PC_HPP
#define NOTE_PLAYER_PC_HPP

#include "note_player.hpp"

class note_player_pc : public note_player{
public:
void play( const note & n ) override{
   if( n.frequency == 0 ){
      hwlib::wait_us( n.duration );
      
   } else {
      auto half_period = 1'000'000 / ( 2 * n.frequency );    
      auto end = hwlib::now_us() + n.duration;
      do { 
         hwlib::cout << n.frequency << hwlib::endl;
         hwlib::wait_us( half_period );
         hwlib::wait_us( half_period );
      } while ( end > hwlib::now_us() );
   }     
}
};

#endif