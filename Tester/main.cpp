#include <iostream>
#include <fstream>

#include "compressor.hpp"
#include "decompressor.hpp"

int main( void ){	
   lz_compressor< 4096 > compressor;
   //lz_decompressor decompress;
   char k = char(34);
   std::ifstream f1;
   f1.open( "wilhelmus.txt" );
   if( ! f1.is_open()){
      std::cerr << "input file not opened";
      return -1;      
   }
   
   std::ofstream f2;
   f2.open( "compressed.asm" );
   f2 << "//code made by Tobias van den Hoogen\n.global compressed\n.text\n\t msg: .asciz" << k;
   if( ! f2.is_open()){
      std::cerr << "output file not opened";
      return -1;      
   }
   
   compressor.compress( 
      [ &f1 ]()-> int { auto c = f1.get(); return f1.eof() ? '\0' : c; },
      [ &f2 ]( char c ){ f2.put( (c == '\n') ? '\b' : c); }
  );
  f2 << k << "\n.end";
  f1.close();
  f2.close();
   
//    f1.open("compressed.txt");
//    if( ! f1.is_open()){
//       std::cerr << "input file not opened";
//       return -1;      
//    }

//    decompress.decompress(
//       [ &f1 ]()-> int { auto c = f1.get(); return f1.eof() ? '\0' : c; },
//       [&f2]( char c ){ std::cout << c; }
//   );
      
   
   
}