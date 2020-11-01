/***************************************************************************************************************************************************/

TEST( 1 , "ArrayList creation when running out of memory" )

  List list ;

  MEM_EXHAUST    list = createArrayList( LIST_NA ) ;    MEM_OK

  ASSERT( list == NULL )

ENDTEST

/*=================================================================================================================================================*/

TEST( 1 , "ArrayList creation with default initialCapacity" )

  List list = createArrayList( LIST_NA ) ;

  ASSERT( list             != NULL )
  ASSERT( listSize( list ) == 0    )

  populate( list , 5 , DIGIT(0) , LETTER('s') , STRING(1) , LETTER('t') , STRING(2) ) ;

  ASSERT( listSize( list ) == 5 )

  listDestroy( list ) ;

ENDTEST

/*=================================================================================================================================================*/

TEST( 1 , "ArrayList creation with zero initialCapacity" )

  List list = createArrayList( 0 ) ;

  ASSERT( list == NULL )

ENDTEST

/*=================================================================================================================================================*/

TEST( 1 , "ArrayList creation with negative initialCapacity" )

  List list = createArrayList( -1 ) ;

  ASSERT( list == NULL )

ENDTEST

/*=================================================================================================================================================*/

TEST( 1 , "ArrayList creation with small initialCapacity" )

  List list = createArrayList( 1 ) ;

  ASSERT( list != NULL )

  populate( list , 5 , DIGIT(0) , LETTER('g') , STRING(1) , LETTER('t') , STRING(2) ) ;

  ASSERT( listSize( list ) == 5 )

  listDestroy( list ) ;

ENDTEST

/*=================================================================================================================================================*/

TEST( 1 , "ArrayList creation from other list when running out of memory" )

  List list1 , list2 ;

  BUILDAL( list2 , 1 , 3 , DIGIT(4) , LETTER('s') , STRING(8) )

  MEM_EXHAUST    list1 = createArrayListFrom( list2 ) ;    MEM_OK

  ASSERT( list1 == NULL )

  listDestroy( list2 ) ;

ENDTEST

/*=================================================================================================================================================*/

TEST( 1 , "ArrayList creation from ArrayList" )

  List list1 , list2 ;

  BUILDAL( list2 , 1 , 3 , DIGIT(4) , LETTER('s') , STRING(8) )

  list1 = createArrayListFrom( list2 ) ;

  ASSERT( list1                 != NULL        )
  ASSERT( listSize( list1     ) == 3           )
  ASSERT( listGet ( list1 , 0 ) == DIGIT(  4 ) )
  ASSERT( listGet ( list1 , 1 ) == LETTER('s') )
  ASSERT( listGet ( list1 , 2 ) == STRING( 8 ) )

  listDestroy( list1 ) ;
  listDestroy( list2 ) ;

ENDTEST

/*=================================================================================================================================================*/

TEST( 1 , "ArrayList creation from LinkedList" )

  List list1 , list2 ;

  BUILDLL( list2 , 3 , DIGIT(4) , LETTER('s') , STRING(8) )

  list1 = createArrayListFrom( list2 ) ;

  ASSERT( list1                 != NULL        )
  ASSERT( listSize( list1     ) == 3           )
  ASSERT( listGet ( list1 , 0 ) == DIGIT(  4 ) )
  ASSERT( listGet ( list1 , 1 ) == LETTER('s') )
  ASSERT( listGet ( list1 , 2 ) == STRING( 8 ) )

  listDestroy( list1 ) ;
  listDestroy( list2 ) ;

ENDTEST

/*=================================================================================================================================================*/

TEST( 1 , "ArrayList creation from empty list" )

  List list1 , list2 ;

  BUILDLL( list2 , 0 , NULL )

  list1 = createArrayListFrom( list2 ) ;

  ASSERT( list1             != NULL )
  ASSERT( listSize( list1 ) == 0    )

  listDestroy( list1 ) ;
  listDestroy( list2 ) ;

ENDTEST

/***************************************************************************************************************************************************/
