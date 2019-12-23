#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include<string.h>
#define BUFFER_SIZE 100000
#define NAME_MAX BUFFER_SIZE - 20




typedef struct Flyght {
    char *name;
    double x;
    double y;
}FLYGHT;

typedef struct Pairs  {
    double distance;
    int id1;
    int id2;
}PAIRS;

void destroy(FLYGHT *fl, int j){
    for (int i=0;i<=j;i++)
    {
     //free(fl[i].name);
    }
    free(fl);
}


void printFlytghts(FLYGHT *fl,PAIRS *pair,const double * distance, const int * pairs );
void PrintFlights(FLYGHT *fl, int const * i);
PAIRS * calculatePairs(FLYGHT *fl,PAIRS * pair, int const * i,int * num_pair,double * min_dist);
void PrintPairs(PAIRS *pr, int const * i);
/*Driving function */
int main()
{
    size_t bufsize = BUFFER_SIZE;
    char *buffer;
    buffer = (char *)malloc(bufsize * sizeof(char));
    int  characters=1;
    FLYGHT *flights;
    FLYGHT* more_fly = NULL;
    flights =(FLYGHT *)malloc(sizeof(*flights));
    PAIRS *pair;
    pair = (PAIRS *)malloc(sizeof(*pair));
    char temp_name[NAME_MAX];
    
    if( buffer == NULL || flights==NULL || pair==NULL)
    {
        perror("Allocation Failure!!!!");
        exit(1);
    }
    double min_dist = DBL_MAX;
    //printf("MIN DISTANCE %lf\n\n",min_dist );
    printf("Zadejte lety:\n");
    int i=0;
    int sc;
    //sc2;
    int byetescan=0;
    int byetescan2=0;
    characters = getline(&buffer,&bufsize,stdin);
    while(characters >=0){
        //printf("Nespravny vstup.%d You typed: '%s'\n",sc,buffer);   
        sc=sscanf(buffer,"[ %lf , %lf ]%n%[^\n]%n",&flights[i].x,&flights[i].y,&byetescan,temp_name,&byetescan2);

        //sc2=sscanf(buffer,"[ %lf , %lf ]",&flights[i].x,&flights[i].y);
        if
        (//sc=sscanf(buffer,"[ %lf , %lf ] %[^\n]%n",&flights[i].x,&flights[i].y,temp_name ,&byetescan))>=2
            (sc>2 || (sc==2 && (strlen(buffer+byetescan)==1)))
        )
        
        {  
            //printf("temp name %d %d %s str %lu\n",sc,sc2,buffer+byetescan,); 
           

            
            
            if(!byetescan2){
                byetescan2=1;
            }
            more_fly= (FLYGHT *)realloc(flights,(sizeof(*flights)+sizeof(*flights)* (byetescan2)) *(i+1));
            
            flights = more_fly;
            
           // printf("temp name daasdas%d\n",byetescan);
           if(byetescan2){
               flights[i].name=(char *)malloc(byetescan2*sizeof(*flights[i].name));
                sscanf(buffer+byetescan,"%[^\n]%n",flights[i].name, &byetescan2);
            //strncpy ( buffer+byetescan, temp_name, byetescan );
                //printf("sc        cas %d\n", sc,byetescan);
                //printf("tmp %s bs %d \n",temp_name,byetescan);
                //strncpy ( flights[i].name, temp_name, byetescan2);
                //printf("tmp2 %s \n",flights[i].name);
           }else{
               flights[i].name=NULL;
             }
            
            //printf("fl name %s\n",flights[i].name);
            i++;
            characters = getline(&buffer,&bufsize,stdin);
            //printf("%d buuf %s", characters,buffer,stdin);
        
        }
        else{
            //printf("Nespravny vstup 111.\n");    
            free(flights);
            free(buffer);
            free(pair);
            printf("Nespravny vstup.\n");
            //printf("Nespravny vstup.%d You typed: '%s'  %d\n",sc,flights[i].name,byetescan);   
            return(0);
        }
        
        
        //printf("char is %d and bytescan  is %d  %d \n", characters,byetescan,(sizeof(*flights)+sizeof(int)* byetescan) *(i+1));
    
    }
    
    int t=0;
    //PrintFlights(flights,&i);
    pair = calculatePairs(flights,pair,&i,&t,&min_dist);
   
    //PrintPairs(pair,&t);
    printf("Nejmensi vzdalenost: %lf\n", min_dist);
    printFlytghts(flights,pair,&min_dist,&t);
    //printf("%d aaaaaaaaaaaaaaaaaaaaaaaaaaaa\n",i);
    destroy(flights,i);
    free(buffer);
    free(pair);
   
    return(0);
}



void PrintFlights(FLYGHT *fl, int const * i){

    for(int j = 0;j<*i;j++){
       printf("%d je to %lf %lf %s\n",j,fl[j].x, fl[j].y, fl[j].name);

    }

}
void PrintPairs(PAIRS *pr, int const * i){

    for(int j = 0;j<*i;j++){
       printf("%d pair %d %d  %lf \n",j,pr[j].id1, pr[j].id2, pr[j].distance);

    }

}
PAIRS *calculatePairs(FLYGHT *fl,PAIRS *pair, int const * i, int * num_pair, double * min_dist){
    int pairctn = 0;
    PAIRS *new_pair=NULL;
    for(int j = 0;j<*i;j++){
        for(int j2 = j+1;j2<*i;j2++){
            pair[pairctn].distance = sqrt((fl[j].x-fl[j2].x)*(fl[j].x-fl[j2].x)+(fl[j].y-fl[j2].y)*(fl[j].y-fl[j2].y)); 
            pair[pairctn].id1=j;
            pair[pairctn].id2=j2;
            new_pair= (PAIRS *)realloc(pair,sizeof(*pair)*(pairctn+2));
            pair = new_pair;
            //printf("a %lf %lf pair distances\n",*min_dist,pair[pairctn].distance );
            if(*min_dist>pair[pairctn].distance){
                *min_dist=pair[pairctn].distance;
            } 
            pairctn++;
        } 
    }
    *num_pair = pairctn;
return pair;    
}
void printFlytghts(FLYGHT *fl,PAIRS *pair,const double * distance, const int * pairs ){
    for(int j = 0;j<*pairs;j++){
        //printf("lf %lf %lf %d\n",*distance,pair[j].distance,fabs(*distance- pair[j].distance)<=1e4 * DBL_EPSILON * (fabs(*distance) + fabs(pair[j].distance)));
       if(fabs(*distance- pair[j].distance)<=1e4 * DBL_EPSILON * (fabs(*distance) + fabs(pair[j].distance))
           
           ){

            printf("%s - %s\n",fl[pair[j].id1].name, fl[pair[j].id2].name);
       }

    }
    
      


}