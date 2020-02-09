

#include <stdio.h>
#include <limits.h>

typedef struct Car
{
    char *name;
    struct Car *next;
} car_t;

typedef struct linked_list
{
    car_t *head;
    car_t *tail;

} linked_list_t;



/* initiliase a list */
void listCreate(linked_list_t * list)
{
    list->head = NULL;
}


/*Check the emptines*/
void listIsEmpty(linked_list_t * list){
    if(list->head == NULL){
        printf("List is empty");
    }else{
        printf("list is not empty");
    }
    


}


int main(void)
{
    linked_list_t cars;
    listCreate(&cars);

    listIsEmpty(&cars);

    return 0;
}
