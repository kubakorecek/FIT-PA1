#include <stdio.h>
#include <float.h>
#include <math.h>
int readLoadTriangle(char * n1, char * n2,char * n3, long double * tus1,long double * tus2, long double * tus3);
void swap(long double *first,long double *second);
int main(int argc, char const *argv[] ){
     long double a1 =-10.0;
     char n1;
     char n2;
     char n3;

     char n1b;
     char n2b;
     char n3b;
     long double b1 =-10.0;
     long double c1 =-10.0;
     long double a2 =-10.0;
     long double b2 =-10.0;
     long double c2 =-10.0;
     
    
    printf("Trojuhelnik #1:\n");
    int T1 = readLoadTriangle(&n1,&n2,&n3,&a1, &b1, &c1);
    if (T1 == 2)               
    {
        printf("Vstup netvori trojuhelnik.\n");
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
    printf("Trojuhelnik #2:\n");
    T1 = readLoadTriangle(&n1b,&n2b,&n3b,&a2, &b2, &c2); 

    if (T1 == 2)               
    {
        printf("Vstup netvori trojuhelnik.\n");
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
    char * n1,char * n2, char * n3,
    long double * tus1,
     long double * tus2,  long double * tus3)

     
{
    //printf("reading \n");
    int scaning_type  = scanf(" %c%c%c",n1,n2,n3);
    int scaning_data  = scanf("%Lf %Lf %Lf",tus1, tus2, tus3);
    //printf("scaning %d %d\n", scaning_type,scaning_data );
    //printf("%c%c%c %Lf %Lf %Lf\n", *n1,*n2,*n3, *tus1,*tus2,*tus3);
    if(scaning_type==3&&scaning_data==3&&
            *tus1 > 0 && *tus2>0 && *tus3>0){
            //printf("%c %c %c \n", *n1,*n2,*n3);

            
        if(*n1=='S' && *n2=='S' && *n3=='S'){
            



        }else if(*n1=='S' && *n2=='U' && *n3=='S'  && *tus2>0 && *tus2<180){

                //printf("trnasforming");
                long double tus1_help;
                long double angle_beta=*tus2 *( M_PI/180.0);
            
            tus1_help = sqrt((*tus1)*(*tus1) + (*tus3)*(*tus3)  - 2*(*tus3)*(*tus1)*cosl(angle_beta));
            *tus2 = tus1_help;
        }
            
        else if(*n1=='U' && *n2=='S' && *n3=='U' && *tus3>0 && *tus3<180 && *tus1>0 && *tus1<180){
                if(*tus1+*tus3-180>1e4 * DBL_EPSILON * ( fabs ( *tus3 ) + fabs ( *tus1) )  ){
                    return 2;
                }
                
                long double tus1_help;
                long double tus3_help;
      
                long double angle_alpha =*tus1 *( M_PI/180.0);
                long double angle_beta =*tus3 *( M_PI/180.0);
                long double angle_gamma=(180 - *tus1 -*tus3) *( M_PI/180.0);
                
                tus1_help = (*tus2)*sinl(angle_alpha)/sinl(angle_gamma);
                tus3_help = (*tus2)*sinl(angle_beta)/sinl(angle_gamma);
                //printf("%Lf %Lf", tus1_help,tus3_help);
                *tus1 = tus1_help;
                *tus3 = tus3_help;
                
        }                
        else{
            return 0;
        }

        if(
            
            
            (*tus1 + *tus2)-*tus3> 1e4 * DBL_EPSILON * ( fabs ( *tus3 ) + fabs ( *tus2 +*tus1) )      
        
         && 
            (*tus1 + *tus3)-*tus2> 1e4 * DBL_EPSILON * ( fabs ( *tus2 ) + fabs ( *tus3 +*tus1) )      
        
        
        
        && 
        (*tus2 + *tus3)-*tus1> 1e4 * DBL_EPSILON * ( fabs ( *tus1 ) + fabs ( *tus3 +*tus2) )      
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
         //printf("Transformaed %c%c%c %Lf %Lf %Lf\n", *n1,*n2,*n3, *tus1,*tus2,*tus3);
         return 1;}
        else{
            return 2;
        }

        

         
    }else{
        return 0;
    }
    
}
void swap( long double *first, long double *second){
     long double tmp = *first;
    *first = *second;
    *second=tmp;
}