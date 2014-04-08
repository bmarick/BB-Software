/* File: main.c
 * Purpose: Central functionality *
 * Created by: Brandon Marick 1/22/14
 */

#include "main.h"

int main(int argc, char *argv[]){
	system("clear");
	
	println("Welcome to the Grad Soils Lab Testing software.");
	
	// TEST SETUP
	testInit();
	while(testConfirm() < 0){ testInit(); }
	
	// CALCUATIONS & TEST PREP		
	if(socketOpen(&test_data) != 0){
		println("\t\tERROR: setting up socket");
		return -1;
	}
	
	motorAutomatic(test_data.station);
		
	testEndTime(&TIME_DAYS,&TIME_HRS,&TIME_MIN,&TIME_SEC,&(test_data.end));
	// LAUNCH TEST
	if(test_data.type == TEST_DISP){
		if(test_data.timer > 0) {
			DisplacementTimedTest(&test_data);	
		} else 
			DisplacementTest(&test_data);
	} else {
		if(test_data.timer > 0) {
			PressureTimedTest(&test_data);	
		} else 
			PressureTest(&test_data);
	}
	
	motorManual(test_data.station);
		
	return 0; 
}

void testInit(){
	// TEST SELECTION
	println("Select on of the following tests: ");
	println("\t1) Pressure");
	println("\t2) Displacement");
	printf("Your Selection: ");
	test_data.type = userInputIntRange(1,2);
	// SET TEST VALUES
	if(test_data.type == TEST_DISP) {
		printf("\nThe max displacement possible is %Lf inches.\n",DISPLACEMENT_MAX);
		printf("Please enter desired displacement: ");
		test_data.goal = userInputDoubleRange(DISPLACEMENT_MIN,DISPLACEMENT_MAX);
	} else {
		printf("\nThe max displacement possible is %Lf Pa.\n",PRESSURE_MAX);
		printf("Please enter desired displacement: ");
		test_data.goal = userInputDoubleRange(PRESSURE_MIN,PRESSURE_MAX);
	}
	// LENGTH OF TEST
	println("\nSetting the length of the test.");
	println("Input format 'Days':'hours':'minutes':'sec'");
	printf("Please enter desired test lenght: ");
	test_data.timer = userInputTime(&TIME_DAYS,&TIME_HRS,&TIME_MIN,&TIME_SEC);
	// SELECT TESTING STATION
	println("\nSelect Testing Station.");
	printf("Please enter desired testing station[%d-%d]: ",STATION_A,STATION_B);
	test_data.station = userInputIntRange(STATION_A,STATION_B);
	// GEAR RATIO
	println("\nSetting the current Gear Ratio.");
	printf("The current gear is[%d-%d]: ",GEAR_LOW,GEAR_HIGH);
	test_data.gear = userInputIntRange(GEAR_LOW,GEAR_HIGH);
	// ACCEPTABLE ERROR
	println("\nSetting the Acceptable Error, in thousandths of a percentage.");
	printf("Please enter the acceptable error[%d-%d]: ",ERROR_LOW,ERROR_HIGH);
	test_data.error = userInputIntRange(ERROR_LOW,ERROR_HIGH);
	test_data.accept_min = (test_data.goal)*
			(((long double)(1000-test_data.error)/1000));
	test_data.accept_max = (test_data.goal)*
			(((long double)(1000+test_data.error)/1000));
}

int testConfirm(){
	println("\n\nPLEASE CONFIRM THE TESTING DETAILS: ");
	if(test_data.type == TEST_PRES){
		println("\tTest type: Pressure");
		printf("\tDesired pressure: %Lf\n",test_data.goal);
	} else {
		println("\tTest type: Displacement");
		printf("\tDesired displacement: %Lf\n",test_data.goal);
	}
	printf("\tAcceptable Min: %Lf\n",test_data.accept_min);
	printf("\tAcceptable Max: %Lf\n",test_data.accept_max);
	if(test_data.timer <= 0){ 
		println("\tTest length: NOT SET!");
	} else  {
		printf("\tTest length: %d days, %d hours, ",TIME_DAYS,TIME_HRS);
		printf("%d minutes, %d seconds\n",TIME_MIN,TIME_SEC);
	}
	printf("\tTest Station: Station %d\n",test_data.station);
	printf("\tGear ratio: %d\n",test_data.gear);
	printf("\tAcceptable Error : %d\n", test_data.error);
	printf("\nIs the above test information correct (y or n)? ");
	return userConfrim();
}
