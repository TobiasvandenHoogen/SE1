#include <iostream>
#include <fstream>

#include "compressor.hpp"
#include "decompressor.hpp"

int main( void ){	
   lz_compressor< 4096 > compressor;
   lz_decompressor decompress;
 
   std::ifstream f1;
   f1.open( "wilhelmus.txt" );
   if( ! f1.is_open()){
      std::cerr << "input file not opened";
      return -1;      
   }
   
   std::ofstream f2;
   f2.open( "compressed.txt" );
   if( ! f2.is_open()){
      std::cerr << "output file not opened";
      return -1;      
   }
   
  compressor.compress( 
      [ &f1 ]()-> int { auto c = f1.get(); return f1.eof() ? '\0' : c; },
      [ &f2 ]( char c ){ if(c == '\n') {f2<< "\\n";}else{ f2 << c;}; }
  );

  f1.close();
  f2.close();
   
   f1.open("compressed.txt");
   if( ! f1.is_open()){
      std::cerr << "input file not opened";
      return -1;      
   }

   decompress.decompress(
      [ &f1 ]()-> int { auto c = f1.get(); return f1.eof() ? '\0' : c; },
      [&f2]( char c ){ std::cout << c; }
  );
      
   
   
}