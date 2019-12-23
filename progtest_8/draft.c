/* This is program to simulate autocomplete, since reading some 
* suggestion, i will try to aproahc with TRIE data structure, shich is very
* demanding for storage but easy for search*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_PHRASES 50
#define BUFFER_SIZE 10000
#define FAIL 0
#define END_SUCCES 2
#define REPEAT 1
/* Trie of Nodes - this is structure of array holding reference to thte tries.
* it will be sorted linked list to hold 


*/
typedef struct sentence
{
    char *phrase;
    double frequency;
} sentence_t;

int struct_cmp_by_freq(const void *a, const void *b) 
{ 
    sentence_t *ia = (sentence_t *)a;
    sentence_t *ib = (sentence_t *)b;
    return (double)( ib->frequency - ia->frequency);
	/* float comparison: returns negative if b > a 
	and positive if a > b. We multiplied result by 100.0
	to preserve decimal fraction */ 
 
} 



void show_sentences(sentence_t * list, const int * cnt )
{
    for(int j = 0;j<*cnt;j++){
       printf("%lf %s\n",list[j].frequency, list[j].phrase);

    }
    
      


}
void append_sentence(sentence_t ** list, int *list_len, double frequency, char const * phrase)
{
    *list_len +=1; /* Sentence counter */
    
    sentence_t *_tmp_sentence =(sentence_t *)realloc(*list,(*list_len) * sizeof(sentence_t));
    if(!_tmp_sentence ){
        free(_tmp_sentence);
        return ;
    }
    *list = _tmp_sentence;
    (*list)[*list_len-1].phrase = (char *)malloc((strlen(phrase)+1)*sizeof(char));
    if(!(*list)[*list_len-1].phrase ){
        free((*list)[*list_len-1].phrase);
        return ;
    }
    
    (*list)[*list_len-1].frequency = frequency;
    strcpy ( (*list)[*list_len-1].phrase, phrase);
}
void destroy(sentence_t ** list, int const * cnt){

    //(*list)[*list_len-1].phrase
    for(int j = 0;j<*cnt;j++){
       //printf("delete %lf %s\n",list[j].frequency, list[j].phrase);
       free((*list)[j].phrase); 
    }
    free(*list);
}
int read_list(sentence_t ** list, int * cnt){
    size_t bufsize = 0;
    int characters = 0;
    char *buffer=NULL;
    //buffer = (char *)malloc(bufsize * sizeof(char));
    int sc = 0;
    characters = getline(&buffer, &bufsize, stdin);
    //printf("buffer %lu %d \n ", bufsize,characters);
    //char temp_name[BUFFER_SIZE];
    char * temp_name=(char *)malloc(2*bufsize * sizeof(*temp_name));
    double temp_frequency = 0;
    while (characters > 1 && sc != -1)
    {
        //temp_name=(sentence_t *)realloc(*list,(*list_len) * sizeof(sentence_t));    
        if ( (sc = sscanf(buffer, "%lf : %[^\n]", &temp_frequency, temp_name)) == 2)

        {
            char * temp_name_2 = (char *)realloc(temp_name,(10*bufsize * sizeof(*temp_name)));
            temp_name = temp_name_2;
            append_sentence(list,cnt,temp_frequency,temp_name);
            characters = getline(&buffer, &bufsize, stdin);
            //free(temp_name);
            //printf(" ttt %d %d size %d \n ", sc, characters, strlen(temp_name));
        }
        else if (sc == 2 && characters == 1)
        {
            free(temp_name);    
            free(buffer);
            return 1;
        }        
        else
        {
            printf("Nespravny vstup.\n");
            free(temp_name);
            free(buffer);
            return 0;
        }
    
    }
    free(temp_name);
    free(buffer);    
    return 1;

    
    
}
void read_res(int res[50],int cnt,sentence_t * list){
    for(int i=0;i<cnt && i<MAX_PHRASES;i++){
        //printf("res %d\n", res[i]);
        printf("> %s\n", list[res[i]].phrase);
    }
}

int KMP(const char *X, const char *Y, int m, int n)
{

    // Base Case 1: Y is NULL or empty
    if (*Y == '\0' || n == 0)

        //printf("Pattern occurs with shift 0");

    return 0;

    // Base Case 2: X is NULL or X's length is less than that of Y's
    if (*X == '\0' || n > m)

        //printf("Pattern not found");

    return 0;
    // next[i] stores the index of next best partial match
    int *next;

    next = (int *)malloc(sizeof(int *) * (n));

    for (int i = 0; i < n + 1; i++)

        next[i] = 0;

    for (int i = 1; i < n; i++)

    {

        int j = next[i + 1];

        while (j > 0 && Y[j] != Y[i])

            j = next[j];

        if (j > 0 || Y[j] == Y[i])

            next[i + 1] = j + 1;
    }

    for (int i = 0, j = 0; i < m; i++)

    {

        if (tolower(*(X + i)) == tolower(*(Y + j)))

        {

            if (++j == n)

            {

                //printf("Pattern occurs with shift %d\n", i - j + 1);
                //printf("Pattern occurs with shift %s\n", Y);
                //printf("Pattern occurs with shift %s\n", X);

                free(next);

                return 1;
            }
        }

        else if (j > 0)
        {

            j = next[j];

            i--; // since i will be incremented in next iteration
        }
    }

    free(next);

    return 0;
}

int search(sentence_t * list, int * cnt, int result[MAX_PHRASES],int * matches){
    size_t bufsize = 0;
    //char temp_name[BUFFER_SIZE];
    int characters = 0;
    int index=0;
    int count=0;
    int m,n;
    char *buffer=NULL;
    //buffer = (char *)malloc(bufsize * sizeof(char));
    //int sc = 0;
    characters = getline(&buffer, &bufsize, stdin);
    char * temp_name = (char *)malloc(4*bufsize * sizeof(*temp_name));
    int sc=0;
    
    //printf("char %d sc %d %d %s\n",characters,sc,count,temp_name);
    if(characters > 0 && (sc=sscanf(buffer,"%[^\n]",temp_name) )==1)
            {   n = strlen(temp_name);

            while(index< *cnt){
                //printf("while index %d %d\n", index, );
            m = strlen(list[index].phrase);
            if(KMP(list[index].phrase,temp_name,m,n)){
                
                if(count<50){
                    result[count] = index;
                    count++;
                    *matches = count;
                }
            }
            index++;
            }
            free(temp_name);
            free(buffer);
            return REPEAT;
            }
    else if(characters==-1){
        free(temp_name);
        //printf("yy %d %d %s\n", characters,sc,temp_name);
        free(buffer);
        return END_SUCCES;
    }else{
        printf("Nespravny vstup.\n");
            free(temp_name);
            free(buffer);
            return FAIL;
    }        
    
    
}
int main(void){
    sentence_t  *list_of_sentences=NULL; /*list of all sentences*/
    int lengts_arr_sent = 0;
    int matches = 0;
    int sc = 0;
    int result[MAX_PHRASES];
    printf("Casto hledane fraze:\n");
    if(read_list(&list_of_sentences,&lengts_arr_sent)){
         //show_sentences(list_of_sentences,&lengts_arr_sent);
         qsort(list_of_sentences, lengts_arr_sent, sizeof(sentence_t), struct_cmp_by_freq);
        
        //show_sentences(list_of_sentences,&lengts_arr_sent);
        sc=search(list_of_sentences,&lengts_arr_sent,result,&matches);
        if(!(sc==END_SUCCES)){
            printf("Hledani:\n"); 
            printf("Nalezeno: %d\n", matches);    
            read_res(result,matches,list_of_sentences);   
        }else{
            printf("Nespravny vstup.\n");
        }
        
        while((sc=search(list_of_sentences,&lengts_arr_sent,result,&matches))){
            
            if(sc==END_SUCCES){
                break;
            }
        printf("Nalezeno: %d\n", matches);    
        read_res(result,matches,list_of_sentences);
        matches=0;
        };
        
    destroy(&list_of_sentences,&lengts_arr_sent);
    };


    //printf("out cnt %d\n", lengts_arr_sent);



    
    
    //destroy(list_of_sentences,&lengts_arr_sent);
    return 0;
}