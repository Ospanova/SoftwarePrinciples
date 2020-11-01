/* Conditional inclusion guard *********************************************************************************************************************/

#ifndef ARRAYLIST_H
#define ARRAYLIST_H

/***************************************************************************************************************************************************/




/* Header files ************************************************************************************************************************************/

#include "List.h"

/***************************************************************************************************************************************************/




/* Function prototypes *****************************************************************************************************************************/

/* Constructs an empty list with the specified initial capacity. If 'initialCapacity' is LIST_NA, then an initial capacity of 10 will be used.
   Returns the created list, or NULL if initialCapacity <= 0, or if running out of memory. */

List createArrayList ( int initialCapacity ) ;

/* Constructs a list containing the elements of the other list, in the order they are stored in the other list.
   Returns the created list (which might be empty if the other list is empty), or NULL if running out of memory. */

List createArrayListFrom ( List other ) ;

/***************************************************************************************************************************************************/




/* Conditional inclusion guard *********************************************************************************************************************/

#endif  /* ARRAYLIST_H */

/***************************************************************************************************************************************************/
