#ifndef __PROGTEST__
#include <stdio.h>
#include <assert.h>
#define RECT_NO_OVERLAP 0
#define RECT_OVERLAP    1
#define RECT_A_IN_B     2
#define RECT_B_IN_A     3
#define RECT_ERROR    (-1)
#endif /* __PROGTEST__ */
void swap( int *, int *);
int Rectangle_contains(const int * ax_left,
               const int * ax_right,
               const int * ay_up,
               const int * ay_down,
               const int * bx_left,
               const int * bx_right,
               const int * by_up,
               const int * by_down);
int DoOverlap(const int * ax_left,
               const int * ax_right,
               const int * ay_up,
               const int * ay_down,
               const int * bx_left,
               const int * bx_right,
               const int * by_up,
               const int * by_down);
void sortNode(int * ax1,int * ax2,int * ay1,int * ay2
              ,int * bx1,int * bx2,int * by1,int * by2 

);
#include <math.h>
int rectanglePosition ( int ax1, int ay1,
                        int ax2, int ay2,
                        int bx1, int by1,
                        int bx2, int by2 )

{


  int resl;
  sortNode(&ax1,&ax2,&ay1,&ay2,&bx1,&bx2,&by1,&by2 );
  if(!(fabs(ax1-ax2)&& fabs(bx1-bx2)&&fabs(ay1-ay2) && fabs(by1-by2))){
      
      return -1;
  }
  if((DoOverlap(&ax1,&ax2,&ay2,&ay1,&bx1,&bx2,&by2,&by1 )))
  {
      resl = Rectangle_contains(&ax1,&ax2,&ay2,&ay1,&bx1,&bx2,&by2,&by1 );
      return resl;
  }else{return 0;}
  ;

}

#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
{


  assert ( rectanglePosition ( 0, 0, 50, 20,
                               10, 5, 75, 40 ) == RECT_OVERLAP );
  assert ( rectanglePosition ( 0, 20, 50, 0,
                               75, 40, 10, 5 ) == RECT_OVERLAP );
                             
  assert ( rectanglePosition ( 0, 0, 50, 20,
                               -100, 100, 100, 90 ) == RECT_NO_OVERLAP );
  assert ( rectanglePosition ( 0, 0, 50, 20,
                               50, -100, 100, 100 ) == RECT_NO_OVERLAP );
 
  assert ( rectanglePosition ( 0, 0, 10, 10,
                               2, 8, 4, 6 ) == RECT_B_IN_A );
  assert ( rectanglePosition ( 2, 6, 3, 7,
                               1, 5, 4, 8 ) == RECT_A_IN_B );
  assert ( rectanglePosition ( 1, 6, 3, 7,
                               1, 5, 4, 8 ) == RECT_OVERLAP );
  assert ( rectanglePosition ( 0, 0, 1, 1,
                               1, 0, 0, 1 ) == RECT_OVERLAP );
  assert ( rectanglePosition ( 0, 0, 50, 20,
                               50, -100, 100, -100 ) == RECT_ERROR );
  
  return 0;
}
#endif /* __PROGTEST__ */

int DoOverlap(const int * ax_left,
               const int * ax_right,
               const int * ay_up,
               const int * ay_down,
               const int * bx_left,
               const int * bx_right,
               const int * by_up,
               const int * by_down){

if(*ax_left>=*bx_right || *bx_left >= *ax_right)
    return 0;
if(*ay_up<=*by_down || *by_up <= *ay_down)
    return 0;


return 1;
}
int Rectangle_contains(const int * ax_left,
               const int * ax_right,
               const int * ay_up,
               const int * ay_down,
               const int * bx_left,
               const int * bx_right,
               const int * by_up,
               const int * by_down){
    // a in b 
    int ah,bh,aw,bw;
    ah = fabs(*ax_left-*ax_right);
    aw = fabs(*ay_down-*ay_up);  
    bh = fabs(*bx_left-*bx_right);
    bw = fabs(*by_down-*by_up);
    if (!(ah&&aw&&bh&&bw) ){
        return -1;
    }  
    if((ah<bh && aw < bw && *ax_left>*bx_left && *ay_down>*by_down)){
        return 2;
    }else if ((ah>bh && aw > bw && *ax_left<*bx_left && *ay_down<*by_down))
    {
      return 3;
           
    }else{
        return 1;
    }
}


void swap(int * a, int * b)
{
    int temp=*a;
    *a = *b;
    *b = temp;
}

void sortNode(int * ax1,int * ax2,int * ay1,int * ay2
              ,int * bx1,int * bx2,int * by1,int * by2 

){
    if(*ax1>*ax2)
  {
      swap(ax1,ax2);
  }
  if(*ay1>*ay2)
  {
      swap(ay1,ay2);
  }  

  if(*bx1>*bx2)
  {
      swap(bx1,bx2);
  }
  if(*by1>*by2)
  {
      swap(by1,by2);
  }  





}
