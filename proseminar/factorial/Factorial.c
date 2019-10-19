/* This is C code to calculate factorial. The main focus is to not using the
  for loop in order to do that.
*/



#include <stdio.h>
unsigned long long factorial (long int p);
int main ()
{
  int check = 0;
  long int p = 0;
  check = scanf("%ld", &p);
  if( check == 1 && p>-1){
      printf("The factorial of %ld is %llu\n", p, factorial(p));

  }else
  {
      printf("Wrong Number!\n");
  }
  


  return 0;
}

unsigned long long factorial (long int p)
{

  if (p > 0)
    {
      unsigned long new_p = p-1;  
      return p * factorial (new_p);
    }
  
  else if (p==0)
  {
    return  1;
  }
  
  else

    {
    return -1;}
}
