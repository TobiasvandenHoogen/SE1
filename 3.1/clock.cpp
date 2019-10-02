#include "clock.hpp"

void clock::draw_middle(){
    constexpr uint_fast16_t rad = 1;
    hwlib::circle mid(middle_point, rad);
    mid.draw( w );
    for(int i = 0; i < 12; i++){
        hwlib::circle point(middle_point + mark[i],rad);
        point.draw( w );
    }
}

void clock::draw_boundary(){
    constexpr uint_fast16_t rad = 30;
    hwlib::circle boun(middle_point, rad);
    boun.draw( w );
}

void clock::draw_hour_hand(int i){
    hwlib::xy endpoint(middle_point - (arr[i] / 2));
    hwlib::line l(middle_point, endpoint);
    l.draw( w );
}

void clock::draw_minute_hand(int i){
    hwlib::xy endpoint(middle_point - arr[i] );
    hwlib::line l(middle_point, endpoint);
    l.draw( w );
}

void clock::draw_second_hand(int i){
    hwlib::xy endpoint(middle_point - arr[i] ); 
    hwlib::line l(middle_point, endpoint);
    l.draw( w );
}

void clock::digital_time(int hour, int min, int sec){
    int whole_hour = hour / 5;
    auto font = hwlib::font_default_8x8();
    auto display = hwlib::terminal_from( w, font);
    display << "\t1207" << whole_hour << ":" << min << hwlib::flush;

}

void clock::addHour(int n){
    hour += n;
}

void clock::addMin(int n){
    min += n;
}
void clock::addSec(int n){
    sec += n;
}
    

void clock::update(){


        if(sec >= 59 ){
            sec=0;
            min++;
        }
        if (min >= 59){
            min = 0;
            hour +=5;
        }

        if (hour >= 59){
            hour = 0;
        }
            

        

    

    

    
    
    
    w.clear();
    draw_middle();
    draw_boundary();
    draw_hour_hand(hour);
    draw_minute_hand(min);
    draw_second_hand(sec);
    digital_time(hour, min, sec);
    w.flush();
}