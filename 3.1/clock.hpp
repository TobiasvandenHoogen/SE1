#include "hwlib.hpp"
#include "calc_angle_sin.hpp"

class clock{
    protected:
    hwlib::window & w;         //to display the clock
    hwlib::xy middle_point;    //where the hands are centralized 
    hwlib::xy arr[60];         //array for clock hands
    hwlib::xy mark[12];        //array for dots that represent hours
    int sec = 0;        
    int min = 0;
    int hour = 0;
    public:
    constexpr clock(hwlib::window & w, hwlib::xy middle_point):
        w ( w ),
        middle_point ( middle_point )
    {
        fill_array();
            

    }

    void draw_middle();
    void draw_boundary();
    void draw_hour_hand(int i);
    void draw_minute_hand(int i);
    void draw_second_hand(int i);
    void digital_time(int hour , int min, int sec);
    void addHour(int n);
    void addMin(int n);
    void addSec(int n);
    
    constexpr void fill_array(){
     for(int i = 0; i < 59; i++){
       float hoek_b =  i * 6;                                   //we want to move the hand on each 6 degrees
       float hoek_c =  180 - 90 - hoek_b;                       
       float x_cor = -sin(radians_from_degrees(hoek_b)) * 30;
       float y_cor = sin(radians_from_degrees(hoek_c)) * 30;
       arr[i] = hwlib::xy(x_cor, y_cor);                  
   }
      for(int i = 0; i < 12; i++){
       float hoek_b =  i * 30;                                 //we want to move the dot on each 30 degrees
       float hoek_c =  180 - 90 - hoek_b;
       float x_cor = -sin(radians_from_degrees(hoek_b)) * 30;
       float y_cor = sin(radians_from_degrees(hoek_c)) * 30;
       if (i == 11) //this is necessary to make the points allign
       {
           x_cor +=5;
       }
       
       mark[i] = hwlib::xy(x_cor, y_cor);
   }
}
    void update();
};