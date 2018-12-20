#ifndef WORLD_H_INCLUDED__ 
#define WORLD_H_INCLUDED__

bool win_screen();

class map_t{
      public:
      bool is_floor[36][36];
      bool is_disc[36][36];// discovered!
      void gen();
      void gen_10();
      int floor;
      int hole_x;
      int hole_y;
      };map_t map;
      
        void map_t::gen_10(){
               //clear old map.
        
      for(int clearx=0; clearx != 36;clearx++){
      for(int cleary=0; cleary != 36;cleary++){
      is_floor[clearx][cleary] = 0;
      }}
      //Make the boss room.
      
      for(int xer=9;xer != 28;xer++){
      for(int yer=9;yer != 28;yer++){
      is_floor[xer][yer] = 1;
      }}
      
      //Make the treasure room.
      for(int xer= 15;xer != 20;xer++){
      for(int yer= 5;yer != 8;yer++){
      is_floor[xer][yer] = 1;
      }}
      // Put the manhole in the treasure room
     map.hole_x = 18;
     map.hole_y = 6;
          
     for(int playa = 0; playa != 4;playa++){
     if(pl[playa].hp>0){
     pl[playa].x = 12+(playa*2);
     pl[playa].y = 25;
     }
     }
   
      
      }
      
      void hide_10(){
for(int xgun = 0; xgun != 36; xgun++){
for(int ygun = 0; ygun != 36; ygun++){ 
map.is_disc[xgun][ygun] = false;
}
}

for(int xer=9;xer != 28;xer++){
for(int yer=9;yer != 28;yer++){
map.is_disc [xer][yer] = 1;
}  
}

}             
      void map_t::gen(){
      //clear old map.
      for(int clearx=0; clearx != 36;clearx++){
      for(int cleary=0; cleary != 36;cleary++){
      is_floor[clearx][cleary] = 0;
      }}
      //Make a data structure for our "rooms"
      int room[16][4];
      //find places to put rooms.
      
      for(int roomer = 0; roomer !=16;roomer++){
      room[roomer][0]= 1 + rand() % 30;//random x up to the wall (35 
      room[roomer][1]= 1 + rand() % 30;
      room[roomer][2]=room[roomer][0]+2+rand() % 8;//max room is 9 by 9
      room[roomer][3]=room[roomer][1]+2+rand() % 8;           
      if(room[roomer][2] > 35){room[roomer][2] = 35;}
      if(room[roomer][3] > 35){room[roomer][3] = 35;}
      }// we made all the rooms.
      
      //Let's write these rooms to the map.
      for(int roomer = 0; roomer !=16;roomer++){  
      for(int xer=room[roomer][0];xer != room[roomer][2];xer++){
      for(int yer=room[roomer][1];yer != room[roomer][3];yer++){
      is_floor[xer][yer] = 1;
      }}}
      
      //Now, connect up all the rooms, in order:
      //Make sure not to connect the last room
      for(int roomer = 0; roomer !=15;roomer++){ 
      int pos_x=room[roomer][0]+ rand() % 3;// each room does extend by at least 3
      int pos_y=room[roomer][1]+ rand() % 3;
      int dest_x=room[roomer+1][0]+ rand() % 3;
      int dest_y=room[roomer+1][1]+ rand() % 3;
   
      while ((pos_x != dest_x) || (pos_y != dest_y)){
      //Here's the int we will use to keep track of movment.
      bool ex = rand() % 2;
      //Snake to get there.      
      if(ex){
      if(pos_x > dest_x){
      pos_x--;
      }//for
      if(pos_x < dest_x){
      pos_x++;
      }//for
      }
      if(!ex){
      if(pos_y > dest_y){
      pos_y--;
      }//for
      if(pos_y < dest_y){
      pos_y++;
      }//end of up
      }//end of Y direction
      
      is_floor[pos_x][pos_y] = true;
      }//Road complete!//end while
      
      }//all roads complete! end path creation.
  
              
}//map's done!

void find_starting_pos(){

     for(int playa = 0; playa != 4;playa++){
     if(pl[playa].hp>0){
     while(1){
     int openx = rand() % 36;
     int openy = rand() % 36;
     if(map.is_floor[openx][openy]){
     pl[playa].x = openx;
     pl[playa].y = openy;
     discover_floor(playa);
     break;
     }// Safe Landing!
     }// While Loop
     }//If Alive loop
     }// for loop
     
     }//enoffunc
     

bool checkempty(int xtest, int ytest){
return map.is_floor[xtest][ytest];
     }

     bool check_space(int thatx, int thaty){
      
      for(int other_playas=0; other_playas != 4; other_playas++){
      if(thatx == pl[other_playas].x && thaty== pl[other_playas].y){
      return 0; //Can't move. (person)
           }
           }
           
      for(int other_npcs=0; other_npcs != 32; other_npcs++){
      if(thatx == npc[other_npcs].x && thaty== npc[other_npcs].y){
      return 0; //Can't moveo. (monster)
           }
           }
           
      if(checkempty(thatx,thaty)){
       return 1;// No people, only wall.
       }
       
return 0; //Can't move (wall)
      
}//endfunc


void discover_floor(int playa){
     //discover UP
     for(int xup = 0; xup!=4;xup++){
             if(!map.is_floor[pl[playa].x+xup][pl[playa].y]){break;}
             for(int xleft = 0; xleft != 4-xup;xleft++){
             if(map.is_floor[pl[playa].x+xup][pl[playa].y-xleft]){
             map.is_disc[pl[playa].x+xup][pl[playa].y-xleft] = true;
             }else{break;}
             }
             for(int xright = 0; xright != 4-xup;xright++){
             if(map.is_floor[pl[playa].x+xup][pl[playa].y+xright]){
             map.is_disc[pl[playa].x+xup][pl[playa].y+xright] = true;
             }else{break;}
             }
     }
     
     //Discover DOWN
     for(int xdown = 0; xdown!=4;xdown++){
             if(!map.is_floor[pl[playa].x-xdown][pl[playa].y]){break;}
             for(int xleft = 0; xleft != 4-xdown;xleft++){
             if(map.is_floor[pl[playa].x-xdown][pl[playa].y-xleft]){
             map.is_disc[pl[playa].x-xdown][pl[playa].y-xleft] = true;
             }else{break;}
             }
             for(int xright = 0; xright != 4-xdown;xright++){
             if(map.is_floor[pl[playa].x-xdown][pl[playa].y+xright]){
             map.is_disc[pl[playa].x-xdown][pl[playa].y+xright] = true;
             }else{break;}
             }
     }
     
       //discover Right
     for(int yup = 0; yup!=4;yup++){
             if(!map.is_floor[pl[playa].x][pl[playa].y+yup]){break;}
             for(int yleft = 0; yleft != 4-yup;yleft++){
             if(map.is_floor[pl[playa].x-yleft][pl[playa].y+yup]){
             map.is_disc[pl[playa].x-yleft][pl[playa].y+yup] = true;
             }else{break;}
             }
             for(int yright = 0; yright != 4-yup;yright++){
             if(map.is_floor[pl[playa].x+yright][pl[playa].y+yup]){
             map.is_disc[pl[playa].x+yright][pl[playa].y+yup] = true;
             }else{break;}
             }
     }
     
     //Discover Left
        for(int ydown = 1; ydown!=4;ydown++){
             if(!map.is_floor[pl[playa].x][pl[playa].y-ydown]){break;}
             
             for(int yleft = 0; yleft != 4-ydown;yleft++){
             if(map.is_floor[pl[playa].x-yleft][pl[playa].y-ydown]){
             map.is_disc[pl[playa].x-yleft][pl[playa].y-ydown] = true;
             }else{break;}
             }
             
             for(int yright = 0; yright != 4-ydown;yright++){
             if(map.is_floor[pl[playa].x+yright][pl[playa].y-ydown]){
             map.is_disc[pl[playa].x+yright][pl[playa].y-ydown] = true;
             }else{break;}
             }
     }
}//endof_func

void create_manhole(){
     while(1){
     int somex= 2 + rand() % 33;
     int somey= 2 + rand() % 33;
     if(map.is_floor[somex][somey]){
     map.hole_x = somex;
     map.hole_y = somey;
     break;
     }// Safe Landing!
     }// While Loop
     }//manhole
void hide_all_floor(){
for(int xgun = 0; xgun != 36; xgun++){
for(int ygun = 0; ygun != 36; ygun++){ 
map.is_disc[xgun][ygun] = false;
}
}
}  

void do_spec_conditions(int floornumba){
     int spawnslot = 0;
     if(floornumba == 10){
     if(!(rand() % 11) && npc[0].x > 0){//moot attracts trolls.
     //spawn a troll in a corner.
     for(int openslot = 1; openslot < 32;openslot++){
     if(npc[openslot].x < 1){//This is the troll's slot!
     spawnslot = openslot;
     openslot = 9001;
     }//troll spot created.
     }//find an open spot for troll.
     if(spawnslot){
     npc[spawnslot].create(7);
     }
     }//troll conditional.
     
     if(npc[0].x < 0){
     // 8, 15-20; 15 16 17 18 19 20
     //open treasure room if moot dies.
     map.is_floor[17][8]=1;
     map.is_floor[18][8]=1;
     map.is_disc[17][8]=1;
     map.is_disc[18][8]=1;
     }//treasure room conditional.
     
     if(pl[0].y == 6 || pl[1].y == 6 || pl[2].y == 6 || pl[3].y == 6 ){
     if(win_screen()){quittomain = 1;}
     }//win demo conditional.
     
     }// floor 10 conditional.
     }//end of func.
   
     
#endif
