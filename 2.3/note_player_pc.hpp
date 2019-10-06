//File made by Tobias van den Hoogen 

#ifndef NOTE_PLAYER_PC_HPP
#define NOTE_PLAYER_PC_HPP
#include <iostream>

#include "note_player.hpp"

class note_player_pc{
public:
//play notes on terminal
void play( const char *s ){
      int start = 0;
      for( const char * p = s; start >= 0; p++ ){ //for loop that will go through each character 
            const char c = *p;

            switch(start){

                  case(0):
                        if(c == ':'){ //title has ended 
                              start = 1;
                        }     

                  case(1):
                        if(c == ','){ //next note 
                              std::cout << '\n';
                   
                        }
                        else if(c == '\0'){ //end character array 
                              std::cout << '\n';
                              start = -1; //exit for loop 
                        }
                        else{
                              std::cout << c; //print note 
                  
                        } 
            }   
      
}
}
};

#endif