/***************************************************************************************************************************************************/

#include "ListImplementation.h"

/***************************************************************************************************************************************************/




/***************************************************************************************************************************************************/

ListBoolean  listAdd          (List list, ListElement element, int index                    ) { return list->add          (list, element, index ) ; }
ListBoolean  listAddAll       (List list, List other, int index                             ) { return list->addAll       (list, other, index   ) ; }
void         listClear        (List list                                                    ) {        list->clear        (list                 ) ; }
ListBoolean  listContains     (List list, ListElement element                               ) { return list->contains     (list, element        ) ; }
ListBoolean  listContainsAll  (List list, List other                                        ) { return list->containsAll  (list, other          ) ; }
ListBoolean  listEquals       (List list, List other                                        ) { return list->equals       (list, other          ) ; }
ListElement  listGet          (List list, int index                                         ) { return list->get          (list, index          ) ; }
int          listIndexOf      (List list, ListElement element                               ) { return list->indexOf      (list, element        ) ; }
ListBoolean  listIsEmpty      (List list                                                    ) { return list->isEmpty      (list                 ) ; }
int          listLastIndexOf  (List list, ListElement element                               ) { return list->lastIndexOf  (list, element        ) ; }
ListElement  listRemove       (List list, int index                                         ) { return list->remove       (list, index          ) ; }
ListBoolean  listRemoveElement(List list, ListElement element                               ) { return list->removeElement(list, element        ) ; }
ListBoolean  listRemoveAll    (List list, List other                                        ) { return list->removeAll    (list, other          ) ; }
void         listReplaceAll   (List list, ListElementUnaryOperator uOperator                ) {        list->replaceAll   (list, uOperator      ) ; }
ListBoolean  listRetainAll    (List list, List other                                        ) { return list->retainAll    (list, other          ) ; }
ListElement  listSet          (List list, int index, ListElement element                    ) { return list->set          (list, index, element ) ; }
int          listSize         (List list                                                    ) { return list->size         (list                 ) ; }
ListBoolean  listSort         (List list, ListElementComparisonFunction compare             ) { return list->sort         (list, compare        ) ; }
ListElement *listToArray      (List list                                                    ) { return list->toArray      (list                 ) ; }
void         listPrint        (List list, char * listName, ListElementPrintingFunction print) {        list->print        (list, listName, print) ; }
void         listDestroy      (List list                                                    ) {        list->destroy      (list                 ) ; }

/***************************************************************************************************************************************************/
