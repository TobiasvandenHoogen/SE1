#include "hwlib.hpp"

extern "C" void uart_put_char( char c ){
   hwlib::cout << c;
}

extern "C" char checkAscii(char c){
   hwlib::cout << "The character before sub is: " << c << " and it's ascii value is: " << int(c) << hwlib::endl;
   hwlib::cout << "The character after sub is: " << char(c - 48) << " and it's ascii value is: " << int(c - 48) << hwlib::endl << hwlib::endl;
   return c;
}

extern "C" char checkingTheChar(char c){
   hwlib::cout << "The character after assembly operation is: " << c << " and it's ascii value is: " << int(c) << hwlib::endl;
   return c;
}

extern "C" void decompressor(char* buffer);

extern "C" char* printBuffer(char* buffer ){
   for(int i = 0; i < 40; i++){
      hwlib::cout << "The value of element: " << i << " is " << buffer[i] << hwlib::endl;
   }
   return buffer;
}

extern "C" int printInt(int i){
   hwlib::cout << "Integer value is: " << i << hwlib::endl;
   return i;
}

int main( void ){	
   char a[40];
   hwlib::wait_ms(2000);
   decompressor(a);
}