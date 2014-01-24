/* File: DevApplication
 * Purpose: Host all the testing applications
 *
 * Created by: Brandon Marick 1/22/14
 *
 * Modified by: 
 *
 */

// #include "DevApplication.h"
#include "SimpleGPIO.h"
#include <stdio.h>

int main(int argc, char *argv[]){
	int running = 1; 
	char testChar;

	printf("/nWelcome to the Grad Soils Lab Block Testing!");
	while(running){
		printf("/nPlease choose from the following sections to run a test");
		printf("/n/t A)  Init State");
		printf("/n/t B)  Value State");
		printf("/n/t C)  Set State");
		printf("/n/t D)  Save State");
		printf("/n/t E)  Exit State");
		printf("/n/t F)  Set Default Values (Optional)");
		printf("/n/t G)  QUIT TESTING");
		printf("/nPlease enter the letter for the test:");
		testChar = getChar();
		running = 0;
	}
	return 0;
}

int State_Init(){
	return 0;
}
int State_Value(int command){
	return 0;
}
int State_Check(int command){
	return 0;
}
int State_Set(int command){
	return 0;
}
int State_Save(){
	return 0;
}
int State_Exit(int command){
	return 0;
}
