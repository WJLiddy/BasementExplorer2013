#ifndef MAINMENU_H_INCLUDED__ 
#define MAINMENU_H_INCLUDED__

int main_menu(){
    play_track(1);
    int sel = 2;
    while (1){
    clear(buffer);
    get_all_inputs();
    //void draw_text(int the_x, int the_y,const char *text, int color){
    textout_ex(buffer,font,"BASEMENT EXPLORATION SIMULATOR",0,0,makecol(255,128,0),-1);
    textout_ex(buffer,font,"NEW GAME",10,10,makecol(0,128,0),-1);
    textout_ex(buffer,font,"CONTINUE",10,20,makecol(0,128,0),-1);
    textout_ex(buffer,font,"OPTIONS",10,30,makecol(0,128,0),-1);
    textout_ex(buffer,font,"EXIT",10,40,makecol(0,128,0),-1);
    textout_ex(buffer,font,">",0,sel*10,makecol(255,255,255),-1);
    
    textout_ex(buffer,font,"a quality game by neutral space",0,290,makecol(64,64,64),-1);
    
       if(playerinput[0].nd && sel < 4){sel++;}
       if(playerinput[0].nu && sel > 1){sel--;}

       
          if(playerinput[0].none){
          return sel;
          }
                            
    
 
    
    v_draw_buffer();
    
}//endof while.
        
  
  //  draw_glyph(10,,"Exit", makecol(0,128,0));
   

}
#endif
