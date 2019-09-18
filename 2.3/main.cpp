#include "hwlib.hpp"
#include "note_player_gpio.hpp"
#include "fur_elise.hpp"
#include "rtttl_player.hpp"
#include "note_player_pc.hpp"

const char sos[]          = "SOS:d=4,o=5,b=60:a,p,a,p,a,p,2a.,p,2a.,p,2a.,p,a,p,a,p,a";
const char let_it_be[]    = "Beatles Let It Be:d=4,o=5,b=100:16e6,8d6,c6,16e6,8g6,8a6,8g.6,16g6,8g6,8e6,16d6,8c6,16a,8g,e.6,p,8e6,16e6,8f.6,8e6,8e6,8d6,16p,16e6,16d6,8d6,2c.6";
const char muppets[]      = "Muppets:d=4,o=5,b=250:c6,c6,a,b,8a,b,g,p,c6,c6,a,8b,8a,8p,g.,p,e,e,g,f,8e,f,8c6,8c,8d,e,8e,8e,8p,8e,g,2p,c6,c6,a,b,8a,b,g,p,c6,c6,a,8b,a,g.,p,e,e,g,f,8e,f,8c6,8c,8d,e,8e,d,8d,c";
const char rickroll[]     = "Never gonna give you up:d=4,o=5,b=120:16c,16d,16f,16d,16a.,16p,32p,8a,16p,g.,16c,16d,16f,16d,16g.,16p,32p,8g,16p,8f.,16e,8d,16c,16d,16f,16d,f,8g,8e.,16d,8c,8c4,8c,8g,8p,2f,16c,16d,16f,16d,16a.,16p,32p,8a,16p,g.,16c,16d,16f,16d,c6,8e,8f.,16e,8d,16c,16d,16f,16d,f,8g,8e.,16d,8c,8c4,8c,8g,8p,2f";
const char one[]          = "NumberOne:d=16,o=5,b=168:4f.,8c6,16b5,16c6,16b5,16c6,8b5,8c6,4g#5,4f.,8f,8g#5,8c6,4c#6,4g#5,4c#6,4d#6,8c6,8c#6,8c6,8c#6,2c6";
const char test[]         = "ZeldaFore:d=4,o=6,b=120:8f5,8a5,b5,8f5,8a5,b5,8f5,8a5,8b5,8e,d,8b5,8c,8b5,8g5,2e5,8p,8d5,8e5,8g5,2e5,8p,8d5,8e5,f5,8g5,8a5,b5,8c,8b5,e5,8p,8d5,8c5,8f5,8e5,8g5,8f5,8a5,8g5,16a_5,16a5,16a5,16g5,2a5";

void PrintNote( const note & n ){
   if( n.frequency == 0 ){
      hwlib::wait_us( n.duration );
      
   } else {
      auto half_period = 1'000'000 / ( 2 * n.frequency );    
      auto end = hwlib::now_us() + n.duration;
      do { 
         hwlib::cout << n.frequency << hwlib::endl;
         hwlib::wait_us( half_period );
         hwlib::wait_us( half_period );
      } while ( end > hwlib::now_us() );
   }     
}

int main( void ){	
   
   namespace target = hwlib::target;   
   auto lsp = target::pin_out( target::pins::d7 );
   auto p = note_player_gpio( lsp );
   auto pc = note_player_pc();
   hwlib::wait_ms( 10 );
   
   HWLIB_TRACE;

   if( 0 ){
      auto fe = fur_elise();
      fe.play( p );
   }      
   
   if( 0 ){ rtttl_play( p,  sos ); }   
   if( 0 ){ rtttl_play( p, let_it_be );  }
   if( 0 ){ rtttl_play( p, muppets );  }
   if( 1 ){ rtttl_play( pc, rickroll );  }
   if( 0 ){ rtttl_play( p, one );  }
   if( 0 ){ rtttl_play(p, test);  }
}
