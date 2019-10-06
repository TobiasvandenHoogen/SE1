//file made by Tobias van den Hoogen 
#include "melody.hpp" 
 
 class melody_song : public melody{ 
 public: 
 	 virtual void play( note_player & p){
		p.play( note{698,250000} );
		p.play( note{880,250000} );
		p.play( note{987,500000} );
		p.play( note{698,250000} );
		p.play( note{880,250000} );
		p.play( note{987,500000} );
		p.play( note{698,250000} );
		p.play( note{880,250000} );
		p.play( note{987,250000} );
		p.play( note{1318,250000} );
		p.play( note{1174,500000} );
		p.play( note{987,250000} );
		p.play( note{1046,250000} );
		p.play( note{987,250000} );
		p.play( note{784,250000} );
		p.play( note{659,1000000} );
		p.play( note{0,250000} );
		p.play( note{587,250000} );
		p.play( note{659,250000} );
		p.play( note{784,250000} );
		p.play( note{659,1000000} );
		p.play( note{0,250000} );
		p.play( note{587,250000} );
		p.play( note{659,250000} );
		p.play( note{698,500000} );
		p.play( note{784,250000} );
		p.play( note{880,250000} );
		p.play( note{987,500000} );
		p.play( note{1046,250000} );
		p.play( note{987,250000} );
		p.play( note{659,500000} );
		p.play( note{0,250000} );
		p.play( note{587,250000} );
		p.play( note{523,250000} );
		p.play( note{698,250000} );
		p.play( note{659,250000} );
		p.play( note{784,250000} );
		p.play( note{698,250000} );
		p.play( note{880,250000} );
		p.play( note{784,250000} );
		p.play( note{880,125000} );
		p.play( note{880,125000} );
		p.play( note{880,125000} );
		p.play( note{784,125000} );
		p.play( note{880,1000000} );
		} 
 };