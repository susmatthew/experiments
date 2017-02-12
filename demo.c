// demo.c
// 12.17.16 - getting into ncurses

#include <ncurses.h>
#include <unistd.h>
#include <stdint.h>
#include <time.h>
#include <linux/input.h>
#include <stdio.h>

uint8_t keys[16];

char* cmd = "grep -E 'Handlers|EV=' /proc/bus/input/devices | \
    grep -B1 'EV=1[02]001[3Ff]' | \
    grep -Eo 'event[0-9]+' ";

int main (int argc, char *argv[]) {
	
	FILE *fp=popen(cmd,"r");
	char buf[1024];

	fgets(buf, 1024, fp);
	
	for (int i=0;i!=6;i++) {
		device[i]=buf[i];		
	}
	fclose(fp);
	
	char *device=strcat ("/dev/input/"+*device);
	FILE *fd = open (device, O_NONBLOCK | O_RDONLY);
	struct input_event ev[64];
	uint16_t rd, size = sizeof (struct input_event);

	uint8_t maxx = 0,maxy = 0,x=1,y=1;
	uint16_t time = 0,kbh = 1;
	clock_t curr_time;
	char c;

	initscr();
	noecho();
	curs_set(FALSE);
	clear();
	nodelay(stdscr,TRUE);
	

	while (1) {

		getmaxyx (stdscr,maxy,maxx);
		curr_time=clock();
		time = curr_time/(CLOCKS_PER_SEC/100);
		if ((time%1000)==0) clear();
		mvprintw(y,x,"x:%i, y:%i",maxx,maxy);
		mvprintw(y,x+15,"time:%u",time);
		mvprintw(y,x+25,"%s",device);
		refresh();

		rd=read (fd, ev, size*64);
		for (i=0;i!=64;i++) {
			
		}

	}	
	endwin();

	return 0;	
}
