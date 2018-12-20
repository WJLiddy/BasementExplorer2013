#ifndef GFX_H_INCLUDED__ 
#define GFX_H_INCLUDED__
#define WHITE makecol(255,255,255)
#define RED makecol(255,0,0)
#define BLUE makecol(0,0,255)
#define GREEN makecol(0,255,0)
#define BLACK makecol(0,0,0)
#define FLOORCOL makecol(64,48,48)

void draw_hud();
//refence to a later program

void draw_aimline(int playa){
     int x = pl[playa].x;//REPLACEING x (Starting point
     int x2 = pl[playa].sel[0];
     int y = pl[playa].y;//REPLACEING x (Starting point
     int y2 = pl[playa].sel[1];
            
    //First,find the slope connecting the two lines.
        double xdist = x2-x;
        double ydist = y2-y;
        double tdist = xdist*xdist+ydist*ydist;
        tdist = sqrt(tdist);
        double ystep = xdist/tdist;
        //the amount of xsteps for each y.
        int deltay =(y2-y);
        int deltax =(x2-x);// no div by zero errors here!
        
        if(deltax != 0){
        double m = (double)deltay/(double)deltax;//y2-y1 ova x2-x1. No div by zero errors either!
        
        for(double step = 0; abs(step) < abs(xdist); step=step+ystep){
        int yadd = int(step*m);
        int xadd = int(step);
        
        rectfill(buffer,((x+xadd)*8)+58,((y+yadd)*8)+2,((x+xadd)*8)+61,((y+yadd)*8)+5,pl[playa].color); 
  
        
        if(!checkempty(x+xadd,y+yadd)){
        tdist = -1;break;
        }//see if we hit a wall. Break if we do.
        }//for each step
        }else{//if delta Y
        
        if(deltay > 0){
        for(int yplus = 0; yplus != deltay;yplus++)
        {
                 
    rectfill(buffer,((x)*8)+58,((y+yplus)*8)+2,((x)*8)+61,((y+yplus)*8)+5,pl[playa].color); 
  
        
        if(!checkempty(x,y+yplus)){
        tdist = -1;break;
                }
                }
                }//endof if vertical pos
        if(deltay < 0){
        for(int yplus = 0; yplus != deltay;yplus--)
        {
        //Go all vertical mode
         rectfill(buffer,((x)*8)+58,((y+yplus)*8)+2,((x)*8)+61,((y+yplus)*8)+5,pl[playa].color); 
  
        
        if(!checkempty(x,y+yplus)){
        tdist = -1;break;
                }
                }
                }//endof if vertical pos
        
        }//end_of_if y
        
        
        if(tdist == -1 || !checkempty(pl[playa].sel[0],pl[playa].sel[1])  ){
        rectfill(buffer,(pl[playa].sel[0]*8)+57,(pl[playa].sel[1]*8)+1,(pl[playa].sel[0]*8)+62,(pl[playa].sel[1]*8)+6,RED); 
        }else{
        rectfill(buffer,(pl[playa].sel[0]*8)+57,(pl[playa].sel[1]*8)+1,(pl[playa].sel[0]*8)+62,(pl[playa].sel[1]*8)+6,pl[playa].color);        
        }
        
        
        }//endoffunc
     

void draw_glyph(int the_x, int the_y,const char *icon, int color){
textout_ex(buffer,font,icon,(the_x*8)+56,the_y*8,color,-1);
}




void draw_text(int the_x, int the_y,const char *text, int color){
textout_ex(buffer,font,text,the_x,the_y,color,-1);
}

void draw_text(int the_x, int the_y,int value, int color){
char textbuffer[16];
itoa(value,textbuffer,10);
textout_ex(buffer,font,textbuffer,the_x,the_y,color,-1);
}//overload. For int.

void draw_floor(){
for(int xgun = 0; xgun != 36; xgun++){
for(int ygun = 0; ygun != 36; ygun++){ 
if(map.is_disc[xgun][ygun] || key[KEY_TILDE]){
if(map.is_floor[xgun][ygun]){
rectfill(buffer,(xgun*8)+56,(ygun*8),(xgun*8)+63,(ygun*8)+7,FLOORCOL); 
//We need to do walls now also!!!
if(!map.is_floor[xgun+1][ygun]){
rectfill(buffer,8+(xgun*8)+56,(ygun*8),8+(xgun*8)+63,(ygun*8)+7,makecol(32,32,32)); }
if(!map.is_floor[xgun-1][ygun]){
rectfill(buffer,(xgun*8)+56-8,(ygun*8),(xgun*8)+63-8,(ygun*8)+7,makecol(32,32,32)); }
if(!map.is_floor[xgun][ygun+1]){
rectfill(buffer,(xgun*8)+56,(ygun*8)+8,(xgun*8)+63,(ygun*8)+7+8,makecol(32,32,32)); }
if(!map.is_floor[xgun][ygun-1]){
rectfill(buffer,(xgun*8)+56,(ygun*8)-8,(xgun*8)+63,(ygun*8)+7-8,makecol(32,32,32)); }
}                      
}
}
}
}

void draw_items(){
   for (int ito = 0; ito != 256;ito++){
   if (item[ito].floor && (map.is_disc[item[ito].x][item[ito].y] || key[KEY_TILDE])){
   switch(item[ito].type){
   case 1://Stick
   draw_glyph(item[ito].x,item[ito].y,"/",makecol(130,80,50));
   break;
   case 2://Club
   draw_glyph(item[ito].x,item[ito].y,"/",makecol(200,140,100));
   break;
   case 3://Rake
   draw_glyph(item[ito].x,item[ito].y,"F",makecol(130,70,60));
   break;
   case 4://Dagger
   draw_glyph(item[ito].x,item[ito].y,"-",makecol(130,130,130));
   break;
   case 5://Fork
   draw_glyph(item[ito].x,item[ito].y,"-",makecol(212,212,212));
   break;
   case 6://Machete
   draw_glyph(item[ito].x,item[ito].y,"/",makecol(192,192,192));
   break;
   case 7://Gladius
   draw_glyph(item[ito].x,item[ito].y,"/",makecol(255,215,0));
   break;
    
   case 201:
   draw_glyph(item[ito].x,item[ito].y,"!",makecol(50,50,50));
   break;
   case 1001:
   draw_glyph(item[ito].x,item[ito].y,"=",makecol(255,32,32));
   break;
   }//endofseitch
   }
}
   
   
} 

void draw_manhole(){
if((map.is_disc[map.hole_x][map.hole_y] || key[KEY_TILDE])){
    draw_glyph(map.hole_x,map.hole_y,"#",BLACK);
     }
     }
     
void v_draw_buffer()
{
     //draws everything to the screen
      vsync();   
stretch_blit(buffer,screen,0,0,GAME_W,GAME_H,0,0,SCREEN_W,SCREEN_H);
	clear(buffer);
}

void draw_overworld()
{
//basic unknown color

draw_floor();
draw_manhole();
draw_items();
//draw our players
for(int allplayers = 0; allplayers!= 4;allplayers++){
        if(pl[allplayers].hp > 0){
        if(pl[allplayers].aimmode){draw_aimline(allplayers);    
        
}
        if(pl[allplayers].turn_over || ((cycler.ctr/8) % 2)){
 draw_glyph(pl[allplayers].x,pl[allplayers].y,"@",pl[allplayers].color);
}}
// Draw a highlighter for enemy turn.
if(npcturnno > -1){
rectfill(buffer,(npc[npcturnno].x*8)+56,npc[npcturnno].y*8,(npc[npcturnno].x*8)+63,npc[npcturnno].y*8+7,makecol(255,255,0));
}

}
for(int allmonsters=0; allmonsters!=32;allmonsters++){
        if(npc[allmonsters].hp > 0 && (map.is_disc[npc[allmonsters].x][npc[allmonsters].y] || key[KEY_TILDE])){
       // if(npc[allmonsters].los_check() > -1){draw_glyph(npc[allmonsters].x,npc[allmonsters].y,"!!",RED);}
        switch(npc[allmonsters].type){
        //Hampstr
        case 1:draw_glyph(npc[allmonsters].x,npc[allmonsters].y,"h",RED);
        break;
        case 2:draw_glyph(npc[allmonsters].x,npc[allmonsters].y,"g",RED);
        break;
        case 3:draw_glyph(npc[allmonsters].x,npc[allmonsters].y,"p",RED);
        break;
        case 4:draw_glyph(npc[allmonsters].x,npc[allmonsters].y,"r",RED);
        break;
        case 5:draw_glyph(npc[allmonsters].x,npc[allmonsters].y,"P",RED);
        break;
        case 6:draw_glyph(npc[allmonsters].x,npc[allmonsters].y,"q",RED);
        break;
        case 7:draw_glyph(npc[allmonsters].x,npc[allmonsters].y,"t",RED);
        break;
        case 101:draw_glyph(npc[allmonsters].x,npc[allmonsters].y,"m",RED);
        break;
}//switch
} //if
}//for

 rectfill(buffer,0,0,55,300,makecol(64,64,64));
 rectfill(buffer,343,0,400,300,makecol(64,64,64));
 rectfill(buffer,0,288,400,300,makecol(64,64,64));
 draw_hud();
draw_narrator_text();


if(pl[0].hp < 1 && pl[1].hp < 1 && pl[2].hp < 1 && pl[3].hp < 1){
 draw_text(64,146,"Game Over. lol. You have no skillz",WHITE);
 BITMAP *loser = create_bitmap (400,300);
 rectfill(loser,0,0,400,300,0);
 set_trans_blender(128, 128, 128, 128);
 draw_trans_sprite(buffer, loser, 0, 0);
            }


 if(key[KEY_TILDE]){ 
 textprintf(buffer,font,0,0,100000,"Frames %i",cycler.ctr/updates_per_second);
 textprintf(buffer,font,0,10,100000,"Logics %i",cycler.loopctr/updates_per_second);
 textprintf(buffer,font,0,20,100000,"Quota %i",cycler.timer/updates_per_second);
 textprintf(buffer,font,0,30,100000,"WSTR %i",item[pl[0].inv[pl[0].eqd]].var[2]);
 textprintf(buffer,font,0,40,100000,"WDEX %i",item[pl[0].inv[pl[0].eqd]].var[3]);
 textprintf(buffer,font,0,50,100000,"NPC %i",npcturnno);
 textprintf(buffer,font,0,60,100000,"Floor %i",map.floor);
 textprintf(buffer,font,0,70,100000,"Narrator %i",is_narrator_talk());

}
 

}
#endif
