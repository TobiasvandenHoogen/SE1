#include <iostream>
#include <fstream>

#include "../07-library/compressor.hpp"

int main( void ){	
   //declare compressor
   lz_compressor< 4096 > compressor;
   char k = char(34);                              //to create a string
   std::ifstream f1;                               //input file   
   f1.open( "wilhelmus.txt" );                     //open input file    
   if( ! f1.is_open()){                            //if input file not openened
      std::cerr << "input file not opened";       
      return -1;      
   }
   
   std::ofstream f2;
   f2.open( "compressed.asm" );                    //open output file 
   f2 << "//code made by Tobias van den Hoogen\n.global msg\n.text\n\t msg: .asciz " << k; //write start of output file 
   if( ! f2.is_open()){                            //if output file not opened 
      std::cerr << "output file not opened";       
      return -1;      
   }
   
   compressor.compress(                                                             
      [ &f1 ]()-> int { auto c = f1.get(); return f1.eof() ? '\0' : c; },     //get char until end of file 
      [ &f2 ]( char c ){ f2.put( (c == '\n') ? '\b' : c); }                   //check if char is newline 
  );
  f2 << k << "\n.end";                                                        //close string
  f1.close();                                                                 //close file 
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