#include <stdio.h>
#include <math.h>
long long unsigned binRepre(long long int number){
    long long unsigned int zb;
    long long unsigned int result=0;
    long long unsigned int mult = 1;
    //printf("%d number\n", number);
    int count = 0;
    while (number)
    {
        
        zb = number % 2;
        result += mult*zb;
        number = ceil(number / 2);
        mult *=10; 
        printf("number %llu result %llu zb %llu mult %llu\n", number, result, zb,mult);
           /* code */
    }

    return result;        


}


long long unsigned int reverseBinNumber(long long unsigned int number){
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

int isSymetric(long long int * number_first, long long  int * number_second){
    printf("first number %llu second %llu and symetry %d\n",*number_first,*number_second,*number_first==*number_second);
    if(*number_first==*number_second){
        
        return 1;
    }else{return 0;} 

}

void LoopOver(const char * t, const long long int * LO,const long long int * HI){
    long long int number_bin,number_bin_reverse,counter;
    counter = 0;
    for(long long int i=*LO; i<=*HI;i++){
        number_bin = binRepre(i);
        number_bin_reverse =reverseBinNumber(number_bin);
        //printf("number %d is in bin %d and reverse bin is %d and",number,number_bin,number_bin_reverse);
        //printf("is symetric: %d\n",isSymetric(&number_bin,&number_bin_reverse) );
    
        


        if(isSymetric(&number_bin_reverse,&number_bin) )
        {

            if(*t=='l'){
                printf("%lld = %lldb\n", i,number_bin);
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
    //printf("start");
    /*int test = 17;
    int test_bin = binRepre(test);
    int test_bin_rev = reverseBinNumber(test_bin);
    
    printf("number %d is in bin %d and reverse bin is %d and is symetric: %d\n",test,test_bin,test_bin_rev,isSymetric(&
    test_bin,&test_bin_rev) );*/
    /*long long int LI=1019;
    long long int HO=2019;
    char X='l';
    LoopOver(&X, &LI,&HO);
    X='c';
    LI=0;
    HO=20;
    LoopOver(&X, &LI,&HO);
    */
    long long int LI;
    long long int HO;
    char X;
    //char XT='a';
    int c;
    int sc;
    unsigned long long x = (unsigned long long) -1;
printf("%llu", x);
    printf("Vstupni intervaly:\n");
    do
    {
        /* code */
    
    sc = scanf("%c %lld %lld", &X,&LI,&HO);
    //printf("%d %lld %lld and c is %c xt is %c\n",sc,LI,HO,X, XT); 
    if(sc==3) 
    
    { if((X=='c' || X=='l') && LI<=HO ){
        LoopOver(&X, &LI,&HO);
    }else{
        killProcces();
    }

    }
    }

    while ((c = getchar())!=EOF);
    
    


    return 0;







}