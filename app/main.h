/* File: main.h
 * Reason: Header functionality
 * Created by: Brandon Marick 1/22/14
 */

#include "helper.h"
#include "SimpleGPIO.h"

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>

// VARIABLES
uint8_t	 TEST_DISP = 2, TEST_PRES = 1;
uint8_t  TEST_SELECT; 
uint16_t PRESSURE_MAX = 2000, PRESSURE_MIN = 0;
uint16_t DISPLACEMENT_MAX = 1500, DISPLACEMENT_MIN = 0;
uint16_t DISPLACEMENT_SEL, PRESSURE_SEL;
clock_t CLOCK_START, CLOCK_END;

// FUNCTIONS
int testInit();
