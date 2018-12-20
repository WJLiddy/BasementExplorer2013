#ifndef OPTIONS_H_INCLUDED__ 
#define OPTIONS_H_INCLUDED__ 


void disp_control(){
    draw_text(0,0,"Known Bug: If you get stuck, revert with R",WHITE);
     for(int playa =0;playa != 4; playa++){
     draw_text(300,10+10*playa,playa,WHITE);
     if(playerinput[playa].using_keyboard){
     draw_text(320,10+10*playa,"KEYBOARD",WHITE);
     }
     if(playerinput[playa].joy_id > -1){
     draw_text(350,10+10*playa,playerinput[playa].joy_id,WHITE);                            
     draw_text(320,10+10*playa,"JOY",WHITE);
     }
     if(playerinput[playa].smartphone > -1){
     draw_text(380,10+10*playa,playerinput[playa].smartphone,WHITE);                            
     draw_text(320,10+10*playa,"PHONE",WHITE);
     }
     
     }//for.
     }

void jork_submenu(int playa){
    int sel = 2;
    
    while (1){
    clear(buffer);
    get_all_inputs();
    disp_control();
    draw_text(20,40,"GAMEPAD CONFIG",makecol(255,128,0));
    //This is our emergency Escape.
    if(key[KEY_R]){setup_joysticks();}
    
    draw_text(30,50,"Use Keyboard?",makecol(0,128,0));
    if(playerinput[playa].using_keyboard){
    draw_text(200,50,"YES",GREEN);}else{draw_text(200,50,"NO",RED);}
    
    draw_text(30,60,"Use Joystick?",makecol(0,128,0));
    if(playerinput[playa].joy_id > -1){
    draw_text(200,60,playerinput[playa].joy_id,GREEN);}else{draw_text(200,60,"NO",RED);}
    
    draw_text(30,70,"Use Phone?",makecol(0,128,0));
    switch(playerinput[playa].smartphone){
    case -1:draw_text(200,70,"NO",RED);break;
    case 0:draw_text(200,70,"ABCD E",GREEN);break;
    case 1:draw_text(200,70,"HIJK L",GREEN);break;
    case 2:draw_text(200,70,"OPQR S",GREEN);break;
    case 3:draw_text(200,70,"1234 5",GREEN);break;
   }
    draw_text(30,80,"GoBack.gif",makecol(0,128,0));
    draw_text(20,50+(sel*10),">",WHITE);
    
    if((playerinput[0].nd) && sel < 3){sel++;}
    if((playerinput[0].nu) && sel > 0){sel--;}
    //move_paddles
    
       if (key[KEY_ESC] || (playerinput[0].none && sel == 3)){
       //Go back!!
       break;}
       
              if(playerinput[0].none && sel == 0){
              //NO SMARTPHONES OR OTHER KEYBOARDERS ALLOWED
              playerinput[0].using_keyboard=false;
              playerinput[1].using_keyboard=false;
              playerinput[2].using_keyboard=false;
              playerinput[3].using_keyboard=false;
              playerinput[0].smartphone=-1;
              playerinput[1].smartphone=-1;
              playerinput[2].smartphone=-1;
              playerinput[3].smartphone=-1;
              playerinput[playa].using_keyboard=true;
              playerinput[playa].joy_id=-1;
              }
              
              if(playerinput[0].none  && sel == 1){//Joystick me.
              playerinput[playa].joy_id++;
              playerinput[playa].using_keyboard=false;
              playerinput[playa].smartphone=-1;
              if(playerinput[playa].joy_id > 3){playerinput[playa].joy_id = 0;};    
              }
              
              if(playerinput[0].none && sel == 2){//Smartphone me.
              playerinput[playa].smartphone++;
              playerinput[0].using_keyboard=false;
              playerinput[1].using_keyboard=false;
              playerinput[2].using_keyboard=false;
              playerinput[3].using_keyboard=false;
              playerinput[playa].joy_id=-1;
              if(playerinput[playa].smartphone > 3){playerinput[playa].smartphone = 0;};    
              }
              
    v_draw_buffer();
    
}//endof while.
        
  

}//endoffucntion




void options_menu(){
    int sel = 2;
    while (1){
    clear(buffer);
    get_all_inputs();
    disp_control();
    //void draw_text(int the_x, int the_y,const char *text, int color){

    textout_ex(buffer,font,"OPTIONS",10,30,makecol(255,128,0),-1);
    textout_ex(buffer,font,"Player 1 GamePad!",20,40,makecol(0,128,0),-1);
    textout_ex(buffer,font,"Player 2 Gamepa.|?",20,50,makecol(0,128,0),-1);
    textout_ex(buffer,font,"Player 3 Gamep@d...",20,60,makecol(0,128,0),-1);
    textout_ex(buffer,font,"Player 4 Gamedap~",20,70,makecol(0,128,0),-1);
    textout_ex(buffer,font,"kthx I figured it out",20,80,makecol(0,128,0),-1);
    textout_ex(buffer,font,">",10,40+(sel*10),makecol(255,255,255),-1);
    
       if(playerinput[0].nd && sel < 4){sel++;}
       if(playerinput[0].nu && sel > 0){sel--;}
       if (key[KEY_ESC] || (playerinput[0].none && sel == 4)){
       break;}
       
              if(playerinput[0].none && sel < 4){
              jork_submenu(sel);
              }
       
       
                            
    
 
    
    v_draw_buffer();
    
}//endof while.
        
  
  //  draw_glyph(10,,"Exit", makecol(0,128,0));
   

}
#endif
