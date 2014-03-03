/* File: main.c
 * Purpose: Central functionality *
 * Created by: Brandon Marick 1/22/14
 */

#include "main.h"
int main(int argc, char *argv[]){
	int result = system("clear");
	
	println("Welcome to the Grad Soils Lab Testing software.");
	
	testInit();
	
	return 0; 
}

int testInit(){
	// TEST SELECTION
	println("Select on of the following tests: ");
	println("\t1) Pressure");
	println("\t2) Displacement");
	printf("Your Selection : ");
	TEST_SELECT = userInput(1,2);
	// SET TEST VALUES
	if(TEST_SELECT == TEST_DISP) {
		printf("The max displacement possible is %d inches.\n",DISPLACEMENT_MAX);
		printf("Please enter desired displacement: ");
		DISPLACEMENT_SEL = userInput(DISPLACEMENT_MIN,DISPLACEMENT_MAX);
	} else {
		printf("The max displacement possible is %d Pa.\n",PRESSURE_MAX);
		printf("Please enter desired displacement: ");
		DISPLACEMENT_SEL = userInput(PRESSURE_MIN,PRESSURE_MAX);
	}
	// LENGTH OF TEST
	println("\nSetting the length of the test.");
	println("To not set a lengthe of the test input: 0:0:0:0");
	println("Input format 'Days':'hours':'minutes':'sec'");
	printf("Please enter desired test lenght: ");
	userInputTime();
	// GEAR RATIO

	return 0;
}
