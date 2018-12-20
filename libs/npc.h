#ifndef NPC_H_INCLUDED__ 
#define NPC_MENU_H_INCLUDED__
bool check_space(int,int);
void do_combat(int,int);
void do_e_combat(int,int);
//temp
void v_draw_buffer();

void draw_glyph(int, int,const char *, int);
     
class npc_t{
      public:
      int x,y;//x and y
      int st,de,in;
      int hp;//current HP
      int type;// monster type
      int weap; //What attack does it know? Bite 
      char name[9];//their name!
      bool try_legal_move(int,int,int);
      bool turn_over;// can make turn?
      void create(int);//create char of type (x)
      
      int los_check();
      };npc_t npc[32];
      
      void npc_t::create(int typeset){
      type = typeset;
       while(1){
        int somex = rand() % 36;
        int somey = rand() % 36;
            if(check_space(somex,somey)){
            x = somex;
            y = somey;
            break;
            }
            }// we put an NPC on the floor!
            
      switch (type){
      case 1:strcpy(name,"Hamster");
      st = rand () % 1 + 1;
      hp = st + 1;
      de = rand () % 10;
      in = 0;
      weap = 1;
      
      break;
      
      case 2:strcpy(name,"Gerbil");
      st = rand() % 2 + 1;
      hp = 2 * st + 2;
      de = 15 + rand () % 5;
      in = 0;
      weap = 1;
      break;
      
      case 3:strcpy(name,"GinyPig");
      st = rand() % 2 + 3;
      hp = rand () % 2 + 5;
      de = 5;
      in = 0;
      weap = 1;
      break;
      
       
      case 4:strcpy(name,"Rat");
      st = rand() % 4 + 3;
      hp = 3 * st + 1;
      de = 20 + rand () % 10;
      in = 2;
      weap = 1;
      break;
      
      case 5:strcpy(name,"Pengin");
      st = 10;
      hp = rand() % 1 + 12;
      de = 3;
      in = 4;
      weap = 2;
      break;
      
      
      case 6:strcpy(name,"Quail");
      st = 3;
      hp = 5 + rand () % 8;
      de = 20;
      in = 1;
      weap = 2;
      break;
      
      case 7:strcpy(name,"Troll");
      st = 2;
      hp = 3 + rand () % 3;
      de = 1;
      in = 5;
      weap = 3;
      break;
      
      case 101:strcpy(name,"Moot");
      st = 10;
      hp = 44;
      de = 10;
      in = 5;
      weap = 101;
      break;
      
      }//end of typesetter
      }//end of func
                
      bool p_v_npc_combat_check(int playa, int xmove, int ymove){
      for(int other_npcs=0; other_npcs != 32; other_npcs++){
      if(xmove == npc[other_npcs].x && ymove== npc[other_npcs].y){
      do_combat(playa,other_npcs);
      return 1; //We did combat!
           }//x
           }//for
           }//func

//Code for "line of sight"

int npc_t::los_check(){
    int targ = -1;
    int targdist = 50;
    for(int playa = 0; playa !=4;playa++){
            
    //First,find the slope connecting the two lines.
        double xdist = pl[playa].x-x;
        double ydist = pl[playa].y-y;
        double tdist = xdist*xdist+ydist*ydist;
        tdist = sqrt(tdist);
        double ystep = xdist/tdist;
        //the amount of xsteps for each y.
        int deltay =(pl[playa].y-y);
        int deltax =(pl[playa].x-x);// no div by zero errors here!
        
        if(deltax != 0){
        double m = (double)deltay/(double)deltax;//y2-y1 ova x2-x1. No div by zero errors either!
        
        for(double step = 0; abs(step) < abs(xdist); step=step+ystep){
        int yadd = int(step*m);
        int xadd = int(step);
        
        /* This draws a line of sight (debug only!)
        draw_glyph(x+xadd,(y+yadd),"x",42394); 
        v_draw_buffer(); 
        Sleep(10);
        */
        
        if(!checkempty(x+xadd,y+yadd)){
        tdist = -1;break;
        }//see if we hit a wall. Break if we do.
        }//for each step
        }else{//if delta Y
        
        if(deltay > 0){
        for(int yplus = 0; yplus != deltay;yplus++)
        {
                /* This draws a line of sight (debug only!)
        draw_glyph(x,(y+yplus),"x",42394); 
        v_draw_buffer(); 
        Sleep(10);
        */
        
        if(!checkempty(x,y+yplus)){
        tdist = -1;break;
                }
                }
                }//endof if vertical pos
        if(deltay < 0){
        for(int yplus = 0; yplus != deltay;yplus--)
        {
                /* This draws a line of sight (debug only!)
        draw_glyph(x,(y+yplus),"x",42394); 
        v_draw_buffer(); 
        Sleep(10);
        */
        
        if(!checkempty(x,y+yplus)){
        tdist = -1;break;
                }
                }
                }//endof if vertical pos
        
        }//end_of_if y
        
    if((tdist > 0) && (tdist < targdist)){
    targdist = tdist;
    targ = playa;
    }
    
        
    

            }//for each player
            return targ;
            }//end of func
            
void do_npc_ai(int id){
 
     int lhealth = 9000;
     
     int thetarg = npc[id].los_check();// If we see a player!
     //Find our closest Targ
     //Certain enemies just kinda roam. They're chill man, ya know?
     
     //SPECIAL AI INSTRUCTIONS
     switch(npc[id].type){
     case 1:case 2:case 4://Hamsters, ginypigs, rats lose their attention rather easily.
     if(!(rand() % 5)){// 20% chance of waiting.
     thetarg = -1;//Roam.
     }
     break;
     case 3:
     //Ginypigs are fat and lazy. They do nothing half their turns but are sure to fight if enemies are closeby
     if((abs(pl[thetarg].y - npc[id].y) + abs(pl[thetarg].x - npc[id].x)) > (rand () % 4 + 2)){
     //enemy is just too far away, bro.
     if(rand () % 4){thetarg = -2;}
     }//end of distance check.
     break;
     case 5://pengins are territorial. They don't aggro les you get too close.
     if((abs(pl[thetarg].y - npc[id].y) + abs(pl[thetarg].x - npc[id].x)) > (7)){
     thetarg = -1;
     }
     break;
     // 6 (quails are just annoying.
     // 7 trolls too. They just chase relentlessly.
     
     case 101:// moot is a boss, in an open square room. he will always target the weakest living player.
     for(int playa = 0; playa !=4;playa++){
             if(pl[playa].hp > 0){
             if(lhealth > pl[playa].hp){
             thetarg = playa;
             lhealth = pl[playa].hp;
             }
             }
             }
     if(!(rand() % 10)){//moot tries to ban a troll.
     thetarg = -2;
     for(int npcctr = 0;npcctr < 32; npcctr++){
     if(npc[npcctr].type == 7){
     npc[npcctr].x = -2;
     npc[npcctr].type = 1;
     npc[npcctr].hp = -1;
     append_msg(3,NULL,NULL);
     npcctr = 100;
     }
     }
     }
     
     break;
     }//end of ai special conditions.
         
         
     //Will attack based on controller based on multiple players. Sloppy. But whatever.
     for(int playa = 0; playa !=4;playa++){
     if(npc[id].y == pl[playa].y){
     if(npc[id].x == pl[playa].x + 1 || npc[id].x == pl[playa].x - 1){
       
          do_e_combat(id,playa); thetarg = -2; // Id for hit. Do not Roam!
          }// x plusminus
          }// Y =
     if(npc[id].x == pl[playa].x){
     if(npc[id].y == pl[playa].y + 1 || npc[id].y == pl[playa].y- 1){
          do_e_combat(id,playa); thetarg = -2;
          }// x plusminus
          }// Y =
          }// for
     
     
     if (thetarg > -1){
     //We have a target.
     bool goxn = false;//xNEG
     bool goxp = false;//xPOS
     bool goyn = false;
     bool goyp = false;
     // Possible directions we can go.
     
     //First, check to see potential directions.
     if(npc[id].x > pl[thetarg].x){// See what direction we wanna go.
     if(check_space(npc[id].x-1,npc[id].y)){
     goxn = true; //We can move in the x direction. good for us                                       
     }
     }//goxn
     
     if(npc[id].x < pl[thetarg].x){// See what direction we wanna go.
     if(check_space(npc[id].x+1,npc[id].y)){
     goxp = true; //We can move in the x direction. good for us                                       
     }
     }//goxn
     
     if(npc[id].y > pl[thetarg].y){// See what direction we wanna go.
     if(check_space(npc[id].x,npc[id].y-1)){
     goyn = true; //We can move in the x direction. good for us                                       
     }
     }//goxn
     
     if(npc[id].y < pl[thetarg].y){// See what direction we wanna go.
     if(check_space(npc[id].x,npc[id].y+1)){
     goyp = true; //We can move in the x direction. good for us                                       
     }
     }//goxn
     
     //At this point we have a list of directions we want to and can go to. Now, we pick.
     
     //These our our candidates if we have only ONE direction avaiable to us. The easiest.
     if(goxn && !goyn && !goyp){npc[id].x--;}
     if(goxp && !goyn && !goyp){npc[id].x++;}
     if(goyn && !goxn && !goxp){npc[id].y--;}
     if(goyp && !goxn && !goxp){npc[id].y++;}
     
     //Good.
     //Now, what if we have two contenders?
     if((goxn || goxp) && (goyp || goyn)){
     // pick x or y
     if(rand() % 2){
     // we chose x!
     if(goxn){npc[id].x--;}
     if(goxp){npc[id].x++;}
     }else{
     //We chose y!
     if(goyn){npc[id].y--;}
     if(goyp){npc[id].y++;}
     }
     }// We chose a contendor.
     
     // Basic, straight line AI complete
     
     
     }else{// If we don't see a player
     //Roam stupidly. (assuming no attack)
     if(thetarg == -1){
     
     int roam = rand () % 5;
     switch(roam){
     case 0:break;// do nothin!
     case 1:if(check_space(npc[id].x+1,npc[id].y)){npc[id].x++;}break;
     case 2:if(check_space(npc[id].x-1,npc[id].y)){npc[id].x--;}break;
     case 3:if(check_space(npc[id].x,npc[id].y+1)){npc[id].y++;}break;            
     case 4:if(check_space(npc[id].x,npc[id].y-1)){npc[id].y--;}break;
     
     
               }
     }//elseif
     }//the targ
}//end_of_func






#endif
