#ifndef INIT_H_INCLUDED__ 
#define INIT_H_INCLUDED__
int npcturnno = -1;
bool quittomain;
#define GAME_W 400
#define GAME_H 300
BITMAP *buffer; 
   GFX_MODE_LIST all_gfx_modes;
void init() {
	allegro_init();
 srand (time(NULL));
	set_color_depth(16);
	int deskW,deskH;
    get_desktop_resolution(&deskW, &deskH);
    set_gfx_mode(GFX_AUTODETECT, deskW, deskH, 0, 0);
    install_sound(DIGI_AUTODETECT, MIDI_NONE,0);
	install_timer();
	install_keyboard();
	install_mouse();
	buffer=create_bitmap(GAME_W,GAME_H);
    load_sound();
}



void deinit() {
	clear_keybuf();
	/* add other deinitializations here */
}
#endif
