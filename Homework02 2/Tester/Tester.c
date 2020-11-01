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




/* Tester includes (don't change this part ) *******************************************************************************************************/

#include <stdio.h>     /* fprintf                          */
#include <stdlib.h>    /* atoi , malloc , calloc , realloc */

/***************************************************************************************************************************************************/




/* Tester macros (don't change this part) **********************************************************************************************************/

#define  MAXIMUM_NUMBER_OF_TESTS  1000    /* Indices from 0 to 999 */

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

#define  UNIQUE_TEST_FUNCTION_NAME                     FUNCTION_NAME(         __COUNTER__ )
#define  FUNCTION_NAME(                counterMacro )  FUNCTION_NAME_HELPER( counterMacro )    /* This indirection expands (evaluates) __COUNTER__ */
#define  FUNCTION_NAME_HELPER( expandedCounterMacro )  Test##expandedCounterMacro              /* Expanded __COUNTER__ can safely be concatenated  */

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

#define  TEST( pts , text )                                                                                                         \
                                                                                                                                    \
         void UNIQUE_TEST_FUNCTION_NAME ( void )                                                                                    \
         {                                                                                                                          \
           int          _index = numberOfTests++ ;                                                                                  \
           const char * _name  = __func__        ;                                                                                  \
                                                                                                                                    \
           tests[_index].functionName = _name  ;                                                                                    \
           tests[_index].description  = (text) ;                                                                                    \
           tests[_index].points       = (pts ) ;                                                                                    \
           tests[_index].result       = PASSED ;  /* By default, assumed to be PASSED. Should explicity SKIP or FAIL to change. */  \
                                                                                                                                    \
           fprintf( stderr , "%-7s (%2d pts) %s\n" , _name , (pts) , (text) ) ;                                                     \
                                                                                                                                    \
           if ( tests[_index].skip == 1 )  SKIP                                                                                     \
                                                                                                                                    \
           {

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

#define  ENDTEST  }}

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

#define  PASS  { tests[_index].result = PASSED  ;  return ; }
#define  SKIP  { tests[_index].result = SKIPPED ;  return ; }
#define  FAIL  { tests[_index].result = FAILED  ;  return ; }

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

#define  ASSERT( statement )  if (! (statement)) { fprintf( stderr , "%23s: %s\n" , "Failed" , #statement ) ; FAIL }

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

#define  MEM_EXHAUST  { simulateExhaustedHeapMemory = 1 ; }
#define  MEM_OK       { simulateExhaustedHeapMemory = 0 ; }

/***************************************************************************************************************************************************/




/* Tester data types and global variables (don't change this part) *********************************************************************************/

typedef enum { PASSED , SKIPPED , FAILED } Result ;

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

typedef struct test
{
        char     skip         ;  // This flag (whether to skip or run this test) should be set before the test functions are called
  const char   * functionName ;  // Filled in by the called function
        char   * description  ;  // Filled in by the called function
        int      points       ;  // Filled in by the called function
        Result   result       ;  // Filled in by the called function
}
Test ;

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

Test tests [ MAXIMUM_NUMBER_OF_TESTS ] = {0} ;
int  numberOfTests                     =  0  ;
int  simulateExhaustedHeapMemory       =  0  ;

/***************************************************************************************************************************************************/




/* Tester functions (don't change this part) *******************************************************************************************************/

void * testerMalloc  ( size_t size               )  { if ( simulateExhaustedHeapMemory )  { return NULL ; }    return malloc ( size        ) ; }
void * testerCalloc  ( size_t nobj , size_t size )  { if ( simulateExhaustedHeapMemory )  { return NULL ; }    return calloc ( nobj , size ) ; }
void * testerRealloc ( void * ptr  , size_t size )  { if ( simulateExhaustedHeapMemory )  { return NULL ; }    return realloc( ptr  , size ) ; }

/***************************************************************************************************************************************************/




/* Helper items for writing tests for the code to be tested (don't change this part, add all helper items in the included file) ********************/

#include "Tester_Auxiliary.c"

/***************************************************************************************************************************************************/




/* All individual test group files will be included by the single directive below (don't change this part) *****************************************/

#include "Tests_All.c"

/***************************************************************************************************************************************************/




/* Test result reporting and main function (don't change this part, just comment/uncomment calls to TestNNN functions in the main function) ********/

void report ( void )
{
  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  int    i                        ;
  int    descriptionLength        ;
  int    maxDescriptionLength = 0 ;
  int    countPassed          = 0 ;
  int    countSkipped         = 0 ;
  int    countFailed          = 0 ;
  int    countTotal           = 0 ;
  int    scorePassed          = 0 ;
  int    scoreSkipped         = 0 ;
  int    scoreFailed          = 0 ;
  int    scoreTotal           = 0 ;
  char   testResultChar           ;
  char * testResultString         ;

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  for ( i = 0 ; i < numberOfTests ; i++ )
  {
    descriptionLength = strlen( tests[i].description ) ;

    if ( descriptionLength > maxDescriptionLength )  { maxDescriptionLength = descriptionLength ; }
  }

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  fprintf( stderr , "\nReport [ %s, %s ]\n" , __DATE__ , __TIME__ ) ;
  fprintf( stderr ,   "--------------------------------\n"        ) ;

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  for ( i = 0 ; i < numberOfTests ; i++ )
  {
    countTotal++                  ;
    scoreTotal += tests[i].points ;

    switch ( tests[i].result )
    {
      default      :
      case PASSED  :  testResultChar = ' ' ;  testResultString = "Passed"  ;  countPassed ++ ;  scorePassed  += tests[i].points ;  break ;
      case SKIPPED :  testResultChar = '-' ;  testResultString = "Skipped" ;  countSkipped++ ;  scoreSkipped += tests[i].points ;  break ;
      case FAILED  :  testResultChar = 'X' ;  testResultString = "FAILED"  ;  countFailed ++ ;  scoreFailed  += tests[i].points ;  break ;
    }

    fprintf( stderr , "%-7s (%2d pts) %c %-7s [ %-*s ]\n" , tests[i].functionName ,
                                                            tests[i].points       ,
                                                            testResultChar        ,
                                                            testResultString      ,
                                                            maxDescriptionLength  ,
                                                            tests[i].description  ) ;
  }

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  fprintf( stderr , "\n" ) ;

  fprintf( stderr , "Passed  : %3d out of %3d Tests (%6.2f %%) , %4d out of %4d Points (%6.2f %%)\n" ,
           countPassed  , countTotal , 100. * countPassed  / countTotal , scorePassed  , scoreTotal , 100. * scorePassed  / scoreTotal ) ;

  fprintf( stderr , "Skipped : %3d out of %3d Tests (%6.2f %%) , %4d out of %4d Points (%6.2f %%)\n" ,
           countSkipped , countTotal , 100. * countSkipped / countTotal , scoreSkipped , scoreTotal , 100. * scoreSkipped / scoreTotal ) ;

  fprintf( stderr , "Failed  : %3d out of %3d Tests (%6.2f %%) , %4d out of %4d Points (%6.2f %%)\n" ,
           countFailed  , countTotal , 100. * countFailed  / countTotal , scoreFailed  , scoreTotal , 100. * scoreFailed  / scoreTotal ) ;

  fprintf( stderr , "\nATTENTION: Remember to account for 'valgrind' score.\n\n" ) ;

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/
}

/*=================================================================================================================================================*/

int main ( int argc , char * argv[] )
{
  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  fprintf( stderr , "\nATTENTION: Tests [0 - %d] should be uncommented in main function.\n\n" , ( __COUNTER__ - 1 ) ) ;

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  if ( argc > 1 )
  {
    int i         ;
    int testIndex ;

    fprintf( stderr , "Indices of tests that will be skipped:\n" ) ;

    for ( i = 1 ; i < argc ; i++ )
    {
      testIndex = atoi( argv[i] ) ;

      if ( ( testIndex >= 0 ) && ( testIndex < MAXIMUM_NUMBER_OF_TESTS ) )
      {
        tests[testIndex].skip = 1 ;

        fprintf( stderr , "[ Test %3d ]\n" , testIndex ) ;
      }
    }

    fprintf( stderr , "\n" ) ;
  }

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  fprintf( stderr , "Running Tests\n" ) ;
  fprintf( stderr , "-------------\n" ) ;

  Test0  () ;   Test1  () ;   Test2  () ;   Test3  () ;   Test4  () ;   Test5  () ;   Test6  () ;   Test7  () ;   Test8  () ;   Test9  () ;
  Test10 () ;   Test11 () ;   Test12 () ;   Test13 () ;   Test14 () ;   Test15 () ;   Test16 () ;   Test17 () ;   Test18 () ;   Test19 () ;
  Test20 () ;   Test21 () ;   Test22 () ;   Test23 () ;   Test24 () ;   Test25 () ;   Test26 () ;   Test27 () ;   Test28 () ;   Test29 () ;
  Test30 () ;   Test31 () ;   Test32 () ;   Test33 () ;   Test34 () ;   Test35 () ;   Test36 () ;   Test37 () ; /*Test38 () ;   Test39 () ;
  Test40 () ;   Test41 () ;   Test42 () ;   Test43 () ;   Test44 () ;   Test45 () ;   Test46 () ;   Test47 () ;   Test48 () ;   Test49 () ;
  Test50 () ;   Test51 () ;   Test52 () ;   Test53 () ;   Test54 () ;   Test55 () ;   Test56 () ;   Test57 () ;   Test58 () ;   Test59 () ;
  Test60 () ;   Test61 () ;   Test62 () ;   Test63 () ;   Test64 () ;   Test65 () ;   Test66 () ;   Test67 () ;   Test68 () ;   Test69 () ;
  Test70 () ;   Test71 () ;   Test72 () ;   Test73 () ;   Test74 () ;   Test75 () ;   Test76 () ;   Test77 () ;   Test78 () ;   Test79 () ;
  Test80 () ;   Test81 () ;   Test82 () ;   Test83 () ;   Test84 () ;   Test85 () ;   Test86 () ;   Test87 () ;   Test88 () ;   Test89 () ;
  Test90 () ;   Test91 () ;   Test92 () ;   Test93 () ;   Test94 () ;   Test95 () ;   Test96 () ;   Test97 () ;   Test98 () ;   Test99 () ;

  Test100() ;   Test101() ;   Test102() ;   Test103() ;   Test104() ;   Test105() ;   Test106() ;   Test107() ;   Test108() ;   Test109() ;
  Test110() ;   Test111() ;   Test112() ;   Test113() ;   Test114() ;   Test115() ;   Test116() ;   Test117() ;   Test118() ;   Test119() ;
  Test120() ;   Test121() ;   Test122() ;   Test123() ;   Test124() ;   Test125() ;   Test126() ;   Test127() ;   Test128() ;   Test129() ;
  Test130() ;   Test131() ;   Test132() ;   Test133() ;   Test134() ;   Test135() ;   Test136() ;   Test137() ;   Test138() ;   Test139() ;
  Test140() ;   Test141() ;   Test142() ;   Test143() ;   Test144() ;   Test145() ;   Test146() ;   Test147() ;   Test148() ;   Test149() ;
  Test150() ;   Test151() ;   Test152() ;   Test153() ;   Test154() ;   Test155() ;   Test156() ;   Test157() ;   Test158() ;   Test159() ;
  Test160() ;   Test161() ;   Test162() ;   Test163() ;   Test164() ;   Test165() ;   Test166() ;   Test167() ;   Test168() ;   Test169() ;
  Test170() ;   Test171() ;   Test172() ;   Test173() ;   Test174() ;   Test175() ;   Test176() ;   Test177() ;   Test178() ;   Test179() ;
  Test180() ;   Test181() ;   Test182() ;   Test183() ;   Test184() ;   Test185() ;   Test186() ;   Test187() ;   Test188() ;   Test189() ;
  Test190() ;   Test191() ;   Test192() ;   Test193() ;   Test194() ;   Test195() ;   Test196() ;   Test197() ;   Test198() ;   Test199() ;

  Test200() ;   Test201() ;   Test202() ;   Test203() ;   Test204() ;   Test205() ;   Test206() ;   Test207() ;   Test208() ;   Test209() ;
  Test210() ;   Test211() ;   Test212() ;   Test213() ;   Test214() ;   Test215() ;   Test216() ;   Test217() ;   Test218() ;   Test219() ;
  Test220() ;   Test221() ;   Test222() ;   Test223() ;   Test224() ;   Test225() ;   Test226() ;   Test227() ;   Test228() ;   Test229() ;
  Test230() ;   Test231() ;   Test232() ;   Test233() ;   Test234() ;   Test235() ;   Test236() ;   Test237() ;   Test238() ;   Test239() ;
  Test240() ;   Test241() ;   Test242() ;   Test243() ;   Test244() ;   Test245() ;   Test246() ;   Test247() ;   Test248() ;   Test249() ;
  Test250() ;   Test251() ;   Test252() ;   Test253() ;   Test254() ;   Test255() ;   Test256() ;   Test257() ;   Test258() ;   Test259() ;
  Test260() ;   Test261() ;   Test262() ;   Test263() ;   Test264() ;   Test265() ;   Test266() ;   Test267() ;   Test268() ;   Test269() ;
  Test270() ;   Test271() ;   Test272() ;   Test273() ;   Test274() ;   Test275() ;   Test276() ;   Test277() ;   Test278() ;   Test279() ;
  Test280() ;   Test281() ;   Test282() ;   Test283() ;   Test284() ;   Test285() ;   Test286() ;   Test287() ;   Test288() ;   Test289() ;
  Test290() ;   Test291() ;   Test292() ;   Test293() ;   Test294() ;   Test295() ;   Test296() ;   Test297() ;   Test298() ;   Test299() ;

  Test300() ;   Test301() ;   Test302() ;   Test303() ;   Test304() ;   Test305() ;   Test306() ;   Test307() ;   Test308() ;   Test309() ;
  Test310() ;   Test311() ;   Test312() ;   Test313() ;   Test314() ;   Test315() ;   Test316() ;   Test317() ;   Test318() ;   Test319() ;
  Test320() ;   Test321() ;   Test322() ;   Test323() ;   Test324() ;   Test325() ;   Test326() ;   Test327() ;   Test328() ;   Test329() ;
  Test330() ;   Test331() ;   Test332() ;   Test333() ;   Test334() ;   Test335() ;   Test336() ;   Test337() ;   Test338() ;   Test339() ;
  Test340() ;   Test341() ;   Test342() ;   Test343() ;   Test344() ;   Test345() ;   Test346() ;   Test347() ;   Test348() ;   Test349() ;
  Test350() ;   Test351() ;   Test352() ;   Test353() ;   Test354() ;   Test355() ;   Test356() ;   Test357() ;   Test358() ;   Test359() ;
  Test360() ;   Test361() ;   Test362() ;   Test363() ;   Test364() ;   Test365() ;   Test366() ;   Test367() ;   Test368() ;   Test369() ;
  Test370() ;   Test371() ;   Test372() ;   Test373() ;   Test374() ;   Test375() ;   Test376() ;   Test377() ;   Test378() ;   Test379() ;
  Test380() ;   Test381() ;   Test382() ;   Test383() ;   Test384() ;   Test385() ;   Test386() ;   Test387() ;   Test388() ;   Test389() ;
  Test390() ;   Test391() ;   Test392() ;   Test393() ;   Test394() ;   Test395() ;   Test396() ;   Test397() ;   Test398() ;   Test399() ;

  Test400() ;   Test401() ;   Test402() ;   Test403() ;   Test404() ;   Test405() ;   Test406() ;   Test407() ;   Test408() ;   Test409() ;
  Test410() ;   Test411() ;   Test412() ;   Test413() ;   Test414() ;   Test415() ;   Test416() ;   Test417() ;   Test418() ;   Test419() ;
  Test420() ;   Test421() ;   Test422() ;   Test423() ;   Test424() ;   Test425() ;   Test426() ;   Test427() ;   Test428() ;   Test429() ;
  Test430() ;   Test431() ;   Test432() ;   Test433() ;   Test434() ;   Test435() ;   Test436() ;   Test437() ;   Test438() ;   Test439() ;
  Test440() ;   Test441() ;   Test442() ;   Test443() ;   Test444() ;   Test445() ;   Test446() ;   Test447() ;   Test448() ;   Test449() ;
  Test450() ;   Test451() ;   Test452() ;   Test453() ;   Test454() ;   Test455() ;   Test456() ;   Test457() ;   Test458() ;   Test459() ;
  Test460() ;   Test461() ;   Test462() ;   Test463() ;   Test464() ;   Test465() ;   Test466() ;   Test467() ;   Test468() ;   Test469() ;
  Test470() ;   Test471() ;   Test472() ;   Test473() ;   Test474() ;   Test475() ;   Test476() ;   Test477() ;   Test478() ;   Test479() ;
  Test480() ;   Test481() ;   Test482() ;   Test483() ;   Test484() ;   Test485() ;   Test486() ;   Test487() ;   Test488() ;   Test489() ;
  Test490() ;   Test491() ;   Test492() ;   Test493() ;   Test494() ;   Test495() ;   Test496() ;   Test497() ;   Test498() ;   Test499() ;

  ...                                                                                                                                    */

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  report() ;

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  return 0 ;

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/
}

/***************************************************************************************************************************************************/
