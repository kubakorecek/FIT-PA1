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

//void push_front_archive_by_year(TARCHIVE ** head_list,TARCHIVE * new_arch, TENGINE ** engine);
void insert_sorted_arch_by_year(TARCHIVE ** head_list,TENGINE ** engine);
void push_front_engine(TENGINE ** head_list, TENGINE ** new_engine);
void push_front_archive(TARCHIVE ** head_list,TARCHIVE * new_arch, TENGINE ** engine);
void insert_sorted_eng_by_type(TENGINE ** head_list,TENGINE ** engine);
TARCHIVE         * AddEngine                               ( TARCHIVE        * list,
                                                             int               listBy,
                                                             TENGINE         * engine )
{
  insert_sorted_arch_by_year(&list,&engine);
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

  a = NULL;
  a = AddEngine ( a, LIST_BY_YEAR, createEngine ( "TDI 1.9", 2010 ) );
   assert ( a
            && a -> m_Prev == NULL
            && a -> m_Engines
            && a -> m_Engines -> m_Year == 2010
            && ! strcmp ( a -> m_Engines -> m_Type, "TDI 1.9" )
            && a -> m_Engines -> m_Prev == NULL
            && a -> m_Engines -> m_Next == NULL
            && a -> m_Next == NULL );
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
  /*a = ReorderArchive ( a, LIST_BY_TYPE );
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
            && a -> m_Next -> m_Next -> m_Next -> m_Next == NULL );*/
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
  /*a = ReorderArchive ( a, LIST_BY_YEAR );
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
            && a -> m_Next -> m_Next == NULL );*/
  DelArchive ( a );

  return 0;
}
#endif /* __PROGTEST__ */


TARCHIVE * initialize_archive_node(){
  TARCHIVE * new_arch = (TARCHIVE *)malloc(sizeof(*new_arch));
  
    if(!new_arch){
        printf("Allocation fail!\n");
    }
  return new_arch; 
}


void insert_sorted_arch_by_year(TARCHIVE ** head_list,TENGINE ** engine){
    //TARCHIVE * current_archive;
    /*archive must me ascending by year*/
    
    //;
    /*archive is empty or the Year is smallest then go front */
    if((*head_list)==NULL || (*head_list)->m_Engines->m_Year > (*engine)->m_Year){
       TARCHIVE * new_archive = initialize_archive_node();
       push_front_archive(head_list,new_archive,engine);
       return;
    }else{
      TARCHIVE * current_arch = (*head_list);
      //new_archive->m_Engines = (*engine);
      while(current_arch->m_Next)/*blbost*/
      {
        if(current_arch->m_Engines->m_Year == (*engine)->m_Year){
          insert_sorted_eng_by_type(&(current_arch->m_Engines),engine);
          return;
        }
        if(
          //current_arch->m_Engines->m_Year > new_archive->m_Engines->m_Year
          current_arch->m_Engines->m_Year > (*engine)->m_Year
          
          ){
          TARCHIVE * new_archive = initialize_archive_node();
          new_archive->m_Engines = (*engine);  
          break;

        }
        current_arch = current_arch->m_Next;
      }
      TARCHIVE * new_archive = initialize_archive_node();
      new_archive->m_Engines = (*engine);
      new_archive->m_Next=current_arch->m_Next;

      if(current_arch->m_Next !=NULL){
        new_archive->m_Next->m_Prev=new_archive;
      }
      current_arch->m_Next = new_archive;
      new_archive->m_Prev = current_arch;
            
      

    }

}
void insert_sorted_eng_by_type(TENGINE ** head_list,TENGINE ** engine){
      TENGINE * new_engine = (*engine);
      if((*head_list)==NULL || strcmp((*head_list)->m_Type,new_engine->m_Type)>0){
       push_front_engine(head_list,&new_engine);
       return;
    }else{
      TENGINE * current_engine = (*head_list);
      while(current_engine->m_Next)
      {
        if(
          strcmp(current_engine->m_Type,new_engine->m_Type)>0
          ){
          break;

        }
        current_engine = current_engine->m_Next;
      }
      new_engine->m_Next=current_engine->m_Next;

      if(current_engine->m_Next !=NULL){
        new_engine->m_Next->m_Prev=new_engine;
      }
      current_engine->m_Next = new_engine;
      new_engine->m_Prev = current_engine;
    }

} 
void push_front_engine(TENGINE ** head_list, TENGINE ** new_engine){


    /*since it is first prev node must me NULL*/
    (*new_engine)->m_Prev=NULL;
    /*save head of current list*/
    (*new_engine)->m_Next=(*head_list);
       

    /*shift head to new engine */
    if((*head_list)!=NULL){
        (*head_list)->m_Prev=(*new_engine);
    }
    (*head_list)=(*new_engine);



}

/*this procedure will add node at the start of the archive*/
void push_front_archive(TARCHIVE ** head_list,TARCHIVE * new_arch, TENGINE ** engine){
    /* Memory allocation */#
    

    /* add data to the new archive node*/
    /* engine should have all pointers done in other rutine*/
    
    TENGINE * new_engine = (*engine);
    push_front_engine(&(new_arch -> m_Engines),&new_engine);
    new_arch -> m_Engines = (*engine);
    /*since it is first, it must me pointing to NULL at start*/
    new_arch ->m_Prev =NULL;

    /*shift the head of list*/
    new_arch -> m_Next = (*head_list);

    /* now the head of old must set its previous node to new one*/
    if((*head_list)!=NULL){
        (*head_list)->m_Prev=new_arch;
    }
    /*shift head*/
    (*head_list)=new_arch;
}


