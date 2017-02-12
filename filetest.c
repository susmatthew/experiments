#define _POSIX_C_SOURCE 200809L

#include "/usr/include/stdio.h"



int main (int argc,char *argv[])
{
char path[1024];

FILE *fp = popen ("ls -al", "r");

while (fgets(path, 200, fp) != NULL)
	printf("%s", path);
}
