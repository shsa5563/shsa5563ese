#include "data.h"
#include<stdio.h>
#include<stdint.h>

int8_t *my_itoa(int8_t *src, int32_t data, int32_t base)
{
        char *s;	/*assign pointer */
        s=(char*)src;
        int a=0,remainder=0,length=0,temp=0;
        int32_t num = data;
        int start=0,end,pos=1;	/* decide start and end indexes for reverse */

        if(data==0)	/* if data is zero, return zero */
        {
                s[a]=0;
                a++;
        }
        if(data<0 && base==10)	/* if a negative decimal, return a negative number */
        {
                num=-num;
                pos=0;
        }


        while (num!=0)	/* perform decimal to ascii conversion operation */
        {
                remainder = num % base;
                if(remainder>9)
                {
                        s[a]=(remainder-10)+'a'; /* for base 16 data */
                        a++;
                }
                else
                {
                        s[a]=remainder + '0'; /* for conversion to ascii */
                        a++;
                }
                        num=num/base;
                }
        if(pos==0) /* if negative, put a "-" sign */
        {
                s[a]='-';
                a++;
        }


        length=a;
        end=length-1;
        while(start<end) /* reverse */
        {
                temp= *(s+start);
                *(s+start)=*(s+end);
                *(s+end)=temp;
                start++;
                end--;
        }
        s[length]='\0'; /* append null character at the end */

        return src; /* return ascii value to main */
}

int32_t my_atoi(int8_t *src)
{
        int8_t *s;	/* assign pointer */
        s=src;
        int32_t result;
        int a=0,neg=0,sign=0;

        if(s[0]=='-') /* check if value is negative */
        {
                neg=1;
                sign=-1;
                a++;
        }

        for(;s[a]!='\0';a++)	/* convert from ascii to integer */
        {
                result=(result*10)+s[a]-'0';

        }
        if(neg==1) /* if negative, put negative sign */
        {
                result=sign*result;
        }

        return result; /* return integer value to main */
}

void dump_memory(uint8_t *start,uint32_t length)
{
        int8_t *s; /* assign pointer */
        s=start;

        int a=0;

        for(a=0;a<length;a++)	/* calculate length */
        {
                s[a]= 0;
        }

        printf("At memory:\t");	/* print data after memory dump */

        for(a=0;a<length-1;a++)
        {
                printf("0x%02x,\t",s[a]);
        }

        printf("0x%02x\n",s[length-1]);
        printf("\n");
}

uint32_t big_to_little(uint32_t data)
{
        uint32_t result;

        result=((data>>24) & 0xff) | ((data<<8) & 0xff0000) | ((data>>8) & 0xff00) | ((data<<24) & 0xff000000);	/* perfrom conversion */

        return result;	/* return value */
}

uint32_t little_to_big(uint32_t data)
{
        uint32_t result;

        result=((data>>24) & 0x000000ff) | ((data>>8) & 0x0000ff00) | ((data<<8) & 0x00ff0000) | ((data<<24) & 0xff000000); /* perfrom conversion */

        return result;  /* return value */
}
