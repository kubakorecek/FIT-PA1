#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 100
#define NAME_MAX BUFFER_SIZE - 20

typedef struct Flyght {
    char name[NAME_MAX];
    double x;
    double y;
}FLYGHT;

typedef struct Pairs  {
    double distance;
    int id1;
    int id2;
}PAIRS;

/*Driving function */
int main()
{
    size_t bufsize = BUFFER_SIZE;
    char *buffer;
    buffer = (char *)malloc(bufsize * sizeof(char));
    int  characters=1;
    FLYGHT *flights;
    FLYGHT* more_fly = NULL;
    flights =(FLYGHT *)malloc(sizeof(FLYGHT));
    PAIRS *pair;
    pair = (PAIRS *)malloc(sizeof(PAIRS *));
    if( buffer == NULL || flights==NULL)
    {
        perror("Allocation Failure!!!!");
        exit(1);
    }

    printf("Zadejte lety:\n");
    int i=0;
    int byetescan=0;
    characters = getline(&buffer,&bufsize,stdin);
    while(characters >=0){
        sscanf(buffer,"[ %lf , %lf ] %[^\n]%n",&flights[i].x,&flights[i].y,flights[i].name,&byetescan);
        characters = getline(&buffer,&bufsize,stdin);
        //printf("%d characters were read.\n",characters);
    //printf("You typed: '%s'\n",buffer);
    //int testx,testy;
    //char *name;
    //name=(char *)malloc(bufsize * sizeof(char));
    
    printf("%d i s %d \n",i,characters);
    
    
    //printf("%d %d\n",byetescan, sizeof(char));
    i++;
    printf("%d i s %d \n",i,characters);
    printf("%d\n",sizeof(*flights));
    more_fly= (FLYGHT *)realloc(flights,sizeof(*flights)*(i+1));
    flights = more_fly;
    }
    //printf("%d %d \n", testx,testy);
    for(int j = 0;j<i-2;j++){
       printf("%d je to %lf %lf %s\n",j,flights[j].x, flights[j].y, flights[j].name);

    }
    
    
    free(flights);
    free(buffer);
    free(more_fly);
    
    return(0);
}

void ReadFlights(FLYGHT *fl){

    /* -------- DATA -------------------*/
    int characters = 1; 

}