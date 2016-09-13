#include <stdio.h>
#include "hw1.h"
#include "hw1.c"

/*Code for REverse string*/

void testcase(int index);
void checkcondn(char *arr);
unsigned int length;

int main()
{
    for (int i = 1; i<7 ; i++)
    {
        testcase(i);
    }
    return 0;
}

/*Test Cases */
void testcase(int i)
{
    if (i== 1)
    {
        unsigned char arr1[9] = {'m','a','l','y','a','l','a','m','\0'};
        length = 8;
        checkcondn(arr1);
    }    else if (i == 2) {
        unsigned char arr2[10]= {'j','a','g','s','o','n','\\','j','b','\0'};
        length = 9;
        checkcondn(arr2);
    }    else if (i==3)
    {   unsigned char arr3[10]=  {'j','a','g','s','o','n','\'','j','b','\0'};
        length = 9;
        checkcondn(arr3);
    }    else if (i ==4) {
        unsigned char arr4[18]= {'T','h','i','s',' ','i','s',' ','a',' ','s','t','r','i','n','g','.','\0'};
        length = 17;
        checkcondn(arr4);
    }    else if (i == 5) {
        unsigned char arr5[19]= {'s','o','m','e',' ','N','U','M','m','b','e','r','s','1','2','3','4','5','\0'};
        length = 18;
        checkcondn(arr5);
    }    else {
        unsigned char arr6[31]= {'D','o','e','s',' ','i','t',' ','r','e','v','e','r','s','e',' ','\n','\0','\t',' ','c','o','r','r','e','c','t','l','y','?','\0'};
        length = 30;
        checkcondn(arr6);
    }
}

/*Print the string before and after the reverse*/

void checkcondn(char *arr)
{
    printf("The input string is :");
    printmystr(arr,length);
    if (reverse_string(arr, length) == 0)
    {
        printf("The array Reverse was succesful\n");
        printf("The reversed string is :");
        printmystr(arr, length);
    }
    else
    {
        printf("Sorry,The array Reverse was not succesful");
    }
}
