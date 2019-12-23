#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define MAXR 200000
#define MAXC 4
void discardInput ( ) {
  int c;
  while ( (c = fgetc(stdin)) != '\n' 
          && c != EOF ) { 
  }    
}
int calculateVOlume(int * x,int * y, int * z){
    return *x * *y * *z;
}

void fillBoundVol(int *arr,int *eq, int n,int m){
    for(int i = 1;i <n;i++){
        //arr[i][1] = 0;
        *(arr+i*2+1)=0;
        for(int j=0; j<m;j++){
            if(
               // arr[i][0] > eq[j][0] && (arr[i][0] > (eq[j][0]+eq[j][1]))){
               (*(arr+i*2+0)> *(eq +j*4+0) && *(arr+i*2+0)> (*(eq +j*4+0)+*(eq +j*4+1)))){
               //arr[i][1]+=calculateVOlume(&eq[j][2],&eq[j][3],&eq[j][1]
               *(arr+i*2+1)+=*(eq +j*4+2) * *(eq +j*4+3) * *(eq +j*4+1);
               }else if((*(arr+i*2+0)> *(eq +j*4+0)))  
            {
              int z = (*(arr+i*2+0)+ *(eq +j*4+0));//(arr[i][0]- eq[j][0]); 
              *(arr+i*2+1)+= *(eq +j*4+2) * *(eq +j*4+3)*z; 
            }
            
        }
    }
}
int removeDuplicates(int *arr, int n, int col) 
{ 
    int j, arr_size;
    j = 0;
    arr_size = n;
    if (n==0 || n==1) 
        {
            return n;
        }
    else{
        for(int i =0; i < n;i++){
            if(
                //arr[i][col]!=arr[j][col]
                *(arr+i*2+col) != *(arr+j*2+col)
                
                ){
                j++;
                *(arr+j*2+col) = *(arr+i*2+col);
                //arr[j][col]=arr[i][col];
            }else{

            }
            
            
        }
    
    return arr_size =  (j+1);
    }
     
} 


int CalculateX(int * low_height,int * high_height, int *eq, int m){
    int x=0;
    for(int j=0; j<m;j++){

            if(
    //*low_height >= eq[j][0] && *high_height<=(eq[j][0]+eq[j][1])){
    // x+=eq[j][2]*eq[j][3];
    *low_height >= *(eq+j*4+0) && *high_height<=(*(eq+j*4+0)+*(eq+j*4+1))){                   
       x+=(*(eq+j*4+2)) * (*(eq+j*4+3));
        }
}
return x;
}
double getHeight(int * hl,int * x,int * adjVol){
    
    return (double)*hl + ((double)*adjVol/(double)*x); 
    

}
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void CleanBuffeR(){
    int c;
    while(( c= fgetc(stdin)) !='\n' && c !=EOF){

    }
}




void fillMatrix(int array [][MAXC],int rows, int cols)
{
for(int r =0; r<rows;++r){
    
  for (int c = 0; c < cols; ++c){
      array[r][c] =0;
  }
    
    
    
    }
}
void printMatrix(int *mat, int rows, int cols) {
  int r, s;
  for (r=0; r<rows; r++) {
    for (s=0; s<cols; s++)
      printf("%5d ", *(mat+r*cols+s ) //mat[r][s]
      );
    printf("\n");
  }
}
void fillBoundaries(int *array,int *silos,int rows)
{
for(int r =0; r<rows;++r){
    
        //array[r+rows][0] =silos[r][0]+silos[r][1];
        //array[r][0] = silos[r][0];
        *(array + (r+rows)*2+0) = (*(silos + r*4 +0 )+*(silos + r*4 +1 ));
        *(array + r*2+0) = *(silos + r*4 +0 );
    
    
    
    }
}

void getVolandAdjHHHL(int * hl, int * hh, int * volADJ,int const * vol,int *array , int m){
    for(int j=m-1;j>=0;j--)
  {
    if(
        //array[j][1] < *vol
        *(array+j*2+1)<*vol
        
        )
    {
        //*hh = array[j+1][0];
        //*hl = array[j][0];
        //*volADJ = *vol - array[j][1];

        *hh = *(array+(j+1)*2+0);
        *hl = *(array+j*2+0);
        *volADJ = *vol - *(array+j*2+1);


        break;
    }
    }    


}
int readInt(int * out, int min, int max) {
  int status;
  while ( (status = scanf("%d", out)) != 1 
          || *out < min 
          || *out > max) {
    if ( status == EOF )
      return 0;      
    discardInput ();
    return 0;
  }
  return 1;
}
int readAlt(int * out, int min, int max) {
  int status;
  while ( (status = scanf("%d", out)) != 1 
          || *out < min 
          || *out > max) {
    if ( status == EOF )
      return 0;      
    discardInput ();
    return 0;
  }
  return 1;
}
int readMatrix(int *mat, int m, int n) {
  int r, s;
  for(r=0; r<m; r++){

  
    if (!readAlt((mat + r*n+0), INT_MIN, INT_MAX )) 
    //&mat[r][0]
        return 0; 
    for (s=1; s<n; s++)
      if ( ! readInt (
          (mat + r*n+s), 
          //&mat[r][s],
           1, INT_MAX ))
        return 0;
}
  return 1;
}
int main(void){
printf("Zadejte pocet nadrzi:\n");
int silos_number, status;


status = 1;
//int static boundaries[2*MAXR][MAXC];
//int static silos[MAXR][MAXC];
int test = 0;
int *silos,*boundaries;
test = scanf("%d",&silos_number);
if(test==1 && silos_number <=MAXR && silos_number > 0){
    printf("Zadejte parametry nadrzi:\n");    
    silos = (int *)malloc(silos_number*4*sizeof(int));
    boundaries = (int *)malloc(2*silos_number*2*sizeof(int));
      
    if (!readMatrix(silos,silos_number,4)){
        printf("Nespravny vstup.\n");
        return 0;
    }
    fillBoundaries(boundaries,silos,silos_number);
    //printMatrix(boundaries,2*silos_number,2);
    qsort (boundaries, 2*silos_number, 2*sizeof(int), cmpfunc );
    //printMatrix(boundaries,2*silos_number,2);
    int n_boun = removeDuplicates(boundaries, 2*silos_number,0); 
    fillBoundVol(boundaries,silos,n_boun,silos_number);
    //printMatrix(silos,silos_number,4);
    printMatrix(boundaries,n_boun,2);
    printf("Zadejte objem vody:\n");
    int vol=0;
    while(status){
        
        status = scanf("%d",&vol); 
        if(status==1 && vol >=0 && status!=EOF){
            if (vol == 0)
                {
                    printf("Prazdne.\n");
                }
            else if(
                //vol > boundaries[n_boun-1][1]
                  vol > *(boundaries+(n_boun-1)*2+1)  
                )
                {
                    printf("Pretece.\n");
                }
            else{
                int hh=0;
                int hl=0;
                int x=0;
                int voladj=0;
                double h=0;
                getVolandAdjHHHL(&hl,&hh,&voladj,&vol,boundaries,n_boun);
                x = CalculateX(&hl,&hh,silos,silos_number);
                h =getHeight(&hl,&x,&voladj);
                printf("h = %.6lf\n",h);
            }

        }else if(vol<0){
            printf("Nespravny vstup.\n");
            break;

        }
        else{
            status=0;
            break;
        }
    }

    return 0;
        
}else{
    printf("Nespravny vstup.\n");
    return 0;
    } 

}