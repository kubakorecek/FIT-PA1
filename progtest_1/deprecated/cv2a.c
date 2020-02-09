#include <stdio.h>
#include <float.h>
#include <math.h>
int readLoadTriangle(long double * tus1,long double * tus2, long double * tus3);
void swap(long double *first,long double *second);
int main(int argc, char const *argv[] ){
     long double a1 =-10.0;
     long double b1 =-10.0;
     long double c1 =-10.0;
     long double a2 =-10.0;
     long double b2 =-10.0;
     long double c2 =-10.0;
    int T1 = readLoadTriangle(&a1, &b1, &c1); 
    
    printf("Trojuhelnik #1:\n");
    if (T1 == 2)               
    {
        printf("Strany netvori trojuhelnik.\n");
        return 0;
    }else if (
        T1 == 1
    )
    {
        /* code */
    }
    else{
        printf("Nespravny vstup.\n");
        return 0;
    };

    T1 = readLoadTriangle(&a2, &b2, &c2); 
    
    printf("Trojuhelnik #2:\n");
    if (T1 == 2)               
    {
        printf("Strany netvori trojuhelnik.\n");
        return 0;
    }else if (
        T1 == 1
    )
    {
        /* code */
    }
    else{
        printf("Nespravny vstup.\n");
        return 0;
    };
    
    if(fabs(a1- a2)<1e4 * DBL_EPSILON * (fabs(a1) + fabs(a2))
       && fabs(b1- b2)<1e4 * DBL_EPSILON * (fabs(b1) + fabs(b2))
       && fabs(c1- c2)<1e4 * DBL_EPSILON * (fabs(c1) + fabs(c2)) 
    
    ) 
    {
       printf("Trojuhelniky jsou shodne.\n"); 
    }else if(
        fabs((a1/a2)-(b1/b2))<1e4 * DBL_EPSILON * (fabs(a1/a2) + fabs(b1/b2))
        //(a1/a2) == (b1/b2)
         && 
         //(a1/a2) == (b1/b2))
        fabs((c1/c2)-(b1/b2))<1e4 * DBL_EPSILON * (fabs(a1/a2) + fabs(b1/b2)))

        {
          printf("Trojuhelniky nejsou shodne, ale jsou podobne.\n");  
        }
    else{
      printf("Trojuhelniky nejsou shodne ani podobne.\n");    
    }
    
    

    return 0;
    



}

int readLoadTriangle(
    long double * tus1,
     long double * tus2,  long double * tus3)
{
    if (scanf("%Lf %Lf %Lf", tus1, tus2, tus3)==3&&
            *tus1 > 0 && *tus2>0 && *tus3>0)
        if((*tus1 + *tus2)>*tus3 && 
        (*tus1 + *tus3)>*tus2 && 
        (*tus2 + *tus3)>*tus1 
         ){

         
         if (*tus1>*tus2){
             swap(*&tus1,*&tus2);
         }
         if (*tus1>*tus3){
             swap(*&tus1,*&tus3);
         }
         if (*tus2>*tus3){
             swap(*&tus2,*&tus3);
         }
         return 1;}
        else{
            return 2;
        }

        

         
    else{
        return 0;
    }
    
}
void swap( long double *first, long double *second){
     long double tmp = *first;
    *first = *second;
    *second=tmp;
}