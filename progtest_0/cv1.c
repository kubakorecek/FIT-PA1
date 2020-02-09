#include <stdio.h>

int main(int argc, char *argv[] ){
    printf("ml\' nob:\n");
    int input_number = 0;
    int check_scan = -1;
    check_scan = scanf("%d ", &input_number);
    
    if (check_scan == 1 &&( input_number>0 && input_number <6)){

    
        printf("Qapla\'\n");
        switch (input_number)
        {
        case 1:
            printf("noH QapmeH wo\' Qaw\'lu\'chugh yay chavbe\'lu\' \'ej wo\' choqmeH may\' DoHlu\'chugh lujbe\'lu\'.\n");
            break;
        case 2:
            printf("Qu\' buSHa\'chugh SuvwI\', batlhHa\' vangchugh, qoj matlhHa\'chugh, pagh ghaH SuvwI\'\'e\'.\n");
            break;
        case 3:
            printf("qaStaHvIS wa\' ram loS SaD Hugh SIjlaH qetbogh loD.\n");
            break;
        case 4:
            printf("Ha\'DIbaH DaSop \'e\' DaHechbe\'chugh yIHoHQo\'.\n");
            break;
        
        case 5:
            printf("leghlaHchu\'be\'chugh mIn lo\'laHbe\' taj jej.\n");
            break; 





        default:
            break;
        }
    }
   else
    {
        printf("luj\n");
    }    
        
        

        


    


    return 0;
}