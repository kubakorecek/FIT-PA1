#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int rec ( int x, int y )
 {
   if ( x == 1 ) return y;
   return rec ( x - 1, y + 2 ) + y;
 }
int main(void){
int r =0;
for (int i = 0; i < 98; i += 2 )
 for (int j = 2 * i; j < 4 * i; j ++ )
  r++;
printf("%d",r);
}