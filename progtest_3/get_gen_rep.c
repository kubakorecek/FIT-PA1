#include <stdio.h>
#include <math.h>
#define SIZE_MAX 8
#define LW 2
#define HW 9
int getRepre(int number[SIZE_MAX], long long int input_number, const int * system ){
    int pos = 0;
        while(input_number){
        number[pos++] = input_number % *system;
        input_number = ceil(input_number / *system);
        //pos++;

    }
    int pos_2 = 0;
    while(pos >=pos_2){
        if(number[pos_2] !=  number[pos-1]){
            //printf("p2 %d p %d ap2 %d ap %d\n",pos_2,pos,number[pos_2],number[pos]);
            return 0;
        } 
        pos_2++;
        pos--;
    }
    return 1;

}

int isSymetricBin( long long int * number){
        long long int number_in = *number;
        long long int number_in_2 = *number;
       int count = -1;int MSB, LSB;
       while (number_in_2)
        {
        number_in_2 /=2;
        count++;
        }
       while (number_in)
       {
          MSB = ((*number & (1<<count))>>count);
          LSB = number_in % 2;
          number_in /=  2;
          count--;
          if (MSB != LSB){
              return 0;
          }
       }
       return 1; 
}

void binRepre(long long int number){
    if(number>1){
    binRepre(number>>1);    
    }
    
    printf("%lld", number & 1);
}


int isSymetric(long long int * number, long long int * number_2){
    if(*number==*number_2){
        return 1;
    }else{
        return 0;
    }

}
void RepreInArr(){

}


long long int repNumber(long long int number,const int * system){
    long long unsigned int zb;
    long long unsigned int result=0;
    long long unsigned int mult = 1;
    while (number)
    {
        
        zb = number % *system;
        result += mult*zb;
        number = ceil(number / *system);
        mult *=10; 
           /* code */
    }

    return result;  
}         
long long unsigned int reverseNum(long long unsigned int number){
    long long unsigned int result=0;
    int lastDigit = 0;

    while(number){
        //printf("%d number \n ", number );
        lastDigit = number%10;
        //printf("last digit %d\n", lastDigit);
        number = ceil(number/ 10);
        result=(result* 10) + lastDigit;
        //printf("result %d\n", result);
    }
    return result;
}

void killProcces(void){
    printf("Nespravny vstup.\n");
}

void LoopOver(const char * t,const int * system, const long long int * LO,const long long int * HI){
     long long int counter;
    counter = 0;
    long long int i;
    if(*system ==2){
       
    if(*LO % 2 ==0 ){
        i = *LO+1;
    if(*LO==0)
    {
       counter++;
       if(*t=='l'){
       printf("0 = 0 (2)\n");
       } 
       
    }}
    
    else{
        i =*LO;
    }
 
    for(; i<=*HI;i+=2){             
        if(isSymetricBin(&i))
        {

            if(*t=='l'){
                //printf("%lld = %lldb\n", i,binRepre(i));
                printf("%lld = ", i);
                binRepre(i);
                printf(" (2)\n");
            }
            


            counter++;

        }
   
        
    }
     
    }else if (*system >LW && *system<=HW){
        for(i=*LO; i<=*HI;i++){
            long long int number_rep = repNumber(i,system);
            long long int number_rep_rev = reverseNum(number_rep);
            if(isSymetric(&number_rep_rev,&number_rep) )
        {

            if(*t=='l'){
                //printf("%lld = %lldb\n", i,binRepre(i));
                printf("%lld = %lld", i ,number_rep);
                printf(" (%d)\n",*system);
            }
            


            counter++;

        }



        }

    }else if (*system >HW && *system<37){

       char HASH_MAP[36]={'0','1','2','3','4','5','6','7','8','9'
       ,'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o',
                          'p','q','r','s','t','u','v','w','x','y','z',  
       };
       int gr=0;
       int number[SIZE_MAX]={};
       if(*LO==0){
         counter++;
         if(*t=='l'){
             printf("0 = 0 (%d)\n",*system);  
         }  
         
       }
       for(i=*LO; i<=*HI;i++){
           if(i % *system){

           
            
            for(int j=0;j<SIZE_MAX;j++){
                number[j]=-1;
            }
            gr = getRepre(number,i,system);
            //printf("%lld  gr  %d\n", i,gr);
            if(gr){counter++;
                   //printf("%lld\n", counter);             
            if(*t=='l'){
            printf("%lld = ", i);    
                for(int t=SIZE_MAX-1; t>=0;t--){            
                 //printf("%lld pos %d %d value %c\n",i,t,number[t],HASH_MAP[number[t]]);
                 if(number[t]>-1){
                     printf("%c",HASH_MAP[number[t]]);
                 }   
             }

             
             printf(" (%d)\n",*system);
             
             }
            
    }



        }
       } 
    }
    if(*t=='c'){
        printf("Celkem: %lld\n", counter);    
    } 
     
}



int main(void){

    long long int LI;
    long long int HO;
    char X;
    int c;
    int system;
    int sc;
    
    printf("Vstupni intervaly:\n");
    
    do
    {
     
    
    sc = scanf("%c %d %lld %lld", &X,&system,&LI,&HO);
    if(sc==4) 
        { 
                if((X=='c' || X=='l') && LI<=HO && LI>=0 && system>1 && system<37){
        LoopOver(&X,&system, &LI,&HO);
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