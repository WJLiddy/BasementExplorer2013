#ifndef SIDEBAR_MENU_H_INCLUDED__ 
#define SIDEBAR_MENU_H_INCLUDED__
bool do_interflooroperations(int);
void do_menu_ops(int playa){
     
       if(!pl[playa].sel[1]){
       //normal menu
       if(playerinput[playa].nd && pl[playa].sel[0] < 3){pl[playa].sel[0]++;}
       if(playerinput[playa].nu && pl[playa].sel[0] > 0){pl[playa].sel[0]--;}
       }else{
       //inv menu
       if(playerinput[playa].nd && pl[playa].sel[1] < 7){pl[playa].sel[1]++;}
       if(playerinput[playa].nu && pl[playa].sel[1] > 1){pl[playa].sel[1]--;}
       }
       
      //the FIRST THING TO DO is see if they wanna go
      if(playerinput[playa].none && pl[playa].x == map.hole_x && pl[playa].y == map.hole_y && pl[playa].sel[0] == 2 ){ 
      pl[playa].state = 2;
      pl[playa].x = -1;
      pl[playa].turn_over = true;
      pl[playa].in_menu = false;
      //Kill every input!
      playerinput[playa].none = false;
      playerinput[playa].ntwo = false;
      pl[playa].sel[0] = 0;
      pl[playa].sel[1] = 0;
      }
 
        
       //option zero= equip item.
       if(pl[playa].sel[0] == 0 && pl[playa].sel[1] > 0  &&playerinput[playa].none){
      pl[playa].eqd = pl[playa].sel[1]-1;
       pl[playa].sel[1] = 0;
       //also end the turn.
       pl[playa].turn_over = true;
       pl[playa].in_menu = false;     
                       
       }
          
          
          
       //option zero= drop item.
       if(pl[playa].sel[0] == 2 && pl[playa].sel[1] > 0 &&playerinput[playa].none){
       //
    int droppeditem = pl[playa].inv[pl[playa].sel[1]-1];
    pl[playa].inv[pl[playa].sel[1]-1] = -1;
    item[droppeditem].x = pl[playa].x;
    item[droppeditem].y = pl[playa].y;
    item[droppeditem].floor = true;
       //also end the turn.
       pl[playa].sel[1] = 0;
       pl[playa].turn_over = true;
       pl[playa].in_menu = false;     
       
       }
        
       if(playerinput[playa].none && ( pl[playa].sel[0] == 0 || pl[playa].sel[0] == 2 ) && !pl[playa].sel[1]){
       //enter inv menu. (only available when nont already open)
       pl[playa].sel[1] = 1;     //"eat" input                  
       }
       
        //option: cancel equip menu.
       if(pl[playa].sel[1] > 0 && playerinput[playa].ntwo){                  
       pl[playa].sel[1] = 0;
       playerinput[playa].ntwo = false;
       //eat input.
       }
    
      
       
       // option one: pick up an item.
       if(playerinput[playa].none && pl[playa].sel[0] == 1){
       //Make sure we can hold the item.
       int slot = -1;
       
       for(int slot_f = 0;slot_f != 7; slot_f++){
       if(pl[playa].inv[slot_f] == -1){
       slot = slot_f;
       break;
       }
       }
       
       //find the item, if we have a slot.
       if(slot != -1){
       for(int itemo = 0;itemo !=256;itemo++){
       if(item[itemo].floor && item[itemo].x == pl[playa].x && item[itemo].y == pl[playa].y){
       //WE found an item! look for an open inv spot.
       item[itemo].floor = 0;
       pl[playa].inv[slot] = itemo;
       play_fx(2);
       append_msg(5,pl[playa].name,item[itemo].name);
       //also end the turn.
       pl[playa].turn_over = true;
       pl[playa].in_menu = false;
       break; 
       }// Item get!
       }//all items searched.
       }// we had a slot.
       }//input condition
      
      /*
      //DROP OPTION
    if(pl[playa].sel[1] > 0 && pl[playa].sel[1] != 8 && playerinput[playa].ntwo){
 
    }
     
      */
      
      
      
      
      
      
       if(playerinput[playa].none && pl[playa].sel[0] == 3){
       pl[playa].turn_over = true;
       pl[playa].in_menu = false; 
       }//SKIP Turn!
      
       
       //Quit Menu.
       if(playerinput[playa].ntwo){
       pl[playa].in_menu = false;
       }
       
     }
void draw_sidebar_menu(int playa){
     int base_x;
     int base_y;
     switch (playa){
       case 0:base_x = 0; base_y = 10; break;
       case 1:base_x = 343; base_y = 10; break;
       case 2:base_x = 0; base_y = 160; break;
       case 3:base_x = 343; base_y = 160; break;
       }
       //Things ALWAYS Displayed.
     draw_text(base_x,base_y+40,"--INV--",pl[playa].anticolor);
     draw_text(base_x,base_y+120,"-------",pl[playa].anticolor);
      rectfill(buffer,base_x,base_y+49+(pl[playa].eqd*10),base_x+55,base_y+57+(pl[playa].eqd*10),WHITE);
   
     for(int inver=0;inver !=7;inver++){
     draw_text(base_x,base_y+50+(inver*10),item[pl[playa].inv[inver]].name,pl[playa].anticolor);//Drop an item. Brings up INV screen        
     } 
    
       
        //submenu for inventory.
      if(!pl[playa].sel[1]){
     draw_text(base_x+8,base_y,"Equip",pl[playa].anticolor);//Get an item from INV.
     draw_text(base_x+8,base_y+10,"PickUp",pl[playa].anticolor);//Pickup item to put in INV.
       draw_text(base_x+1,base_y+130,"T:",pl[playa].anticolor);//Tickets.
     draw_text(base_x,base_y+130,"=",pl[playa].anticolor);//Tickets
     draw_text(base_x+16,base_y+130,pl[playa].tickets,pl[playa].anticolor);//Tickets
   
    
   
     if(pl[playa].x == map.hole_x && pl[playa].y == map.hole_y){ 
     draw_text(base_x+8,base_y+20,"Enter",pl[playa].anticolor);//Drop an item. Brings up INV screen
     }else{
 draw_text(base_x+8,base_y+20,"Drop",pl[playa].anticolor);//Drop an item. Brings up INV screen
               
     }
     draw_text(base_x+8,base_y+30,"Wait",pl[playa].anticolor);
   
       
  
     draw_text(base_x,base_y+(pl[playa].sel[0]*10),">",pl[playa].anticolor);                                                     
                                                     
                                                     
     }else{
          //Draw the stats of all weapons .
      if(item[pl[playa].inv[pl[playa].sel[1]-1]].type < 1000 && pl[playa].inv[pl[playa].sel[1]-1] != -1 && pl[playa].sel[1] != 8){
          draw_text(base_x+25,base_y+20,"+d",pl[playa].anticolor);
          draw_text(base_x+1,base_y+30,"Acc:",pl[playa].anticolor);
          draw_text(base_x+1,base_y+20,item[pl[playa].inv[pl[playa].sel[1]-1]].var[0],pl[playa].anticolor);
          draw_text(base_x+41,base_y+20,item[pl[playa].inv[pl[playa].sel[1]-1]].var[1],pl[playa].anticolor);
          draw_text(base_x+33,base_y+30,itemacc(pl[playa].inv[pl[playa].sel[1]-1],pl[playa].st,pl[playa].de),pl[playa].anticolor);
          }
    
     line(buffer,base_x,base_y+48+(pl[playa].sel[1]*10),base_x+55,base_y+48+(pl[playa].sel[1]*10),pl[playa].anticolor);}
     draw_text(base_x,base_y+120,"",pl[playa].anticolor);
          
     }
#endif
