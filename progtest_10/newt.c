#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 100
#define NAME_MAX BUFFER_SIZE - 20

typedef struct Flyght {
    double x;
    double y;
}FLYGHT;




void PrintFlyghts(FLYGHT * flyghts, int const * len);
int readFlyght(FLYGHT ** flyghts);
int main( void ){
    /* Array of structs holding the flyghts */
    FLYGHT *flyghts;
    int count;
    if((flyghts = (FLYGHT *)malloc(sizeof(FLYGHT *)))==NULL){
        perror("Allocation Failure!!!! on the start");
        exit(1);
    }
    
    //realloc(flyghts,5*sizeof(flyghts));
    //printf("%d\n",sizeof(&flyghts));
    if((count = readFlyght(&flyghts))!=-1){
        printf("Succes %d\n",count);
    }
    //PrintFlyghts(flyghts,&count);
}
void relocMemory(FLYGHT *flyghts)
{
    if(realloc(flyghts,sizeof(FLYGHT *))==NULL){
            perror("Allocation Failure!!!! after reloc");
            exit(1);
        }
}
int readFlyght(FLYGHT **flyghts){
    /* ------------- Variables --------------*/
    int id=0; /* counter of ids to each flight */
    char *buffer; /* Var holding buffer array*/
    buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
    int characters = 1; /* Var holding value returned by get line, starting at one to have loop going */
    int bytescan; /*Var holding sscanf the number of bytes which was read */
    size_t bufsize = BUFFER_SIZE;  /*Buffer size */
    char temp_name[NAME_MAX];
    while((characters=getline(&buffer,&bufsize,stdin))!=-1
     ){
        if(sscanf(buffer,"[ %lf , %lf ] %[^\n]%n",&(*flyghts)[id].x,&(*flyghts)[id].y,temp_name,&bytescan))
        
        {
            id++;
            (FLYGHT *)realloc(&(*flyghts),(id+1)*sizeof(FLYGHT *));
            //if(==NULL){
            //perror("Allocation Failure!!!! after reloc");
            //exit(1);
//}
        }
        
        else{return -1;}
        
        
    }
    return id+1; 
}
void PrintFlyghts(FLYGHT * flyght, int const * len){
    for(int i=0;i<*len;i++)
    {
        printf("je to %lf %lf \n",flyght[i].x, flyght[i].y);

    }
}