#ifndef GAME_ENGINE_H_INCLUDED__ 
#define GAME_ENGINE_H_INCLUDED__ 

void see_if_dead(){
     if(pl[0].hp < 1 && pl[1].hp < 1 && pl[2].hp < 1 && pl[3].hp < 1){
pl[0].state = 1;
if(playerinput[0].none){
quittomain = true;
}                  
}
}
void do_hp_rec(){
     
for(int playas = 0; playas != 4; playas++){
if(pl[playas].hp < pl[playas].max_hp()){
pl[playas].hp_rec_timer++;
}
if(pl[playas].hp_rec_timer > 7 && pl[playas].hp < pl[playas].max_hp() && pl[playas].hp > 0){
pl[playas].hp++;
pl[playas].hp_rec_timer = 0;
}
}

}
void do_all_ai(){
     while(npcturnno != 31 && !is_narrator_talk()){
        npcturnno++;
        if(npc[npcturnno].hp > 0){
        do_npc_ai(npcturnno);
                               }
                               }
                               }
void next_floor_check(){
     //see if we can goto next floor
if((pl[0].state == 2 || pl[0].state == 0) && (pl[1].state == 2 || pl[1].state == 0 )&& (pl[2].state == 2 || pl[2].state == 0) && (pl[3].state == 2 || pl[3].state == 0)){
 play_track(1);
do_interflooroperations(map.floor);
}
}

bool everyone_moved(){
     return ((pl[0].turn_over || pl[0].hp < 1)&&(pl[1].turn_over || pl[1].hp < 1)&&(pl[2].turn_over || pl[2].hp < 1)&&(pl[3].turn_over || pl[3].hp < 1)&& !is_narrator_talk());
     }
     
     
//This code takes us into the game.
void run_game(){
    init_ticker(); 
    quittomain = false;
// int npcturnno = -1;
   
	while (!key[KEY_ESC] && !quittomain) { //The exit command.

 sem_wait(&cycler.sem_rest);//wait until a full tick has passed using the semaphore
 while(cycler.ticks > 0)      {cycler.old_ticks = cycler.ticks;

//--------------------------------------------------------------------------------------------  
//This is where all logic goes.
get_all_inputs();
do_status_stuff();
//YOU CAN NOT MOVE THIS PIECE OF CODE! DON'T ASK WHY! I HAVE NO CLUE!!!!!
for(int playas = 0; playas != 4; playas++){
if(!pl[playas].turn_over && pl[playas].hp > 0){
accept_commands(playas);
}
}

//see if we can goto next floor
next_floor_check();

//Reset if all players have moved, or are dead, or do not exist.
if(everyone_moved()){
//Do monsters UNTIL we get a message
if(npcturnno == -1){          
clear_narrator_buf();
do_hp_rec();
do_savingthrow();
do_spec_conditions(map.floor);
}
do_all_ai();

      
if(npcturnno == 31){
pl[0].turn_over = false;pl[1].turn_over = false;pl[2].turn_over = false;pl[3].turn_over = false;
//give ppl turns
//Except if they make it to next floor.
for(int players = 0; players != 4; players++){
if(pl[players].state == 2){
pl[players].turn_over = true;                    
}
}
npcturnno = -1;
//Reset monsters.
clear_narrator_buf();
}// end of AI loop

see_if_dead();
}// end of enemy trn


//If at any time the players all die.


//-------------------------------------------------------------------------------------                                                                                                                 


			                                        cycler.ticks--;cycler.loopctr++;
			                                        if(cycler.old_ticks <= cycler.ticks){
				                                    break; 
                                                    }
		                                      }  
           draw_overworld();
        //This is where we draw it all.                                                                                              
        v_draw_buffer(); 
        
        cycler.ctr++;// A frame was drawn. Add 1 Frame to the counter.                


	                          }// The User wants to quit to the main menu.
}//runs the game!!
#endif
