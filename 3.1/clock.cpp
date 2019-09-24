#include "clock.hpp"

void clock::draw_middle(){
    constexpr uint_fast16_t rad = 1;
    hwlib::circle mid(middle_point, rad);
    mid.draw( w );
}

void clock::draw_boundary(){
    constexpr uint_fast16_t rad = 30;
    hwlib::circle boun(middle_point, rad);
    boun.draw( w );
}

void clock::draw_minute_hand(){
    
}

void clock::update(){
    w.clear();
    draw_middle();
    draw_boundary();
    w.flush();
}