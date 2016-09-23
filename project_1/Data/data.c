#include "data.h"
#include<stdio.h>
#include<stdint.h>

int8_t *my_itoa(int8_t *src, int32_t data, int32_t base)
{
        char *st;
        st=(char*)src;
        int a=0,remainder=0;
        int32_t num = data;
        int begin=0,end,j=1;
        int length=0,temp=0;

        if(data==0)
	 {
                st[a]=0;
                a++;
        }
        if(data<0 && base==10)	/* check for negative number */
        {
                num=-num;
                j=0;
        }


        while (num!=0)	/* decimal to ascii */
        {
                remainder = num % base;
                if(remainder>9)
                {
                        st[a]=(remainder-10)+'a'; /* for base 16 data */
                        a++;
                }
                else
                {
                        st[a]=remainder + '0'; /* for conversion to ascii */
                        a++;
                }
                        num=num/base;
                }
        if(j==0) /* if negative, put a "-" sign */
        {
                st[a]='-';
                a++;
        }


        length=a;
        end=length-1;
        while(begin<end) /* reverse */
        {
                temp= *(st+begin);
                *(st+begin)=*(st+end);
                *(st+end)=temp;
                begin++;
                end--;
        }
        st[length]='\0'; /* null character end */

        return src; /* return ascii */
}

int32_t my_atoi(int8_t *src)
{
        int8_t *p;
        int32_t ascii;
		p=src;
        int a,negative=0,sign=0;

        if(p[0]=='-')
        {
                negative=1;
                sign=-1;
                a++;
        }

        for(a=0;p[a]!='\0';a++)	/* convert from ascii to integer */
        {
                ascii=(ascii*10)+p[a]-'0';

        }
        if(negative==1) /* if negative, put negative sign */
        {
                ascii=sign*ascii;
        }

        return ascii; /* return integer value to main */
}

void dump_memory(uint8_t *start,uint32_t length)
{
        int8_t *st;
        st=start;

        int a=0;

        for(a=0;a<length;a++)
        {
                st[a]= 0;
        }

        printf("At memory:\t");	/* data after memory dump */

        for(a=0;a<length-1;a++)
        {
                printf("0x%02x,\t",st[a]);
        }

        printf("0x%02x\n",st[length-1]);
        printf("\n");
}

uint32_t big_to_little(uint32_t data)
{

        return ((data>>24) & 0xff) | ((data<<8) & 0xff0000) | ((data>>8) & 0xff00) | ((data<<24) & 0xff000000);	/* perfrom conversion */

       	
}

uint32_t little_to_big(uint32_t data)
{
       

        return ((data>>24) & 0x000000ff) | ((data>>8) & 0x0000ff00) | ((data<<8) & 0x00ff0000) | ((data<<24) & 0xff000000); /* perfrom conversion */


}
