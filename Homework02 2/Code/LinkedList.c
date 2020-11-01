/***************************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

#include "LinkedList.h"
#include "ListImplementation.h"

/***************************************************************************************************************************************************/




/***************************************************************************************************************************************************/

#define ILL(list)  ( * ( (LinkedList *) ((list)->pInternalList) ) )  /* Internal LinkedList */
/***************************************************************************************************************************************************/




/***************************************************************************************************************************************************/

static ListBoolean   llAdd           ( List list , ListElement element , int index                     ) ;
static ListBoolean   llAddAll        ( List list , List other , int index                              ) ;
static void          llClear         ( List list                                                       ) ;
static ListBoolean   llContains      ( List list , ListElement element                                 ) ;
static ListBoolean   llContainsAll   ( List list , List other                                          ) ;
static ListBoolean   llEquals        ( List list , List other                                          ) ;
static ListElement   llGet           ( List list , int index                                           ) ;
static int           llIndexOf       ( List list , ListElement element                                 ) ;
static ListBoolean   llIsEmpty       ( List list                                                       ) ;
static int           llLastIndexOf   ( List list , ListElement element                                 ) ;
static ListElement   llRemove        ( List list , int index                                           ) ;
static ListBoolean   llRemoveElement ( List list , ListElement element                                 ) ;
static ListBoolean   llRemoveAll     ( List list , List other                                          ) ;
static void          llReplaceAll    ( List list , ListElementUnaryOperator uOperator                  ) ;
static ListBoolean   llRetainAll     ( List list , List other                                          ) ;
static ListElement   llSet           ( List list , int index , ListElement element                     ) ;
static int           llSize          ( List list                                                       ) ;
static ListBoolean   llSort          ( List list , ListElementComparisonFunction compare               ) ;
static ListElement * llToArray       ( List list                                                       ) ;
static void          llPrint         ( List list , char * listName , ListElementPrintingFunction print ) ;
static void          llDestroy       ( List list                                                       ) ;

/***************************************************************************************************************************************************/




/* This is a suggested data structure (you may change it if you wish) ******************************************************************************/

typedef struct node
{
  ListElement   element ;
  struct node * next    ;
}
Node ;

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

typedef struct linkedList
{
  int    numberOfElements ;
  Node * pHead            ;
  Node * pTail            ;
}
LinkedList ;

/***************************************************************************************************************************************************/




/***************************************************************************************************************************************************/

static void setFunctionPointers ( List list )
{
  list->add           = llAdd           ;
  list->addAll        = llAddAll        ;
  list->clear         = llClear         ;
  list->contains      = llContains      ;
  list->containsAll   = llContainsAll   ;
  list->equals        = llEquals        ;
  list->get           = llGet           ;
  list->indexOf       = llIndexOf       ;
  list->isEmpty       = llIsEmpty       ;
  list->lastIndexOf   = llLastIndexOf   ;
  list->remove        = llRemove        ;
  list->removeElement = llRemoveElement ;
  list->removeAll     = llRemoveAll     ;
  list->replaceAll    = llReplaceAll    ;
  list->retainAll     = llRetainAll     ;
  list->set           = llSet           ;
  list->size          = llSize          ;
  list->sort          = llSort          ;
  list->toArray       = llToArray       ;
  list->print         = llPrint         ;
  list->destroy       = llDestroy       ;
}

/***************************************************************************************************************************************************/




/***************************************************************************************************************************************************/

List createLinkedList ( void )
{
    LinkedList * linkedList = malloc( sizeof( LinkedList ) ) ;
    List list = malloc(sizeof(List));
    linkedList->numberOfElements = 0;
    linkedList->pHead = NULL;
    linkedList->pTail = NULL;
    list->pInternalList = linkedList;
    setFunctionPointers(list);
    return list;
}

/*=================================================================================================================================================*/

List createLinkedListFrom ( List other )  /* 'other' list can be implemented using arrays or other underlying data structures */
{
    ListElement* elements = llToArray(other);

    LinkedList * linkedList = malloc( sizeof( LinkedList ) ) ;
    List list = malloc(sizeof(List));
    list->pInternalList = linkedList;
    setFunctionPointers(list);
    printf("size %d\n", llSize(other));
    for (int i = 0; i < llSize(other); ++i) {
        llAdd(list, *(elements++), LIST_NA);
    }
    return list;
}

/***************************************************************************************************************************************************/

ListBoolean isPointerCreated(void* ptr) {
    return (ptr != NULL) ? True : False;
}
ListBoolean isValidIndex(List list, int index) {
    return (index < 0 || index > ILL(list).numberOfElements) ? False : True;
}

Node* getPrevNode(List list, int index) {
    if (index == ILL(list).numberOfElements || index == LIST_NA) {
        return ILL(list).pTail;
    } if (!index) {
        return NULL;
    } if (index == LIST_NA || index == ILL(list).numberOfElements)
        return ILL(list).pTail;
    Node* cur = ILL(list).pHead;
    while (--index > 0) {
        cur = cur->next;
    }
    return cur;
}


/***************************************************************************************************************************************************/

ListBoolean llAdd ( List list , ListElement element , int index )
{
    Node* newNode = malloc( sizeof( Node ) ) ;
    printf("ADDsize %d\n", llSize(list));
    if ((!isValidIndex(list, index) && index != LIST_NA) || !isPointerCreated(newNode))
        return False;
    newNode->element = element;
    newNode->next = NULL;
    Node* prevNode = getPrevNode(list, index);
    if (!ILL(list).numberOfElements) {
        ILL(list).pHead = newNode;
        ILL(list).pTail = newNode;
    } else if (prevNode == NULL && index == 0) {
        newNode->next = ILL(list).pHead;
        ILL(list).pHead = newNode;
    } else {
        Node *next = prevNode->next;
        prevNode->next = newNode;
        newNode->next = next;
        if (index == ILL(list).numberOfElements || index == LIST_NA)
            ILL(list).pTail = newNode, ILL(list).pTail->next = NULL;
    }
    ILL(list).numberOfElements++;
    return True;
}

/*=================================================================================================================================================*/

ListBoolean llAddAll ( List list , List other , int index )
{
    List newList = list;
    if ((!isValidIndex(list, index) && index != LIST_NA))
        return False;
    Node* prevNode = getPrevNode(list, index);
    if (!ILL(list).numberOfElements) {
        ILL(list).pTail = ILL(newList).pTail;
        ILL(list).pHead = ILL(newList).pHead;
    } else if (!index) {
        ILL(newList).pTail->next = ILL(list).pHead;
        ILL(list).pHead = ILL(newList).pHead;
    } else {
        Node* next = prevNode->next;
        prevNode->next = ILL(newList).pHead;
        ILL(newList).pTail->next = next;
        if (index == ILL(list).numberOfElements || index == LIST_NA)
            ILL(list).pTail = ILL(newList).pTail;
    }
    ILL(list).numberOfElements += ILL(other).numberOfElements;
    return True;
}

/*=================================================================================================================================================*/

void llClear ( List list )
{
    Node* next = NULL;
    while (ILL(list).pHead) {
        next =  ILL(list).pHead->next;
        ILL(list).pHead = NULL;
        free(ILL(list).pHead);
        ILL(list).pHead = next;
    }
    next = NULL;
    free(next);
    ILL(list).numberOfElements = 0;
}

/*=================================================================================================================================================*/

ListBoolean llContains ( List list , ListElement element )
{
    Node* cur = ILL(list).pHead;
    while (cur) {
        if (cur->element == element) {
            return True;
        }
        cur = cur->next;
    }
    return False;
}

/*=================================================================================================================================================*/

ListBoolean llContainsAll ( List list , List other )
{

}

/*=================================================================================================================================================*/

ListBoolean llEquals ( List list , List other )
{
}

/*=================================================================================================================================================*/

ListElement llGet ( List list , int index )
{
    if (!isValidIndex(list, index))
        return NULL;
    Node* cur = ILL(list).pHead;

    while ((index--) >= 0) {
        printf(index);
        cur = cur->next;
        return NULL;
    }
    return cur->element;
}

/*=================================================================================================================================================*/

int llIndexOf ( List list , ListElement element )
{
}

/*=================================================================================================================================================*/

ListBoolean llIsEmpty ( List list )
{
}

/*=================================================================================================================================================*/

int llLastIndexOf ( List list , ListElement element )
{
}

/*=================================================================================================================================================*/

ListElement llRemove ( List list , int index )
{
}

/*=================================================================================================================================================*/

ListBoolean llRemoveElement ( List list , ListElement element )
{
}

/*=================================================================================================================================================*/

ListBoolean llRemoveAll ( List list , List other )
{
}

/*=================================================================================================================================================*/

void llReplaceAll ( List list , ListElementUnaryOperator uOperator )
{
}

/*=================================================================================================================================================*/

ListBoolean llRetainAll ( List list , List other )
{
}

/*=================================================================================================================================================*/

ListElement llSet ( List list , int index , ListElement element )
{
}

/*=================================================================================================================================================*/

int llSize ( List list )
{
    printf("SIZesize %d\n", ILL(list).numberOfElements);

    return ILL(list).numberOfElements > INT_MAX ? INT_MAX : ILL(list).numberOfElements;
}


/*=================================================================================================================================================*/

ListBoolean llSort ( List list , ListElementComparisonFunction compare )
{
}

/*=================================================================================================================================================*/

ListElement * llToArray ( List list )
{
    int sz = llSize(list);
    ListElement elements[sz];
    Node* cur = ILL(list).pHead;
    for (int i = 0; i < sz; ++i) {
        if (!cur)
            elements[i] = NULL;
        else
            elements[i] = cur->element;
        cur = cur->next;
    }
    return elements;
}

/*=================================================================================================================================================*/

void llPrint ( List list , char * listName , ListElementPrintingFunction print )
{
    int sz = llSize(list);
    printf("LinkedList : %s\nElements   : %d", listName, sz);
    return;
    ListElement* elements = llToArray(list);

    for (int i = 0; i < sz; ++i) {
        print(*(elements++));
    }

}

/*=================================================================================================================================================*/

void llDestroy ( List list )
{
}

/***************************************************************************************************************************************************/
