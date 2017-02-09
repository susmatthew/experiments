// demo.c
// 12.17.16 - getting into ncurses

#include <ncurses.h>
#include <unistd.h>
#include <stdint.h>
#include <time.h>

int main (int argc, char *argv[]) {
	
	uint8_t maxx = 0,maxy = 0,x=1,y=1;
	uint16_t time = 0;
	clock_t curr_time;

	initscr();
	noecho();
	curs_set(FALSE);
	clear();
	
	while (1) {

		getmaxyx (stdscr,maxy,maxx);
		curr_time=clock();
		time = curr_time/(CLOCKS_PER_SEC/100);
		if ((time%1000)==0) clear();
		mvprintw(((time/100)%32),x,"x:%i, y:%i",maxx,maxy);
		mvprintw(y+1,x,"time:%u",time);
		refresh();
	}
	
	endwin();

	return 0;	
}
