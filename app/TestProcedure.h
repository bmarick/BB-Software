/* File: TestProcedure.h
 * Reason: Header information about both tests
 *
 * Created by: Brandon Marick 03/04/14
 */

#ifndef TEST_PROCEDURE_HEADER

#define TEST_PROCEDURE_HEADER

#include "helper.h"
#include "motorControl.h"
#include "socket.h"
#include "testData.h"

#include <stdio.h>
#include <time.h> 

// FUNCTION
int TimedTest(Test_Data *test_data);
int NonTimedTest(Test_Data *test_data);

// Function to generate a one secont time difference in time_t variable
inline void setTestTimeout(time_t *out){
	time_t timer;
	time(&timer);
	struct tm temp_tm = *localtime(&timer);
	temp_tm.tm_sec += 1;
	timer = mktime(&temp_tm);
	*out = timer;
}

#endif /* TEST_PROCEDURE_HEADER */

