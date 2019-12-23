#include <stdio.h>
#include <math.h>


int isSymetric( long long int * number){
    //if(*number % 2 == 0 && *number !=0){
     //   return 0;
   // }else{
        //printf("check %lld\n", *number);
        long long int number_in = *number;
        long long int number_in_2 = *number;
       int count = -1;int MSB, LSB;
       while (number_in_2)
        {
        number_in_2 /=2;
        count++;
        }
        //printf("count %d\n",count);
       while (number_in)
       {
          MSB = ((*number & (1<<count))>>count);
          LSB = number_in % 2;
          //printf("MSB %d LSB %d number %lld\n", MSB, LSB,number_in);
          number_in /=  2;
          count--;
          if (MSB != LSB){
              return 0;
          }
       }
       return 1; 
    
   // }

}

void binRepre(long long int number){
    if(number>1){
    binRepre(number>>1);    
    }
    
    printf("%lld", number & 1);
}
/*
long long unsigned binRepre(long long int number){
    long long unsigned int zb;
    long long unsigned int result=0;
    long long unsigned int mult = 1;
    while (number)
    {
        
        zb = number % 2;
        result += mult*zb;
        number /= 2;
        mult *=10; 
    }

    return result;        


}*/

void LoopOver(const char * t, const long long int * LO,const long long int * HI){
    long long int counter;
    counter = 0;
    long long int i;
    if(*LO % 2 ==0 ){
        i = *LO+1;
    if(*LO==0)
    {
       counter++;
       if(*t=='l'){
       printf("0 = 0b\n");
       } 
       
    }}
    
    else{
        i =*LO;
    }
 
    for(; i<=*HI;i+=2){             
        if(isSymetric(&i) )
        {

            if(*t=='l'){
                //printf("%lld = %lldb\n", i,binRepre(i));
                printf("%lld = ", i);
                binRepre(i);
                printf("b\n");
            }
            


            counter++;

        }
   
        
    }
    if(*t=='c'){
        printf("Celkem: %lld\n", counter);    
    }  
     
}

void killProcces(void){
    printf("Nespravny vstup.\n");
}



int main(void){

    long long int LI;
    long long int HO;
    char X;
    int c;
    int sc;
    printf("Vstupni intervaly:\n");
    
    do
    {
     
    
    sc = scanf("%c %lld %lld", &X,&LI,&HO);
    if(sc==3) 
        { 
                if((X=='c' || X=='l') && LI<=HO && LI>=0){
        LoopOver(&X, &LI,&HO);
        }else{
            
            killProcces();
            return -1;
            }

        }else if(sc!=-1){
            //printf("%d scan f", sc);
            killProcces();
            return -1;
        }
    }

    while ((c = getchar())!=EOF);
   
    


    return 0;







}