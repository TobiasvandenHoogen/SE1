#include "hwlib.hpp"
#include "calc_angle_sin.hpp"

class clock{
    protected:
    hwlib::window & w;
    hwlib::xy middle_point;
    hwlib::xy arr[60];
    hwlib::xy mark[12];

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
    constexpr void fill_array(){
     for(int i = 0; i < 59; i++){
       float hoek_b =  i * 6;
       float hoek_c =  180 - 90 - hoek_b;
       float x_cor = -sin(radians_from_degrees(hoek_b)) * 30;
       float y_cor = sin(radians_from_degrees(hoek_c)) * 30;
       arr[i] = hwlib::xy(x_cor, y_cor);
   }
      for(int i = 0; i < 12; i++){
       float hoek_b =  i * 30;
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