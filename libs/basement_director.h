#ifndef BASEMENT_DIRECTOR_H_INCLUDED__ 
#define BASEMENT_DIRECTOR_H_INCLUDED__
void spawn_10(){
     //first let's kill all the old enemies.
     for(int npckiller = 0;npckiller!=32;npckiller++){
     npc[npckiller].hp = 0;
     npc[npckiller].x = -1;
     npc[npckiller].y = -1;        
     }
     npc[0].create(101); 
     npc[0].x = 22;
     npc[0].y = 12;
     
     for(int playa = 0;playa != 4; playa++){
     if(pl[playa].hp > 0){
     
     npc[1+(playa*4)].create(2); //Frontline of rats and gerbuls (2,4)
     npc[1+(playa*4)].x = 11+(playa*2);
     npc[1+(playa*4)].y = 14;
     
     npc[2+(playa*4)].create(4); //and 
     npc[2+(playa*4)].x = 12+(playa*2);
     npc[2+(playa*4)].y = 14;
     
     npc[3+(playa*4)].create(7); //Backline of troll.
     npc[3+(playa*4)].x = 11+(playa*2);
     npc[3+(playa*4)].y = 12;
     
     npc[4+(playa*4)].create(7); 
     npc[4+(playa*4)].x = 12+(playa*2);
     npc[4+(playa*4)].y = 12;
     
     }
     }//spawn his trolls.
     
     }
     

void spawn_enemies(){
     int points = 0;
     for(int playa = 0;playa != 4;playa++){
     if(pl[playa].state == 3){
     points = points + 100;//arbitrary!
     }                        
     }        
     //Now, we have some points to spend. 
     //first let's kill all the old enemies.
     for(int npckiller = 0;npckiller!=32;npckiller++){
     npc[npckiller].hp = 0;
     npc[npckiller].x = -1;
     npc[npckiller].y = -1;        
     }
     int numberer = 0;
     while (points > 0){
     points--;
     /*
     get_all_inputs();
     playerinput[0].none = false;
     while(!playerinput[0].none){
     get_all_inputs();
     clear(buffer);
     draw_text(0,0,points,9001);
     v_draw_buffer();
     } 
     */
     
     if(!(rand () % (1+((abs(map.floor-1))*(abs(map.floor-1))*(abs(map.floor-1)))))&& (points  > (20/map.floor))){// 100% frequencty on floor 3.
     npc[numberer].create(1);      
     points = points - (20/map.floor);
     numberer++;
     }//4 @ 2 = 8; quota 9.
     
     
     if(!(rand () % (1+((abs(map.floor-3))*(abs(map.floor-3))*(abs(map.floor-3)))))&& (points  > (40/map.floor))){// 100% frequencty on floor 3.
     npc[numberer].create(2);      
     points = points - (40/map.floor);//
     numberer++;
     }//10(ish) @ 3 = 30; quota 25;
     
     if(!(rand () % (1+((abs(map.floor-4))*(abs(map.floor-4))*(abs(map.floor-4)))))&& (points  > (50/map.floor))){// 100% frequencty on floor 4
     npc[numberer].create(3);      
     points = points - (50/map.floor);
     numberer++;
     }//10(ish) @ 4 = 40; quota 36;
     
     if(!(rand () % (1+((abs(map.floor-5))*(abs(map.floor-5))*(abs(map.floor-5)))))&& (points  > (100/map.floor))){// 100% frequencty on floor 4
     npc[numberer].create(6);      
     points = points - (100/map.floor);
     numberer++;
     }//4 @ 10 = 40; quota 49;
     
     if(!(rand () % (1+((abs(map.floor-7))*(abs(map.floor-7))*(abs(map.floor-7)))))&& (points  > (200/map.floor))){// 100% frequencty on floor 7.
     npc[numberer].create(4);      
     points = points - (200/map.floor);
     numberer++;
     }//3 @ 25 = 81;
     
     if(!(rand () % (4+((abs(map.floor-9))*(abs(map.floor-9))*(abs(map.floor-9)))))&& (points  > (20))){// 100% frequencty on floor 4
     npc[numberer].create(7);      
     points = points - 20;
     numberer++;
     }
     
     if(!(rand () % (1+((abs(map.floor-9))*(abs(map.floor-9))*(abs(map.floor-9)))))&& (points  > (300/map.floor))){// 100% frequencty on floor 7.
     npc[numberer].create(5);      
     points = points - (300/map.floor);
     numberer++;
     }//3 @ 35 121 quota
     
     
     
      
     }//endof while
      
     }
     
void spawn_items(){     
    clear_dropped_items();
    // 1, 2 ,or 3 loops
    
     for(int loops = 1+(rand() % 3); loops != 0; loops--){         
     for(int playa = 0;playa != 4;playa++){
     if(pl[playa].state == 3){
                        
     if(!(rand () % 3)){item[unused_item_slot()].gen(1001);}
     //50% chance to drop band-aid. 

     if(!(rand () % (1+(4*(abs(map.floor-1)))))){// 100% frequency on floor 1, 25,12,7...
     item[unused_item_slot()].gen(1);//Stick. Generated on floor 1. @ 100 %. cost: 10 pointz 
     }
     
     if(!(rand () % (10+(5*(abs(map.floor-3)))))){// 10% frequency on floor 3. Quick Decay.
     item[unused_item_slot()].gen(2); //Club. The rarer version of a stick. Floor 2, but somewhat rare. 
                                      //Does not prevent other sticks from spawning in, players need a base weapon
     }
      
     if(!(rand () % (2+(3*(abs(map.floor-5)))))){// 50% frequency on floor 5. SLOW Decay.
     item[unused_item_slot()].gen(3); //Step up from a stick. Good stuff.
      }
      
     if(!(rand () % (20+(2*(abs(map.floor-6)))))){// 5% frequency on floor 6. SLOW Decay.
     item[unused_item_slot()].gen(4); //Rare weapon with very slow decay.
      }
      
     if(!(rand () % (20+(2*(abs(map.floor-4)))))){// 5% frequency on floor 4. SLOW Decay.
     item[unused_item_slot()].gen(5); //Fork: Identical to the knife on a smaller scale.
      }
      
      if(!(rand () % (2+(2*(abs(map.floor-8)))))){// 50% frequency on floor 8. then slow decay.
     item[unused_item_slot()].gen(6); //Machete.
      }
      
         if(!(rand () % (10+(6*(abs(map.floor-9)))))){// 10% frequency on floor 9. EXTREME Decay.
     item[unused_item_slot()].gen(7); //Gladius: A C_C_Crazy weapon.
      }
     
     }//For                        
     }//IfALive
     }//loops   
      
     }//end_of_func();
     
     
     
     
#endif
