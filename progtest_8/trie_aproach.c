/* This is program to simulate autocomplete, since reading some 
* suggestion, i will try to aproahc with TRIE data structure, shich is very
* demanding for storage but easy for search*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_PHRASE 1000
#define BUFFER_SIZE 100000
/* Trie of Nodes - this is structure of array holding reference to thte tries.
* it will be sorted linked list to hold 


*/
typedef struct
{
    char *phrase; // predelat na pole s nefixnim poctem
    double frequency;
} features_t;

typedef struct SentenceNode
{
    struct SentenceNode *next;
    features_t feature;

} sentence_t;

typedef struct
{
    sentence_t *head;
    sentence_t *tail;

} sentence_linked_list_t;

/* Trie node - structure holding exactlz one NODE
* This structure need to hold reference to others trie nodes 
* and as well the mark if it is end or not, this will be hold by integer
* in this structure, we will hold all words presented in the sentence.
*/
typedef struct TrieNode
{
    struct TrieNode *children[100];
    int EndOf;
} NodeOfWords;

/*****************************************************
*  LIST FUNCTIONS ***********************************
*****************************************************/

/*
 Initilizer of the list
*/
void sentence_list_init(sentence_linked_list_t *list)
{
    list->head = NULL;
    list->tail = NULL;
}

void sentence_list_print(sentence_linked_list_t *list)
{
    sentence_t *temporary;
    printf("Senteces are given in the following: \n");
    while (temporary)
    {
        printf("The frequency is %lf and phrase is %s \n",
               temporary->feature.frequency, temporary->feature.phrase);
        temporary = temporary->next;
    }
}

sentence_t *create_sentence(double frequency_in, const char *sentence_in)
{
    sentence_t *sentence_add = (sentence_t *)malloc(sizeof(*sentence_add));
    int len = strlen(sentence_in);
    sentence_add->feature.phrase = (char *)malloc(sizeof(sentence_add->feature.phrase) * len);
    if (sentence_add != NULL && sentence_add->feature.phrase != NULL)
    {
        sentence_add->feature.frequency = frequency_in;
        strncpy(sentence_add->feature.phrase, sentence_in, len);
    }
    else
    {
        printf("allocation of memory fails!!!!\n");
    }
    sentence_add->next = NULL;
    return sentence_add;
}

void list_insert_front(sentence_linked_list_t *list, sentence_t *sentence)
{
    sentence->next = list->head;
    list->head = sentence;

    if (!list->tail)
    {
        list->tail = sentence;
    }
}

void list_insert_back(sentence_linked_list_t *list, sentence_t *sentence)
{

    if (list->tail)
    {
        list->tail->next = sentence;
        list->tail = sentence;
    }
    else
    {
        list->tail = sentence;
        list->head = sentence;
    }
}

void insert_sorted(sentence_linked_list_t *list, sentence_t *sentence)
{
    if (!list->head || sentence->feature.frequency > list->head->feature.frequency)
    {

        list_insert_front(list, sentence);
        return;
    }

    sentence_t *curr_sentence = list->head;

    while (curr_sentence->next)
    {
        if (sentence->feature.frequency > curr_sentence->next->feature.frequency)
            // if (strcmp(node->number.value_text, curr_node->next->number.value_text) > 0)
            break;

        curr_sentence = curr_sentence->next;
    }

    // vkladame za curr_node
    sentence->next = curr_sentence->next;
    curr_sentence->next = sentence;

    if (sentence->next == NULL)
        list->tail = sentence;
}

void show_sentences(sentence_linked_list_t *list)
{
    {
        sentence_t *tmp = list->head;
        printf("Spojovy seznam:\n");
        while (tmp)
        {
            printf("-> number[%lf, %s]\n", tmp->feature.frequency, tmp->feature.phrase);
            tmp = tmp->next;
        }
    }
}

int KMP(const char *X, const char *Y, int m, int n)
{

    // Base Case 1: Y is NULL or empty
    if (*Y == '\0' || n == 0)

        printf("Pattern occurs with shift 0");

    //return;

    // Base Case 2: X is NULL or X's length is less than that of Y's
    if (*X == '\0' || n > m)

        printf("Pattern not found");

    //return;
    // next[i] stores the index of next best partial match
    int *next;

    next = (int *)malloc(sizeof(*next) * (n));

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

                printf("Pattern occurs with shift %d\n", i - j + 1);

                printf("Pattern occurs with shift %s\n", X);

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

int read_input(sentence_linked_list_t *list)
{
    size_t bufsize = BUFFER_SIZE;
    int characters = 0;
    char *buffer;
    buffer = (char *)malloc(bufsize * sizeof(char));
    int sc = 0;
    characters = getline(&buffer, &bufsize, stdin);
    char temp_name[BUFFER_SIZE];
    double temp_frequency = 0;
    sentence_t *tmp = list->head;
    while (characters > 1 && sc != -1)
    {
        if ( (sc = sscanf(buffer, "%lf : %[^\n]", &temp_frequency, temp_name)) == 2)

        {
            tmp = create_sentence(temp_frequency, temp_name);
            insert_sorted(list, tmp);
            characters = getline(&buffer, &bufsize, stdin);
            printf(" ttt %d %d size %d \n ", sc, characters, strlen(temp_name));
        }
        else if (sc == 2 && characters == 1)
        {
            free(buffer);
            return 1;
        }        
        else
        {
            printf("Nespravny vstup.\n");
            free(buffer);
            return 0;
        }
    
    }
    free(buffer);    
    return 1;
}
void read_res(char * res, int count){
    for(int k=0;k<count;k++){
        printf("Find in: %s \n",res[count]);
    
    }
}
int search(sentence_linked_list_t *list){
    int result[50];
    size_t bufsize = BUFFER_SIZE;
    int characters = 0;
    char *buffer;
    buffer = (char *)malloc(bufsize * sizeof(char));
    int sc = 0;
    int m,n;
    characters = getline(&buffer, &bufsize, stdin);
    char temp_name[BUFFER_SIZE];
    double temp_frequency = 0;
    sentence_t *tmp = list->head;
    int count = 0;
    while (characters > 1 && sc != -1)
    {
        if( (sc = sscanf(buffer,"%[^\n]",temp_name)) == 1)

        {   m = strlen(temp_name);
            while(tmp){
            n = strlen(tmp->feature.phrase);
            printf("searching %s in \n %s\n",temp_name,tmp->feature.phrase);
            if(KMP(temp_name,tmp->feature.phrase,n,m)){
                result[count] = tmp;
                count++;
    
            };
            tmp = tmp->next;

            }
            read_res(result,count);
            free(result);

            characters = getline(&buffer, &bufsize, stdin);
            printf(" ttt2 %d %d\n ", sc, characters);
        }
        else if (sc == 2 && characters == 1)
        {
            free(buffer);
            return 1;
        }
        else if ((sc = sscanf(buffer, "%[^\n]", temp_name)) == 1)
        {
            /* code */
        }

        else
        {
            printf("Nespravny vstup.\n");
            free(buffer);
            return 0;
        }
    
    }
    free(result);
    free(buffer);    
    return 0;

}



void destroy(sentence_linked_list_t *list)
{

    sentence_t *tmp = list->head;
    printf("DELETE:\n");
    while (tmp)
    {
        printf("-> number[%lf, %s]\n", tmp->feature.frequency, tmp->feature.phrase);
        free(tmp->feature.phrase);
        tmp = tmp->next;
    }
    free(tmp);
}
int main(void)
{
    sentence_linked_list_t senteces_list;
    sentence_list_init(&senteces_list);
    if (read_input(&senteces_list))
    {
        printf("Hledani:\n");
        search(&senteces_list);

        show_sentences(&senteces_list);
    }
    else
    {
    };
    //addd phrase
    /*
    sentence_t * tmp;
	tmp = create_sentence(440,"Progtest random test failed");
    insert_sorted(&senteces_list,tmp);
    tmp = create_sentence(70,"Segmentation fault");
    insert_sorted(&senteces_list,tmp);
    tmp = create_sentence(170,"ASegmentation fault");
    insert_sorted(&senteces_list,tmp);
    tmp = create_sentence(10,"ASegmentation fault");
    insert_sorted(&senteces_list,tmp);
    tmp = create_sentence(80,"Progtest random test failed");
    insert_sorted(&senteces_list,tmp);
    tmp = create_sentence(70,"Segmentation fault");
    insert_sorted(&senteces_list,tmp);
    tmp = create_sentence(170,"vASegmentation fault");
    insert_sorted(&senteces_list,tmp);
    tmp = create_sentence(10,"AvvvSegmentation fault");
    insert_sorted(&senteces_list,tmp);*/
    destroy(&senteces_list);
    printf("end\n");
    return 0;
}