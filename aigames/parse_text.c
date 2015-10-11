#include <string.h>
#include <stdio.h>

/*
// parse takes string str 
it modifies array of pointers to char ln
it returns number of pointers necessary for all 
//
*/
int parse(char *str,char *ln[])
{
  const char s[2] = " ";
  int i=0;
   
  /* get the first token */
  ln[i++] = strtok(str, s);
   
  /* walk through other tokens */
  while( ln[i] != NULL ) 
  {
    ln[i++] = strtok(NULL, s);
  }
   
  return(i);
}
