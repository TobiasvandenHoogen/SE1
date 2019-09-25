#include "hwlib.hpp"
#include "clock.hpp"
#include "calc_angle_sin.hpp"

int main(){

    // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   namespace target = hwlib::target;
   
    WDT->WDT_MR = WDT_MR_WDDIS;
   
      // wait for the PC console to start
   hwlib::wait_ms( 500 );   
   
   namespace target = hwlib::target;
   
   auto scl     = target::pin_oc( target::pins::scl );
   auto sda     = target::pin_oc( target::pins::sda );
   auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl, sda );
   auto oled    = hwlib::glcd_oled( i2c_bus, 0x3c ); 

   hwlib::xy cor[60];
   for(int i = 0; i < 59; i++){
       float hoek_b =  i * 6;
       float hoek_c =  180 - 90 - hoek_b;
       float x_cor = -sin(radians_from_degrees(hoek_b)) * 30;
       float y_cor = sin(radians_from_degrees(hoek_c)) * 30;
       cor[i] = hwlib::xy(x_cor, y_cor);
   }
   
   hwlib::xy mark[12];
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
    

   clock c(oled, hwlib::xy(64, 32), cor, mark);
   c.update();

 
}