/***************************************************************************************************************************************************/

#include <stdio.h>

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

#include "ArrayList.h"
#include "ListImplementation.h"

/***************************************************************************************************************************************************/




/***************************************************************************************************************************************************/

#define IAL(list)  ( * ( (ArrayList *) ((list)->pInternalList) ) )  /* Internal ArrayList */

/***************************************************************************************************************************************************/




/***************************************************************************************************************************************************/

static ListBoolean   alAdd           ( List list , ListElement element , int index                     ) ;
static ListBoolean   alAddAll        ( List list , List other , int index                              ) ;
static void          alClear         ( List list                                                       ) ;
static ListBoolean   alContains      ( List list , ListElement element                                 ) ;
static ListBoolean   alContainsAll   ( List list , List other                                          ) ;
static ListBoolean   alEquals        ( List list , List other                                          ) ;
static ListElement   alGet           ( List list , int index                                           ) ;
static int           alIndexOf       ( List list , ListElement element                                 ) ;
static ListBoolean   alIsEmpty       ( List list                                                       ) ;
static int           alLastIndexOf   ( List list , ListElement element                                 ) ;
static ListElement   alRemove        ( List list , int index                                           ) ;
static ListBoolean   alRemoveElement ( List list , ListElement element                                 ) ;
static ListBoolean   alRemoveAll     ( List list , List other                                          ) ;
static void          alReplaceAll    ( List list , ListElementUnaryOperator uOperator                  ) ;
static ListBoolean   alRetainAll     ( List list , List other                                          ) ;
static ListElement   alSet           ( List list , int index , ListElement element                     ) ;
static int           alSize          ( List list                                                       ) ;
static ListBoolean   alSort          ( List list , ListElementComparisonFunction compare               ) ;
static ListElement * alToArray       ( List list                                                       ) ;
static void          alPrint         ( List list , char * listName , ListElementPrintingFunction print ) ;
static void          alDestroy       ( List list                                                       ) ;

/***************************************************************************************************************************************************/




/* This is a suggested data structure (you may change it if you wish) ******************************************************************************/

typedef struct arrayList
{
  int           numberOfElements ;
  size_t        arraySize        ;
  ListElement * array            ;
}
ArrayList ;

/***************************************************************************************************************************************************/




/***************************************************************************************************************************************************/

static void setFunctionPointers ( List list )
{
  list->add           = alAdd           ;
  list->addAll        = alAddAll        ;
  list->clear         = alClear         ;
  list->contains      = alContains      ;
  list->containsAll   = alContainsAll   ;
  list->equals        = alEquals        ;
  list->get           = alGet           ;
  list->indexOf       = alIndexOf       ;
  list->isEmpty       = alIsEmpty       ;
  list->lastIndexOf   = alLastIndexOf   ;
  list->remove        = alRemove        ;
  list->removeElement = alRemoveElement ;
  list->removeAll     = alRemoveAll     ;
  list->replaceAll    = alReplaceAll    ;
  list->retainAll     = alRetainAll     ;
  list->set           = alSet           ;
  list->size          = alSize          ;
  list->sort          = alSort          ;
  list->toArray       = alToArray       ;
  list->print         = alPrint         ;
  list->destroy       = alDestroy       ;
}

/***************************************************************************************************************************************************/




/***************************************************************************************************************************************************/

List createArrayList ( int initialCapacity )
{
}

/*=================================================================================================================================================*/

List createArrayListFrom ( List other )  /* 'other' list can be implemented using linked lists or other underlying data structures */
{
}

/***************************************************************************************************************************************************/




/***************************************************************************************************************************************************/

ListBoolean alAdd ( List list , ListElement element , int index )
{
}

/*=================================================================================================================================================*/

ListBoolean alAddAll ( List list , List other , int index )
{
}

/*=================================================================================================================================================*/

void alClear ( List list )
{
}

/*=================================================================================================================================================*/

ListBoolean alContains ( List list , ListElement element )
{
}

/*=================================================================================================================================================*/

ListBoolean alContainsAll ( List list , List other )
{
}

/*=================================================================================================================================================*/

ListBoolean alEquals ( List list , List other )
{
}

/*=================================================================================================================================================*/

ListElement alGet ( List list , int index )
{
}

/*=================================================================================================================================================*/

int alIndexOf ( List list , ListElement element )
{
}

/*=================================================================================================================================================*/

ListBoolean alIsEmpty ( List list )
{
}

/*=================================================================================================================================================*/

int alLastIndexOf ( List list , ListElement element )
{
}

/*=================================================================================================================================================*/

ListElement alRemove ( List list , int index )
{
}

/*=================================================================================================================================================*/

ListBoolean alRemoveElement ( List list , ListElement element )
{
}

/*=================================================================================================================================================*/

ListBoolean alRemoveAll ( List list , List other )
{
}

/*=================================================================================================================================================*/

void alReplaceAll ( List list , ListElementUnaryOperator uOperator )
{
}

/*=================================================================================================================================================*/

ListBoolean alRetainAll ( List list , List other )
{
}

/*=================================================================================================================================================*/

ListElement alSet ( List list , int index , ListElement element )
{
}

/*=================================================================================================================================================*/

int alSize ( List list )
{
}

/*=================================================================================================================================================*/

ListBoolean alSort ( List list , ListElementComparisonFunction compare )
{
}

/*=================================================================================================================================================*/

ListElement * alToArray ( List list )
{
}

/*=================================================================================================================================================*/

void alPrint ( List list , char * listName , ListElementPrintingFunction print )
{
}

/*=================================================================================================================================================*/

void alDestroy ( List list )
{
}

/***************************************************************************************************************************************************/
