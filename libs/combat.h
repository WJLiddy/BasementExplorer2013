#ifndef COMBAT_H_INCLUDED__ 
#define COMBAT_H_INCLUDED__

void do_combat(int p_id, int e_id){
     int dmg;
     if(pl[p_id].inv[pl[p_id].eqd] == -1){
     play_fx(3);
     //He's unarmed! give a 75% chance to hit based on STR and DEX
     if(rand() % 4){
     //do unarmed combat. 
     
     if(npc[e_id].de <  rand() % 100 + 1){//Monster did not dodge!
      
     dmg = (pl[p_id].st/4+1+rand()%( pl[p_id].de/2));
      pl[p_id].tickets = pl[p_id].tickets + 1; //dbl tickets for Punching! cause why not!
     npc[e_id].hp = npc[e_id].hp-dmg;
     append_msg(7,pl[p_id].name,npc[e_id].name);
     
     char buf[6];
      itoa (dmg, buf,10 );
      append_msg(9,npc[e_id].name,buf);
     
     
    if(npc[e_id].hp < 1){
    append_msg(8,pl[p_id].name,npc[e_id].name);
     npc[e_id].x = -2;
    }//Enemy died.
    //TODO: Give EXP.
    


}else{
       append_msg(11,npc[e_id].name,pl[p_id].name);//dodge'd
      }
      

    
     }else{// Pl hit with an unarmed if
     
     //do nothing! You missed loser! Ha!
append_msg(6,pl[p_id].name,npc[e_id].name);
     
}


     }else{
     
     //Make a cool FX! fix this later!
 int its = item[pl[p_id].inv[pl[p_id].eqd]].type;
     if(its == 1 || its == 2 || its == 3){//Stick, Club, Rake
            play_fx(3);
            }
     if(its == 4 || its == 5|| its == 6 || its == 7){//Knife, Fork, Gladius, Machete.
            play_fx(4);
            }
           
           
     //first, calc the attacking player's chance to hit.
     if(rand() % 100 + 1 < itemacc(pl[p_id].inv[pl[p_id].eqd],pl[p_id].st,pl[p_id].de)){
     //It was a hit.
     ///See if the monster can dodge it
      if(npc[e_id].de <  rand() % 100 + 1){//Monster did not dodge!
     //Roll the dice for damage.//Const plus rand [0] + [1]
    dmg = item[pl[p_id].inv[pl[p_id].eqd]].var[0]+1+(rand() % item[pl[p_id].inv[pl[p_id].eqd]].var[1]);
    npc[e_id].hp =  npc[e_id].hp-dmg;
     
      append_msg(7,pl[p_id].name,npc[e_id].name);
      //damage converter
      char buf[6];
      itoa (dmg, buf,10 );
      append_msg(9,npc[e_id].name,buf);
     
      
    if(npc[e_id].hp < 1){
    append_msg(8,pl[p_id].name,npc[e_id].name);
    npc[e_id].x = -2;
    //give out tickets!
    switch(npc[e_id].type){
    case 1:
    pl[p_id].tickets = pl[p_id].tickets + 2;
    break;
    case 2:
    pl[p_id].tickets = pl[p_id].tickets + 3;
    break;
    case 3:
    pl[p_id].tickets = pl[p_id].tickets + 4 + rand() % 2;//(5)
    break;
    case 4:
    pl[p_id].tickets = pl[p_id].tickets + 22 + rand() % 4;//(25)
    break;
    case 5:
    pl[p_id].tickets = pl[p_id].tickets + 31 + rand() % 5;//(35)
    break;
    case 6:
    pl[p_id].tickets = pl[p_id].tickets + 8 + rand() % 3;//(10)
    break;
    case 7:
    if(pl[p_id].tickets > 0){
    pl[p_id].tickets = pl[p_id].tickets - 1;
    }
    break;
    case 101:
    pl[p_id].tickets = pl[p_id].tickets + 1;
    break;
    }
}


}else{
       append_msg(11,npc[e_id].name,pl[p_id].name);//dodge'd
      }
      
     }else{
     //it was a melee miss.
     append_msg(6,pl[p_id].name,npc[e_id].name);
     }//endofmiss
     
     }//end of armed attack
     }//endoffunc
     
     

void do_e_combat(int e_id, int p_id){
     
       int thits = 0;

       
       
     int dmg;
     
     switch(npc[e_id].weap){
     case 1:
     //*Bite*
     dmg = (npc[e_id].st) + (rand() % 3);

         
     if(90 > rand() % 100 + 1){// We have the chance to hit!
     if(pl[p_id].de <  rand() % 100 + 1){//no dodge
     pl[p_id].hp = pl[p_id].hp - dmg;
     play_fx(1);
     char buf[6];
     itoa (dmg, buf,10 );
     append_msg(10,npc[e_id].name,pl[p_id].name);// x bites y!
     append_msg(9,pl[p_id].name,buf);// y took X damg!
     }else{
     append_msg(11,pl[p_id].name,npc[e_id].name);//dodge'd
     }
     }else{
     append_msg(6,npc[e_id].name,pl[p_id].name);// missed  
     }
     
     break;

  case 2:
     //*Peck*
     play_fx(5);
     
     for(int nhits = (rand() % 4) + 1; nhits != 0; nhits--){
     dmg = (npc[e_id].st/3) + (rand() % 4);
     
     if(75 > rand() % 100 + 1){// We have the chance to hit!
     if(pl[p_id].de <  rand() % 100 + 1){
     pl[p_id].hp = pl[p_id].hp - dmg;
     thits++;
     char buf[6];
     itoa (dmg, buf,10 );
     append_msg(15,npc[e_id].name,pl[p_id].name);// x bites y!
     append_msg(9,pl[p_id].name,buf);// y took X damg!
     }else{
     append_msg(11,pl[p_id].name,npc[e_id].name);//dodge'd
     }
     }else{
     append_msg(6,npc[e_id].name,pl[p_id].name);// missed  
     }
     }
     
     char buf[6];
     itoa (thits, buf,10 );
     append_msg(16,buf,NULL);// missed  
     break;
     
  
  case 3:
     //*Troll attack!*
     thits = rand () % 4;
     if(thits){
     //Pasta attack. Does nothing.
     append_msg(18,npc[e_id].name,NULL);// missed  
     append_msg(19,NULL,NULL);// missed   
     }
     if(!thits){
     //Magnet attack! You can't dodge it but it can be resisted
     append_msg(20,npc[e_id].name,NULL);
     dmg = (rand() % 33) - (pl[p_id].in*3);
     if(dmg < 1){dmg = 1;}
     pl[p_id].is_confused = pl[p_id].is_confused + dmg;
     append_msg(21,pl[p_id].name,NULL);
     }
     break;
     
     
     case 101:
      //*Moot's weapon, the banhamr
     dmg = 22 + rand() % 16 - (pl[p_id].in)*4;
     if (dmg < 0){dmg = rand()% 3;}
         
     if(62 > rand() % 100 + 1){// We have the chance to hit!
     if(pl[p_id].de <  rand() % 100 + 1){
     pl[p_id].hp = pl[p_id].hp - dmg;
     char buf[6];
     itoa (dmg, buf,10);
     append_msg(14,npc[e_id].name,pl[p_id].name);// x banned y!
     append_msg(13,pl[p_id].name,buf);// y took X emotional damg!
     }else{
     append_msg(11,pl[p_id].name,npc[e_id].name);//dodge'd
     }
     }else{
     append_msg(6,npc[e_id].name,pl[p_id].name);// missed  
     }
     break;
     }
     
     
 if(pl[p_id].hp < 1){
    append_msg(8,npc[e_id].name,pl[p_id].name);
    pl[p_id].x = -1;
    pl[p_id].color = 2;
   strcpy(pl[p_id].name,"+DEAD+");
    pl[p_id].state = 0;
    for(int itokill = 0; itokill != 7;itokill++){
    item[pl[p_id].inv[itokill]].x = -1;
    pl[p_id].inv[itokill] = -1;
    }
    }     
     
}
#endif
