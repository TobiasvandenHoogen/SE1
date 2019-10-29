#ifndef _NOTE_GENERATOR_HPP
#define _NOTE_GENERATOR_HPP

#include "note_player.hpp"
#include <iostream>
#include <fstream>


class note_generator : public note_player{
public:

    void start(){
        std::ofstream melodyfile;
        melodyfile.open("melody.cpp");
        melodyfile << "//file made by Tobias van den Hoogen \n#include \"melody.hpp\" \n \n class melody_song : public melody{ \n public: \n \t virtual void play( note_player & p){\n\t\t";

    }

    virtual void play(const note & n){
        std::ofstream melodyfile;
        melodyfile.open("melody.cpp", std::fstream::app);
        melodyfile << "p.play( note{" << n.frequency  << "," << n.duration << "} );\n\t\t";
        melodyfile.close();

    }

    void end(){
        std::ofstream melodyfile;
        melodyfile.open("melody.cpp", std::fstream::app);
        melodyfile << "} \n };";
        melodyfile.close(); 

    }
};


#endif 