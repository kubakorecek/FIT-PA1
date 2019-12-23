#include <stdio.h>
#include <math.h>
int binRepre(long long int number,
    long long unsigned int * f_16,
    long long unsigned int * f_32,
    long long unsigned int * f_48,
    long long unsigned int * f_64

){
    long long unsigned int zb;
    //long long unsigned int result=0;
    long long unsigned int mult = 1;

    //printf("%d number\n", number);
    int count = 0;
    while (number)
    {
        if(count==16 || count == 32 || count==64){
            mult=1;
        }
        zb = number % 2;
        if(count<16){
          *f_16 += mult*zb;      
        }else if (count>=16 && count< 32
           
        )
        {
           *f_32 += mult*zb;  /* code */
        }
        else if (count>=32 && count< 48
           
        )
        {
           *f_48 += mult*zb;  /* code */
        }
         else if (count>=48
           
        )
        {
           *f_64 += mult*zb;  /* code */
        }
        
        number = ceil(number / 2);

        mult *=10;
        count++; 
        //printf("number %lld  zb %lld mult %lld count %d\n", number,zb,  mult,count );
  
    }
    //printf("%d COUNTER",count );
    return count;        


}


void reverseBinNumber(long long unsigned int * f1_16,
    long long unsigned int * f1_32,
    long long unsigned int * f1_48,
    long long unsigned int * f1_64,
    long long unsigned int * f2_16,
    long long unsigned int * f2_32,
    long long unsigned int * f2_48,
    long long unsigned int * f2_64,int count_in


){
    //long long unsigned int result=0;


    int lastDigit = 0;
    int count = 0;
    long long unsigned int number = *f1_16; 

    while(count_in) {
        //printf("%lld number \n",number);
        lastDigit = number%10;
        //printf("last digit %d\n",lastDigit);
        number = ceil(number/ 10);
       
        if(count<16){
            
          *f2_64 = 10*(*f2_64)+lastDigit;      
        }else if (count>=16 && count< 32
           
        )
        {
           *f2_48 =10*(*f2_48)+lastDigit;  /* code */
        }
        else if (count>=32 && count< 48
           
        )
        {
           *f2_32 = 10*(*f2_32)+lastDigit;  /* code */
        }
         else if (count>=48
           
        )
        {
           *f2_16 = 10*(*f2_16)+lastDigit;  /* code */
        }
        count++;count_in--;
        //printf("count=%d and number= %lld\n",count,number );
        if(count == 16){
            number = *f1_32;
        }
        else if (count == 32)
        {
            number = *f1_48;
        }else if (count == 48)
        {
            number = *f1_64;
        }
        
        //printf("f1  16 %lld f2 16 %lld \n",*f1_16,*f2_16);
        //printf("f1 32 %lld f2 32 %lld  f1 48 %lld f2 48 %lld f1 64 %lld f2 64 %lld count=%d and number= %lld count in %d\n",*f1_32,*f2_32,*f1_48,*f2_48,*f1_64,*f2_64,count,number,count_in );
        


        //result=(result* 10) + lastDigit;
        //printf("result %d\n", result);
    }
    //return result;
}

int isSymetric(
    long long unsigned int * f1_16,
    long long unsigned int * f1_32,
    long long unsigned int * f1_48,
    long long unsigned int * f1_64,
    long long unsigned int * f2_16,
    long long unsigned int * f2_32,
    long long unsigned int * f2_48,
    long long unsigned int * f2_64
    ){
    //printf("first number %lld second %lld and symetry %d\n",*number_first,*number_second,*number_first==*number_second);
    
   // printf("con %d  f1 %lld f264 %lld",*f1_16 && *f1_16==*f2_64,*f1_16,*f2_64);
    if(*f1_16 && *f1_32 && *f1_16==*f2_64 && *f1_32==*f2_48 ){
        return 1;
    }
    else if(*f1_16 && *f1_32 ==0  && *f1_16==*f2_64 ){
        return 1;
    }else
    {
        return 0;
    }
   


   
   /*
    if(       
        *f1_16==*f2_16
         && *f1_32==*f2_32 
         && *f1_48==*f2_48 
         && *f1_64==*f2_64){
        
        return 1;
    else if (*f1_16==*f2_16 && *f1_32==*f2_32 && *f1_48==*f2_48)
    {
     
    }
        
    }else{
        return 0;
        } */
    return 1;    

}

void LoopOver(const char * t, const long long int * LO,const long long int * HI){
    long long unsigned int f1_16;
    long long unsigned int f1_32;
    long long unsigned int f1_48;
    long long unsigned int f1_64;
    long long unsigned int f2_16;
    long long unsigned int f2_32;
    long long unsigned int f2_48;
    long long unsigned int f2_64;
     long long int counter = 0;
    for(long long int i=*LO; i<=*HI;i++){
        f1_16 = f1_32 =f1_48 = f1_64 =f2_32 =f2_64 =f2_16 =f2_48 =0;
       //number_bin = binRepre(i);
        //number_bin_reverse =reverseBinNumber(number_bin);
        
        
        //printf("number %lld is in bin1 %lld bin2 %lld bin 3 %lld bin4 %lld start \n",i,f1_16,f1_32,f1_48,f1_64);
       
        
        reverseBinNumber(&f1_16,&f1_32,&f1_48,&f1_64,&f2_16,&f2_32,&f2_48,&f2_64,binRepre(i,&f1_16,&f1_32,&f1_48,&f1_64));
        printf("number %lld is in %lld %lld %lld %lld end \n",i,f1_64,f1_48,f1_32,f1_16);
        printf("reverse %lld is in  %lld %lld %lld %lld end \n",i,f2_64,f2_48,f2_32,f2_16);
        printf("number is sym %d\n",isSymetric(&f1_16,&f1_32,&f1_48,&f1_64,&f2_16,&f2_32,&f2_48,&f2_64 ));
        if(i==0){
            printf("0 = 0b\n");
            counter++;
        }
        if(isSymetric(&f1_16,&f1_32,&f1_48,&f1_64,&f2_16,&f2_32,&f2_48,&f2_64 ) )
        {

            if(*t=='l'){
                
                if(f1_32 && f1_48 && f1_64){
                       printf("%lld = %lld%lld%lld%lldb\n", i,f1_16,f1_32,f1_48,f1_64); 
                }else if (f1_32 && f1_48)
                {
                    printf("%lld = %lld%lld%lldb\n", i,f1_16,f1_32,f1_48);
                }else if (f1_32)
                {
                    printf("%lld = %lld%lldb\n", i,f1_16,f1_32);
                }else
                {
                    printf("%lld = %lldb\n", i,f1_16);
                }
                 
                
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