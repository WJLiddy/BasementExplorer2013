#ifndef INPUT_H_INCLUDED__ 
#define INPUT_H_INCLUDED__ 
class input_getter{
      public:      
      bool left,right,up,down,one,two,three;
      bool nl,nr,nu,nd,none,ntwo,nthree;
      bool check_inputs();
      int joy_id;
      int smartphone;
     bool using_keyboard;
      };input_getter playerinput[4];

      bool input_getter::check_inputs(){
        nl = false;
        nr = false;
        nu = false;
        nd = false;
        none = false;
        ntwo = false;
        nthree = false;
 // THE NEWPRESS MIST BE CLEARED TO PREVENT SEVERAL OF THEM
        if(using_keyboard){
        if(left == false && key[KEY_A]){nl = true;}
        if(right == false && key[KEY_D]){nr = true;}
        if(down == false && key[KEY_S]){nd = true;}
        if(up == false && key[KEY_W]){nu = true;}
        if(one == false && key[KEY_ENTER]){none = true;}
        if(two == false && key[KEY_L]){ntwo = true;}
        // A NEWPRESS HAPPENS
        left = key[KEY_A];
        right = key[KEY_D];
        down = key[KEY_S];
        up = key[KEY_W];
        one = key[KEY_ENTER];
        two = key[KEY_L];
        }
        if(joy_id > -1){  
        poll_joystick();
        if(left == false && joy[joy_id].stick[0].axis[0].d1){nl = true;}
        if(right == false && joy[joy_id].stick[0].axis[0].d2){nr = true;}
        if(down == false && joy[joy_id].stick[0].axis[1].d2){nd = true;}
        if(up == false && joy[joy_id].stick[0].axis[1].d1){nu = true;}
        if(one == false && joy[joy_id].button[0].b){none = true;}
        if(two == false && joy[joy_id].button[1].b){ntwo = true;}
        // A NEWPRESS HAPPENS
        left =joy[joy_id].stick[0].axis[0].d1;
        right =joy[joy_id].stick[0].axis[0].d2;
        down =joy[joy_id].stick[0].axis[1].d2;
        up =joy[joy_id].stick[0].axis[1].d1;
        one = joy[joy_id].button[0].b;
        two = joy[joy_id].button[1].b;
        // see what's pressed
        }
        if(smartphone == 0){
        if(left == false && key[KEY_C]){nl = true;}
        if(right == false && key[KEY_D]){nr = true;}
        if(down == false && key[KEY_B]){nd = true;}
        if(up == false && key[KEY_A]){nu = true;}
        if(one == false && key[KEY_E]){none = true;}
        if(two == false && key[KEY_F]){ntwo = true;}
        // A NEWPRESS HAPPENS
        left = key[KEY_C];
        right = key[KEY_D];
        down = key[KEY_B];
        up = key[KEY_A];
        one = key[KEY_E];
        two = key[KEY_F];
        }
          if(smartphone == 1){
        if(left == false && key[KEY_J]){nl = true;}
        if(right == false && key[KEY_K]){nr = true;}
        if(down == false && key[KEY_I]){nd = true;}
        if(up == false && key[KEY_H]){nu = true;}
        if(one == false && key[KEY_L]){none = true;}
        if(two == false && key[KEY_M]){ntwo = true;}
        // A NEWPRESS HAPPENS
        left = key[KEY_J];
        right = key[KEY_K];
        down = key[KEY_I];
        up = key[KEY_H];
        one = key[KEY_L];
        two = key[KEY_M];
        }
          if(smartphone == 2){
        if(left == false && key[KEY_Q]){nl = true;}
        if(right == false && key[KEY_R]){nr = true;}
        if(down == false && key[KEY_P]){nd = true;}
        if(up == false && key[KEY_O]){nu = true;}
        if(one == false && key[KEY_S]){none = true;}
        if(two == false && key[KEY_T]){ntwo = true;}
        // A NEWPRESS HAPPENS
        left = key[KEY_Q];
        right = key[KEY_R];
        down = key[KEY_P];
        up = key[KEY_O];
        one = key[KEY_S];
        two = key[KEY_T];
        }
          if(smartphone == 3){
        if(left == false && key[KEY_3]){nl = true;}
        if(right == false && key[KEY_4]){nr = true;}
        if(down == false && key[KEY_2]){nd = true;}
        if(up == false && key[KEY_1]){nu = true;}
        if(one == false && key[KEY_5]){none = true;}
        if(two == false && key[KEY_6]){ntwo = true;}
        // A NEWPRESS HAPPENS
        left = key[KEY_3];
        right = key[KEY_4];
        down = key[KEY_2];
        up = key[KEY_1];
        one = key[KEY_5];
        two = key[KEY_6];
        }
        
        // done. This is some nice code.
        };
        
void setup_joysticks(){
   install_joystick(JOY_TYPE_AUTODETECT);
   calibrate_joystick(0);
   calibrate_joystick(1);
   calibrate_joystick(2);
   calibrate_joystick(3);
   playerinput[0].using_keyboard = 1;
   playerinput[0].joy_id = -1;
   playerinput[1].joy_id = -1;
   playerinput[2].joy_id = -1;
   playerinput[3].joy_id = -1;
   playerinput[0].smartphone = -1;
   playerinput[1].smartphone = -1;
   playerinput[2].smartphone = -1;
   playerinput[3].smartphone = -1;
   //Use only joysticks if we have 'em, otherwise keyboard it.
   

}

void get_all_inputs(){
playerinput[0].check_inputs();
playerinput[1].check_inputs();
playerinput[2].check_inputs();
playerinput[3].check_inputs(); 
}
   
  
#endif
