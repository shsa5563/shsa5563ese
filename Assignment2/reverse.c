#include <stdio.h>
#include "hw1.h"
#include "hw1.c"

int strlength(char *p);

int main()
{
unsigned char arr[50];
unsigned length;
printf("Please enter the string you want to reverse\n");
gets(arr);
printf("Please enter the length of the array\n");
scanf("%d", &length);
printf("The input string is : %s\n" , arr);
    if (reverse_string(arr, length) == 0)
    {
        printf("The array Reverse was succesful\n");
        printf("The reversed string is : %s \n", arr);
    }
    else
    {
        printf("Sorry,The array Reverse was not succesful\n");
    }

}
