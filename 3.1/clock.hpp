#include "hwlib.hpp"

class clock{
    protected:
    hwlib::window & w;
    hwlib::xy middle_point;
    hwlib::xy time;

    public:
    clock(hwlib::window & w, hwlib::xy middle_point, hwlib::xy time):
        w ( w ),
        middle_point ( middle_point ),
        time ( time )
    {}
    void draw_middle();
    void draw_boundary();
    void draw_minute_hand();
    void update();
};