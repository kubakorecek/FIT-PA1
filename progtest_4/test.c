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
         double *x2, double *y2, int * p1, int * p2);
void setRegion(int *regionP1, int *regionP2, double variables[8]);
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
    double variables[8]; // x0 y0 x1 y1 xmin xmax ymin ymax

    if (*ax > *bx)
    {
        variables[0] = *bx;
        variables[2] = *ax;
    }
    else
    {
        variables[0] = *ax;
        variables[2] = *bx;
    }
    if (*ay > *by)
    {
        variables[1] = *by;
        variables[3] = *ay;
    }
    else
    {
        variables[1] = *ay;
        variables[3] = *by;
    }

    if (rx1 > rx2)
    {
        variables[4] = rx2;
        variables[5] = rx1;
    }
    else
    {
        variables[4] = rx1;
        variables[5] = rx2;
    }
    if (ry1 > ry2)
    {
        variables[6] = ry2;
        variables[7] = ry1;
    }
    else
    {
        variables[6] = ry1;
        variables[7] = ry2;
    }
    setRegion(&regionP1, &regionP2, variables);
    for (int i = 0; i < 8; i++)
    {
        printf("%f ", variables[i]);
    }
    printf("\n");
    printf("reg1 %d reg2 %d\n", regionP1, regionP1);

    cSl(ax, ay,
         bx, by, &regionP1, &regionP1);

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

void setRegion(int regionP1[4], int regionP2[4], double variables[8])
{
    for (int i = 0; i < 8; i++)
    {
        printf("%f ", variables[i]);
    }
    printf("\n");
    if (variables[0] < variables[4])
    {
        *regionP1 |= LEFT;
    }
    else if (variables[0] > variables[5])
    {
        *regionP1 |= RIGHT;
    }
    if (variables[1] < variables[6])
    {
        *regionP1 |= BOTTOM;
    }
    else if (variables[1] > variables[7])
    {
        *regionP1 |= TOP;
    }
    if (variables[2] < variables[4])
    {
        *regionP2 |= LEFT;
    }
    else if (variables[2] > variables[5])
    {
        *regionP2 |= RIGHT;
    }
    if (variables[3] < variables[6])
    {
        *regionP2 |= BOTTOM;
    }
    else if (variables[3] > variables[7])
    {
        *regionP2 |= TOP;
    }
}
void cSl(double *x1, double *y1,
         double *x2, double *y2, int * p1, int * p2)
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
        }else{

        } 



    }
}