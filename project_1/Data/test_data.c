#include<stdio.h>
#include<stdint.h>

int8_t *my_itoa(int8_t *src, int32_t data, int32_t base);
int32_t my_atoi(int8_t *src);
void dump_memory(uint8_t *start,uint32_t length);
uint32_t big_to_little(uint32_t data);
uint32_t little_to_big(uint32_t data);

void test()
{
	//using itoa function
	printf("\nitoa function\n");

	int8_t *str;
        int8_t R[50];
        str = R;

	int32_t A=256;
        int32_t base=2;
	//base 2
        str=my_itoa(str,A,base);
        printf("ASCII Value of %d base %d is %s\n",A,base,str);

	A=256;
        base=8;
        //base 8
        str=my_itoa(str,A,base);
        printf("ASCII Value of %d base %d is %s\n",A,base,str);

	A=156;
        base=10;
        //base 10
        str=my_itoa(str,A,base);
        printf("ASCII Value of %d base %d is %s\n",A,base,str);

	A=-256;
        base=10;
        //base 10 with negative number
        str=my_itoa(str,A,base);
        printf("ASCII Value of %d base %d is %s\n",A,base,str);

	A=256;
        base=16;
        //base 16
        str=my_itoa(str,A,base);
        printf("ASCII Value of %d base %d is %s\n",A,base,str);


	//using atoi function
        printf("\natoi function implementation\n");
        
	char c[50]="256";
	int8_t *p;
	int32_t r=0;
	p=(uint8_t*)c;
	r=my_atoi(p);

        printf("Integer 256\n");

	 //using dump memory function
        printf("\ndump_memory function\n");

	char Arr[50]={0x1A,0x1B,0x1C,0x1D,0x1E};
        uint32_t len=5;
        int i;
        int8_t *stri;
        stri = (uint8_t*)Arr;

        printf("data at memory:\t");

        for(i=0;i<len-1;i++)
        {
                printf("0x%02x,\t",Arr[i]);
        }

        printf("0x%02x\n",Arr[len-1]);


        dump_memory(stri,len);

	//using big to little function
        printf("\nbig to little endian\n");
	
	uint32_t num=0xA1C4E55F;
        uint32_t res;

        printf("Big_Endian: 0x%02x\n",num);

        res=big_to_little(num);

        printf("Little_Endian: 0x%02x\n",res);

	//using little to big function
        printf("\nlittle to big endian\n");
	uint32_t num1=0xA1C4E55F;
        uint32_t res1;

        printf("Little Endian: 0x%02x\n",num1);

        res1=little_to_big(num1);

        printf("Big Endian: 0x%02x\n\n",res1);
}
