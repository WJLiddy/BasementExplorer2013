#ifndef WINSCREEN_H_INCLUDED__ 
#define WINSCREEN_H_INCLUDED__
bool win_screen(){
     int stage = 0;
     stop_mod();
     play_track(1);
    while (1) { //The exit command.
 sem_wait(&cycler.sem_rest);//wait until a full tick has passed using the semaphore
 while(cycler.ticks > 0)      {cycler.old_ticks = cycler.ticks;

//--------------------------------------------------------------------------------------------  
//This is where all logic goes.
stage++;
if(stage < 100){
 draw_text(20,20,"Congratulations...",makecol(stage*2,stage*2,stage*2));
}
if(stage >= 100 && stage < 200) {
 draw_text(20,20,"Congratulations...",makecol(200,200,200));
 draw_text(40,40,"You beat the demo.",makecol((stage-100)*2,(stage-100)*2,(stage-100)*2));
}
if(stage >= 200 && stage < 300) {
 draw_text(60,60,"Good job, I guess.",makecol((stage-200)*2,(stage-200)*2,(stage-200)*2));
 draw_text(20,20,"Congratulations...",makecol(200,200,200));
 draw_text(40,40,"You beat the demo.",makecol(200,200,200));
}

if(stage >= 350 && stage < 450) {
 draw_text(70,80,"A Game by Neutral Space (c) 2013",makecol(200,200,200));
}

if (stage == 500){return 1;}

//-------------------------------------------------------------------------------------                                                                                                                 


			                                        cycler.ticks--;cycler.loopctr++;
			                                        if(cycler.old_ticks <= cycler.ticks){
				                                    break; 
                                                    }
		                                      }
        //This is where we draw it all.                                                                                              
        v_draw_buffer(); 
        
        cycler.ctr++;// A frame was drawn. Add 1 Frame to the counter.                


	                          }// The User wants to quit to the main menu.
	                          quittomain = 1;
}
#endif
