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

void clock::update(){
    int sec = 0;
    int min = 0;
    int hour = 0;
    uint64_t timer = hwlib::now_us() + 1000000;
    while(true){
    
    if (timer <= hwlib::now_us() )
    {
        timer = hwlib::now_us() + 10000;
        sec++;
        
        if(sec == 59 ){
            sec=1;
            min++;
       
            if (min == 59){
                min = 0;
            }

        if(min %5 == 0){
            hour++;
            
            if (hour == 59){
                hour = 0;
            }
        }

        }

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
}