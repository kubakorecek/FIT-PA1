#ifndef __PROGTEST__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define LIST_BY_YEAR       0
#define LIST_BY_TYPE       1

#define TYPE_MAX           100
#define SETUP_MAX          100

typedef struct TEngine
{
  struct TEngine * m_Next;
  struct TEngine * m_Prev;
  int              m_Year;
  char             m_Type  [ TYPE_MAX ];
  int              m_Setup [ SETUP_MAX ];
} TENGINE;

typedef struct TArchive
{
  struct TArchive * m_Next;
  struct TArchive * m_Prev;
  TENGINE         * m_Engines;
} TARCHIVE;
void push_front(TARCHIVE ** list,TENGINE ** engine);
TENGINE          * createEngine                            ( const char      * type,
                                                             int               year )
{
  TENGINE * res = (TENGINE *) malloc ( sizeof  (*res ) );
  res -> m_Next = NULL;
  res -> m_Prev = NULL;
  res -> m_Year = year;
  strncpy ( res -> m_Type, type, sizeof ( res -> m_Type ) );
  for ( int i = 0; i < SETUP_MAX; i ++ )
    res -> m_Setup[i] = 0;
  return res;
}
#endif /* __PROGTEST__ */
void insert_sorted_by_year(TARCHIVE ** list, TENGINE ** engine){
    TARCHIVE* current_engine;

  /*list is empty */
  if(!(*list)->m_Prev == NULL){
    (*list)->m_Engines = (*engine);
  }
  /*inserting ot the beginning */
  else if ((*list)->m_Engines->m_Year<(*engine)->m_Year
  )
  {
    push_front(list,engine);
  }else /*other cases*/
  {
    current_engine = (*list); /*beginnig of the list*/
    while (current_engine->m_Next !=NULL && 
          current_engine->m_Next->m_Engines->m_Year<(*engine)->m_Year)
    {
      current_engine = current_engine->m_Next;

      (*engine) = current_engine->m_Next->m_Engines;


      if(current_engine->m_Next !=NULL){
        (*engine)->m_Next->m_Prev=(*engine);
      }
      current_engine->m_Next=(*engine);
      (*engine)->m_Prev = current_engine;
    }
    
  }
  
  
  
  


}



void push_front(TARCHIVE ** list,TENGINE ** engine)
{
  /* memory allocation */
  TARCHIVE * arch = (TARCHIVE *) malloc ( sizeof  (*arch ) );
  if(!arch){
    /*If memory os no allocated do then no continue*/
    printf("Memmory failed to be allocated!\n");
    return;
  }else{

    /*Allocate new engine */
    arch ->m_Engines = (*engine);
    
    /*Save head of the current list*/
    arch ->m_Next =(*list);
    
    /*Set previous node as null*/
    arch ->m_Prev = NULL;
    
    /*switch prev head between old and new engine */
    if((*list)!=NULL){
      (*list)->m_Prev=arch;
    }
  /*move head */  
  (*list) = arch;
  }
}
void push_back(TARCHIVE ** list,TENGINE ** engine)
{
  /* memory allocation */
  TARCHIVE * arch = (TARCHIVE *) malloc ( sizeof  (*arch ) );
  if(!arch){
    /*If memory os no allocated do then no continue*/
    printf("Memmory failed to be allocated!\n");
    return;
  }else{

    /*Allocate new engine */
    arch ->m_Engines = (*engine);
    
    /*Set next node as null*/
    arch ->m_Next = NULL;

    /*deal with emptinnes of list*/
    if((*list) == NULL){
      arch ->m_Prev = NULL;
      (*list) =arch;
      return;};
    
    TARCHIVE * arch_last = (*list);
    while(arch_last->m_Next !=NULL){
      arch_last = arch_last->m_Next;
    }   
    arch_last->m_Next=arch;
    arch->m_Prev=arch_last;
    return;
  }
}
TARCHIVE         * AddEngine                               ( TARCHIVE        * list,
                                                             int               listBy,
                                                             TENGINE         * engine )
{
insert_sorted_by_year(&list,&engine);  
return list;
}
void               DelArchive                              ( TARCHIVE        * list )
{
  /* todo */
}
TARCHIVE         * ReorderArchive                          ( TARCHIVE        * list,
                                                             int               listBy )
{
  /* todo */
}
#ifndef __PROGTEST__
int                main                                    ( int               argc,
                                                             char            * argv [] )
{
  TARCHIVE * a;

  xt -> m_Engines
            && a -> m_Next -> m_Next -> m_Nea = NULL;
  /*a = AddEngine ( a, LIST_BY_YEAR, createEngine ( "TDI 1.9", 2010 ) );
   assert ( a
            && a -> m_Prev == NULL
            && a -> m_Engines
            && a -> m_Engines -> m_Year == 2010
            && ! strcmp ( a -> m_Engines -> m_Type, "TDI 1.9" )
            && a -> m_Engines -> m_Prev == NULL
            && a -> m_Engines -> m_Next == NULL
            && a -> m_Next == NULL 
            );
  a = AddEngine ( a, LIST_BY_YEAR, createEngine ( "TDI 1.9", 2005 ) );
   assert ( a
            && a -> m_Prev == NULL
            && a -> m_Engines
            && a -> m_Engines -> m_Year == 2005
            && ! strcmp ( a -> m_Engines -> m_Type, "TDI 1.9" )
            && a -> m_Engines -> m_Prev == NULL
            && a -> m_Engines -> m_Next == NULL
            && a -> m_Next
            && a -> m_Next -> m_Prev == a
            && a -> m_Next -> m_Engines
            && a -> m_Next -> m_Engines -> m_Year == 2010
            && ! strcmp ( a -> m_Next -> m_Engines -> m_Type, "TDI 1.9" )
            && a -> m_Next -> m_Engines -> m_Prev == NULL
            && a -> m_Next -> m_Engines -> m_Next == NULL
            && a -> m_Next -> m_Next == NULL );
  /*
  a = AddEngine ( a, LIST_BY_YEAR, createEngine ( "TSI 1.2", 2010 ) );
   assert ( a
            && a -> m_Prev == NULL
            && a -> m_Engines
            && a -> m_Engines -> m_Year == 2005
            && ! strcmp ( a -> m_Engines -> m_Type, "TDI 1.9" )
            && a -> m_Engines -> m_Prev == NULL
            && a -> m_Engines -> m_Next == NULL
            && a -> m_Next
            && a -> m_Next -> m_Prev == a
            && a -> m_Next -> m_Engines
            && a -> m_Next -> m_Engines -> m_Year == 2010
            && ! strcmp ( a -> m_Next -> m_Engines -> m_Type, "TDI 1.9" )
            && a -> m_Next -> m_Engines -> m_Prev == NULL
            && a -> m_Next -> m_Engines -> m_Next -> m_Year == 2010
            && ! strcmp ( a -> m_Next -> m_Engines -> m_Next -> m_Type, "TSI 1.2" )
            && a -> m_Next -> m_Engines -> m_Next -> m_Prev == a -> m_Next -> m_Engines
            && a -> m_Next -> m_Engines -> m_Next -> m_Next == NULL
            && a -> m_Next -> m_Next == NULL );
  a = AddEngine ( a, LIST_BY_YEAR, createEngine ( "TDI 2.0", 2005 ) );
   assert ( a
            && a -> m_Prev == NULL
            && a -> m_Engines
            && a -> m_Engines -> m_Year == 2005
            && ! strcmp ( a -> m_Engines -> m_Type, "TDI 1.9" )
            && a -> m_Engines -> m_Prev == NULL
            && a -> m_Engines -> m_Next -> m_Year == 2005
            && ! strcmp ( a -> m_Engines -> m_Next -> m_Type, "TDI 2.0" )
            && a -> m_Engines -> m_Next -> m_Prev == a -> m_Engines
            && a -> m_Engines -> m_Next -> m_Next == NULL
            && a -> m_Next
            && a -> m_Next -> m_Prev == a
            && a -> m_Next -> m_Engines
            && a -> m_Next -> m_Engines -> m_Year == 2010
            && ! strcmp ( a -> m_Next -> m_Engines -> m_Type, "TDI 1.9" )
            && a -> m_Next -> m_Engines -> m_Prev == NULL
            && a -> m_Next -> m_Engines -> m_Next -> m_Year == 2010
            && ! strcmp ( a -> m_Next -> m_Engines -> m_Next -> m_Type, "TSI 1.2" )
            && a -> m_Next -> m_Engines -> m_Next -> m_Prev == a -> m_Next -> m_Engines
            && a -> m_Next -> m_Engines -> m_Next -> m_Next == NULL
            && a -> m_Next -> m_Next == NULL );
  a = AddEngine ( a, LIST_BY_YEAR, createEngine ( "MPI 1.4", 2005 ) );
   assert ( a
            && a -> m_Prev == NULL
            && a -> m_Engines
            && a -> m_Engines -> m_Year == 2005
            && ! strcmp ( a -> m_Engines -> m_Type, "MPI 1.4" )
            && a -> m_Engines -> m_Prev == NULL
            && a -> m_Engines -> m_Next -> m_Year == 2005
            && ! strcmp ( a -> m_Engines -> m_Next -> m_Type, "TDI 1.9" )
            && a -> m_Engines -> m_Next -> m_Prev == a -> m_Engines
            && a -> m_Engines -> m_Next -> m_Next -> m_Year == 2005
            && ! strcmp ( a -> m_Engines -> m_Next -> m_Next -> m_Type, "TDI 2.0" )
            && a -> m_Engines -> m_Next -> m_Next -> m_Prev == a -> m_Engines -> m_Next
            && a -> m_Engines -> m_Next -> m_Next -> m_Next == NULL
            && a -> m_Next
            && a -> m_Next -> m_Prev == a
            && a -> m_Next -> m_Engines
            && a -> m_Next -> m_Engines -> m_Year == 2010
            && ! strcmp ( a -> m_Next -> m_Engines -> m_Type, "TDI 1.9" )
            && a -> m_Next -> m_Engines -> m_Prev == NULL
            && a -> m_Next -> m_Engines -> m_Next -> m_Year == 2010
            && ! strcmp ( a -> m_Next -> m_Engines -> m_Next -> m_Type, "TSI 1.2" )
            && a -> m_Next -> m_Engines -> m_Next -> m_Prev == a -> m_Next -> m_Engines
            && a -> m_Next -> m_Engines -> m_Next -> m_Next == NULL
            && a -> m_Next -> m_Next == NULL );
  a = ReorderArchive ( a, LIST_BY_TYPE );
   assert ( a
            && a -> m_Prev == NULL
            && a -> m_Engines
            && a -> m_Engines -> m_Year == 2005
            && ! strcmp ( a -> m_Engines -> m_Type, "MPI 1.4" )
            && a -> m_Engines -> m_Prev == NULL
            && a -> m_Engines -> m_Next == NULL
            && a -> m_Next
            && a -> m_Next -> m_Prev == a
            && a -> m_Next -> m_Engines
            && a -> m_Next -> m_Engines -> m_Year == 2005
            && ! strcmp ( a -> m_Next -> m_Engines -> m_Type, "TDI 1.9" )
            && a -> m_Next -> m_Engines -> m_Prev == NULL
            && a -> m_Next -> m_Engines -> m_Next -> m_Year == 2010
            && ! strcmp ( a -> m_Next -> m_Engines -> m_Next -> m_Type, "TDI 1.9" )
            && a -> m_Next -> m_Engines -> m_Next -> m_Prev == a -> m_Next -> m_Engines
            && a -> m_Next -> m_Engines -> m_Next -> m_Next == NULL
            && a -> m_Next -> m_Next
            && a -> m_Next -> m_Next -> m_Prev == a -> m_Next
            && a -> m_Next -> m_Next -> m_Engines
            && a -> m_Next -> m_Next -> m_Engines -> m_Year == 2005
            && ! strcmp ( a -> m_Next -> m_Next -> m_Engines -> m_Type, "TDI 2.0" )
            && a -> m_Next -> m_Next -> m_Engines -> m_Prev == NULL
            && a -> m_Next -> m_Next -> m_Engines -> m_Next == NULL
            && a -> m_Next -> m_Next -> m_Next
            && a -> m_Next -> m_Next -> m_Next -> m_Prev == a -> m_Next -> m_Next
            && a -> m_Next -> m_Next -> m_Next -> m_Engines -> m_Year == 2010
            && ! strcmp ( a -> m_Next -> m_Next -> m_Next -> m_Engines -> m_Type, "TSI 1.2" )
            && a -> m_Next -> m_Next -> m_Next -> m_Engines -> m_Prev == NULL
            && a -> m_Next -> m_Next -> m_Next -> m_Engines -> m_Next == NULL
            && a -> m_Next -> m_Next -> m_Next -> m_Next == NULL );
  DelArchive ( a );

  a = NULL;
  a = AddEngine ( a, LIST_BY_TYPE, createEngine ( "TDI 1.9", 2010 ) );
   assert ( a
            && a -> m_Prev == NULL
            && a -> m_Engines
            && a -> m_Engines -> m_Year == 2010
            && ! strcmp ( a -> m_Engines -> m_Type, "TDI 1.9" )
            && a -> m_Engines -> m_Prev == NULL
            && a -> m_Engines -> m_Next == NULL
            && a -> m_Next == NULL );
  a = AddEngine ( a, LIST_BY_TYPE, createEngine ( "TDI 1.9", 2005 ) );
   assert ( a
            && a -> m_Prev == NULL
            && a -> m_Engines
            && a -> m_Engines -> m_Year == 2005
            && ! strcmp ( a -> m_Engines -> m_Type, "TDI 1.9" )
            && a -> m_Engines -> m_Prev == NULL
            && a -> m_Engines -> m_Next -> m_Year == 2010
            && ! strcmp ( a -> m_Engines -> m_Next -> m_Type, "TDI 1.9" )
            && a -> m_Engines -> m_Next -> m_Prev == a -> m_Engines
            && a -> m_Engines -> m_Next -> m_Next == NULL
            && a -> m_Next == NULL );
  a = AddEngine ( a, LIST_BY_TYPE, createEngine ( "TSI 1.2", 2010 ) );
   assert ( a
            && a -> m_Prev == NULL
            && a -> m_Engines
            && a -> m_Engines -> m_Year == 2005
            && ! strcmp ( a -> m_Engines -> m_Type, "TDI 1.9" )
            && a -> m_Engines -> m_Prev == NULL
            && a -> m_Engines -> m_Next -> m_Year == 2010
            && ! strcmp ( a -> m_Engines -> m_Next -> m_Type, "TDI 1.9" )
            && a -> m_Engines -> m_Next -> m_Prev == a -> m_Engines
            && a -> m_Engines -> m_Next -> m_Next == NULL
            && a -> m_Next
            && a -> m_Next -> m_Prev == a
            && a -> m_Next -> m_Engines
            && a -> m_Next -> m_Engines -> m_Year == 2010
            && ! strcmp ( a -> m_Next -> m_Engines -> m_Type, "TSI 1.2" )
            && a -> m_Next -> m_Engines -> m_Prev == NULL
            && a -> m_Next -> m_Engines -> m_Next == NULL
            && a -> m_Next -> m_Next == NULL );
  a = AddEngine ( a, LIST_BY_TYPE, createEngine ( "TDI 2.0", 2005 ) );
   assert ( a
            && a -> m_Prev == NULL
            && a -> m_Engines
            && a -> m_Engines -> m_Year == 2005
            && ! strcmp ( a -> m_Engines -> m_Type, "TDI 1.9" )
            && a -> m_Engines -> m_Prev == NULL
            && a -> m_Engines -> m_Next -> m_Year == 2010
            && ! strcmp ( a -> m_Engines -> m_Next -> m_Type, "TDI 1.9" )
            && a -> m_Engines -> m_Next -> m_Prev == a -> m_Engines
            && a -> m_Engines -> m_Next -> m_Next == NULL
            && a -> m_Next
            && a -> m_Next -> m_Prev == a
            && a -> m_Next -> m_Engines
            && a -> m_Next -> m_Engines -> m_Year == 2005
            && ! strcmp ( a -> m_Next -> m_Engines -> m_Type, "TDI 2.0" )
            && a -> m_Next -> m_Engines -> m_Prev == NULL
            && a -> m_Next -> m_Engines -> m_Next == NULL
            && a -> m_Next -> m_Next
            && a -> m_Next -> m_Next -> m_Prev == a -> m_Next
            && a -> m_Next -> m_Next -> m_Engines
            && a -> m_Next -> m_Next -> m_Engines -> m_Year == 2010
            && ! strcmp ( a -> m_Next -> m_Next -> m_Engines -> m_Type, "TSI 1.2" )
            && a -> m_Next -> m_Next -> m_Engines -> m_Prev == NULL
            && a -> m_Next -> m_Next -> m_Engines -> m_Next == NULL
            && a -> m_Next -> m_Next -> m_Next == NULL );
  a = AddEngine ( a, LIST_BY_TYPE, createEngine ( "MPI 1.4", 2005 ) );
   assert ( a
            && a -> m_Prev == NULL
            && a -> m_Engines
            && a -> m_Engines -> m_Year == 2005
            && ! strcmp ( a -> m_Engines -> m_Type, "MPI 1.4" )
            && a -> m_Engines -> m_Prev == NULL
            && a -> m_Engines -> m_Next == NULL
            && a -> m_Next
            && a -> m_Next -> m_Prev == a
            && a -> m_Next -> m_Engines
            && a -> m_Next -> m_Engines -> m_Year == 2005
            && ! strcmp ( a -> m_Next -> m_Engines -> m_Type, "TDI 1.9" )
            && a -> m_Next -> m_Engines -> m_Prev == NULL
            && a -> m_Next -> m_Engines -> m_Next -> m_Year == 2010
            && ! strcmp ( a -> m_Next -> m_Engines -> m_Next -> m_Type, "TDI 1.9" )
            && a -> m_Next -> m_Engines -> m_Next -> m_Prev == a -> m_Next -> m_Engines
            && a -> m_Next -> m_Engines -> m_Next -> m_Next == NULL
            && a -> m_Next -> m_Next
            && a -> m_Next -> m_Next -> m_Prev == a -> m_Next
            && a -> m_Next -> m_Next -> m_Engines
            && a -> m_Next -> m_Next -> m_Engines -> m_Year == 2005
            && ! strcmp ( a -> m_Next -> m_Next -> m_Engines -> m_Type, "TDI 2.0" )
            && a -> m_Next -> m_Next -> m_Engines -> m_Prev == NULL
            && a -> m_Next -> m_Next -> m_Engines -> m_Next == NULL
            && a -> m_Next -> m_Next -> m_Next
            && a -> m_Next -> m_Next -> m_Next -> m_Prev == a -> m_Next -> m_Next
            && a -> m_Next -> m_Next -> m_Next -> m_Engines
            && a -> m_Next -> m_Next -> m_Next -> m_Engines -> m_Year == 2010
            && ! strcmp ( a -> m_Next -> m_Next -> m_Next -> m_Engines -> m_Type, "TSI 1.2" )
            && a -> m_Next -> m_Next -> m_Next -> m_Engines -> m_Prev == NULL
            && a -> m_Next -> m_Next -> m_Next -> m_Engines -> m_Next == NULL
            && a -> m_Next -> m_Next -> m_Next -> m_Next == NULL );
  a = AddEngine ( a, LIST_BY_TYPE, createEngine ( "TDI 1.9", 2010 ) );
   assert ( a
            && a -> m_Prev == NULL
            && a -> m_Engines
            && a -> m_Engines -> m_Year == 2005
            && ! strcmp ( a -> m_Engines -> m_Type, "MPI 1.4" )
            && a -> m_Engines -> m_Prev == NULL
            && a -> m_Engines -> m_Next == NULL
            && a -> m_Next
            && a -> m_Next -> m_Prev == a
            && a -> m_Next -> m_Engines
            && a -> m_Next -> m_Engines -> m_Year == 2005
            && ! strcmp ( a -> m_Next -> m_Engines -> m_Type, "TDI 1.9" )
            && a -> m_Next -> m_Engines -> m_Prev == NULL
            && a -> m_Next -> m_Engines -> m_Next -> m_Year == 2010
            && ! strcmp ( a -> m_Next -> m_Engines -> m_Next -> m_Type, "TDI 1.9" )
            && a -> m_Next -> m_Engines -> m_Next -> m_Prev == a -> m_Next -> m_Engines
            && a -> m_Next -> m_Engines -> m_Next -> m_Next -> m_Year == 2010
            && ! strcmp ( a -> m_Next -> m_Engines -> m_Next -> m_Next -> m_Type, "TDI 1.9" )
            && a -> m_Next -> m_Engines -> m_Next -> m_Next -> m_Prev == a -> m_Next -> m_Engines -> m_Next
            && a -> m_Next -> m_Engines -> m_Next -> m_Next -> m_Next == NULL
            && a -> m_Next -> m_Next
            && a -> m_Next -> m_Next -> m_Prev == a -> m_Next
            && a -> m_Next -> m_Next -> m_Engines
            && a -> m_Next -> m_Next -> m_Engines -> m_Year == 2005
            && ! strcmp ( a -> m_Next -> m_Next -> m_Engines -> m_Type, "TDI 2.0" )
            && a -> m_Next -> m_Next -> m_Engines -> m_Prev == NULL
            && a -> m_Next -> m_Next -> m_Engines -> m_Next == NULL
            && a -> m_Next -> m_Next -> m_Next
            && a -> m_Next -> m_Next -> m_Next -> m_Prev == a -> m_Next -> m_Next
            && a -> m_Next -> m_Next -> m_Next -> m_Engines
            && a -> m_Next -> m_Next -> m_Next -> m_Engines -> m_Year == 2010
            && ! strcmp ( a -> m_Next -> m_Next -> m_Next -> m_Engines -> m_Type, "TSI 1.2" )
            && a -> m_Next -> m_Next -> m_Next -> m_Engines -> m_Prev == NULL
            && a -> m_Next -> m_Next -> m_Next -> m_Engines -> m_Next == NULL
            && a -> m_Next -> m_Next -> m_Next -> m_Next == NULL );
  a = ReorderArchive ( a, LIST_BY_YEAR );
   assert ( a
            && a -> m_Prev == NULL
            && a -> m_Engines
            && a -> m_Engines -> m_Year == 2005
            && ! strcmp ( a -> m_Engines -> m_Type, "MPI 1.4" )
            && a -> m_Engines -> m_Prev == NULL
            && a -> m_Engines -> m_Next -> m_Year == 2005
            && ! strcmp ( a -> m_Engines -> m_Next -> m_Type, "TDI 1.9" )
            && a -> m_Engines -> m_Next -> m_Prev == a -> m_Engines
            && a -> m_Engines -> m_Next -> m_Next -> m_Year == 2005
            && ! strcmp ( a -> m_Engines -> m_Next -> m_Next -> m_Type, "TDI 2.0" )
            && a -> m_Engines -> m_Next -> m_Next -> m_Prev == a -> m_Engines -> m_Next
            && a -> m_Engines -> m_Next -> m_Next -> m_Next == NULL
            && a -> m_Next
            && a -> m_Next -> m_Prev == a
            && a -> m_Next -> m_Engines
            && a -> m_Next -> m_Engines -> m_Year == 2010
            && ! strcmp ( a -> m_Next -> m_Engines -> m_Type, "TDI 1.9" )
            && a -> m_Next -> m_Engines -> m_Prev == NULL
            && a -> m_Next -> m_Engines -> m_Next -> m_Year == 2010
            && ! strcmp ( a -> m_Next -> m_Engines -> m_Next -> m_Type, "TDI 1.9" )
            && a -> m_Next -> m_Engines -> m_Next -> m_Prev == a -> m_Next -> m_Engines
            && a -> m_Next -> m_Engines -> m_Next -> m_Next -> m_Year == 2010
            && ! strcmp ( a -> m_Next -> m_Engines -> m_Next -> m_Next -> m_Type, "TSI 1.2" )
            && a -> m_Next -> m_Engines -> m_Next -> m_Next -> m_Prev == a -> m_Next -> m_Engines -> m_Next
            && a -> m_Next -> m_Engines -> m_Next -> m_Next -> m_Next == NULL
            && a -> m_Next -> m_Next == NULL );
  DelArchive ( a );*/

  return 0;
}
#endif /* __PROGTEST__ */