// demo.c
// 12.17.16 - getting into ncurses

#include <ncurses.h>
#include <unistd.h>
#include <stdint.h>

int main (int argc, char *argv[]) {
	
	uint8_t maxx = 0,maxy = 0,x=1,y=1;

	initscr();
	noecho();
	curs_set(FALSE);
	clear();
	
	while (1) {
	
	getmaxyx (stdscr,maxy,maxx);
	
	mvprintw(x,y,"x:%i, y:%i",maxx,maxy);
	refresh();
	}
	
	endwin();

	return 0;	
}
