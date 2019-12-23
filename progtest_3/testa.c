#include <stdio.h>
#include <math.h>
#include <string.h>
int foo3( int a[][17], int b[][13] )
 {
   return sizeof ( *a ) - sizeof ( *b );
 }
void foo ( int a, int b, int * c )
 {
   *c = a + b;
 }
int foo2( int pp[15], int ppp[43] )
 {
   return sizeof ( pp ) - sizeof ( ppp );
 }
int bar ( int x, int y )
 {
   int * z = &x;
   foo ( x, y, z );
   return *z;
 }



int main(void){

     int a[5] = { 1, 2, 3, 4, 5 };
    int * b = a + 3;

//b[-1] = b[1];
printf("%d %d %d",b[-1],b[1], a[1]);


    

char str15[10] = "abcd";
char * p1, *p2;

p1 = str15;
p2 = str15;
*p2 = 'A';

printf ( "%s %s", p1, p2 );
printf ( "%d", bar ( 13, 13 ) );
char str[666];
char * x = str + 4;
strcpy ( str, "Hello world!" );

while ( *x )
 {
   *x ++ = 0;
 }
printf ( "%s", str );
char str1[10] = "abcd";
char str2[10] = "xyz";

printf ( "xx %d len %d", strlen ( str1 ) - strlen ( str2 ), sizeof ( str1 ) - sizeof ( str2 ) );

/*int ab[5] = { 1, 2, 0, 3, 0 };
int * bb = ab + 1;

while ( bb )
 {
   *bb ++ = 0;
 }
char stor[666];
char * po1, *po2;

strcpy ( stor, "Hello world!" );
po2 = (po1 = stor) + 6;
while ( *po2++ = *po1++ ) {}
printf ( "%s", stor );
*/

int ppap[15];
int ppp[10];

printf ( "\nww %d\n", foo2 ( ppap, ppp ) );

int fa[25][17];
int fb[25][13];

printf ( "%d", foo3( fa, fb ) );

return 0;

}