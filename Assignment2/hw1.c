#include <stdio.h>
#include "hw1.h"

/* To print the string */
void printmystr(char *arr, int length);

void printmystr(char *arr, int length)
{
 for(int i = 0; i<length; i++)
 {
  if (arr[i] == '\n')
  printf("\\n"); // adding an escape char
  else if (arr[i] == '\t')
  printf("\\t");  //adding an escape char
  else if (arr[i] == '\0')
  printf("\\0");  // adding an escape char
  else
  printf("%c",arr[i]);
}
printf("\n");
}

/*To REverse the string*/
char reverse_string(char * str, int length)
{
 if (length > 0)
 {
 char * ptr;
 char temp;
 ptr = str;
 ptr += length -1;
  for(int i=0; i<length/2; i++)
  {
  temp = *str;
  *str = *ptr;
  *ptr = temp;
  str++;
  ptr--;
  }
 return 0;
 }
 else
 {
 return 1;
 }
}


