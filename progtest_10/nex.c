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
    char *buffer;
    size_t bufsize = BUFFER_SIZE;
    int  characters=1;
    FLYGHT *flights;
    flights = (FLYGHT *)malloc(sizeof(FLYGHT *));
    PAIRS *pair;
    pair = (PAIRS *)malloc(sizeof(PAIRS *));
    buffer = (char *)malloc(bufsize * sizeof(char));

    if( buffer == NULL)
    {
        perror("Allocation Failure!!!!");
        exit(1);
    }

    printf("Zadejte lety:\n");
    int i=0;
    int byetescan=0;
    while(characters !=-1){
        characters = getline(&buffer,&bufsize,stdin);
        //printf("%d characters were read.\n",characters);
    //printf("You typed: '%s'\n",buffer);
    //int testx,testy;
    //char *name;
    //name=(char *)malloc(bufsize * sizeof(char));
    sscanf(buffer,"[ %lf , %lf ] %[^\n]%n",&flights[i].x,&flights[i].y,flights[i].name,&byetescan);
    
    
    realloc(flights,sizeof(FLYGHT *));
    printf("%d %d\n",byetescan, sizeof(char));
    i++;
    
    }
    //printf("%d %d \n", testx,testy);
    for(int j = 0;j<i;j++){
       printf("je to %lf %lf %s\n",flights[j].x, flights[j].y, flights[j].name);

    }
    printf("\n");
    
    
    
    return(0);
}
