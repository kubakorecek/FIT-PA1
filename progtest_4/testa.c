#ifndef __PROGTEST__
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <float.h>
#include <assert.h>
#endif /* __PROGTEST__ */

#define INSIDE 0;
#define LEFT 1;
#define RIGHT 2;
#define BOTTOM 4;
#define TOP 8;
void cSl(double *x1, double *y1,
         double *x2, double *y2, int * p1, int * p2,double variables[8]);

void setMax_min(double * n1, double * n2);         
void setRegion(int *region, double * x, double * y
               ,double * x_min, double * y_min,double * x_max, double * y_max
);
int clipLine(double rx1,
             double ry1,
             double rx2,
             double ry2,
             double *ax,
             double *ay,
             double *bx,
             double *by)
{
    int regionP1 = INSIDE;
    int regionP2 = INSIDE;
    setMax_min(&rx1,&rx2);
    setMax_min(&ry1,&ry2);

    
    setRegion(&regionP1,ax,ay,&rx1, &ry1,&rx2, &ry2);
    setRegion(&regionP2,bx,by,&rx1, &ry1,&rx2, &ry2);
    printf("x_min %d x_max %d \n", rx1,rx2);
    printf("y_min %d y_max %d \n", ry1,ry2);
    printf("R1 %d R2 %d \n", regionP1,regionP2);
    /*
    cSl(ax, ay,
         bx, by, &regionP1, &regionP1);*/

    return 1;     

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

void setRegion(int *region, double * x, double * y
               ,double * x_min, double * y_min,double * x_max, double * y_max

)
{ 
    if (*x < *x_min)
    {
        *region |= LEFT;
    }
    else if (*x > *x_max)
    {
        *region |= RIGHT;
    }
    if (*y < *y_min)
    {
        *region |= BOTTOM;
    }
    else if (*y > *y_max)
    {
        *region |= TOP;
    }
    
}


void setMax_min(double * n1, double * n2){
    int temp = *n1;
    if(*n1>*n2){
        *n1 = *n2;
        *n2 = temp;
    }
}


void cSl(double *x1, double *y1,
         double *x2, double *y2, int * p1, int * p2,double variables[8])
{
    int flag = 0;
    while(1){
        if(*p1 == 0 && *p2==0){
            flag =1;
            break;
        }else if (*p1 & *p2) 
        { 
            // If both endpoints are outside rectangle, 
            // in same region 
            break; 
        }else
        { 
            // Some segment of line lies within the 
            // rectangle 
            int p_out; 
            double x, y; 
  
            // At least one endpoint is outside the  
            // rectangle, pick it. 
            if (*p1 != 0) 
                p_out = *p1; 
            else
                p_out = *p2; 
  
            // Find intersection point; 
            // using formulas y = y1 + slope * (x - x1), 
            // x = x1 + (1 / slope) * (y - y1) 
            if (p_out & TOP) 
            { 
                // point is above the clip rectangle 
                x = *x1 + (*x2 - *x1) * (variables[7] - *y1) / (*y2 - *y1); 
                y = variables[7]; 
            } 
            else if (p_out & BOTTOM) 
            { 
                // point is below the rectangle 
                x = *x1 + (*x2 - *x1) * (variables[6] - *y1) / (*y2 - *y1); 
                y = variables[6]; 
            } 
            else if (p_out & RIGHT) 
            { 
                // point is to the right of rectangle 
                y = *y1 + (*y2 - *y1) * (variables[5] - *x1) / (*x2 - *x1); 
                x = variables[5]; 
            } 
            else if (p_out & LEFT) 
            { 
                // point is to the left of rectangle 
                y = *y1 + (*y2 - *y1) * (variables[4] - *x1) / (*x2 - *x1); 
                x = variables[4]; 
            } 
  
            // Now intersection point x,y is found 
            // We replace point outside rectangle 
            // by intersection point 
            if (p_out == *p1) 
            { 
                *x1 = x; 
                *y1 = y; 
                *p1 = computeCode(*x1, *y1); 
            } 
            else
            { 
                *x2 = x; 
                *y2 = y; 
                *p2 = computeCode(*x2, *y2); 
            } 
        } 

        } 



    }
}