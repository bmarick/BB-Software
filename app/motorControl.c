/* File: motorControl.c
 * Reason: motor funcitonality
 *
 * Created by: Brandon Marick 03/09/14
 */

#include "motorControl.h"

void motorAutomatic(int station){
	int i;

	if(station == STATION_A){
		for(i=0; i<GPIO_PIN_COUNT;i++){
			gpio_export(GPIO_S1[i]);
	        	gpio_set_dir(GPIO_S1[i], OUTPUT_PIN);
        		gpio_set_value(GPIO_S1[0], HIGH);
		        gpio_set_value(GPIO_S1[2], HIGH);
		        gpio_set_value(GPIO_S1[4], HIGH);
		}
	} else {
		for(i=0; i<GPIO_PIN_COUNT;i++){
			gpio_export(GPIO_S2[i]);
	        	gpio_set_dir(GPIO_S2[i], OUTPUT_PIN);
        		gpio_set_value(GPIO_S2[0], HIGH);
		        gpio_set_value(GPIO_S2[2], HIGH);
		        gpio_set_value(GPIO_S2[4], HIGH);
		}
	}
}

void motorHalt(int station){
	if(station == STATION_A){
       		gpio_set_value(GPIO_S1[1], LOW);
	        gpio_set_value(GPIO_S1[3], LOW);
	        gpio_set_value(GPIO_S1[5], LOW);
	} else {
       		gpio_set_value(GPIO_S2[1], LOW);
	        gpio_set_value(GPIO_S2[3], LOW);
	        gpio_set_value(GPIO_S2[5], LOW);
	}
}

void motorManual(int station){
	int i;	

	if(station == STATION_A){
		for(i=0; i<GPIO_PIN_COUNT;i++){
			gpio_set_value(GPIO_S1[i], LOW);
			gpio_unexport(GPIO_S1[i]);
		}
	} else {
		for(i=0; i<GPIO_PIN_COUNT;i++){
			gpio_set_value(GPIO_S2[i], LOW);
			gpio_unexport(GPIO_S2[i]);
		}
	}
}

void motorMove(int station, int direction, int gear){
	if(direction == 0){
		motorHalt(station);
		return;
	} else if( gear < GEAR_LOW || gear > GEAR_HIGH){
		printf("\t\tINVALID GEAR!!");
		return;
	}

	if(station == STATION_A){
		if(direction > 0 && (gear == 1 || gear == 3 || gear == 5)){
       			gpio_set_value(GPIO_S1[1], HIGH);
		        gpio_set_value(GPIO_S1[3], HIGH);
		} else if(direction < 0 && (gear == 2 || gear == 4)){
       			gpio_set_value(GPIO_S1[1], HIGH);
		        gpio_set_value(GPIO_S1[3], HIGH);
		} else {
       			gpio_set_value(GPIO_S1[1], HIGH);
		        gpio_set_value(GPIO_S1[5], HIGH);
		}
	} else { 
		if(direction > 0 && (gear == 1 || gear == 3 || gear == 5)){
       			gpio_set_value(GPIO_S2[1], HIGH);
		        gpio_set_value(GPIO_S2[3], HIGH);
		} else if(direction < 0 && (gear == 2 || gear == 4)){
       			gpio_set_value(GPIO_S2[1], HIGH);
		        gpio_set_value(GPIO_S2[3], HIGH);
		} else {
       			gpio_set_value(GPIO_S2[1], HIGH);
		        gpio_set_value(GPIO_S2[5], HIGH);
		}
	}
}
