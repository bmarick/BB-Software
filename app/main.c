/* File: main.c
 * Purpose: Central functionality *
 * Created by: Brandon Marick 1/22/14
 */

#include "main.h"

int main(int argc, char *argv[]){
	system("clear");
	
	println("Welcome to the Grad Soils Lab Testing software.");
	
	testInit();
	while(testConfirm() < 0){ testInit(); }
		
	testEndTime(&TIME_DAYS,&TIME_HRS,&TIME_MIN,&TIME_SEC,&TIME_END);
	printf("TIME_END is: %s\n", ctime(&TIME_END));


	return 0; 
}

void testInit(){
	// TEST SELECTION
	println("Select on of the following tests: ");
	println("\t1) Pressure");
	println("\t2) Displacement");
	printf("Your Selection : ");
	TEST_SELECT = userInputRange(1,2);
	// SET TEST VALUES
	if(TEST_SELECT == TEST_DISP) {
		printf("\nThe max displacement possible is %d inches.\n",DISPLACEMENT_MAX);
		printf("Please enter desired displacement: ");
		DISPLACEMENT_SEL = userInputRange(DISPLACEMENT_MIN,DISPLACEMENT_MAX);
	} else {
		printf("\nThe max displacement possible is %d Pa.\n",PRESSURE_MAX);
		printf("Please enter desired displacement: ");
		DISPLACEMENT_SEL = userInputRange(PRESSURE_MIN,PRESSURE_MAX);
	}
	// LENGTH OF TEST
	println("\nSetting the length of the test.");
	println("Input format 'Days':'hours':'minutes':'sec'");
	printf("Please enter desired test lenght: ");
//	userInputTime(&TIME_END);
	TIME_LIMIT = userInputTime(&TIME_DAYS,&TIME_HRS,&TIME_MIN,&TIME_SEC);
//	printf("TIME_END is: %s\n", ctime(&TIME_END));
	// SELECT TESTING STATION
	println("\nSelect Testing Station.");
	printf("Please enter desired testing station[%d-%d]: ",STATION_A,STATION_B);
	STATION_SELECT = userInputRange(STATION_A,STATION_B);
	// GEAR RATIO
	println("\nSetting the current Gear Ratio.");
	printf("The current gear is[%d-%d]: ",GEAR_LOW,GEAR_HIGH);
	GEAR_SELECT = userInputRange(GEAR_LOW,GEAR_HIGH);
}

int testConfirm(){
	println("\n\nPLEASE CONFIRM THE TESTING DETAILS: ");
	if(TEST_SELECT == TEST_PRES){
		println("\tTest type: Pressure");
		printf("\tDesired pressure: %d\n",DISPLACEMENT_SEL);
	} else {
		println("\tTest type: Displacement");
		printf("\tDesired displacement: %d\n",PRESSURE_SEL);
	}
	if(TIME_LIMIT <= 0){ 
		println("\tTest length: NOT SET!");
	} else  {
		printf("\tTest length: %d days, %d hours, ",TIME_DAYS,TIME_HRS);
		printf("%d minutes, %d seconds\n",TIME_MIN,TIME_SEC);
	}
	printf("\tTest Station: Station %d\n",STATION_SELECT);
	printf("\tGear ration: %d\n",GEAR_SELECT);
	printf("\nIs the above test information correct (y or n)?");
	return userConfrim();
}
