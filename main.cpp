#include <allegro.h>
#include <winalleg.h>
#include <jgmod.h>
#include <semaphore.h>
#include <fstream>
#include <cmath>
#include <time.h>
using namespace std;
#include "libs/sound.h"
#include "libs/init.h"
#include "libs/input.h"
#include "libs/narrator.h"
#include "libs/names.h"
#include "libs/players.h"
#include "libs/npc.h"
#include "libs/class.h"
#include "libs/world.h"
#include "libs/items.h"
#include "libs/combat.h"
#include "libs/fpsr2.h"
#include "libs/gfx.h"
#include "libs/hud.h"
#include "libs/sidebar_menu.h"
#include "libs/names.h"
#include "libs/mainmenu.h"
#include "libs/game_engine.h"
#include "libs/basement_director.h"
#include "libs/interfloor.h"
#include "libs/options.h"
#include "libs/aimer.h"
#include "libs/winscreen.h"

int main() {
    

    
	init();
	initalize_item_array();
	setup_joysticks();
	bool exit_game = 0;
	while(!exit_game){
                      
                      switch(main_menu()){
                      case 1:map.floor = 0;
                      //do the first floor operations.
                       if(do_interflooroperations(0)){
                      //save.
                      run_game();
                      }
                      break;
                      case 2:
                      stop_mod();
                      //Load the game from its last operation state (nope.exe)
                      //run the game.     
                      run_game();
                      break;
                       play_track(2);
                      case 3:options_menu();
                      break;
                      case 4: exit_game = true;
                      break;
                           }
    }

	deinit();
	return 0;
}
END_OF_MAIN()
