

#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
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
    list->tail = NULL;
}


/*Check the emptines*/
void listIsEmpty(linked_list_t * list){
    if(list->head == NULL){
        printf("List is empty\n");
    }else{
        printf("list is not empty\n");
    }
   
}

car_t * createCar(char * name){
    car_t * new_car;
    new_car = (car_t *)malloc(sizeof(*new_car));
    if(new_car == NULL){
        printf("Failed to allocate memory");
    }
    new_car->name = (char *)malloc(sizeof(name));
    if (new_car->name==NULL){
        printf("Failed to allocate memory for name");
      
    }
    int len =  strlen(name);
    strncpy(new_car->name,name,len);
    new_car->next = NULL;
    return new_car;
}
void listPushFront(linked_list_t * list, car_t * car){

     
    car->next = list->head;
    list->head = car;
    if(list->tail == NULL){
        list->tail = car;
    } 
}

void listPushBack(linked_list_t * list, car_t * car){

    if(list->tail){
        list->tail->next=car;
        list->tail=car;
    }else{
        list->tail = car;
        list->head = car;
    }   
}

void printList(linked_list_t * list){
    car_t * temporary = list->head;
    while(temporary){
        printf("CAR: %s\n",temporary->name);
        temporary = temporary->next;
    }
}


int listGetSize(linked_list_t * list){
    car_t * tmp = list->head;
    int cnt = 0;
    while(tmp){
        cnt++;
        tmp = tmp->next;
    }
    return cnt; 
}


void listPopFront(linked_list_t * list){
    

    list->head = list->head->next

}

int main(void)
{
    linked_list_t cars;
    listCreate(&cars);
    car_t * car;
    car = createCar("FABIA");


    listPushFront(&cars,car);
    car = createCar("MERCEDES");
    listPushFront(&cars,car);
    car = createCar("FERRARI");
    listPushFront(&cars,car);

    car = createCar("LAM");
    listPushBack(&cars,car);
    listIsEmpty(&cars);

    printList(&cars);

    printf("%d\n", listGetSize(&cars));

    return 0;
}
