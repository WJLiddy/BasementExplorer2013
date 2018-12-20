#ifndef CAMERA_H_INCLUDED__ 
#define CAMERA_H_INCLUDED__ 

// POINTERS!!!
class camera{
      public:
      int x,y,mode;
      int camoffx,camoffy;//camera offset.
      //mode 1: follow mainchar.
      //mode 2: combat.
      void follow(int*, int*, int, int);
      };
      
      void camera::follow(int *targx, int *targy, int xadd, int yadd){
           x= *targx + xadd;
           y= *targy + yadd;
           x=*targx+(800/2);
           y=*targy+(600/2);
           camoffx = 400-*targx;
           camoffy = 300-*targy;
           }
   
           
                
               camera cam;  
#endif
