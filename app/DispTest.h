/* File: DispTest.h
 * Reason: Header information about the Displacement tests
 *
 * Created by: Brandon Marick 03/04/14
 */

#ifndef DISP_TEST_HEADER

#define DISP_TEST_HEADER

#include "socket.h"
#include "helper.h"
#include "testData.h"

#include <stdint.h>
#include <stdio.h>
#include <time.h> 

// FUNCTION
int DisplacementTimedTest(time_t *end, uint16_t *goal, uint8_t *station);
int DisplacementTest(uint16_t goal, uint8_t station);

#endif /* DISP_TEST_HEADER */
