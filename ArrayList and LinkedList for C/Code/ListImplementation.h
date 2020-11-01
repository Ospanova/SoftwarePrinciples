/***************************************************************************************************************************************************/

#ifndef LIST_IMPLEMENTATION_H
#define LIST_IMPLEMENTATION_H

/***************************************************************************************************************************************************/




/***************************************************************************************************************************************************/

#include "List.h"

/***************************************************************************************************************************************************/




/***************************************************************************************************************************************************/

struct list
{
  ListBoolean   (* add          )  ( List list , ListElement element , int index                     ) ;
  ListBoolean   (* addAll       )  ( List list , List other , int index                              ) ;
  void          (* clear        )  ( List list                                                       ) ;
  ListBoolean   (* contains     )  ( List list , ListElement element                                 ) ;
  ListBoolean   (* containsAll  )  ( List list , List other                                          ) ;
  ListBoolean   (* equals       )  ( List list , List other                                          ) ;
  ListElement   (* get          )  ( List list , int index                                           ) ;
  int           (* indexOf      )  ( List list , ListElement element                                 ) ;
  ListBoolean   (* isEmpty      )  ( List list                                                       ) ;
  int           (* lastIndexOf  )  ( List list , ListElement element                                 ) ;
  ListElement   (* remove       )  ( List list , int index                                           ) ;
  ListBoolean   (* removeElement)  ( List list , ListElement element                                 ) ;
  ListBoolean   (* removeAll    )  ( List list , List other                                          ) ;
  void          (* replaceAll   )  ( List list , ListElementUnaryOperator uOperator                  ) ;
  ListBoolean   (* retainAll    )  ( List list , List other                                          ) ;
  ListElement   (* set          )  ( List list , int index , ListElement element                     ) ;
  int           (* size         )  ( List list                                                       ) ;
  ListBoolean   (* sort         )  ( List list , ListElementComparisonFunction compare               ) ;
  ListElement * (* toArray      )  ( List list                                                       ) ;
  void          (* print        )  ( List list , char * listName , ListElementPrintingFunction print ) ;
  void          (* destroy      )  ( List list                                                       ) ;

  void *        pInternalList                                                                          ;
} ;

/***************************************************************************************************************************************************/




/***************************************************************************************************************************************************/

#endif  /* LIST_IMPLEMENTATION_H */

/***************************************************************************************************************************************************/
