#include <stdio.h>
#include <math.h>
#define BITS sizeof(int) * 8 

  
// Driver code 
int main() 
{ 
    unsigned long long int number = 9;
    unsigned long long int bit = 1;
    printf("%llu \n", number & (bit<<0));
    printf("%llu \n", (number & (bit<<1))>>1);
    printf("%llu \n", (number & (bit<<2))>>2);
    printf("%llu \n", (number & (bit<<3))>>3);
    printf("%llu \n", (number & (bit<<4))>>4);
    printf("%llu \n", (number & (bit<<5))>>5);
    int cc = 4;
    printf("4 bit of 9 is %llu \n", ((number & (1<<cc))>>cc));
     
    int count = 0;
    while (number)
    {
        number = ceil(number / 2);
        count++;
    }
    printf("%d\n",count);
    while(1){
        printf("dsfsd\n");
        if(1){
            printf("end\n");
            return 1;
        }
    }
} 