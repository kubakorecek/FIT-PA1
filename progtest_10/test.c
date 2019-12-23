#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include<string.h>
int rec2 ( int x )
 {
   if ( x == 0 ) return 0;
   return rec2 ( x / 2 ) + ( x & 1 );
 }


  int rec ( int x, int y )
 {
   if ( x <= 0 ) return y;
   return rec ( x - 1, y + 1 );
 }
int main(void){
 

int r = rec ( 104, 9 );
int r2 =  rec2 ( 32 );;

int count=0;
for ( int i =0; i < 76; i += 2 )
 for ( int j =  2 * i; j < 4 * i; j ++ )
  count ++;
printf("%d \n %d\n %d",r,count,r2);
    return 0;
}