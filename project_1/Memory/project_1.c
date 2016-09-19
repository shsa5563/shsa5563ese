#include "project_1.h"
#include <stdio.h> 
#include <stdint.h> 
#include "memory.h"

void project_1_report() {
  uint8_t array[32];
  uint8_t * aptr_1 = array;
  uint8_t * aptr_2 = (array + 8);
  uint8_t * aptr_3 = (array + 16);
  int i;

  for (i = 0; i < 16; i++) 
  {
  * (aptr_1 + i) = 31 + i;
  }

  if (my_memzero((aptr_3), 16) != 0) 
  {
    printf("Memzero failed\n");
  }
  printf("\n\nPointer locations:\naptr_1=%p\naptr_2=%p\naptr_3=%p", aptr_1, aptr_2, aptr_3);

  printf("\nafter initialization:\n");

  for (i = 0; i < 32; i++) {
    printf("%p\t", * (aptr_1 + i));
  }
  printf("\n Pointer locations:\naptr_1=%p\naptr_2=%p\naptr_3=%p", aptr_1, aptr_2, aptr_3);

  printf("\n\n  Array elements before move and reverse\n\n");

  for (i = 0; i < 32; i++) {
    printf("%p\t", * (aptr_1 + i));
  }
  //condition to check for the memove function 
  if (my_memmove(aptr_1, aptr_3, 8) != 0) {
    printf("Memmove failed\n");
  }
  
  if (my_memmove(aptr_2, aptr_1, 16) != 0) {
    printf("Memmove function failed\n");
  }

  my_reverse(aptr_1, 32); //reverse the values 

  printf("\n\n Pointer locations:\naptr_1=%p\naptr_2=%p\naptr_3=%p", aptr_1, aptr_2, aptr_3);

  printf("\n Reversing entire 32 on aptr_1\n");
  for (i = 0; i < 32; i++) {
    printf("%p\t", * (aptr_1 + i));
  }
  printf("\n");
}
