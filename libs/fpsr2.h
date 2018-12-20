#ifndef FPSR2_H_INCLUDED__ 
#define FPSR2_H_INCLUDED__ 


#define updates_per_second 20
class letimer{
      public:
      sem_t sem_rest;
      volatile int ticks;
      volatile int timer;
      int ctr;
      int loopctr;
      int old_ticks;
      void ticker();
      void timeticker();
      
      

}; 
letimer cycler;

void ticker()
{
	sem_post(&cycler.sem_rest);//unlock the semaphore, and allow the game loop to continue
	cycler.ticks++;
}
END_OF_FUNCTION(ticker)

void timeticker()
{
	cycler.timer++;
}
END_OF_FUNCTION(timeticker)

void init_ticker(){// sets up the game loop ticker.	
	sem_init(&cycler.sem_rest, 0, 1);
 	 
	LOCK_VARIABLE(ticks);// Hit the ticker every frame.
	LOCK_FUNCTION(ticker);
	install_int_ex(ticker, BPS_TO_TIMER(updates_per_second));

	LOCK_VARIABLE(timer);// Hit the lag ticker every second.
	LOCK_FUNCTION(timeticker);
	install_int_ex(timeticker, BPS_TO_TIMER(updates_per_second));

}

#endif
