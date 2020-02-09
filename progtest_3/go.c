#ifndef __PROGTEST__
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <float.h>
#include <assert.h>
#endif /* __PROGTEST__ */

const int INSIDE = 0;
const int LEFT =1;
const int RIGHT = 2;
const int BOTTOM = 4;
const int TOP = 8;
int cSl(double *x1, double *y1,
         double *x2, double *y2, double * x_min, double * y_min,double * x_max, double * y_max);

void setMax_min(double * n1, double * n2);         
int setRegion(double * x, double * y
               ,double * x_min, double * y_min,double * x_max, double * y_max
);
int almost_greater(double, double);
int clipLine(double rx1,
             double ry1,
             double rx2,
             double ry2,
             double *ax,
             double *ay,
             double *bx,
             double *by)
{   
    setMax_min(&rx1,&rx2);
    setMax_min(&ry1,&ry2);
    return cSl(ax,ay,bx,by,&rx1, &ry1,&rx2, &ry2);

}

#ifndef __PROGTEST__
int almostEqual(double x,
                double y)
{
    if(fabs(x- y)<1e4 * DBL_EPSILON * (fabs(x) + fabs(y))){
        return 1;
    }
    return 0;
}

int main(void)
{
    double x1, y1, x2, y2;

    x1 = 60;
    y1 = 40;
    x2 = 70;
    y2 = 50;
    assert(clipLine(10, 20, 90, 100, &x1, &y1, &x2, &y2) && almostEqual(x1, 60) && almostEqual(y1, 40) && almostEqual(x2, 70) && almostEqual(y2, 50));

    x1 = 0;
    y1 = 50;
    x2 = 20;
    y2 = 30;
    assert(clipLine(90, 100, 10, 20, &x1, &y1, &x2, &y2) && almostEqual(x1, 10) && almostEqual(y1, 40) && almostEqual(x2, 20) && almostEqual(y2, 30));

    x1 = 0;
    y1 = 30;
    x2 = 120;
    y2 = 150;
    assert(clipLine(10, 20, 90, 100, &x1, &y1, &x2, &y2) && almostEqual(x1, 10) && almostEqual(y1, 40) && almostEqual(x2, 70) && almostEqual(y2, 100));

    x1 = -10;
    y1 = -10;
    x2 = -20;
    y2 = -20;
    assert(!clipLine(10, 20, 90, 100, &x1, &y1, &x2, &y2));

    x1 = 0;
    y1 = 30;
    x2 = 20;
    y2 = 10;
    assert(clipLine(10, 20, 90, 100, &x1, &y1, &x2, &y2) && almostEqual(x1, 10) && almostEqual(y1, 20) && almostEqual(x2, 10) && almostEqual(y2, 20));

    x1 = 0;
    y1 = 0.3553;
    x2 = 10.45;
    y2 = 0;
    assert(clipLine(0.95, 0.323, 1, 1, &x1, &y1, &x2, &y2) && almostEqual(x1, 0.95) && almostEqual(y1, 0.323) && almostEqual(x2, 0.95) && almostEqual(y2, 0.323));
    return 0;
}
#endif /* __PROGTEST__ */

int setRegion(double * x, double * y
               ,double * x_min, double * y_min,double * x_max, double * y_max

)
{ 
    int resl = INSIDE;
    if (
        almost_greater(*x_min,*x)
    )
        //*x < *x_min)
    {
        resl |= LEFT;
    }
    else if (
        almost_greater(*x,*x_max))
        
       // *x > *x_max)
    {
        resl |= RIGHT;
    }
    if (
        almost_greater(*y_min,*y)
        //*y < *y_min
    )
    {
        resl |= BOTTOM;
    }
    else if (
        //*y > *y_max
        almost_greater(*y,*y_max)
        )
    {
        resl |= TOP;
    }
    return resl;
}


void setMax_min(double * n1, double * n2){
    int temp = *n1;
    if(*n1>*n2){
        *n1 = *n2;
        *n2 = temp;
    }
}


int cSl(double *x1, double *y1,
         double *x2, double *y2,double * x_min, double * y_min,double * x_max, double * y_max)
{
    int p1 =setRegion(x1,y1,x_min, y_min,x_max, y_max);
    int p2 =setRegion(x2,y2,x_min, y_min,x_max, y_max);
    int p_out=0; 
    double x = 0;
    double y =0;
    while(1){
        if(p1 == 0 && p2==0){
                   return 1;
        }else if (p1 & p2) 
        { 

            return 0; 
        }else
        { 

             
            if(p1 != 0) 
                {p_out = p1;} 
            else{
                p_out = p2;}
            if (p_out & TOP) 
            { 

                x = *x1 + (*x2 - *x1) * (*y_max - *y1) / (*y2 - *y1); 
                y = *y_max ; 
            } 
            else if (p_out & BOTTOM) 
            { 
                x = *x1 + (*x2 - *x1) * (*y_min - *y1) / (*y2 - *y1); 
                y = *y_min; 
            } 
            else if (p_out & RIGHT) 
            { 

                y = *y1 + (*y2 - *y1) * (*x_max  - *x1) / (*x2 - *x1); 
                x = *x_max ; 
            } 
            else if (p_out & LEFT) 
            { 

                y = *y1 + (*y2 - *y1) * (*x_min - *x1) / (*x2 - *x1); 
                x = *x_min ; 
            } 
 
            if (p_out == p1) 
            { 
                *x1 = x; 
                *y1 = y; 
                p1 = setRegion(x1,y1,x_min, y_min,x_max, y_max);
            } 
            else
            { 
                *x2 = x; 
                *y2 = y; 
                p2 = setRegion(x2,y2,x_min, y_min,x_max, y_max); 
            } 
        } 

        } 



    }


int  almost_greater  ( double  a, double  b ) { 
return a - b > 1e4 * DBL_EPSILON * ( fabs ( a ) + fabs ( b ) ); }

