#ifndef SOUND_H_INCLUDED__ 
#define SOUND_H_INCLUDED__
//Sound variables.
JGMOD *t1;
JGMOD *denter;
JGMOD *denter_boss;
SAMPLE *rod1;
SAMPLE *rod2;
SAMPLE *grab;
SAMPLE *knife;
SAMPLE *blunt;
SAMPLE *peck;

void load_sound(){
     	//Fx
rod1 = load_wav("sound/fx/rodent_1.jsf");
rod2 = load_wav("sound/fx/rodent_2.jsf");
peck = load_wav("sound/fx/peck.jsf");
grab = load_wav("sound/fx/grab.jsf");
knife = load_wav("sound/fx/knife_1.jsf");
blunt = load_wav("sound/fx/blunt.jsf");
	//tracker
	install_mod (7);
    t1 = load_mod ("sound/t1.xm");
    denter = load_mod ("sound/denter.xm");
    denter_boss = load_mod ("sound/denter_boss.xm");
    Sleep(500);
	/* add other initializations here */
}

void play_track(int trackno){
         stop_mod ();
     switch(trackno){
     case 1://Intro Music!
     play_mod (t1,0);
     break;
     case 2:// Entering the Dungeon!
     play_mod (denter,0);// Entering dungeon music! aww yea
     break;
     case 3:
     play_mod (denter_boss,0);// Entering dungeon music! aww yea
     break;
     }
     }
     
void play_fx(int fxno){
     switch(fxno){
     case 1://A rodent sound.
       if(rand() % 2){ 
    play_sample(rod1, 200, 128, 800+ (rand() % 400), 0); 
}else{ play_sample(rod2, 200, 128, 800+ (rand() % 400), 0);} 
break;
      case 2://Picking up an item.
      play_sample(grab, 200, 128,1000, 0); 
      break;
      case 3://A Blunt Weap.
      play_sample(blunt, 200, 128,800+ (rand() % 400), 0); 
      break;
      case 4://A Sharp Weap.      
      play_sample(knife, 200, 128,800+ (rand() % 400), 0); 
      break;
      case 5://A Bird's Peck.      
      play_sample(peck, 200, 128,800+ (rand() % 400), 0); 
      break;
      }
     
     
}
     
     
#endif
