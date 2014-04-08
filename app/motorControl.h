/* File: motorControl.h
 * Reason: Header for motor control
 *
 * Created by: Brandon Marick 03/09/14
 */

#ifndef MOTOR_CONTROL
#define MOTOR_CONTROL

#include "testData.h"
#include "SimpleGPIO.h"

#include <stdio.h>

// Variables
const unsigned int GPIO_S1[] = { 66, 67, 69, 68, 45, 44 };
const unsigned int GPIO_S2[] = { 23, 26, 47, 46, 27, 65 };
const int GPIO_PIN_COUNT = 6;

// Functions

void motorAutomatic(int station);
void motorHalt(int station);
void motorManual(int station);
void motorMove(int station, int direction, int gear);

#endif
