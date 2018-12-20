#ifndef NARRATOR_H__ 
#define NARRATOR_H__
char msg[32][36];// A List of messages.
int msg_timer[32];
void append_msg(int msg_type, char *f_1, char *f_2){
     // find an empy spot in the queue for that message.
     int openmsg = 31;
     for(int looker = 0; looker != 10; looker++){
     if (!msg[looker][0]){//open messgae!
     openmsg = looker;
     break;
     }
     }//endof for.
     
     
     switch (msg_type){
     case 0:msg_timer[openmsg] = 20;strcpy (msg[openmsg],f_1);break;
     case 1:msg_timer[openmsg] = 50;strcpy (msg[openmsg],"You have encountered Moot, the administrator!");break;
     case 2:msg_timer[openmsg] = 50;strcpy (msg[openmsg],"Moot: GTFO my forums u troll! omg!");break;
     case 3:msg_timer[openmsg] = 20;strcpy (msg[openmsg],"Moot banned a troll from the interwebs.");break;
     case 4:msg_timer[openmsg] = 20;strcpy (msg[openmsg],f_1);break;
     case 5:msg_timer[openmsg] = 20;strcpy (msg[openmsg],f_1);strcpy (msg[openmsg]+strlen(f_1)," picked up a ");strcpy (msg[openmsg]+strlen(f_1)+13,f_2);break;
     case 6:msg_timer[openmsg] = 20;strcpy (msg[openmsg],f_1);strcpy (msg[openmsg]+strlen(f_1)," missed ");strcpy (msg[openmsg]+strlen(f_1)+8,f_2);break;
     case 7:msg_timer[openmsg] = 20;strcpy (msg[openmsg],f_1);strcpy (msg[openmsg]+strlen(f_1)," hit ");strcpy (msg[openmsg]+strlen(f_1)+5,f_2);break;
     case 8:msg_timer[openmsg] = 20;strcpy (msg[openmsg],f_1);strcpy (msg[openmsg]+strlen(f_1)," defeated ");strcpy (msg[openmsg]+strlen(f_1)+10,f_2);break;
     case 9:msg_timer[openmsg] = 20;strcpy (msg[openmsg],f_1);strcpy (msg[openmsg]+strlen(f_1)," took ");strcpy (msg[openmsg]+strlen(f_1)+6,f_2);strcpy (msg[openmsg]+strlen(f_1)+6+strlen(f_2)," damage!");break;
     case 10:msg_timer[openmsg] = 20;strcpy (msg[openmsg],f_1);strcpy (msg[openmsg]+strlen(f_1)," bites ");strcpy (msg[openmsg]+strlen(f_1)+7,f_2);break;     
     case 11:msg_timer[openmsg] = 20;strcpy (msg[openmsg],f_1);strcpy (msg[openmsg]+strlen(f_1)," dodged ");strcpy (msg[openmsg]+strlen(f_1)+8,f_2);strcpy (msg[openmsg]+strlen(f_1)+8+strlen(f_2),"'s attack.");break;
     case 12:msg_timer[openmsg] = 20;strcpy (msg[openmsg],f_1);strcpy (msg[openmsg]+strlen(f_1)," recovered ");strcpy (msg[openmsg]+strlen(f_1)+11,f_2);strcpy (msg[openmsg]+strlen(f_1)+11+strlen(f_2)," HP.");break;
     case 13:msg_timer[openmsg] = 30;strcpy (msg[openmsg],f_1);strcpy (msg[openmsg]+strlen(f_1)," took ");strcpy (msg[openmsg]+strlen(f_1)+6,f_2);strcpy (msg[openmsg]+strlen(f_1)+6+strlen(f_2)," emotional damage!");break;
     case 14:msg_timer[openmsg] = 30;strcpy (msg[openmsg],f_1);strcpy (msg[openmsg]+strlen(f_1)," deleted ");strcpy (msg[openmsg]+strlen(f_1)+9,f_2);strcpy (msg[openmsg]+strlen(f_1)+9+strlen(f_2),"'s comment.");break;         
     case 15:msg_timer[openmsg] = 20;strcpy (msg[openmsg],f_1);strcpy (msg[openmsg]+strlen(f_1)," pecked ");strcpy (msg[openmsg]+strlen(f_1)+8,f_2);break;         
     case 16:msg_timer[openmsg] = 20;strcpy (msg[openmsg],"Hit ");strcpy (msg[openmsg]+4,f_1);strcpy (msg[openmsg]+strlen(f_1)+4," Time(s)!");break;         
     case 17:msg_timer[openmsg] = 30;strcpy (msg[openmsg],f_1);strcpy (msg[openmsg]+strlen(f_1)," snapped out of confusion! ");break;
     case 18:msg_timer[openmsg] = 20;strcpy (msg[openmsg],f_1);strcpy (msg[openmsg]+strlen(f_1)," recites a pasta!");break;// To player X
     case 19:msg_timer[openmsg] = 25;strcpy (msg[openmsg],"It's not very convincing...");break;
     case 20:msg_timer[openmsg] = 20;strcpy (msg[openmsg],f_1);strcpy (msg[openmsg]+strlen(f_1)," used magnet attack!");break;// on player X
     case 21:msg_timer[openmsg] = 20;strcpy (msg[openmsg],f_1);strcpy (msg[openmsg]+strlen(f_1)," became confused!");break;
     }
     }
    
void draw_narrator_text(){
for(int all_msg = 0;all_msg!=32;all_msg++){
if(msg_timer[all_msg]){
textout_centre_ex(buffer, font,msg[all_msg],200,290,makecol(255, 255, 255), makecol(0, 0, 0));
msg_timer[all_msg]--;
break;
}//If There is time left
}//For each message.
}//endoffunc

bool is_narrator_talk(){
for(int all_msg=0;all_msg!=32;all_msg++){
if(msg_timer[all_msg]){
return 1;
}
}
return 0;
}

void clear_narrator_buf(){
for(int all_msg=0;all_msg!=32;all_msg++){
msg[all_msg][0] = 0;
msg_timer[all_msg] = 0;
}
}


#endif
