#include "hwlib.hpp"

class cor_lookup{
protected:
    hwlib::xy arr[60] = {};
public:

    constexpr cor_lookup(){
          for(int i = 0; i < 59; i++){
            float hoek_b =  i * 6;
            float hoek_c =  180 - 90 - hoek_b;
            float x_cor = -sin(radians_from_degrees(hoek_b)) * 30;
            float y_cor = sin(radians_from_degrees(hoek_c)) * 30;
            arr[i] = hwlib::xy(x_cor, y_cor);
        }
    }
    constexpr hwlib::xy get(hwlib::xy* a)


}