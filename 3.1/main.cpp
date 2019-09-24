#include "hwlib.hpp"
#include "clock.hpp"

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
   
   clock c(oled, hwlib::xy(64, 32));
   c.update();
}