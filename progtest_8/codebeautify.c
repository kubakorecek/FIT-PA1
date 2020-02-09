/*
*  Bc.Jakub Korece, Msci(Hon)
*  2019 
*
*/
#ifndef __PROGTEST__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define LIST_BY_YEAR 0
#define LIST_BY_TYPE 1

#define TYPE_MAX 100
#define SETUP_MAX 100

typedef struct TEngine
{
  struct TEngine *m_Next;
  struct TEngine *m_Prev;
  int m_Year;
  char m_Type[TYPE_MAX];
  int m_Setup[SETUP_MAX];
} TENGINE;

typedef struct TArchive
{
  struct TArchive *m_Next;
  struct TArchive *m_Prev;
  TENGINE *m_Engines;
} TARCHIVE;

TENGINE *createEngine(const char *type,
                      int year)
{
  TENGINE *res = (TENGINE *)malloc(sizeof(*res));
  res->m_Next = NULL;
  res->m_Prev = NULL;
  res->m_Year = year;
  strncpy(res->m_Type, type, sizeof(res->m_Type));
  for (int i = 0; i < SETUP_MAX; i++)
    res->m_Setup[i] = 0;
  return res;
}
#endif /* __PROGTEST__ */

/* Declaring all functions */
void insert_sorted_arch_by_year(TARCHIVE **head_list, TENGINE **engine);
void insert_sorted_arch_by_type(TARCHIVE **head_list, TENGINE **engine);
TARCHIVE *initialize_archive_node();
void set_engine_by_type(TENGINE **engines_list, TENGINE **engine);
void set_engine_by_year(TENGINE **engines_list, TENGINE **engine);
void set_front_engine(TENGINE **first_engine, TENGINE **engine);
void push_front_archive(TARCHIVE **head_list, TARCHIVE **new_arch);

/* 
  *Function: AddEngine
  *------------------
  *Calling other porcedures based on type od the list
  *
  *INPUTS: list - head of archive list, 
  *         listBy - sort method,
  *         enigne - newly created engine
  *           
  *RETURNS: pointer to the head of archive list. 
  */
TARCHIVE *AddEngine(TARCHIVE *list,
                    int listBy,
                    TENGINE *engine)
{

  if (listBy == LIST_BY_YEAR)
  {
    insert_sorted_arch_by_year(&list, &engine);
  }
  else if (listBy == LIST_BY_TYPE)
  {
    insert_sorted_arch_by_type(&list, &engine);
  }

  return list;
}

/* 
*Procedure: DelArchive
*------------------
*Procedure to free aloccated memmory for archive.
*
*INPUTS: list - head of archive list, 
*           
*RETURNS: Void.
*/
void DelArchive(TARCHIVE *list)
{
  /* set head of current list */
  TARCHIVE *current = list;
  while (current != NULL)
  {

    /* prepare to save next pointer and list of engines of the current pointer */
    TARCHIVE *next = current->m_Next;
    TENGINE *current_engine = current->m_Engines;

    /* free all memory allocated for engines*/
    while (current_engine != NULL)
    {
      TENGINE *next_engine = current_engine->m_Next;
      free(current_engine);
      current_engine = next_engine;
    }
    /*after all engines are freed, free the list memory*/
    free(current);
    current = next;
  }
}
/* 
*Function: ReorderArchive
*------------------
*Function for reordering archive by calling embeded function AddEngine.
*
*INPUTS: list - head of archive list, 
*        listBy - sort method, 
*           
*RETURNS: pointer to head of new list.
*/
TARCHIVE *ReorderArchive(TARCHIVE *list,
                         int listBy)
{
  /*declare new archive, save old one to current*/
  TARCHIVE *new_list = NULL;
  TARCHIVE *current = list;

  while (current != NULL)
  {
    /*prepare engines*/
    TARCHIVE *next = current->m_Next;
    TENGINE *current_engine = current->m_Engines;
    /*loop over all engines*/
    while (current_engine != NULL)
    {

      TENGINE *next_engine = current_engine->m_Next;

      /* reset pointers in engines */
      current_engine->m_Next = NULL;
      current_engine->m_Prev = NULL;

      /*save pointers to the new list*/
      new_list = AddEngine(new_list, listBy, current_engine);
      current_engine = next_engine;
    }
    /*free memory for currently relordered engines*/
    free(current);
    current = next;
  }

  return new_list;
}
#ifndef __PROGTEST__
/*drivign function*/
int main(int argc,
         char *argv[])
{
  TARCHIVE *a;

  a = NULL;
  a = AddEngine(a, LIST_BY_YEAR, createEngine("TDI 1.9", 2010));
  assert(a && a->m_Prev == NULL && a->m_Engines && a->m_Engines->m_Year == 2010 && !strcmp(a->m_Engines->m_Type, "TDI 1.9") && a->m_Engines->m_Prev == NULL && a->m_Engines->m_Next == NULL && a->m_Next == NULL);
  a = AddEngine(a, LIST_BY_YEAR, createEngine("TDI 1.9", 2005));
  assert(a && a->m_Prev == NULL && a->m_Engines && a->m_Engines->m_Year == 2005 && !strcmp(a->m_Engines->m_Type, "TDI 1.9") && a->m_Engines->m_Prev == NULL && a->m_Engines->m_Next == NULL && a->m_Next && a->m_Next->m_Prev == a && a->m_Next->m_Engines && a->m_Next->m_Engines->m_Year == 2010 && !strcmp(a->m_Next->m_Engines->m_Type, "TDI 1.9") && a->m_Next->m_Engines->m_Prev == NULL && a->m_Next->m_Engines->m_Next == NULL && a->m_Next->m_Next == NULL);
  a = AddEngine(a, LIST_BY_YEAR, createEngine("TSI 1.2", 2010));
  assert(a && a->m_Prev == NULL && a->m_Engines && a->m_Engines->m_Year == 2005 && !strcmp(a->m_Engines->m_Type, "TDI 1.9") && a->m_Engines->m_Prev == NULL && a->m_Engines->m_Next == NULL && a->m_Next && a->m_Next->m_Prev == a && a->m_Next->m_Engines && a->m_Next->m_Engines->m_Year == 2010 && !strcmp(a->m_Next->m_Engines->m_Type, "TDI 1.9") && a->m_Next->m_Engines->m_Prev == NULL && a->m_Next->m_Engines->m_Next->m_Year == 2010 && !strcmp(a->m_Next->m_Engines->m_Next->m_Type, "TSI 1.2") && a->m_Next->m_Engines->m_Next->m_Prev == a->m_Next->m_Engines && a->m_Next->m_Engines->m_Next->m_Next == NULL && a->m_Next->m_Next == NULL);
  a = AddEngine(a, LIST_BY_YEAR, createEngine("TDI 2.0", 2005));
  assert(a && a->m_Prev == NULL && a->m_Engines && a->m_Engines->m_Year == 2005 && !strcmp(a->m_Engines->m_Type, "TDI 1.9") && a->m_Engines->m_Prev == NULL && a->m_Engines->m_Next->m_Year == 2005 && !strcmp(a->m_Engines->m_Next->m_Type, "TDI 2.0") && a->m_Engines->m_Next->m_Prev == a->m_Engines && a->m_Engines->m_Next->m_Next == NULL && a->m_Next && a->m_Next->m_Prev == a && a->m_Next->m_Engines && a->m_Next->m_Engines->m_Year == 2010 && !strcmp(a->m_Next->m_Engines->m_Type, "TDI 1.9") && a->m_Next->m_Engines->m_Prev == NULL && a->m_Next->m_Engines->m_Next->m_Year == 2010 && !strcmp(a->m_Next->m_Engines->m_Next->m_Type, "TSI 1.2") && a->m_Next->m_Engines->m_Next->m_Prev == a->m_Next->m_Engines && a->m_Next->m_Engines->m_Next->m_Next == NULL && a->m_Next->m_Next == NULL);
  a = AddEngine(a, LIST_BY_YEAR, createEngine("MPI 1.4", 2005));
  assert(a && a->m_Prev == NULL && a->m_Engines && a->m_Engines->m_Year == 2005 && !strcmp(a->m_Engines->m_Type, "MPI 1.4") && a->m_Engines->m_Prev == NULL && a->m_Engines->m_Next->m_Year == 2005 && !strcmp(a->m_Engines->m_Next->m_Type, "TDI 1.9") && a->m_Engines->m_Next->m_Prev == a->m_Engines && a->m_Engines->m_Next->m_Next->m_Year == 2005 && !strcmp(a->m_Engines->m_Next->m_Next->m_Type, "TDI 2.0") && a->m_Engines->m_Next->m_Next->m_Prev == a->m_Engines->m_Next && a->m_Engines->m_Next->m_Next->m_Next == NULL && a->m_Next && a->m_Next->m_Prev == a && a->m_Next->m_Engines && a->m_Next->m_Engines->m_Year == 2010 && !strcmp(a->m_Next->m_Engines->m_Type, "TDI 1.9") && a->m_Next->m_Engines->m_Prev == NULL && a->m_Next->m_Engines->m_Next->m_Year == 2010 && !strcmp(a->m_Next->m_Engines->m_Next->m_Type, "TSI 1.2") && a->m_Next->m_Engines->m_Next->m_Prev == a->m_Next->m_Engines && a->m_Next->m_Engines->m_Next->m_Next == NULL && a->m_Next->m_Next == NULL);
  a = ReorderArchive(a, LIST_BY_TYPE);
  assert(a && a->m_Prev == NULL && a->m_Engines && a->m_Engines->m_Year == 2005 && !strcmp(a->m_Engines->m_Type, "MPI 1.4") && a->m_Engines->m_Prev == NULL && a->m_Engines->m_Next == NULL && a->m_Next && a->m_Next->m_Prev == a && a->m_Next->m_Engines && a->m_Next->m_Engines->m_Year == 2005 && !strcmp(a->m_Next->m_Engines->m_Type, "TDI 1.9") && a->m_Next->m_Engines->m_Prev == NULL && a->m_Next->m_Engines->m_Next->m_Year == 2010 && !strcmp(a->m_Next->m_Engines->m_Next->m_Type, "TDI 1.9") && a->m_Next->m_Engines->m_Next->m_Prev == a->m_Next->m_Engines && a->m_Next->m_Engines->m_Next->m_Next == NULL && a->m_Next->m_Next && a->m_Next->m_Next->m_Prev == a->m_Next && a->m_Next->m_Next->m_Engines && a->m_Next->m_Next->m_Engines->m_Year == 2005 && !strcmp(a->m_Next->m_Next->m_Engines->m_Type, "TDI 2.0") && a->m_Next->m_Next->m_Engines->m_Prev == NULL && a->m_Next->m_Next->m_Engines->m_Next == NULL && a->m_Next->m_Next->m_Next && a->m_Next->m_Next->m_Next->m_Prev == a->m_Next->m_Next && a->m_Next->m_Next->m_Next->m_Engines && a->m_Next->m_Next->m_Next->m_Engines->m_Year == 2010 && !strcmp(a->m_Next->m_Next->m_Next->m_Engines->m_Type, "TSI 1.2") && a->m_Next->m_Next->m_Next->m_Engines->m_Prev == NULL && a->m_Next->m_Next->m_Next->m_Engines->m_Next == NULL && a->m_Next->m_Next->m_Next->m_Next == NULL

  );
  DelArchive(a);

  a = NULL;
  a = AddEngine(a, LIST_BY_TYPE, createEngine("TDI 1.9", 2010));
  assert(a && a->m_Prev == NULL && a->m_Engines && a->m_Engines->m_Year == 2010 && !strcmp(a->m_Engines->m_Type, "TDI 1.9") && a->m_Engines->m_Prev == NULL && a->m_Engines->m_Next == NULL && a->m_Next == NULL);
  a = AddEngine(a, LIST_BY_TYPE, createEngine("TDI 1.9", 2005));
  assert(a && a->m_Prev == NULL && a->m_Engines && a->m_Engines->m_Year == 2005 && !strcmp(a->m_Engines->m_Type, "TDI 1.9") && a->m_Engines->m_Prev == NULL && a->m_Engines->m_Next->m_Year == 2010 && !strcmp(a->m_Engines->m_Next->m_Type, "TDI 1.9") && a->m_Engines->m_Next->m_Prev == a->m_Engines && a->m_Engines->m_Next->m_Next == NULL && a->m_Next == NULL);
  a = AddEngine(a, LIST_BY_TYPE, createEngine("TSI 1.2", 2010));
  assert(a && a->m_Prev == NULL && a->m_Engines && a->m_Engines->m_Year == 2005 && !strcmp(a->m_Engines->m_Type, "TDI 1.9") && a->m_Engines->m_Prev == NULL && a->m_Engines->m_Next->m_Year == 2010 && !strcmp(a->m_Engines->m_Next->m_Type, "TDI 1.9") && a->m_Engines->m_Next->m_Prev == a->m_Engines && a->m_Engines->m_Next->m_Next == NULL && a->m_Next && a->m_Next->m_Prev == a && a->m_Next->m_Engines && a->m_Next->m_Engines->m_Year == 2010 && !strcmp(a->m_Next->m_Engines->m_Type, "TSI 1.2") && a->m_Next->m_Engines->m_Prev == NULL && a->m_Next->m_Engines->m_Next == NULL && a->m_Next->m_Next == NULL);
  a = AddEngine(a, LIST_BY_TYPE, createEngine("TDI 2.0", 2005));
  assert(a && a->m_Prev == NULL && a->m_Engines && a->m_Engines->m_Year == 2005 && !strcmp(a->m_Engines->m_Type, "TDI 1.9") && a->m_Engines->m_Prev == NULL && a->m_Engines->m_Next->m_Year == 2010 && !strcmp(a->m_Engines->m_Next->m_Type, "TDI 1.9") && a->m_Engines->m_Next->m_Prev == a->m_Engines && a->m_Engines->m_Next->m_Next == NULL && a->m_Next && a->m_Next->m_Prev == a && a->m_Next->m_Engines && a->m_Next->m_Engines->m_Year == 2005 && !strcmp(a->m_Next->m_Engines->m_Type, "TDI 2.0") && a->m_Next->m_Engines->m_Prev == NULL && a->m_Next->m_Engines->m_Next == NULL && a->m_Next->m_Next && a->m_Next->m_Next->m_Prev == a->m_Next && a->m_Next->m_Next->m_Engines && a->m_Next->m_Next->m_Engines->m_Year == 2010 && !strcmp(a->m_Next->m_Next->m_Engines->m_Type, "TSI 1.2") && a->m_Next->m_Next->m_Engines->m_Prev == NULL && a->m_Next->m_Next->m_Engines->m_Next == NULL && a->m_Next->m_Next->m_Next == NULL);
  a = AddEngine(a, LIST_BY_TYPE, createEngine("MPI 1.4", 2005));
  assert(a && a->m_Prev == NULL && a->m_Engines && a->m_Engines->m_Year == 2005 && !strcmp(a->m_Engines->m_Type, "MPI 1.4") && a->m_Engines->m_Prev == NULL && a->m_Engines->m_Next == NULL && a->m_Next && a->m_Next->m_Prev == a && a->m_Next->m_Engines && a->m_Next->m_Engines->m_Year == 2005 && !strcmp(a->m_Next->m_Engines->m_Type, "TDI 1.9") && a->m_Next->m_Engines->m_Prev == NULL && a->m_Next->m_Engines->m_Next->m_Year == 2010 && !strcmp(a->m_Next->m_Engines->m_Next->m_Type, "TDI 1.9") && a->m_Next->m_Engines->m_Next->m_Prev == a->m_Next->m_Engines && a->m_Next->m_Engines->m_Next->m_Next == NULL && a->m_Next->m_Next && a->m_Next->m_Next->m_Prev == a->m_Next && a->m_Next->m_Next->m_Engines && a->m_Next->m_Next->m_Engines->m_Year == 2005 && !strcmp(a->m_Next->m_Next->m_Engines->m_Type, "TDI 2.0") && a->m_Next->m_Next->m_Engines->m_Prev == NULL && a->m_Next->m_Next->m_Engines->m_Next == NULL && a->m_Next->m_Next->m_Next && a->m_Next->m_Next->m_Next->m_Prev == a->m_Next->m_Next && a->m_Next->m_Next->m_Next->m_Engines && a->m_Next->m_Next->m_Next->m_Engines->m_Year == 2010 && !strcmp(a->m_Next->m_Next->m_Next->m_Engines->m_Type, "TSI 1.2") && a->m_Next->m_Next->m_Next->m_Engines->m_Prev == NULL && a->m_Next->m_Next->m_Next->m_Engines->m_Next == NULL && a->m_Next->m_Next->m_Next->m_Next == NULL);
  a = AddEngine(a, LIST_BY_TYPE, createEngine("TDI 1.9", 2010));
  assert(a && a->m_Prev == NULL && a->m_Engines && a->m_Engines->m_Year == 2005 && !strcmp(a->m_Engines->m_Type, "MPI 1.4") && a->m_Engines->m_Prev == NULL && a->m_Engines->m_Next == NULL && a->m_Next && a->m_Next->m_Prev == a && a->m_Next->m_Engines && a->m_Next->m_Engines->m_Year == 2005 && !strcmp(a->m_Next->m_Engines->m_Type, "TDI 1.9") && a->m_Next->m_Engines->m_Prev == NULL && a->m_Next->m_Engines->m_Next->m_Year == 2010 && !strcmp(a->m_Next->m_Engines->m_Next->m_Type, "TDI 1.9") && a->m_Next->m_Engines->m_Next->m_Prev == a->m_Next->m_Engines && a->m_Next->m_Engines->m_Next->m_Next->m_Year == 2010 && !strcmp(a->m_Next->m_Engines->m_Next->m_Next->m_Type, "TDI 1.9") && a->m_Next->m_Engines->m_Next->m_Next->m_Prev == a->m_Next->m_Engines->m_Next && a->m_Next->m_Engines->m_Next->m_Next->m_Next == NULL && a->m_Next->m_Next && a->m_Next->m_Next->m_Prev == a->m_Next && a->m_Next->m_Next->m_Engines && a->m_Next->m_Next->m_Engines->m_Year == 2005 && !strcmp(a->m_Next->m_Next->m_Engines->m_Type, "TDI 2.0") && a->m_Next->m_Next->m_Engines->m_Prev == NULL && a->m_Next->m_Next->m_Engines->m_Next == NULL && a->m_Next->m_Next->m_Next && a->m_Next->m_Next->m_Next->m_Prev == a->m_Next->m_Next && a->m_Next->m_Next->m_Next->m_Engines && a->m_Next->m_Next->m_Next->m_Engines->m_Year == 2010 && !strcmp(a->m_Next->m_Next->m_Next->m_Engines->m_Type, "TSI 1.2") && a->m_Next->m_Next->m_Next->m_Engines->m_Prev == NULL && a->m_Next->m_Next->m_Next->m_Engines->m_Next == NULL && a->m_Next->m_Next->m_Next->m_Next == NULL);
  a = ReorderArchive(a, LIST_BY_YEAR);
  assert(a && a->m_Prev == NULL && a->m_Engines && a->m_Engines->m_Year == 2005 && !strcmp(a->m_Engines->m_Type, "MPI 1.4") && a->m_Engines->m_Prev == NULL && a->m_Engines->m_Next->m_Year == 2005 && !strcmp(a->m_Engines->m_Next->m_Type, "TDI 1.9") && a->m_Engines->m_Next->m_Prev == a->m_Engines && a->m_Engines->m_Next->m_Next->m_Year == 2005 && !strcmp(a->m_Engines->m_Next->m_Next->m_Type, "TDI 2.0") && a->m_Engines->m_Next->m_Next->m_Prev == a->m_Engines->m_Next && a->m_Engines->m_Next->m_Next->m_Next == NULL && a->m_Next && a->m_Next->m_Prev == a && a->m_Next->m_Engines && a->m_Next->m_Engines->m_Year == 2010 && !strcmp(a->m_Next->m_Engines->m_Type, "TDI 1.9") && a->m_Next->m_Engines->m_Prev == NULL && a->m_Next->m_Engines->m_Next->m_Year == 2010 && !strcmp(a->m_Next->m_Engines->m_Next->m_Type, "TDI 1.9") && a->m_Next->m_Engines->m_Next->m_Prev == a->m_Next->m_Engines && a->m_Next->m_Engines->m_Next->m_Next->m_Year == 2010 && !strcmp(a->m_Next->m_Engines->m_Next->m_Next->m_Type, "TSI 1.2") && a->m_Next->m_Engines->m_Next->m_Next->m_Prev == a->m_Next->m_Engines->m_Next && a->m_Next->m_Engines->m_Next->m_Next->m_Next == NULL && a->m_Next->m_Next == NULL);
  DelArchive(a);

  return 0;
}
#endif /* __PROGTEST__ */

/* 
  *Function: initialize_archive_node()
  *------------------
  *Function initilizing new archive and allocating memory for it.
  *
  *INPUTS: 
  *           
  *RETURNS: pointer to the new archive. 
  */

TARCHIVE *initialize_archive_node()
{
  TARCHIVE *new_arch = (TARCHIVE *)malloc(sizeof(*new_arch));

  /* check the memory allocation*/
  if (!new_arch)
  {
    printf("Allocation fail!\n");
  }
  /*set all pointers to NULL*/
  new_arch->m_Engines = NULL;
  new_arch->m_Next = NULL;
  new_arch->m_Prev = NULL;
  return new_arch;
}

/* 
  *Proccedure: insert_sorted_arch_by_type
  *------------------
  *Proccedure which will set new archive sorted by type.
  *Insertion is with sorting already.
  *
  *INPUTS: head_list - archives lists,
  *        engine - new engine, 
  *           
  *RETURNS: void. 
  */
void insert_sorted_arch_by_type(TARCHIVE **head_list, TENGINE **engine)
{
  /*list is empty or new archive wil lbe already first due to alphabethical order.*/
  if (((*head_list) == NULL) ||

      strcmp((*head_list)->m_Engines->m_Type, (*engine)->m_Type) > 0)

  {

    /* set new archive push front alognside with engine*/
    TARCHIVE *new_archive = initialize_archive_node();
    set_front_engine(&(new_archive->m_Engines), engine);
    push_front_archive(head_list, &new_archive);
    return;
  }
  else
  {
    /*traverse through all archives to get right plate to place it*/
    TARCHIVE *current_arch = (*head_list);
    while (current_arch->m_Next)
    {
      /*find place*/
      if (strcmp(current_arch->m_Next->m_Engines->m_Type, (*engine)->m_Type) > 0 || strcmp(current_arch->m_Engines->m_Type, (*engine)->m_Type) == 0)
      {
        break;
      }

      current_arch = current_arch->m_Next;
    }

    /*archive already exist, then insert engine in sorted way*/
    if (
        strcmp(current_arch->m_Engines->m_Type, (*engine)->m_Type) == 0)
    {

      set_engine_by_year(&(current_arch->m_Engines), engine);
    }
    else
    {
      /*archive do not exist */
      TARCHIVE *new_archive = initialize_archive_node();

      /*add new engine to the new archive */
      new_archive->m_Engines = (*engine);

      /*make it point the next current*/
      new_archive->m_Next = current_arch->m_Next;

      /*set pointers of the new to itself*/
      if (current_arch->m_Next != NULL)
      {
        new_archive->m_Next->m_Prev = new_archive;
      }
      /* shift pointers so that new archive is poiting to current and vice versa,
      * since the break out of the loop is when current_archive->m_Newxt, we insert new archive behind current one but
      * infront of the current one -> next
      * */
      current_arch->m_Next = new_archive;
      new_archive->m_Prev = current_arch;
      return;
    }
  }
}
/* 
  *Proccedure: set_engine_by_type
  *------------------
  *Proccedure which will set new archive sorted by type.
  *Insertion is with sorting already.
  *
  *INPUTS: engine list
  *         engine  
  *           
  *RETURNS: void. 
  */

void set_engine_by_type(TENGINE **engines_list, TENGINE **engine)
{
  /*list is empty or new archive wil lbe already first due to year.*/
  if ((*engines_list) == NULL || strcmp((*engines_list)->m_Type, (*engine)->m_Type) > 0)
  {
    /*push front engine*/
    set_front_engine(engines_list, engine);
    return;
  }
  else
  {
    TENGINE *current_engine = (*engines_list);
    /*traverse through all archives to get right plate ot place it*/
    while (current_engine->m_Next)
    {
      /*find the right place*/
      if (

          strcmp(current_engine->m_Next->m_Type, (*engine)->m_Type) > 0)
      {
        break;
      }
      current_engine = current_engine->m_Next;
    }
    /*make it point the next current*/
    (*engine)->m_Next = current_engine->m_Next;
    /*set pointers of the new to itself*/
    if (current_engine->m_Next != NULL)
    {
      (*engine)->m_Next->m_Prev = (*engine);
    }
    /* shift pointers so that new engine is poiting to current and vice versa,
      * since the break out of the loop is when current_archive->m_Newxt, we insert new engine behind current one but
      * infront of the current one -> next
      * */
    current_engine->m_Next = (*engine);
    (*engine)->m_Prev = current_engine;
  }
}

/* 
  *Proccedure: insert_sorted_arch_by_type
  *------------------
  *Proccedure which will set new archive sorted by type.
  *Insertion is with sorting already.
  *
  *INPUTS: head_list - archives lists,
  *        engine - new engine, 
  *           
  *RETURNS: void. 
  */

void insert_sorted_arch_by_year(TARCHIVE **head_list, TENGINE **engine)
{
  /*list is empty or new archive wil lbe already first due to year order.*/
  if (((*head_list) == NULL) || (*head_list)->m_Engines->m_Year > (*engine)->m_Year)
  {
    /* set new archive push front alognside with engine*/
    TARCHIVE *new_archive = initialize_archive_node();
    set_front_engine(&(new_archive->m_Engines), engine);
    push_front_archive(head_list, &new_archive);
    return;
  }
  else
  { /*traverse through all archives to get right plate to place it*/
    TARCHIVE *current_arch = (*head_list);
    while (current_arch->m_Next)
    {
      /*find place*/
      if (
          current_arch->m_Engines->m_Year == (*engine)->m_Year || current_arch->m_Next->m_Engines->m_Year > (*engine)->m_Year)
      {
        break;
      }
      current_arch = current_arch->m_Next;
    }
    /*archive already exist, then insert engine in sorted way*/
    if (current_arch->m_Engines->m_Year == (*engine)->m_Year)
    {
      set_engine_by_type(&(current_arch->m_Engines), engine);
    }
    else
    {
      /*archive do not exist */
      TARCHIVE *new_archive = initialize_archive_node();
      /*add new engine to the new archive */
      new_archive->m_Engines = (*engine);

      /*make it point the next current*/
      new_archive->m_Next = current_arch->m_Next;

      if (current_arch->m_Next != NULL)
      {
        new_archive->m_Next->m_Prev = new_archive;
      }
      /* shift pointers so that new archive is poiting to current and vice versa,
      * since the break out of the loop is when current_archive->m_Newxt, we insert new archive behind current one but
      * infront of the current one -> next
      * */
      current_arch->m_Next = new_archive;
      new_archive->m_Prev = current_arch;
      return;
    }
  }
}
/* 
  *Proccedure: set_front_engine
  *------------------
  *Proccedure which will set new engine in front of the list - head.
  *
  *
  *INPUTS: first_engine - head of engine list 
  *         engine  
  *           
  *RETURNS: void. 
  */
void set_front_engine(TENGINE **first_engine, TENGINE **engine)
{
  /*new node must be poiting to the NULL since it is first.*/
  (*engine)->m_Prev = NULL;
  /* new node will be pointing back on old first node*/
  (*engine)->m_Next = (*first_engine);
  if ((*first_engine) != NULL)
  {
    (*first_engine)->m_Prev = (*engine);
  }
  /* list of nodes must be starting with the new node pushed front*/
  (*first_engine) = (*engine);
}
/* 
  *Proccedure: push_front_archive
  *------------------
  *Proccedure which will set new engine in front of the list - head.
  *
  *
  *INPUTS: head_list - head of archive list 
  *         engine  
  *           
  *RETURNS: void. 
  */
void push_front_archive(TARCHIVE **head_list, TARCHIVE **new_arch)
{
  /*new node must be poiting to the NULL since it is first.*/
  (*new_arch)->m_Prev = NULL;
  /* new node will be pointing back on old first node*/
  (*new_arch)->m_Next = (*head_list);
  if ((*head_list) != NULL)
  {
    (*head_list)->m_Prev = (*new_arch);
  }
  /* list of nodes must be starting with the new node pushed front*/
  (*head_list) = (*new_arch);
}
/* 
  *Proccedure: set_engine_by_year
  *------------------
  *Proccedure which will set new archive sorted by type.
  *Insertion is with sorting already.
  *
  *INPUTS: engine list
  *         engine  
  *           
  *RETURNS: void. 
  */
void set_engine_by_year(TENGINE **engines_list, TENGINE **engine)
{
  /*list is empty or new archive wil lbe already first due to alphabetical staart of the head of the list.*/
  if ((*engines_list) == NULL || (*engines_list)->m_Year > (*engine)->m_Year)
  {
    /*push front engine*/
    set_front_engine(engines_list, engine);
    return;
  }
  else
  {
    /*traverse through all archives to get right plate ot place it*/
    TENGINE *current_engine = (*engines_list);
    while (current_engine->m_Next)
    { /*find the right place*/
      if (
          current_engine->m_Next->m_Year > (*engine)->m_Year

      )
      {
        break;
      }
      current_engine = current_engine->m_Next;
    }
    /*make it point the next current*/
    (*engine)->m_Next = current_engine->m_Next;
    /*set pointers of the new to itself*/
    if (current_engine->m_Next != NULL)
    {
      (*engine)->m_Next->m_Prev = (*engine);
    }
    /* shift pointers so that new engine is poiting to current and vice versa,
      * since the break out of the loop is when current_archive->m_Newxt, we insert new engine behind current one but
      * infront of the current one -> next
      * */
    current_engine->m_Next = (*engine);
    (*engine)->m_Prev = current_engine;
  }
}
