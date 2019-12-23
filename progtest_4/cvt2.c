#include <stdio.h>

int main(void){

int a = 0;
unsigned int b = 456;
int x = 0;
int y = 12;
printf("  >%d !%d ||%d &%d  | %d\n ", a>b, !a,x||y, (x&y), x|y);
int t = 24;
int t0 =26;
int t1 = 6;
if (t == t0 & t1){
    printf("splnenoi &&\n");
}else{
    printf("nesplneno &&\n");
}

if (t == t0 || t1){
    printf("splnenoi ||\n");
}else{
    printf("nesplneno ||\n");
}

if (t == (t0 & t1)){
    printf("splnenoi (&&)\n");
}else{
    printf("nesplneno (&&)\n");
}

if (t == (t0 || t1)){
    printf("splnenoi (||)\n");
}else{
    printf("nesplneno (||)\n");
}



int o;
double p;
o = p = 15.4375 + 0.0;
printf("x= %d a y= %f end\n",o,p);

int xx = 6;
int yy = 0;
if(xx=!yy){
    printf("a is %d \n", xx+14);
}else{
    printf("a is %d \n", xx+28);
}


int x1 = -98;

if ( -128 < x1 < -19 ) 
 printf ( "1" );
else
 printf ( "2" );

}

