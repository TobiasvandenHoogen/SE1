#include "hwlib.hpp"

class clock{
    protected:
    hwlib::window & w;
    hwlib::xy middle_point;
    hwlib::xy* arr;
    hwlib::xy* mark;
    

    public:
    clock(hwlib::window & w, hwlib::xy middle_point, hwlib::xy* arr, hwlib::xy* mark):
        w ( w ),
        middle_point ( middle_point ),
        arr( arr ),
        mark( mark )
    {

    }

    void draw_middle();
    void draw_boundary();
    void draw_hour_hand(int i);
    void draw_minute_hand(int i);
    void draw_second_hand(int i);
    void update();
};