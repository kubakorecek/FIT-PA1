#include <stdio.h>
void scanTriangleType(char * ,char * ,char * );


int main(int argc, char const *argv[] ){
    
    char c1=' ';
    char c3=' ';
    char c2=' ';    
    
    scanTriangleType(&c1 ,&c2 ,&c3  );


    printf("%c%c%c", c1, c2,c3);


    return 0;
}


void scanTriangleType(char * c1,char * c2,char * c3 ){
    printf("scaned optimaly: %d\n",scanf("%c %c %c", &*c1, &*c2, &*c3));
}