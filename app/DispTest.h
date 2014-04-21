/* File: DispTest.h
 * Reason: Header information about the Displacement tests
 *
 * Created by: Brandon Marick 03/04/14
 */

#ifndef DISP_TEST_HEADER

#define DISP_TEST_HEADER

#include "helper.h"
#include "motorControl.h"
#include "socket.h"
#include "testData.h"

#include <stdio.h>
#include <time.h> 

// FUNCTION
int DisplacementTimedTest(Test_Data *test_data);
int DisplacementTest(Test_Data *test_data);

#endif /* DISP_TEST_HEADER */
