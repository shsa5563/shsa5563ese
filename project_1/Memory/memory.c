#include <stdio.h>
#include "memory.h"
#include <stdint.h>

//function to make the memory zero for the given source and destination parameters 
int8_t  my_memmove(uint8_t *source,uint8_t *destination,uint32_t length)
{
        int i = 0;
        uint8_t *src = (uint8_t *)source;
        uint8_t *dest = (uint8_t *)destination;
        if(src == dest) {
        printf("Same string, same address\n");
        }
	else if(dest<src)
        {
		for( i = 0; i < length; i++)
		{
		        *(dest + i) = *(src + i);
		}
	printf("dest is %p\n",dest);
        }
	else
	{
		for(i=length-1;i>=0;i--)
		 *(dest + i) = *(src + i);
		printf("dest is %p\n",dest);
	}
return 0;
}

//function to make the memory zero from the given source upto the specified length of memory.
int8_t my_memzero(uint8_t *src, uint32_t length)
{
        uint8_t *s;
        s=src;
        uint8_t *end=s+length;

        while(s!=end)
        {
                *s=0;
                s++;
        }

return 0;
}

// function to reverse the pointers 
int8_t my_reverse(uint8_t *str, int32_t length)
{
	int start=0, end=length-1;
    char *s;
	char temp;
	s=(char*)str;
	while(start<end)
    {
        temp = *(s+start);
        *(s+start) = *(s+end);
        *(s+end) = temp;
	start++;
	end--;
    }
return *str;
}


