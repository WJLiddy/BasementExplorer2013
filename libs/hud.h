#ifndef HUD_H_INCLUDED__ 
#define HUD_H_INCLUDED__
void draw_sidebar_menu(int);
//
void draw_hud(){
//players
for(int playas = 0; playas!=4;playas++){
        
//Get our starting points.
//If out player is alive:
if(pl[playas].hp > 0){
switch (playas){
       case 0:base_x = 0; base_y = 0; break;
       case 1:base_x = 343; base_y = 0; break;
       case 2:base_x = 0; base_y = 150; break;
       case 3:base_x = 343; base_y = 150; break;
       }
//Fill it with their colour
rectfill(buffer,base_x,base_y,base_x+55,base_y+150,pl[playas].color);
//nametag.jpg
rectfill(buffer,base_x,base_y,base_x+55,base_y+8,pl[playas].anticolor);
draw_text(base_x+1,base_y+1,pl[playas].name,pl[playas].color);     
if(pl[playas].in_menu){
draw_sidebar_menu(playas);  
}else{
//HP Number
draw_text(base_x+2,base_y+11,"",pl[playas].anticolor);       
draw_text(base_x+2,base_y+11,"HP:",pl[playas].anticolor);       
draw_text(base_x+26,base_y+11,pl[playas].hp,pl[playas].anticolor);    
//HP Bar
rectfill(buffer,base_x+1,base_y+20,base_x+53,base_y+23,WHITE); 
rect(buffer,base_x+2,base_y+21,base_x+2+((50*pl[playas].hp)/(pl[playas].max_hp())),base_y+22,RED); 
//Tickets
draw_text(base_x+1,base_y+140,"T:",pl[playas].anticolor);//Tickets.
draw_text(base_x,base_y+140,"=",pl[playas].anticolor);//Tickets
draw_text(base_x+16,base_y+140,pl[playas].tickets,pl[playas].anticolor);//Tickets
    

//item
draw_text(base_x+1,base_y+26,"Equip:",pl[playas].anticolor); 

if(pl[playas].inv[pl[playas].eqd] == -1){
draw_text(base_x+25,base_y+46,"+d",pl[playas].anticolor);
draw_text(base_x+1,base_y+56,"Acc:",pl[playas].anticolor);
draw_text(base_x+1,base_y+36,"Nothing",pl[playas].anticolor);
draw_text(base_x+1,base_y+46,pl[playas].st/4,pl[playas].anticolor);
draw_text(base_x+41,base_y+46,pl[playas].de/2,pl[playas].anticolor);
draw_text(base_x+33,base_y+56,"75",pl[playas].anticolor);                                
}else{   
draw_text(base_x+1,base_y+36,item[pl[playas].inv[pl[playas].eqd]].name,pl[playas].anticolor);
//Always say the item name.
if(eqdtype(playas) < 1000){  
draw_text(base_x+25,base_y+46,"+d",pl[playas].anticolor);
draw_text(base_x+1,base_y+56,"Acc:",pl[playas].anticolor);
draw_text(base_x+1,base_y+46,item[pl[playas].inv[pl[playas].eqd]].var[0],pl[playas].anticolor);
draw_text(base_x+41,base_y+46,item[pl[playas].inv[pl[playas].eqd]].var[1],pl[playas].anticolor);
draw_text(base_x+33,base_y+56,itemacc(pl[playas].inv[pl[playas].eqd],pl[playas].st,pl[playas].de),pl[playas].anticolor);
//We also need to tell the player if it's heavy or akward.
if((item[pl[playas].inv[pl[playas].eqd]].var[2] - pl[playas].st) > 3){
draw_text(base_x+1,base_y+66,"[WEAK]",pl[playas].anticolor);
}else{
if((item[pl[playas].inv[pl[playas].eqd]].var[3] - pl[playas].de) > 3){
draw_text(base_x+1,base_y+66,"[INEPT]",pl[playas].anticolor);      
}
}
}}//item.

}//player not in menu
}//player is alive
}//endof player
}//endonf Func

#endif
