#include "hwlib.hpp"

extern "C" void uart_put_char( char c ){
   hwlib::cout << c;
}

extern "C" void print_asciz( const char * s );

extern "C" void application();

extern "C" char convert_char( char c){
   int val = c;
   if((val > 64) && (val < 91)){
      val = val + 32;
   }
   else if((val > 96) && (val < 123)){
      val = val - 32;
   }
   c = val;
   return c;
}

int main( void ){	
   
   namespace target = hwlib::target;   
    
      // wait for the PC console to start
   hwlib::wait_ms( 2000 );

   application();
}