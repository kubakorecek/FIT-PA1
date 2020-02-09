/*
*  Bc.Jakub Korece, Msci(Hon)
*  2019 
*  Solution is treating each tank as one comulative tank and looking for boudaries where to switch new tank. Not very
*  elegant but it worked :).
*/

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define MAXR 200000 /*max row*/
#define MAXC 4      /*max col*/

/* 
*Proccedure: ReorderArchive
*------------------
*Proccedure for cancel output.
*
*INPUTS:  
*           
*RETURNS: .
*/
void discardInput(void)
{
    int c;
    while ((c = fgetc(stdin)) != '\n' && c != EOF)
    {
    }
}

/* 
*Function: ReorderArchive
*------------------
*Function for calculate output.
*
*INPUTS x,y,z as pointers for eaech side.:  
*           
*RETURNS int - Volume: .
*/
int calculateVOlume(int *x, int *y, int *z)
{
    return *x * *y * *z;
}

/* 
*Proccedure: fillBoundVol
*------------------
*Proccedure for calculate boundary for volumes. This will set for each boundaries, what is actual volume a filled matrix 
* with that.
*
*INPUTS arr - matrix with boundaries
*       eq - matrix holding silos.  
*       n  - number of rows
*       m  - number of columns
*           
*RETURNS void: .
*/
void fillBoundVol(int arr[][MAXC], int eq[][MAXC], int n, int m)
{
    /* loop over whole matrix*/
    for (int i = 1; i < n; i++)
    {
        /* make sure if the number is not found, that 0 will be set.*/
        arr[i][1] = 0;
        for (int j = 0; j < m; j++)
        {

            if (arr[i][0] <= eq[j][0])
            { /*keep 0 */
            }
            else if (arr[i][0] > eq[j][0] && (arr[i][0] > (eq[j][0] + eq[j][1])))
            { /*stronger condition to calculate volume*/
                arr[i][1] += calculateVOlume(&eq[j][2], &eq[j][3], &eq[j][1]);
            }
            else if (arr[i][0] > eq[j][0])
            {
                int z = (arr[i][0] - eq[j][0]);
                /*neccesery condition for volume calculation*/
                arr[i][1] += calculateVOlume(&eq[j][2], &eq[j][3], &z);
            }
        }
    }
}
/* 
*Proccedure: removeDuplicates
*------------------
*Proccedure for calculate boundary for volumes. This will set for each boundaries, what is actual volume a filled matrix 
* with that.
*
*INPUTS arr - matrix with boundaries
*       
*       n  - number of rows
*       col  - number of columns
*           
*RETURNS void: .
*/
int removeDuplicates(int arr[][MAXC], int n, int col)
{
    int j, arr_size;
    j = 0;
    /*arry is actually scalar*/
    arr_size = n;
    if (n == 0 || n == 1)
    {
        return n;
    }
    else
    {
        for (int i = 0; i < n; i++)
        /*loop over the whole matrix */
        {
            /* if not eqaul shifth all of them*/
            if (arr[i][col] != arr[j][col])
            {
                j++;
                arr[j][col] = arr[i][col];
            }
            else
            { /*do nothing, therefore duplicates will be removed*/
            }
        }
        /*return new size without duplicates*/
        return arr_size = (j + 1);
    }
}
/* 
*Function: CalculateX
*------------------
*Function for calculate X fro m high height and low height given by volume. 
*
*INPUTS low_height - low boundary height.
*       high_height - high boundary height.
        er - array of silos
*       m  - number of rows
*
*           
*RETURNS int x: .
*/
int CalculateX(int *low_height, int *high_height, int eq[][MAXC], int m)
{
    int x = 0;
    for (int j = 0; j < m; j++)
    {
        /*comulative function which is comullating volume*/
        if (*low_height >= eq[j][0] && *high_height <= (eq[j][0] + eq[j][1]))
        {
            x += eq[j][2] * eq[j][3];
        }
    }
    return x;
}
/* 
*Function: getHeight
*------------------
*Given low height boundaris and adjusted volume, x funtion will return actual height given as 
* low height + x
*
*INPUTS low_height - low boundary height.
*       x - rest of height from low boundary.
*       adjVol - volume in boundary
*       
*
*           
*RETURNS double x: .
*/
double getHeight(int *hl, int *x, int *adjVol)
{

    return (double)*hl + ((double)*adjVol / (double)*x);
}
int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

/*
* DEBUG FUNCTIONS******************************************************************************
*/
/* Helping funtion used just for debugs */
void CleanBuffeR()
{
    int c;
    while ((c = fgetc(stdin)) != '\n' && c != EOF)
    {
    }
}
/* Helping funtion used just for debugs to fill matrix with 0*/
void fillMatrix(int array[][MAXC], int rows, int cols)
{
    for (int r = 0; r < rows; ++r)
    {

        for (int c = 0; c < cols; ++c)
        {
            array[r][c] = 0;
        }
    }
}
/* Helping funtion used just for debugs to show matrix*/
void printMatrix(int mat[][MAXC], int rows, int cols)
{
    int r, s;
    for (r = 0; r < rows; r++)
    {
        for (s = 0; s < cols; s++)
            printf("%5d ", mat[r][s]);
        printf("\n");
    }
}
/***************************************************************************************
/* 
*Proccedure: fillBoundaries
*------------------
*Proccedure for flling matrix withh all posible boundaries.
*
*INPUTS: array - boundary array
*        silos - silos array
*        int - number of rows for matrix
*           
*RETURNS: .
*/
void fillBoundaries(int array[][MAXC], int silos[][MAXC], int rows)
{
    for (int r = 0; r < rows; ++r)
    {

        array[r + rows][0] = silos[r][0] + silos[r][1];
        array[r][0] = silos[r][0];
    }
}

/* 
*Proccedure: getVolandAdjHHHL
*------------------
*Proccedure for cancel output.
*
*INPUTS:  
*           
*RETURNS: .
*/
void getVolandAdjHHHL(int *hl, int *hh, int *volADJ, int const *vol, int array[][MAXC], int m)
{
    /* not very high tech trial to speed up the calculations*/
    /* merge sort would be more efficient*/
    int part = m - 1;
    if (array[((m - 1) / 4) + 1][1] > *vol)
    {
        part = ((m - 1) / 4) + 1;
    }
    else if (array[((m - 1) / 3) + 1][1] > *vol)
    {
        part = ((m - 1) / 3) + 1;
    }
    else if (array[((m - 1) / 2) + 1][1] > *vol)
    {
        part = ((m - 1) / 2) + 1;
    }

    else
    {
    }

    for (int j = part; j >= 0; j--)
    {
        if (array[j][1] < *vol)
        {
            /*find heght low and height high, adjusted volume*/
            *hh = array[j + 1][0];
            *hl = array[j][0];
            *volADJ = *vol - array[j][1];

            break;
        }
    }
}
/* 
*Functions: readInt
*------------------
*Functions for check input boundaries.
*
*INPUTS *out - outputing readed input .
*       min - # number max
*       max - # number min
*           
*RETURNS: int 1 for succes , 0 for fail.
*/
int readInt(int *out, int min, int max)
{
    int status;
    while ((status = scanf("%d", out)) != 1 || *out < min || *out > max)
    {
        if (status == EOF)
            return 0;
        discardInput();
        return 0;
    }
    return 1;
}
/* 
*Functions: readAlt
*------------------
*Functions for check input boundaries.
*
*INPUTS *out - outputing readed input .
*       min - # number max
*       max - # number min
*           
*RETURNS: int 1 for succes , 0 for fail.
*/

int readAlt(int *out, int min, int max)
{
    int status;
    while ((status = scanf("%d", out)) != 1 || *out < min || *out > max)
    {
        if (status == EOF)
            return 0;
        discardInput();
        return 0;
    }
    return 1;
}
/* 
*Functions: readMatrix
*------------------
*Functions for read input matrix.
*
*INPUTS mat - matrix for silos.
*       m - # number of rows
*       n - # number of columns
*           
*RETURNS: int 1 for succes , 0 for fail.
*/
int readMatrix(int mat[][MAXC], int m, int n)
{
    int r, s;
    /* populate matrix*/
    for (r = 0; r < m; r++)
    {
        /*check the boundaries of the given input, it they will not overflow*/
        if (!readAlt(&mat[r][0], INT_MIN, INT_MAX))
            return 0;
        /*check the boundaries of the given input, it they will not overflow and would be >0*/
        for (s = 1; s < n; s++)
            if (!readInt(&mat[r][s], 1, INT_MAX))
                return 0;
    }
    return 1;
}
/* 
*Function: main
*------------------
*Driving function.
*
*INPUTS x,y,z as pointers for eaech side.:  
*           
*RETURNS int.
*/
int main(void)
{
    /*
    *  Solution is treating each tank as one comulative tank and looking for boudaries where to switch new tank. Not very
    *  elegant but it worked :).
    */
    printf("Zadejte pocet nadrzi:\n");

    /*declare number of silos, status*/
    int silos_number, status;

    status = 1;

    /* there are always max 2*max number of silos, for the boundaries.*/
    int static boundaries[2 * MAXR][MAXC];
    int static silos[MAXR][MAXC];

    /*test scanf*/
    int test = 0;

    test = scanf("%d", &silos_number);

    if (test == 1 && silos_number <= MAXR && silos_number > 0)
    {
        printf("Zadejte parametry nadrzi:\n");
        /*check the correctness of reading the matrix*/
        if (!readMatrix(silos, silos_number, 4))
        {
            printf("Nespravny vstup.\n");
            return 0;
        }

        /* fill boundaries with the numbers based on silos input*/
        fillBoundaries(boundaries, silos, silos_number);

        /*sort boundaries to get them in order*/
        qsort(boundaries, 2 * silos_number, 4 * sizeof(int), cmpfunc);

        /* remove boundaries which are the duplicates*/
        int n_boun = removeDuplicates(boundaries, 2 * silos_number, 0);

        /*fill boundaries volumes */
        fillBoundVol(boundaries, silos, n_boun, silos_number);

        printf("Zadejte objem vody:\n");
        int vol = 0;
        while (status)
        {

            status = scanf("%d", &vol);
            if (status == 1 && vol >= 0 && vol != EOF)
            {
                if (vol == 0)
                {
                    printf("Prazdne.\n");
                }
                else if (vol > boundaries[n_boun - 1][1])
                {
                    printf("Pretece.\n");
                }
                else
                { /*need to calculate acuat height*/
                    int hh = 0;
                    int hl = 0;
                    int x = 0;
                    int voladj = 0;
                    double h = 0;
                    getVolandAdjHHHL(&hl, &hh, &voladj, &vol, boundaries, n_boun);
                    x = CalculateX(&hl, &hh, silos, silos_number);
                    h = getHeight(&hl, &x, &voladj);
                    printf("h = %.6lf\n", h);
                }
            }
            else if (vol < 0)
            {
                printf("Nespravny vstup.\n");
                break;
            }
            else if (status == 0)
            {
                printf("Nespravny vstup.\n");
            }
            else
            {
                status = 0;
                break;
            }
        }

        return 0;
    }
    else
    {
        printf("Nespravny vstup.\n");
        return 0;
    }
}