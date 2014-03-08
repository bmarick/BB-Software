/* File: PresTest.h
 * Reason: Header information about the Pressure tests
 *
 * Created by: Brandon Marick 03/04/14
 */

#ifndef PRES_TEST_HEADER

#define PRES_TEST_HEADER

#include "socket.h"
#include "helper.h"

#include <stdint.h>
#include <stdio.h>
#include <time.h> 

// FUNCTION
int PressureTimedTest(time_t *end, uint16_t *goal, uint8_t *station);
int PressureTest(uint16_t goal, uint8_t station);

#endif /* PRES_TEST_HEADER */
