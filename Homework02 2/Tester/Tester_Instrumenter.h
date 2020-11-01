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




/* Conditional inclusion guard *********************************************************************************************************************/

#ifndef  __TESTER_INSTRUMENTER__
#define  __TESTER_INSTRUMENTER__

/***************************************************************************************************************************************************/




/* Instrumentation includes (don't change this part) ***********************************************************************************************/

#include <stddef.h>  /* size_t */

/***************************************************************************************************************************************************/




/* Instrumentation macros (don't change this part) *************************************************************************************************/

#define  malloc   testerMalloc
#define  calloc   testerCalloc
#define  realloc  testerRealloc

/***************************************************************************************************************************************************/




/* Instrumentation declarations (don't change this part) *******************************************************************************************/

extern void * testerMalloc  ( size_t size               ) ;
extern void * testerCalloc  ( size_t nobj , size_t size ) ;
extern void * testerRealloc ( void * ptr  , size_t size ) ;

/***************************************************************************************************************************************************/




/* Conditional inclusion guard *********************************************************************************************************************/

#endif  /* __TESTER_INSTRUMENTER__ */

/***************************************************************************************************************************************************/
