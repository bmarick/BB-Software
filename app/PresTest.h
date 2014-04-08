/* File: PresTest.h
 * Reason: Header information about the Pressure tests
 *
 * Created by: Brandon Marick 03/04/14
 */

#ifndef PRES_TEST_HEADER

#define PRES_TEST_HEADER

#include "helper.h"
#include "motorControl.h"
#include "socket.h"
#include "testData.h"

#include <stdio.h>
#include <time.h> 

// FUNCTION
int PressureTimedTest(Test_Data *test_data);
int PressureTest(Test_Data *test_data);

#endif /* PRES_TEST_HEADER */
