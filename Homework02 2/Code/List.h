/* Conditional inclusion guard *********************************************************************************************************************/

#ifndef LIST_H
#define LIST_H

/***************************************************************************************************************************************************/




/* Header files ************************************************************************************************************************************/

#include <limits.h>  /* For definition of INT_MIN */

/***************************************************************************************************************************************************/




/* Macro definitions *******************************************************************************************************************************/

#define LIST_NA ( INT_MIN )

/***************************************************************************************************************************************************/




/* Type definitions ********************************************************************************************************************************/

/* Forward declaration. 'List' is a pointer to a struct. */

typedef struct list * List ;

/* Lists will store 'void pointers' as elements. */

typedef void * ListElement ;

/* Boolean values to be used with the 'List' data type are 'True' and 'False'. */

typedef enum { True = 1 , False = 0 } ListBoolean ;

/* A unary operator takes a list element, optionally modifies it or uses its value in some calculations, and returns another list element (which can
   also be the same element that was passed as the argument to the operator). */

typedef ListElement (* ListElementUnaryOperator) ( ListElement ) ;

/* A printing function should print a string representation of the element (preferably a very short text) to the standard output stream (stdout).
   The function should not add a space, or a comma, or a newline after the string representation. */

typedef void (* ListElementPrintingFunction) ( const ListElement ) ;

/* A comparison function should return a negative integer, zero, or a positive integer when ;
   - the first element is 'less than' the second element (the first element should come before the second element in sort order),
   - both elements are 'equal' (both have the same sort order), or
   - the first element is 'greater than' the second element (the first element should come after the second element in sort order), respectively. */

typedef int (* ListElementComparisonFunction) ( const ListElement , const ListElement ) ;

/***************************************************************************************************************************************************/




/* Function prototypes *****************************************************************************************************************************/

/* Inserts the specified element at the specified position in the list. Shifts the element currently at that position (if any) and any subsequent
   elements to the right (adds one to their indices). If index is LIST_NA, then appends the specified element to the end of the list.
   Returns True if the operation is successful.
   Returns False if the operation is unsuccessful; for example if index < 0, or index > listSize(list), or running out of memory. */

ListBoolean listAdd ( List list , ListElement element , int index ) ;

/* Inserts all of the elements in the other list into the list at the specified position. Shifts the element currently at that position (if any) and
   any subsequent elements to the right (increases their indices). If index is LIST_NA, then appends all of the elements in the other list to the end
   of the list. The new elements will appear in the list in the order that they are stored in the other list. The behavior of this operation is
   undefined if the other list is modified while the operation is in progress (note that this will occur if the other list is the same as the list,
   and it is nonempty).
   Returns True if the list is changed as a result of the call.
   Returns False if the list is unchanged and/or if the operation is unsuccessful. */

ListBoolean listAddAll ( List list , List other , int index ) ;

/* Removes all of the elements from the list. The list will be empty after this call returns. */

void listClear ( List list ) ;

/* Returns True if the list contains the specified element. More formally, returns True if and only if the list contains at least one element 'e'
   such that the pointer comparison ( element == e ) is true. Otherwise, returns False. */

ListBoolean listContains ( List list , ListElement element ) ;

/* Returns True if the list contains all of the elements of the other list. Otherwise, returns False. */

ListBoolean listContainsAll ( List list , List other ) ;

/* Compares the other list with the list for equality. More formally, returns True if and only if the pointer comparison ( list == other ) is true.
   Otherwise, returns False. */

ListBoolean listEquals ( List list , List other ) ;

/* Returns the element at the specified position in the list (indices start from 0).
   Returns NULL if index < 0, or index >= listSize(list).
   Note: NULL is also a valid element value that can be stored in a list. */

ListElement listGet ( List list , int index ) ;

/* Returns the index of the first occurrence of the specified element in the list, or -1 if the list does not contain the element. More formally,
   returns the lowest index i such that ( element == listGet(list,i) ), or -1 if there is no such index. */

int listIndexOf ( List list , ListElement element ) ;

/* Returns True if the list contains no elements. Otherwise, returns False. */

ListBoolean listIsEmpty ( List list ) ;

/* Returns the index of the last occurrence of the specified element in the list, or -1 if the list does not contain the element. More formally,
   returns the highest index i such that ( element == listGet(list,i) ), or -1 if there is no such index. */

int listLastIndexOf ( List list , ListElement element ) ;

/* Removes the element at the specified position in the list. Shifts any subsequent elements to the left (subtracts one from their indices).
   Returns the element that was removed from the list.
   Returns NULL if index < 0, or index >= listSize(list).
   Note: NULL is also a valid element value that can be stored in a list. */

ListElement listRemove ( List list , int index ) ;

/* Removes the first occurrence of the specified element from the list, if it is present. If the list does not contain the element, it is unchanged.
   More formally, removes the element with the lowest index i such that ( element == listGet(list,i) ), if such an element exists.
   Returns True if the list contained the specified element (or equivalently, if the list changed as a result of the call).
   Otherwise, returns False. */

ListBoolean listRemoveElement ( List list , ListElement element ) ;

/* Removes from the list all of its elements that are contained in the other list.
   Returns True if the list changed as a result of the call. Otherwise, returns False. */

ListBoolean listRemoveAll ( List list , List other ) ;

/* Replaces each element of the list with the result of applying the unary operator to that element. */

void listReplaceAll ( List list , ListElementUnaryOperator uOperator ) ;

/* Retains only the elements in the list that are contained in the other list. In other words, removes from the list all of its elements that are not
   contained in the other list.
   Returns True if the list changed as a result of the call. Otherwise, returns False. */

ListBoolean listRetainAll ( List list , List other ) ;

/* Replaces the element at the specified position in the list with the specified element.
   Returns the element previously at the specified position.
   Returns NULL if index < 0, or index >= listSize(list).
   Note: NULL is also a valid element value that can be stored in a list. */

ListElement listSet ( List list , int index , ListElement element ) ;

/* Returns the number of elements in the list. If the list contains more than INT_MAX elements, returns INT_MAX. */

int listSize ( List list ) ;

/* Sorts the list according to the order induced by the specified comparison function.
   All elements in the list must be mutually comparable using the specified comparison function.
   Implementation Requirements: The default implementation obtains an array containing all elements in the list, sorts the array, and iterates over
   the list resetting each element from the corresponding position in the array. (This avoids the n^2 log(n) performance that would result from
   attempting to sort a linked list in place.)
   Returns True if successful (if list is in sorted order when function returns).
   Returns False if cannot sort the list due to running out of memory. */

ListBoolean listSort ( List list , ListElementComparisonFunction compare ) ;

/* Returns an array containing all of the elements in the list in proper sequence (from first to last element).
   The returned array will be 'safe' in that no references to it are maintained by the list (in other words, this method must allocate a new array
   even if the list is backed by an array). The caller is thus free to modify the returned array. This method acts as bridge between array-based and
   list-based APIs.
   Returns NULL if the list does not contain any elements, or if running out of memory. */

ListElement * listToArray ( List list ) ;

/* Prints the list (a short header, and then all of the list elements, one element per line, with index of each element printed at the beginning of
   its line) to the standard output stream (stdout). */

void listPrint ( List list , char * listName , ListElementPrintingFunction print ) ;

/* Destroys the list and frees up its memory. */

void listDestroy ( List list ) ;

/***************************************************************************************************************************************************/




/* Conditional inclusion guard *********************************************************************************************************************/

#endif  /* LIST_H */

/***************************************************************************************************************************************************/
