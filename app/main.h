/* File: main.h
 * Reason: Header functionality
 * Created by: Brandon Marick 1/22/14
 */

#include "helper.h"
//#include "DispTest.h"
#include "motorControl.h"
//#include "PresTest.h"
#include "testData.h"
#include "TestProcedure.h"

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>

// VARIABLES
Test_Data 	test_data;
	//TIME VALUES
int	 TIME_DAYS, TIME_HRS, TIME_MIN, TIME_SEC;

// FUNCTIONS
int testConfirm();
void testInit();
int testPressure();
int testDisplacement();

