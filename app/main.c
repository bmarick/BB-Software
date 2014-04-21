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

	TimedTest(&test_data);
	// LAUNCH TEST
	if(test_data.timer > 0) {
		TimedTest(&test_data);
	} else {
		NonTimedTest(&test_data);
	}
	
	motorManual(test_data.station);
		
	return 0; 
}

void testInit(){
	int temp;
	// TEST SELECTION
	println("Select on of the following tests: ");
	println("\t1) Pressure");
	println("\t2) Displacement");
	printf("Your Selection: ");
	temp = userInputIntRange(1,2);
	// SET TEST VALUES
	if(temp == 2) {
		test_data.test_type = DISPLACEMENT;
		printf("\nThe max displacement possible is %Lf inches.\n",DISPLACEMENT_MAX);
		printf("Please enter desired displacement: ");
		test_data.goal = userInputDoubleRange(DISPLACEMENT_MIN,DISPLACEMENT_MAX);
	} else {
		test_data.test_type = PRESSURE;
		printf("\nThe max displacement possible is %Lf Pa.\n",PRESSURE_MAX);
		printf("Please enter desired pressure: ");
		test_data.goal = userInputDoubleRange(PRESSURE_MIN,PRESSURE_MAX);
	}
	// LENGTH OF TEST
	println("\nSetting the length of the test.");
	println("Input format 'Days':'hours':'minutes':'sec'");
	println("To not set a length input: 0:0:0:0");
	printf("Please enter desired test lenght,: ");
	test_data.timer = userInputTime(&TIME_DAYS,&TIME_HRS,&TIME_MIN,&TIME_SEC);
	// SELECT TESTING STATION
	println("\nSelect Testing Station.");
	printf("Please enter desired testing station[1-2]: ");
	temp = userInputIntRange(1,2);
	if(temp == 2)	test_data.station = STATION_B;
	else		test_data.station = STATION_A;
	// GEAR RATIO
	println("\nSetting the current Selector Position.");
	printf("The current position is[%d-%d]: ",SELECTOR_LOW,SELECTOR_HIGH);
	test_data.selector = userInputIntRange(SELECTOR_LOW,SELECTOR_HIGH);
	// ACCEPTABLE ERROR
	println("\nSetting the Acceptable Error, in percentage.");
	printf("Please enter the acceptable error[%Lf-%Lf]: ",ERROR_LOW,ERROR_HIGH);
	test_data.error = userInputDoubleRange(ERROR_LOW,ERROR_HIGH);
	test_data.accept_min = (test_data.goal)*
			(((long double)(100-test_data.error)/100));
	test_data.accept_max = (test_data.goal)*
			(((long double)(100+test_data.error)/100));
}

int testConfirm(){
	println("\n\nPLEASE CONFIRM THE TESTING DETAILS: ");
	if(test_data.test_type == PRESSURE){
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
	printf("\tSelector ratio: %d\n",test_data.selector);
	printf("\tAcceptable Error : %Lf\n", test_data.error);
	printf("\nIs the above test information correct (y or n)? ");
	return userConfrim();
}
