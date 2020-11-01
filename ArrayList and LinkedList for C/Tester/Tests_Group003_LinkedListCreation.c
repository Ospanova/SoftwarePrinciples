/***************************************************************************************************************************************************/

TEST( 1 , "LinkedList creation when running out of memory" )

  List list ;

  MEM_EXHAUST    list = createLinkedList() ;    MEM_OK

  ASSERT( list == NULL )

ENDTEST

/*=================================================================================================================================================*/

TEST( 1 , "LinkedList creation" )

  List list = createLinkedList() ;

  ASSERT( list             != NULL )
  ASSERT( listSize( list ) == 0    )

  populate( list , 4 , DIGIT(0) , LETTER('s') , STRING(1) , LETTER('t') ) ;

  ASSERT( listSize( list ) == 4 )

  listDestroy( list ) ;

ENDTEST

/*=================================================================================================================================================*/

TEST( 1 , "LinkedList creation from other list when running out of memory" )

  List list1 , list2 ;

  BUILDLL( list2 , 3 , DIGIT(4) , LETTER('s') , STRING(8) )

  MEM_EXHAUST    list1 = createLinkedListFrom( list2 ) ;    MEM_OK

  ASSERT( list1 == NULL )

  listDestroy( list2 ) ;

ENDTEST

/*=================================================================================================================================================*/

TEST( 1 , "LinkedList creation from ArrayList" )

  List list1 , list2 ;

  BUILDAL( list2 , 1 , 3 , DIGIT(4) , LETTER('s') , STRING(8) )

  list1 = createLinkedListFrom( list2 ) ;

  ASSERT( list1                 != NULL        )
  ASSERT( listSize( list1     ) == 3           )
  ASSERT( listGet ( list1 , 0 ) == DIGIT(  4 ) )
  ASSERT( listGet ( list1 , 1 ) == LETTER('s') )
  ASSERT( listGet ( list1 , 2 ) == STRING( 8 ) )

  listDestroy( list1 ) ;
  listDestroy( list2 ) ;

ENDTEST

/*=================================================================================================================================================*/

TEST( 1 , "LinkedList creation from LinkedList" )

  List list1 , list2 ;

  BUILDLL( list2 , 3 , DIGIT(4) , LETTER('s') , STRING(8) )

  list1 = createLinkedListFrom( list2 ) ;

  ASSERT( list1                 != NULL        )
  ASSERT( listSize( list1     ) == 3           )
  ASSERT( listGet ( list1 , 0 ) == DIGIT(  4 ) )
  ASSERT( listGet ( list1 , 1 ) == LETTER('s') )
  ASSERT( listGet ( list1 , 2 ) == STRING( 8 ) )

  listDestroy( list1 ) ;
  listDestroy( list2 ) ;

ENDTEST

/*=================================================================================================================================================*/

TEST( 1 , "LinkedList creation from empty list" )

  List list1 , list2 ;

  BUILDAL( list2 , LIST_NA , 0 , NULL )

  list1 = createLinkedListFrom( list2 ) ;

  ASSERT( list1             != NULL )
  ASSERT( listSize( list1 ) == 0    )

  listDestroy( list1 ) ;
  listDestroy( list2 ) ;

ENDTEST

/***************************************************************************************************************************************************/
