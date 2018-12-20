#ifndef PLAYERS_H_INCLUDED__ 
#define PLAYERS_H_INCLUDED__
bool use_item(int,int,bool,int);
int eqdtype(int);
void do_menu_ops(int);
void discover_floor(int);
bool check_space(int,int);
bool p_v_npc_combat_check(int,int,int);
void aimer(int);


int base_x;
int base_y;
bool checkempty(int,int);
class player_t{
      public:
      bool aimmode;
      int is_confused;
      int x,y;
      int st,de,in;
      int state;// Loading setting, or whatever. 
      int sel[5];
      int hp;
      int tickets;
      int inv[7];
      int hp_rec_timer;
      int eqd;
      int anticolor;
      int color;
      void init_new();
      void refresh();
      void create_anticolor();
      int max_hp();
      char name[9];//their name!
      int clas; //their class!
      void try_move(int,int,int);
      bool in_menu;
      bool turn_over;
      };player_t pl[4];
      
      void player_t::create_anticolor(){
      anticolor=makecol(255-getr16(color),255-getg16(color),255-getb16(color));
      }
      
    
      
      int player_t::max_hp(){
      return in+(2*de)+(4*st);
      }
          
      void player_t::refresh(){
      int sel[5] = {0,0,0,0,0};
      hp_rec_timer = rand() % 7;
      hp = max_hp();
      in_menu = false;
      turn_over = false;
      }
      
      void player_t::init_new(){
      clas = 0;
      st = 3;
      de = 3;
      in = 3;
      is_confused = 0;
      tickets = 0;
      inv[0] = -1;inv[1] = -1;inv[2] = -1;inv[3] = -1;inv[4] = -1;inv[5] = -1;inv[6] = -1;
      strcpy(name,"         ");
      hp = max_hp();
      }
                 
      
      void player_t::try_move(int id,int deltax, int deltay){
      //first, see if we hit a monster.
       if(eqdtype(id) < 1000){// we are using a weapon.
       if(p_v_npc_combat_check(id,x+deltax,y+deltay)){
       turn_over = true;// attack is good!
       }}
       //we did not attack. can we move?
       if(check_space((x+deltax),(y+deltay)) && !turn_over){
       x = x+deltax;y = y+deltay;discover_floor(id);turn_over = true;
       }
}//endfunc
      
      

     

void accept_commands(int playa){
    if(pl[playa].aimmode){aimer(playa);}else{
    if(!pl[playa].in_menu){
     //See if they wanna move first
     if(playerinput[playa].nu){pl[playa].try_move(playa,0,-1);}else
     if(playerinput[playa].nl){pl[playa].try_move(playa,-1,0);}else
     if(playerinput[playa].nd){pl[playa].try_move(playa,0,1);}else
     if(playerinput[playa].nr){pl[playa].try_move(playa,1,0);}else
     if(playerinput[playa].ntwo){
     if(use_item(playa,pl[playa].eqd,1,playa)){pl[playa].turn_over = true;}
     }else
     if(playerinput[playa].none){pl[playa].in_menu = 1;pl[playa].sel[0] = 0;pl[playa].sel[1] = 0;pl[playa].sel[2] = 0;}
     }else{
     do_menu_ops(playa);
     }
     //In the Menu.
     }//!not aiming
     
}

void do_status_stuff(){
     for(int playa = 0; playa !=4; playa++){
     if(pl[playa].hp > 0){
     //Confusion! screw with all inputs.
if(pl[playa].is_confused){
if(playerinput[playa].none || playerinput[playa].ntwo || playerinput[playa].nu ||playerinput[playa].nl ||playerinput[playa].nr ||playerinput[playa].nd){
     //if they tried to input something.
     //cancel it.
playerinput[playa].none = 0;
playerinput[playa].ntwo = 0;
 playerinput[playa].nu = 0;
 playerinput[playa].nl = 0;
 playerinput[playa].nr = 0;
 playerinput[playa].nd = 0;
 
 //replace it with our own!!! HAHAHAAH
int randbut= rand () % 6;
switch(randbut){
case 0:
 playerinput[playa].none = 1;
 break;
 case 1:
playerinput[playa].ntwo = 1;
 break;
 case 2:
 playerinput[playa].nu = 1;
  break;
 case 3:
 playerinput[playa].nl = 1;
  break;
 case 4:
 playerinput[playa].nr = 1;
  break;
 case 5:
 playerinput[playa].nd = 1;
 break;
 //random inputs done!
}//end of case
}//end of if_input
}//end of confused.
                                       
                 }
                 }
                 }

void do_savingthrow(){
for(int playa = 0; playa !=4; playa++){
if(pl[playa].hp > 0){
if(pl[playa].is_confused){
pl[playa].is_confused = pl[playa].is_confused - pl[playa].in;
if(pl[playa].is_confused < 0 || !(rand() % 20)){
//Player snapped out of confusion
pl[playa].is_confused = 0;
append_msg(17,pl[playa].name,NULL);
}
}// player is indeed confused
}// player's alive.
}//for
}//end_of_func();

                 
#endif
      
      
