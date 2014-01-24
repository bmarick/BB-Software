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

unsigned int DEVICE1[] = { 66, 67, 69, 68, 45, 44 };
unsigned int DEVICE2[] = { 23, 26, 47, 46, 27, 65 };

int DEVICE_PINS = 6;

int State_Init();
int State_Value(int command);
int State_Check(int command);
int State_Set(int command);
int State_Save();
int State_Exit(int command);

