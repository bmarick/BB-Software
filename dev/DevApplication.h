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

#include <errno.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/dir.h>
#include <sys/param.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

// Test Variable Defines
int TEST_SET		= 1;
int TEST_SAVE		= 2;
int TEST_F_READ		= 3;
int TEST_PIPE		= 4;
int TEST_SOCKET		= 5; 
int TEST_RELAY		= 6;
int TEST_MOTOR		= 7;
int TEST_EXIT		= 8;
int TEST_MAX_VALUE	= 8;
int TEST_MIN_VALUE	= 1;

// PIN DEFINES
unsigned int GPIO_D1[] = { 66, 67, 69, 68, 45, 44 };
unsigned int GPIO_D2[] = { 23, 26, 47, 46, 27, 65 };
int GPIO_PIN_COUNT = 6;

// COMUNICATION DEFINES
int MAX_LINE = 80;
int PORT = 32000;

// FUNCTION DEFINES
int State_Motor();
int State_Pipe();
int State_Read();
int State_Save();
int State_Set();
int State_Socket();
int State_Relay();
