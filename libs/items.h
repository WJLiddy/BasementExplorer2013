#ifndef ITEMS_H_INCLUDED__ 
#define ITEMS_H_INCLUDED__
class item_t{
      public:
      bool floor;
      int x;//x co0rd
      int y;//y co0rd
      int type;
      int var[4];
      char name[7];
      void gen(int);
      //For Type = 0 (not-item)
      /*
      //For Type = 1 (Melee Weapon)
      
      var0 Damage Constant
      var1 Damage Rand
      var2 Str Lvl Reqw
      var3 Dex Req 
      
      */
      
};item_t item[256];

        void item_t::gen(int itype){
        while(1){//find a valid sopt for the item
        int somex = rand() % 36;
        int somey = rand() % 36;
            if(map.is_floor[somex][somey]){
            x = somex;
            y = somey;
            floor = 1;
            break;
            }
            }// we put an item on the floor!
        type = itype;
        switch (type){
        // A Stick. The God Tier of Weapon. Yay.
        case 1: 
        var[0] = rand () % 2 + 1;//Melee Base 1-2
        var[1] = rand () % 4 + 1;//Melee Rand 1-4    
        //Does anywhere from 2-4 avg damage.
        var[2] = rand () % 8;// STR REQ
        var[3] = rand () % 8;// DEX REQ
        strcpy(name,"Stick");
        break;
        case 2: 
        var[0] = rand () % 5 + 2;//Melee Base 2-6
        var[1] = rand () % 2 + 1;//Melee Rand 1-2    
        var[2] = rand () % 8 + 5;// STR REQ 
        var[3] = 2;// DEX REQ
        strcpy(name,"Club");
        break;
        case 3: 
        var[0] = rand () % 3 + 2;//Melee Base 2-4
        var[1] = rand () % 9 + 4;//Melee Rand 4-8
        var[2] = rand () % 8 + 5;// STR REQ
        var[3] = rand () % 8 + 5;// DEX REQ
        strcpy(name,"Rake");
        break;
        case 4: 
        var[0] = 0;//Melee Base
        var[1] = rand () % 16 + 16;//Melee Rand     
        var[2] = 1;// STR REQ
        var[3] = (var[1]/4) + 9 + (rand()%2)  ;// This weapon's DEX REQ affectes it by up to 4
        strcpy(name,"Knife");
        break;
        
        //A Fork. Like a Knife, but on a smaller scale.
        case 5: 
        var[0] = rand() % 2 + 1;//Melee Base (1-2)
        var[1] = rand () % 11 + 10;//Melee Rand(12-16) +(5-10ss)    
        var[2] = 1;// STR REQ
        var[3] = 9 + rand() % 7;
        strcpy(name,"Fork");
        break;
        
        //Machete. A somewhat normalized weapon. Reqs DEX and STR
        case 6: 
        var[0] = rand() % 5 + 10;//Melee Base (1-2)
        var[1] = rand () % 2 + 1;//Melee Rand(12-16) +(5-10ss)    
        var[2] = 6+rand() % 3;// STR REQ (12 to 15 total skill)
        var[3] = 6+rand() % 3;
        strcpy(name,"Machete");
        break;
        
        //Gladius. High strength weapon with *very* random stats. Rare.
        //Median version is a 25 d 5. best is a 50 d5
        case 7: 
        var[0] = rand() % 50 + 1;//Melee Base (5-)
        var[1] = rand () % 10 + 1;//Melee Rand(12-16) +(5-10ss)    
        var[2] = 4 + rand() % 22;// STR REQ (4 to 21 total skill)
        var[3] = 3;
        strcpy(name,"Gladius");
        break;
        
        case 201://RANGED_AMMO_BASED
        var[0] = rand () % 100 + 2;//BASE DMG
        var[1] = rand () % 5 + 1;//RANDOM ROLLER       
        var[2] = rand () % 7 + 1;//RANGE
        var[3] = rand () % 7 + 1;//ACCURACY
        strcpy(name,"Glack");
        break;
        case 1001:
        var[0] = -1;//????
        var[1] = rand () % 10 + 10;//Base Health Add              
        var[2] = 0;//Intel Multiplyer
        var[3] = 0;//FAid multiplyer
        strcpy(name,"BandAid");
        break;
        }
        }
        
        
        
        
        
      int itemacc(int itemno, int str, int dex){                                                     
      int depen=0;
      int stpen=0;
      if(str < item[itemno].var[2]){
      stpen = (item[itemno].var[2]-str)*(item[itemno].var[2]-str);
      }
      if(dex < item[itemno].var[3]){
      depen = (item[itemno].var[3]-dex)*(item[itemno].var[3]-dex);
      }
      if(100-stpen-depen > 1){
      return (100-stpen-depen);
      }else{return (1);}
      }   
      
      
     bool use_item(int holder,int invslot, bool playa, int targ){
     int itemtype = item[pl[holder].inv[invslot]].type;
     if (itemtype == 1001){
     pl[targ].hp = pl[targ].hp + item[pl[holder].inv[invslot]].var[1];
      char buf[6];
      itoa (item[pl[holder].inv[invslot]].var[1], buf,10 );
     append_msg(12,pl[holder].name,buf);// recovery.
     pl[holder].inv[invslot] = -1;   //lose the item.
     if(pl[targ].hp > pl[targ].max_hp()){
     pl[targ].hp = pl[targ].max_hp();
     }
     return 1;
     
     }// Bandage-type-item.
     
     //Ranged, ammo-based item.
     if(itemtype == 201){//glack.
     pl[holder].aimmode = true;
     pl[holder].sel[0] = pl[holder].x;
     pl[holder].sel[1] = pl[holder].y;
     return 0;
     }
     return 0;
     }
                    
                    int eqdtype(int id){
                         return  item[pl[id].inv[pl[id].eqd]].type;
                         } 
     int unused_item_slot(){
         for(int itemfinder = 0; itemfinder!= 255; itemfinder++){
         if(item[itemfinder].x == -1){
         return itemfinder;
         }
         }
         return -1;
         }
         
     void initalize_item_array(){
     for(int itemfinder = 0; itemfinder!= 255; itemfinder++){
     item[itemfinder].x = -1;
     }
     }
     
     void clear_dropped_items(){
     for(int itemfinder = 0; itemfinder!= 255; itemfinder++){
     if(item[itemfinder].floor){
     item[itemfinder].x = -1;
     }
     }
     }
          
#endif
