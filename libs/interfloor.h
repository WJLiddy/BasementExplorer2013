#ifndef INTERFLOOR_H_INCLUDED__ 
#define INTERFLOOR_H_INCLUDED__
//new characters share the same pool:
char name_list[12][9];
int color_list[12];//list of colors to choose.


void gen_name_list(){// Now without repeats!
for(int ctr = 0; ctr != 12; ctr++){//For each slot.
give_name(&name_list[ctr][0]);// create a new name.
// for each new name...
//compare to each previous name.
for(int ctr2 = 0; ctr2 != ctr;ctr2++){
if(*name_list[ctr] == *name_list[ctr2]){
//We found a cloned name!
give_name(&name_list[ctr][0]);
ctr2 = -1;// Make sure our new name does not conflict.

}//cloned name reset
}//each name comparison.
}//each name.
}//func

void gen_color_list(){
//alw colors: WRGB
color_list[0] = RED;
color_list[1] = GREEN;
color_list[2] = BLUE;

color_list[3] = makecol(255,0,125);
color_list[4] = makecol(125,255,0);
color_list[5] = makecol(0,125,255);

color_list[6] = makecol(255,0,255);
color_list[7] = makecol(0,255,255);
color_list[8] = makecol(255,255,0);

color_list[9] = makecol(255,125,0);
color_list[10] =makecol(0,255,125);
color_list[11] =makecol(125,0,255);


}



void do_char_create_screen(int playerscreen){
 // Player is creating a Char.
              draw_text(base_x, base_y,"Name",RED);
              draw_text(base_x+75, base_y+140,"Done",WHITE);
              draw_text(base_x+75, base_y,"Class",GREEN);
              draw_text(base_x+150, base_y,"Colour",BLUE);
              
              //Give [possible names]
              for(int nameops = 0; nameops != 12; nameops++){
              draw_text(base_x+10, base_y+10+(10*nameops),name_list[nameops],RED);
              }
              draw_text(base_x+85, base_y+10,"n00b",GREEN);
              
              //Give possible colors
              for(int nameops = 0; nameops != 12; nameops++){
              draw_text(base_x+160, base_y+10+(10*nameops),"@",color_list[nameops]);
              }
              
            //Name 0
            //Class 1
            //Colour 2
            //Cursor X. 3
            //Cursor Y. 4
            if(playerinput[playerscreen].nd && pl[playerscreen].sel[4] < 12){pl[playerscreen].sel[4]++;};
            if(playerinput[playerscreen].nu && pl[playerscreen].sel[4] > 0){pl[playerscreen].sel[4]--;};
            if(playerinput[playerscreen].nl && pl[playerscreen].sel[3] > 0){pl[playerscreen].sel[3]--;};
            if(playerinput[playerscreen].nr && pl[playerscreen].sel[3] < 2){pl[playerscreen].sel[3]++;};
             
              //THESE ARE THE SELECTOR BUTTONS.
               draw_text(base_x,10+ base_y+(pl[playerscreen].sel[0]*10),">",makecol(128,0,0));
               draw_text(base_x+75,10+ base_y+(pl[playerscreen].sel[1]*10),">",makecol(0,128,0));
               draw_text(base_x+150,10+ base_y+(pl[playerscreen].sel[2]*10),">",makecol(0,0,128));
            
            
              if(*name_list[pl[playerscreen].sel[0]] == *pl[0].name || *name_list[pl[playerscreen].sel[0]] == *pl[1].name  || *name_list[pl[playerscreen].sel[0]] == *pl[2].name || *name_list[pl[playerscreen].sel[0]] == *pl[3].name){
              draw_text(base_x+1,140+base_y,"NAME USED",WHITE);//cursor is done, else...
               }
               
              if(pl[0].color == color_list[pl[playerscreen].sel[2]] || pl[1].color == color_list[pl[playerscreen].sel[2]] || pl[2].color == color_list[pl[playerscreen].sel[2]] || pl[3].color == color_list[pl[playerscreen].sel[2]]){
               draw_text(base_x+110,140+base_y,"COLOUR USED",WHITE);//cursor is done, else...               
                             }  
    
              
              //THIS IS OUR CURSOR.
              if(pl[playerscreen].sel[4] == 12){
              draw_text(base_x+67,140+base_y,">Done",GREEN);//cursor is done, else...
              
                 if(playerinput[playerscreen].none&&!(*name_list[pl[playerscreen].sel[0]] == *pl[0].name || *name_list[pl[playerscreen].sel[0]] == *pl[1].name  || *name_list[pl[playerscreen].sel[0]] == *pl[2].name || *name_list[pl[playerscreen].sel[0]] == *pl[3].name)&&!(pl[0].color == color_list[pl[playerscreen].sel[2]] || pl[1].color == color_list[pl[playerscreen].sel[2]] || pl[2].color == color_list[pl[playerscreen].sel[2]] || pl[3].color == color_list[pl[playerscreen].sel[2]])){
                 pl[playerscreen].init_new();
                 pl[playerscreen].clas = 1;
                 //^ THIS NEEDS CHANGED.... LATER. More than one class
                 int namebufid = pl[playerscreen].sel[0];
                 strcpy(pl[playerscreen].name,name_list[namebufid]);
                 
                 
                 pl[playerscreen].color = color_list[pl[playerscreen].sel[2]];
                 pl[playerscreen].create_anticolor();
                 pl[playerscreen].state++;  
                 pl[playerscreen].sel[0]=0;      
                 pl[playerscreen].sel[1]=0; 
                 pl[playerscreen].sel[2]=0; 
                 pl[playerscreen].sel[3]=0; 
                 pl[playerscreen].sel[4]=0; 
                 }                            
              }else{
                                        
              
              //draw a normal cursoer.
              if(pl[playerscreen].sel[3] == 0){
              draw_text(base_x,10+base_y+(pl[playerscreen].sel[4]*10),">",WHITE);
              
              if(playerinput[playerscreen].none){
              pl[playerscreen].sel[0] = pl[playerscreen].sel[4];
              }
              }
      
 
              if(pl[playerscreen].sel[3] == 1){
              //draw_text(base_x+75,10+base_y+(pl[playerscreen].sel[4]*10),">",WHITE);
              draw_text(base_x+75,10+base_y,">",WHITE);
              pl[playerscreen].sel[1] = 0;
              
              }
              
              if(pl[playerscreen].sel[3] == 2){
              draw_text(base_x+150,10+base_y+(pl[playerscreen].sel[4]*10),">",WHITE);
              if(playerinput[playerscreen].none){
              pl[playerscreen].sel[2] = pl[playerscreen].sel[4];
              
              }
              }
              
              }             
     
     }
     
void do_char_prepare_screen(int playerscreen){
rectfill(buffer,base_x,base_y,base_x+199,base_y+149,pl[playerscreen].color);
if(!pl[playerscreen].sel[1]){
draw_text(base_x,base_y,pl[playerscreen].name,pl[playerscreen].anticolor);
draw_text(base_x+150,base_y+20,"STR:",pl[playerscreen].anticolor);
draw_text(base_x+150,base_y+30,"DEX:",pl[playerscreen].anticolor);
draw_text(base_x+150,base_y+40,"INT:",pl[playerscreen].anticolor);
draw_text(base_x+150,base_y+50,"T:",pl[playerscreen].anticolor);
draw_text(base_x+149,base_y+50,"=",pl[playerscreen].anticolor);

draw_text(base_x+20,base_y+10,"Manage Items",makecol(128,128,128));
draw_text(base_x+20,base_y+20,"Spend Tickets",pl[playerscreen].anticolor);
draw_text(base_x+20,base_y+30,"All Ready!",pl[playerscreen].anticolor);

draw_text(base_x+180,base_y+20,pl[playerscreen].st,pl[playerscreen].anticolor);
draw_text(base_x+180,base_y+30,pl[playerscreen].de,pl[playerscreen].anticolor);
draw_text(base_x+180,base_y+40,pl[playerscreen].in,pl[playerscreen].anticolor);
draw_text(base_x+170,base_y+50,pl[playerscreen].tickets,pl[playerscreen].anticolor);
//Adjust moving of cursor
if(playerinput[playerscreen].nd && pl[playerscreen].sel[0] < 2){pl[playerscreen].sel[0]++;};
if(playerinput[playerscreen].nu && pl[playerscreen].sel[0] > 0){pl[playerscreen].sel[0]--;};
draw_text(base_x+10,base_y+10+(10*pl[playerscreen].sel[0]),">",pl[playerscreen].anticolor);        

if(pl[playerscreen].sel[0] == 1 && playerinput[playerscreen].none){
pl[playerscreen].sel[1] = 2;
//absorb the input
playerinput[playerscreen].none = false;
}

if(pl[playerscreen].sel[0] == 2 && playerinput[playerscreen].none){
pl[playerscreen].refresh();
pl[playerscreen].state++;
}
}// If no submenu.


if(pl[playerscreen].sel[1] == 2){
draw_text(base_x+150,base_y+20,"STR:",pl[playerscreen].anticolor);
draw_text(base_x+150,base_y+30,"DEX:",pl[playerscreen].anticolor);
draw_text(base_x+150,base_y+40,"INT:",pl[playerscreen].anticolor);
draw_text(base_x+150,base_y+50,"T:",pl[playerscreen].anticolor);
draw_text(base_x+149,base_y+50,"=",pl[playerscreen].anticolor);
draw_text(base_x+180,base_y+20,pl[playerscreen].st,pl[playerscreen].anticolor);
draw_text(base_x+180,base_y+30,pl[playerscreen].de,pl[playerscreen].anticolor);
draw_text(base_x+180,base_y+40,pl[playerscreen].in,pl[playerscreen].anticolor);
draw_text(base_x+170,base_y+50,pl[playerscreen].tickets,pl[playerscreen].anticolor);

draw_text(base_x+10,base_y+1,"BUY SOMETHIN' WILL YA?",pl[playerscreen].anticolor);
draw_text(base_x+20,base_y+20,"Buy STR:",makecol(128,128,128));
draw_text(base_x+20,base_y+30,"Buy DEX:",makecol(128,128,128));
draw_text(base_x+20,base_y+40,"Buy INT:",makecol(128,128,128));
draw_text(base_x+90,base_y+20,((pl[playerscreen].st)*(pl[playerscreen].st)),makecol(128,128,128));
draw_text(base_x+90,base_y+30,((pl[playerscreen].de)*(pl[playerscreen].de)),makecol(128,128,128));
draw_text(base_x+90,base_y+40,((pl[playerscreen].in)*(pl[playerscreen].in)),makecol(128,128,128));             


if(((pl[playerscreen].st)*(pl[playerscreen].st)) <= pl[playerscreen].tickets){
draw_text(base_x+20,base_y+20,"Buy STR:",pl[playerscreen].anticolor);
draw_text(base_x+90,base_y+20,((pl[playerscreen].st)*(pl[playerscreen].st)),pl[playerscreen].anticolor);
}
if(((pl[playerscreen].de)*(pl[playerscreen].de)) <= pl[playerscreen].tickets){
draw_text(base_x+20,base_y+30,"Buy DEX:",pl[playerscreen].anticolor);
draw_text(base_x+90,base_y+30,((pl[playerscreen].de)*(pl[playerscreen].de)),pl[playerscreen].anticolor);
}
if(((pl[playerscreen].in)*(pl[playerscreen].in)) <= pl[playerscreen].tickets){
draw_text(base_x+20,base_y+40,"Buy INT:",pl[playerscreen].anticolor);
draw_text(base_x+90,base_y+40,((pl[playerscreen].in)*(pl[playerscreen].in)),pl[playerscreen].anticolor);
}
draw_text(base_x+20,base_y+50,"Exit",pl[playerscreen].anticolor);

 //Adjust moving of cursor
if(playerinput[playerscreen].nd && pl[playerscreen].sel[2] < 3){pl[playerscreen].sel[2]++;};
if(playerinput[playerscreen].nu && pl[playerscreen].sel[2] > 0){pl[playerscreen].sel[2]--;};

draw_text(base_x+10,base_y+20+(10*pl[playerscreen].sel[2]),">",pl[playerscreen].anticolor);        

if(playerinput[playerscreen].none && pl[playerscreen].sel[2] == 0 && (((pl[playerscreen].st)*(pl[playerscreen].st)) <= pl[playerscreen].tickets)){
// we bought a STR!
pl[playerscreen].tickets = pl[playerscreen].tickets - ((pl[playerscreen].st)*(pl[playerscreen].st));
pl[playerscreen].st++;
}

if(playerinput[playerscreen].none && pl[playerscreen].sel[2] == 1 && (((pl[playerscreen].de)*(pl[playerscreen].de)) <= pl[playerscreen].tickets)){
// we bought a DEX!
pl[playerscreen].tickets = pl[playerscreen].tickets -((pl[playerscreen].de)*(pl[playerscreen].de));

pl[playerscreen].de++;
}
     
if(playerinput[playerscreen].none && pl[playerscreen].sel[2] == 2 && (((pl[playerscreen].in)*(pl[playerscreen].in)) <= pl[playerscreen].tickets)){
// we bought a INT!
pl[playerscreen].tickets= pl[playerscreen].tickets - ((pl[playerscreen].in)*(pl[playerscreen].in));
pl[playerscreen].in++;
}
         
if(playerinput[playerscreen].none && pl[playerscreen].sel[2] == 3){
pl[playerscreen].sel[1] = 0;      
pl[playerscreen].sel[2] = 0;                             
                                   }
                           }
                           
                           

     }



void do_player_screens(){
for(int playerscreen = 0; playerscreen != 4; playerscreen++){
if(playerscreen == 0){base_x = 0; base_y = 0;}
if(playerscreen == 1){base_x = 200; base_y = 0;}
if(playerscreen == 2){base_x = 0; base_y = 150;}
if(playerscreen == 3){ base_x = 200; base_y = 150;}

// individual player decisions.
switch (pl[playerscreen].state){
       case 0:// No player...
            draw_text(base_x, base_y,"Press Attack to Join!",WHITE);
       if(playerinput[playerscreen].none){pl[playerscreen].state++;}
            break;
            
       case 1:do_char_create_screen(playerscreen);
       break;     
       case 2:do_char_prepare_screen(playerscreen);
             break;
       case 3:draw_text(base_x+68, base_y+71,"Ready!!!",pl[playerscreen].color);
            break;
            
}//end of screen 
}//end of "for"
}//end of funct.





bool do_interflooroperations(int level){
gen_name_list();
gen_color_list();

int state[4]; // 0 not playing. 1 creating char. 2 preparing.... 3 ready!
if (!level){
pl[0].state = 1;
pl[1].state = 0;
pl[2].state = 0;
pl[3].state = 0;
}

while(1){
if(key[KEY_ESC]){return 0;}
// break if we can go.
if((pl[0].state == 0 || pl[0].state == 3) &&(pl[1].state == 0 || pl[1].state == 3) &&(pl[2].state == 0 || pl[2].state == 3) &&(pl[3].state == 0 || pl[3].state == 3)){
break;
}
clear(buffer);
get_all_inputs();
do_player_screens();
//group draws.
line(buffer,199,0,199,300,makecol(127,127,127));
line(buffer,0,149,400,149,makecol(127,127,127));
v_draw_buffer();
}//While.

map.floor++;
if(map.floor == 10){
map.gen_10();

spawn_10();
hide_10();
play_track(3);
init_ticker();
append_msg(1,NULL,NULL);
append_msg(2,NULL,NULL);

return 1;
}      

map.gen();
create_manhole();
hide_all_floor();
find_starting_pos();
spawn_items();
spawn_enemies();
play_track(2);
init_ticker();
return 1;


}
#endif
     
