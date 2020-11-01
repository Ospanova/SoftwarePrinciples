/****************************************************************************************************************************************************
|
| Copyright (C) 2020 Selim Temizer.
|
| This program is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License
| as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
|
| This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
| MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
|
| You should have received a copy of the GNU Lesser General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.
|
****************************************************************************************************************************************************/




/***************************************************************************************************************************************************/

#include "List.h"
#include "ArrayList.h"
#include "LinkedList.h"

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

/***************************************************************************************************************************************************/




/***************************************************************************************************************************************************/

List list1 , list2 ;    /* Global lists */

/***************************************************************************************************************************************************/




/***************************************************************************************************************************************************/

int digits [] = { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 } ;

/*=================================================================================================================================================*/

ListElement doubleInt   (       ListElement e                         )  { int *p  = (int *) e ;         (*p) *= 2 ;    return (ListElement) p ; }
int         compareInts ( const ListElement e1 , const ListElement e2 )  { int *p1 = (int *) e1 , *p2 = (int *) e2 ;    return (*p1) - (*p2)   ; }
void        printInt    ( const ListElement e                         )  { printf( "%d" , *((int *) e) )                                       ; }

/***************************************************************************************************************************************************/




/***************************************************************************************************************************************************/

int main ( int argc , char * argv[] )
{
  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  List list3 , list4 ;    /* Local lists */

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  printf( "\n" ) ;

  list1 = createLinkedList() ;

  listAdd( list1 , digits+4 , LIST_NA ) ;
  listAdd( list1 , digits+8 , LIST_NA ) ;
  listAdd( list1 , digits+3 , LIST_NA ) ;

//  listPrint( list1 , "list1" , (ListElementPrintingFunction) printInt ) ;    printf( "\n" ) ;

//  listContains(list1, digits+4);
  list2 = createLinkedListFrom( list1 ) ;
//    listPrint( list1 , "list1" , (ListElementPrintingFunction) printInt ) ;    printf( "\n" ) ;
//
//    listAdd   ( list2 , digits+5 , 1       ) ;
//    listPrint( list2 , "list2" , (ListElementPrintingFunction) printInt ) ;    printf( "\n" ) ;
//
//    listAddAll( list2 , list1    , LIST_NA ) ;
//
//  listPrint( list2 , "list2" , (ListElementPrintingFunction) printInt ) ;    printf( "\n" ) ;
//  listPrint( list1 , "list1" , (ListElementPrintingFunction) printInt ) ;    printf( "\n" ) ;

//  listSort( list2 , (ListElementComparisonFunction) compareInts ) ;
//
//  listPrint( list2 , "list2" , (ListElementPrintingFunction) printInt ) ;    printf( "\n" ) ;
//
//  list3 = createArrayListFrom( list1 ) ;
//
//  listRemoveElement( list3 , digits+4 ) ;
//
//  listPrint( list3 , "list3" , (ListElementPrintingFunction) printInt ) ;    printf( "\n" ) ;
//
//  listRemoveAll( list2 , list3 ) ;
//
//  listPrint( list2 , "list2" , (ListElementPrintingFunction) printInt ) ;    printf( "\n" ) ;
//
//  list4 = createLinkedListFrom( list2 ) ;
//
//  listReplaceAll( list4 , doubleInt ) ;
//
//  listPrint( list4 , "list4" , (ListElementPrintingFunction) printInt ) ;    printf( "\n" ) ;
//
//  printf( "Note that elements 0 and 1 point to the same 'digit', therefore that digit is doubled twice!\n\n" ) ;
//
//  listClear( list1 ) ;
//  listClear( list2 ) ;
//
//  listAddAll( list1 , list3 , LIST_NA ) ;
//  listAddAll( list1 , list4 , 1       ) ;
//
//  listAddAll( list2 , list1 , LIST_NA ) ;
//  listAddAll( list2 , list1 , LIST_NA ) ;
//  listAddAll( list2 , list1 , LIST_NA ) ;
//
//  listPrint( list2 , "list2" , (ListElementPrintingFunction) printInt ) ;    printf( "\n" ) ;
//
//  listDestroy( list1 ) ;
//  listDestroy( list2 ) ;
//  listDestroy( list3 ) ;
//  listDestroy( list4 ) ;

  printf( "There should be no memory leaks when the user application destroys all lists.\n\n" ) ;

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  return 0 ;

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/
}

/***************************************************************************************************************************************************/
