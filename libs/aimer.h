#ifndef AIMER_H_INCLUDED__ 
#define AIMER_H_INCLUDED__ 
bool canranged(int playa){
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
        
        
        
        if(!checkempty(x+xadd,y+yadd)){
        tdist = -1;break;
        }//see if we hit a wall. Break if we do.
        }//for each step
        }else{//if delta Y
        
        if(deltay > 0){
        for(int yplus = 0; yplus != deltay;yplus++)
        {
                 
    
        
        if(!checkempty(x,y+yplus)){
        tdist = -1;break;
                }
                }
                }//endof if vertical pos
        if(deltay < 0){
        for(int yplus = 0; yplus != deltay;yplus--)
        {
        //Go all vertical mode
        
        
        if(!checkempty(x,y+yplus)){
        tdist = -1;break;
                }
                }
                }//endof if vertical pos
        
        }//end_of_if y
        
        
        if(tdist == -1 || !checkempty(pl[playa].sel[0],pl[playa].sel[1])  ){
         return 0;
        }else{return 1;}
        
}

void aimer(int playa){
     //FIRST THING: GET LATEST INPUTS
     if(playerinput[playa].nu){pl[playa].sel[1]--;};
     if(playerinput[playa].nd){pl[playa].sel[1]++;};
     if(playerinput[playa].nl){pl[playa].sel[0]--;};
     if(playerinput[playa].nr){pl[playa].sel[0]++;};
     if(playerinput[playa].ntwo){pl[playa].aimmode = false;};
     if(playerinput[playa].none && canranged(playa)){
     //Let's hit someone!
     pl[playa].aimmode = false;
     pl[playa].turn_over = true;
     
     }
        

            
     
     
     }
#endif
