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
void insert_sorted_arch_by_year(TARCHIVE ** head_list,TENGINE ** engine);
void insert_sorted_arch_by_type(TARCHIVE ** head_list,TENGINE ** engine);
TARCHIVE * initialize_archive_node();
void set_engine_by_type(TENGINE ** engines_list,TENGINE ** engine);
void set_engine_by_year(TENGINE ** engines_list,TENGINE ** engine);
void set_front_engine(TENGINE ** first_engine,TENGINE ** engine);
void push_front_archive(TARCHIVE ** head_list,TARCHIVE ** new_arch);
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

TARCHIVE         * AddEngine                               ( TARCHIVE        * list,
                                                             int               listBy,
                                                             TENGINE         * engine )
{
  if(listBy==LIST_BY_YEAR){
      insert_sorted_arch_by_year(&list,&engine);
  }else if(listBy==LIST_BY_TYPE){
insert_sorted_arch_by_type(&list,&engine);
  }
    
    
  
  return list;
}
void               DelArchive                              ( TARCHIVE        * list )
{
  TARCHIVE * current = list; 
 while(current!=NULL)
 {
     
    TARCHIVE * next = current->m_Next;
    TENGINE * current_engine = current->m_Engines;
    while(current_engine !=NULL){
      TENGINE * next_engine = current_engine->m_Next;
      free(current_engine);
      current_engine=next_engine;

    }
    free(current);
    current = next;
  }
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
  a = AddEngine ( a, LIST_BY_TYPE, createEngine ( "TDI 1.9", 2010 ) );
   a = AddEngine ( a, LIST_BY_TYPE, createEngine ( "TDI 1.9", 2005 ) );
  
  a = AddEngine ( a, LIST_BY_TYPE, createEngine ( "TSI 1.2", 2010 ) );
    a = AddEngine ( a, LIST_BY_TYPE, createEngine ( "TDI 2.0", 2005 ) );
     a = AddEngine ( a, LIST_BY_TYPE, createEngine ( "MPI 1.4", 2005 ) );
   
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
            && a -> m_Next -> m_Next -> m_Next -> m_Next == NULL);
     return 0;
}
#endif /* __PROGTEST__ */
TARCHIVE * initialize_archive_node(){
  TARCHIVE * new_arch = (TARCHIVE *)malloc(sizeof(*new_arch));
  
    if(!new_arch){
        printf("Allocation fail!\n");
    }
    new_arch->m_Engines=NULL;
    new_arch->m_Next=NULL;
    new_arch->m_Prev=NULL;
  return new_arch; 
}

void insert_sorted_arch_by_type(TARCHIVE ** head_list,TENGINE ** engine)
{
   
     
        if(((*head_list)==NULL) || 
             
         strcmp((*head_list)->m_Engines->m_Type,(*engine)->m_Type)>0
        )
         
        {   
             TARCHIVE * new_archive = initialize_archive_node();
            set_front_engine(&(new_archive->m_Engines),engine);
            push_front_archive(head_list,&new_archive);
            return;
            
        }else{
            TARCHIVE * current_arch = (*head_list);
      while(current_arch->m_Next)
      {
        if(strcmp(current_arch->m_Next->m_Engines->m_Type,(*engine)->m_Type)>0
          || strcmp(current_arch->m_Engines->m_Type,(*engine)->m_Type)==0
        )
        {
          break;
        }

        current_arch = current_arch->m_Next;
      }
   
       
       if(
        strcmp(current_arch->m_Engines->m_Type,(*engine)->m_Type)==0
      ){
        set_engine_by_year(&(current_arch->m_Engines),engine);
      }else{      
      TARCHIVE * new_archive = initialize_archive_node();
      new_archive->m_Engines = (*engine);
      new_archive->m_Next=current_arch->m_Next;

      if(current_arch->m_Next !=NULL){
        new_archive->m_Next->m_Prev=new_archive;
      }
      current_arch->m_Next = new_archive;
      new_archive->m_Prev = current_arch;
      return;
      }
        } 

}
void set_engine_by_type(TENGINE ** engines_list,TENGINE ** engine){
    if((*engines_list)==NULL || strcmp((*engines_list)->m_Type,(*engine)->m_Type)>0){
       set_front_engine(engines_list,engine);
       return;
}else{
   TENGINE * current_engine = (*engines_list);
      while(current_engine->m_Next)
      {
        if(
          strcmp(current_engine->m_Next->m_Type,(*engine)->m_Type)>0
          ){
          break;

        }
        current_engine = current_engine->m_Next;
      }
      (*engine)->m_Next=current_engine->m_Next;

      if(current_engine->m_Next !=NULL){
        (*engine)->m_Next->m_Prev=(*engine);
      }
      current_engine->m_Next = (*engine);
      (*engine)->m_Prev = current_engine;
    } 
}



void insert_sorted_arch_by_year(TARCHIVE ** head_list,TENGINE ** engine)
{

        if(((*head_list)==NULL) || (*head_list)->m_Engines->m_Year > (*engine)->m_Year){
            TARCHIVE * new_archive = initialize_archive_node();
            set_front_engine(&(new_archive->m_Engines),engine);
            push_front_archive(head_list,&new_archive);
            return;
            
        }else{
            TARCHIVE * current_arch = (*head_list);
      while(current_arch->m_Next)
      {

        if(
          //(*engine)->m_Year <=current_arch->m_Engines->m_Year
          current_arch->m_Next->m_Engines->m_Year == (*engine)->m_Year
          || current_arch->m_Next->m_Engines->m_Year > (*engine)->m_Year
          ){
          break;
        }
        current_arch = current_arch->m_Next;
      }
      //printf("%d WTF\n",current_arch->m_Engines->m_Year == (*engine)->m_Year);
      /*if(current_arch->m_Engines->m_Year > (*engine)->m_Year){
        TARCHIVE * new_archive = initialize_archive_node();
        set_front_engine(&(new_archive->m_Engines),engine);
        push_front_archive(head_list,&new_archive);
        return; */   
      //}else 
      if(current_arch->m_Next->m_Engines->m_Year == (*engine)->m_Year){
        set_engine_by_type(&(current_arch->m_Next->m_Engines),engine);
      }else{      
      TARCHIVE * new_archive = initialize_archive_node();
      new_archive->m_Engines = (*engine);
      new_archive->m_Next=current_arch->m_Next;

      if(current_arch->m_Next !=NULL){
        new_archive->m_Next->m_Prev=new_archive;
      }
      current_arch->m_Next = new_archive;
      new_archive->m_Prev = current_arch;
      return;
      }
        } 

}
/*
void set_engine_by_type(TENGINE ** engines_list,TENGINE ** engine){
    if((*engines_list)==NULL || strcmp((*engines_list)->m_Type,(*engine)->m_Type)>0){
       set_front_engine(engines_list,engine);
       return;
}else{
   TENGINE * current_engine = (*engines_list);
      while(current_engine->m_Next)
      {
        if(
          strcmp(current_engine->m_Type,(*engine)->m_Type)>0
          ){
          break;

        }
        current_engine = current_engine->m_Next;
      }
      (*engine)->m_Next=current_engine->m_Next;

      if(current_engine->m_Next !=NULL){
        (*engine)->m_Next->m_Prev=(*engine);
      }
      current_engine->m_Next = (*engine);
      (*engine)->m_Prev = current_engine;
    } 
}
*/

void set_front_engine(TENGINE ** first_engine,TENGINE ** engine){
    (*engine)->m_Prev=NULL;
    (*engine)->m_Next=(*first_engine);
    if((*first_engine)!=NULL){
        (*first_engine)->m_Prev=(*engine);
    }
    (*first_engine)=(*engine);
}
void push_front_archive(TARCHIVE ** head_list,TARCHIVE ** new_arch){
    (*new_arch) ->m_Prev =NULL;
    (*new_arch) -> m_Next = (*head_list);
    if((*head_list)!=NULL){
        (*head_list)->m_Prev=(*new_arch) ;
    }
    /*shift head*/
    (*head_list)=(*new_arch) ;
}
void set_engine_by_year(TENGINE ** engines_list,TENGINE ** engine){
if((*engines_list)==NULL || (*engines_list)->m_Year> (*engine)->m_Year){
       set_front_engine(engines_list,engine);
       return;
}else{
   TENGINE * current_engine = (*engines_list);
      while(current_engine->m_Next)
      {
        if(
          current_engine->m_Next->m_Year > (*engine)->m_Year
            ){
          break;

        }
        current_engine = current_engine->m_Next;
      }
      (*engine)->m_Next=current_engine->m_Next;

      if(current_engine->m_Next !=NULL){
        (*engine)->m_Next->m_Prev=(*engine);
      }
      current_engine->m_Next = (*engine);
      (*engine)->m_Prev = current_engine;
    } 

}
