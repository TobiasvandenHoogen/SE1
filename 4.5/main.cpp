#include "hwlib.hpp"

extern "C" void uart_put_char( char c ){
   hwlib::cout << c;
}

extern "C" void decompressor(char* buffer);

int main( void ){	
   char a[40];
   hwlib::wait_ms(2000);
   decompressor(a);
}