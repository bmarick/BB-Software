/* File: DevApplication.h
 * Reason: Used as a header such that all constants and functions are declared
 * here. 
 *
 * Created by: Brandon Marick 1/22/14
 *
 * Modified by: 
 *
 */

#include "SimpleGPIO.h"
#include <stdio.h>
#include <sys/dir.h>
#include <sys/param.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// Test Variable Defines
int TEST_CHECK	 = 1;
int TEST_SET	 = 2;
int TEST_SAVE	 = 3;
int TEST_F_READ	 = 4; 
int TEST_EXIT	 = 5;
int TEST_MAX_VALUE = 5;
int TEST_MIN_VALUE = 1;

// PIN DEFINES
unsigned int GPIO_D1[] = { 66, 67, 69, 68, 45, 44 };
unsigned int GPIO_D2[] = { 23, 26, 47, 46, 27, 65 };
int GPIO_PIN_COUNT = 6;

// PIPE DEFINES
int MAX_LINE = 80;

// FUNCTION DEFINES
int State_Check();
int State_Read();
int State_Set();
int State_Save();

