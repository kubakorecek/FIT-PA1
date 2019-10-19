#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{   
    int a =0;
    int b =0;
    int c =0;
    int discriminant = 0;

    printf("Input a, b, c in ax^2 +bx + c\n");
    if (scanf("%d %d %d", &a, &b,&c) ==3){
        double x1 = 0;
        double x2 = 0;
        if(a == 0){
            printf("Not a quadratic EQ\n");
            return 0;
        }
        discriminant = pow(b,2) - (4*a*c);
        if (discriminant < 0){
            printf("Solution is complex number\n");
            return 0;
        }else{
            
            x1 = (-b + sqrt(discriminant))/(2*a);
            x2 = (-b - sqrt(discriminant))/(2*a);
        }
        printf("%.2f %.2f\n", x1,x2);


    }else{
        printf("Wrong Format!\n")
    };


    return 0;
}
