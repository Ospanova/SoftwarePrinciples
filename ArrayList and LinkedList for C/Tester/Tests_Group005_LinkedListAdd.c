/***************************************************************************************************************************************************/

TEST( 1 , "LinkedList add when running out of memory" )

  List        list   ;
  ListBoolean status ;

  BUILDLL( list , 1 , STRING(8) )

  ASSERT( list != NULL )

  MEM_EXHAUST    status = listAdd( list , STRING(9) , LIST_NA ) ;    MEM_OK

  ASSERT( status           == False )
  ASSERT( listSize( list ) == 1     )

  listDestroy( list ) ;

ENDTEST

/*=================================================================================================================================================*/

TEST( 1 , "LinkedList add to empty list" )

  List        list   ;
  ListBoolean status ;

  BUILDLL( list , 0 , NULL )

  ASSERT( list != NULL )

  status = listAdd( list , STRING(8) , LIST_NA ) ;

  ASSERT( status           == True )
  ASSERT( listSize( list ) == 1    )

  listDestroy( list ) ;

ENDTEST

/*=================================================================================================================================================*/

TEST( 1 , "LinkedList add to beginning of list" )

  List        list   ;
  ListBoolean status ;

  BUILDLL( list , 0 , NULL )

  ASSERT( list != NULL )

  status = listAdd( list , STRING( 8 ) , 0 ) ;
  status = listAdd( list , LETTER('a') , 0 ) ;

  ASSERT( status              == True        )
  ASSERT( listSize( list    ) == 2           )
  ASSERT( listGet( list , 0 ) == LETTER('a') )
  ASSERT( listGet( list , 1 ) == STRING( 8 ) )

  listDestroy( list ) ;

ENDTEST

/*=================================================================================================================================================*/

TEST( 1 , "LinkedList add to middle of list" )

  List        list   ;
  ListBoolean status ;

  BUILDLL( list , 3 , DIGIT(0) , DIGIT(1) , DIGIT(2) )

  ASSERT( list != NULL )

  status = listAdd( list , STRING( 8 ) , 2 ) ;

  ASSERT( status              == True        )
  ASSERT( listSize( list    ) == 4           )
  ASSERT( listGet( list , 1 ) == DIGIT ( 1 ) )
  ASSERT( listGet( list , 2 ) == STRING( 8 ) )
  ASSERT( listGet( list , 3 ) == DIGIT ( 2 ) )

  listDestroy( list ) ;

ENDTEST

/*=================================================================================================================================================*/

TEST( 1 , "LinkedList add to end of list" )

  List        list   ;
  ListBoolean status ;

  BUILDLL( list , 3 , DIGIT(0) , DIGIT(1) , DIGIT(2) )

  ASSERT( list != NULL )

  status = listAdd( list , STRING( 8 ) , 3 ) ;

  ASSERT( status == True )

  status = listAdd( list , STRING( 9 ) , LIST_NA ) ;

  ASSERT( status              == True        )
  ASSERT( listSize( list    ) == 5           )
  ASSERT( listGet( list , 2 ) == DIGIT ( 2 ) )
  ASSERT( listGet( list , 3 ) == STRING( 8 ) )
  ASSERT( listGet( list , 4 ) == STRING( 9 ) )

  listDestroy( list ) ;

ENDTEST

/*=================================================================================================================================================*/

TEST( 1 , "LinkedList add to negative index" )

  List        list   ;
  ListBoolean status ;

  BUILDLL( list , 3 , DIGIT(0) , DIGIT(1) , DIGIT(2) )

  ASSERT( list != NULL )

  status = listAdd( list , STRING( 8 ) , -1 ) ;

  ASSERT( status           == False )
  ASSERT( listSize( list ) == 3     )

  listDestroy( list ) ;

ENDTEST

/*=================================================================================================================================================*/

TEST( 1 , "LinkedList add to invalid index" )

  List        list   ;
  ListBoolean status ;

  BUILDLL( list , 3 , DIGIT(0) , DIGIT(1) , DIGIT(2) )

  ASSERT( list != NULL )

  status = listAdd( list , STRING( 8 ) , 5 ) ;

  ASSERT( status           == False )
  ASSERT( listSize( list ) == 3     )

  listDestroy( list ) ;

ENDTEST

/***************************************************************************************************************************************************/
