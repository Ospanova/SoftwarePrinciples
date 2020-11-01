/****************************************************************************************************************************************************
|
| Copyright (C) 2020 Selim Temizer.
|
| This file is part of Tester Suite.
|
| Tester Suite is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License
| as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
|
| Tester Suite is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
| MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
|
| You should have received a copy of the GNU Lesser General Public License along with Tester Suite. If not, see <http://www.gnu.org/licenses/>.
|
****************************************************************************************************************************************************/




/* Header files that are required by the code to be tested *****************************************************************************************/

#include "List.h"
#include "ArrayList.h"
#include "LinkedList.h"

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

/***************************************************************************************************************************************************/




/* Helper items for the code to be tested (macros, data types, global variables, functions) ********************************************************/

int    digits  [] = { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 }                                     ;
char   letters [] =   "abcdefghijklmnopqrstuvwxyz"                                                ;
char * strings [] = { "ab" , "cde" , "f" , "gh" , "ijkl" , "mno" , "pqr" , "st" , "uvwx" , "yz" } ;

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

#define  DIGIT(   intDigit  )  ( & ( digits [ ( intDigit )       ] ) )    /*  0  to  9  */
#define  LETTER( charLetter )  ( & ( letters[ (charLetter) - 'a' ] ) )    /* 'a' to 'z' */
#define  STRING(  intIndex  )  ( & ( strings[ ( intIndex )       ] ) )    /*  0  to  9  */

/*=================================================================================================================================================*/

static void populate ( List list , ... )  /* Second argument should be an integer (count of elements) */
{
  int     i            ;
  int     count        ;
  va_list nextArgument ;    va_start( nextArgument , list ) ;

  count = va_arg( nextArgument , int ) ;

  for ( i = 0 ; i < count ; i++ )  { listAdd( list , va_arg( nextArgument , void * ) , LIST_NA ) ; }

  va_end( nextArgument ) ;
}

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

#define  BUILDAL( listVariable , intCapacity , elementCount , ... )   \
                                                                      \
         (listVariable) = createArrayList( (intCapacity) ) ;          \
                                                                      \
         populate( (listVariable) , (elementCount) , __VA_ARGS__ ) ;

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

#define  BUILDLL( listVariable , elementCount , ... )                 \
                                                                      \
         (listVariable) = createLinkedList() ;                        \
                                                                      \
         populate( (listVariable) , (elementCount) , __VA_ARGS__ ) ;

/***************************************************************************************************************************************************/
