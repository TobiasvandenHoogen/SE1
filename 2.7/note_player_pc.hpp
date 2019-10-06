#ifndef NOTE_PLAYER_PC_HPP
#define NOTE_PLAYER_PC_HPP
#include <iostream>

#include "note_player.hpp"

class note_player_pc{
public:
void play( const char *s ){
      int start = 0;
      for( const char * p = s; start >= 0; p++ ){
            const char c = *p;

            switch(start){

                  case(0):
                        if(c == ':'){
                              start = 1;
                        }     

                  case(1):
                        if(c == ','){
                              std::cout << '\n';
                   
                        }
                        else if(c == '\0'){
                              std::cout << '\n';
                              start = -1;
                        }
                        else{
                              std::cout << c;
                  
                        } 
            }   
      
}
}
};

#endif