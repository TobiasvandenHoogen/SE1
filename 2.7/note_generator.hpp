#ifndef _NOTE_GENERATOR_HPP
#define _NOTE_GENERATOR_HPP

#include "note_player.hpp"
#include <iostream>
#include <fstream>


//class that generates notes to cpp file 
class note_generator : public note_player{
public:

    //create file 
    void start(){
        std::ofstream melodyfile;
        melodyfile.open("melody.cpp"); //open file 
        melodyfile << "//file made by Tobias van den Hoogen \n#include \"melody.hpp\" \n \n class melody_song : public melody{ \n public: \n \t virtual void play( note_player & p){\n\t\t";

    }

    virtual void play(const note & n){
        std::ofstream melodyfile;
        melodyfile.open("melody.cpp", std::fstream::app);//edit file 
        melodyfile << "p.play( note{" << n.frequency  << "," << n.duration << "} );\n\t\t"; //place frequencies 
        melodyfile.close(); //close file 

    }

    void end(){
        std::ofstream melodyfile;
        melodyfile.open("melody.cpp", std::fstream::app); //edit file 
        melodyfile << "} \n };";
        melodyfile.close();                               //close file 

    }
};


#endif 