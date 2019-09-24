#include "hwlib.hpp"

extern "C" void uart_put_char( char c ){
   hwlib::cout << c;
}

extern "C" void print_asciz( const char * s );

extern "C" void application();

extern "C" char convert_char( char c){ 
   if((c >= 'A' ) && (c < 'Z')){ //if given char is between A and Z
      c = c + 32;                //make it lowercase
   }
   else if((c > 'a') && (c < 'z')){ //if given char is between aand z 
      c = c + 32;                   //make it uppercase
      c = c - 32;                   
   }
   return c;                      
}

int main( void ){	
   
   namespace target = hwlib::target;   
    
      // wait for the PC console to start
   hwlib::wait_ms( 2000 );

   application();
}