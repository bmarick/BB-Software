/* File: TestProcedure.c
 * Reason: Both test procedures
 *
 * Created by: Brandon Marick 04/11/14
 */

#include "TestProcedure.h"

int TimedTest(Test_Data *test_data){
	test_type_t test_type = test_data->test_type;
	time_t now, test_pause_time, end = test_data->end;
	bool test_pause_bool = false;
	int result, prev_state = 0, station = test_data->station;
	long double d0=0, d1=0, d2=0, d3=0, current=0;
	long double accept_min = test_data->accept_min; 
	long double accept_max = test_data->accept_max;
	long double goal = test_data->goal;
	char msg[MAX_LINE];

	time(&test_pause_time);
	
	while(1){
		// CHECK TIME AND EXIT IF NEEDED
		time(&now);
		if(difftime(end,now) <= 0){
			println("EXITING TEST: DUE TO TIME NOW >= END");
			printf("\tEnd   time: %s\n",ctime(&now));
			break;
		}
		// READ FROM SOCKET
		result = socketRead(test_data, msg);
		// If motor paused, check if end of pause period 
		if(test_pause_bool && difftime(test_pause_time,now) <= 0){
			test_pause_bool = false;
		}
		// Motor actions: 
		// Check socket read
		if(result > 0) {
			// Pull out data for test data
			result = sscanf(msg," %Lf %Lf %Lf %Lf ",&d0,&d1,&d2,&d3);
			if(test_type == DISPLACEMENT)	current=d0;
			else				current=d1;
			// MOTOR ACTION
			if(!test_pause_bool && prev_state == 0){	// MOTOR HALTED
				// Check if still in acceptable range
				if(current >= accept_max){
					prev_state = -1;
					//motorMove((*test_data).station,prev_state,(*test_data).selector);
				} else if (current <= accept_min){
					prev_state = 1;
					//motorMove((*test_data).station,prev_state,(*test_data).selector);
				}
			} else if (!test_pause_bool && prev_state > 0 && current >= goal){ // MOTOR UP & needs to Stop
					prev_state = 0;
					//motorHalt(station);
					test_pause_bool = true;
					setTestTimeout(&test_pause_time);
			} else if (!test_pause_bool && prev_state < 0 && current <= goal){ // MOTOR DOWN & needs to Stop
					prev_state = 0;
					//motorHalt(station);
					test_pause_bool = true;
					setTestTimeout(&test_pause_time);
			}
			// PRINT OUTPUT
			if(test_type == DISPLACEMENT){
				if(prev_state == 0)
					printf("Current Displacement: %Lf\tMOTOR OFF\n",current);
				else if(prev_state > 0)
					printf("Current Displacement: %Lf\tMOTOR UP\n",current);
				else
					printf("Current Displacement: %Lf\tMOTOR DOWN\n",current);
			} else {
				if(prev_state == 0)
					printf("Current Pressure: %Lf\tMOTOR OFF\n",current);
				else if(prev_state > 0)
					printf("Current Pressure: %Lf\tMOTOR UP\n",current);
				else
					printf("Current Pressure: %Lf\tMOTOR DOWN\n",current);
			}
		}
		else if(result == -1){
			if(test_type == DISPLACEMENT)
				printf("Current Displacement: %Lf\tMOTOR OFF\n",(long double) 0);
			else
				printf("Current Pressure: %Lf\tMOTOR OFF\n",(long double) 0);
			if(prev_state != 0) {
				prev_state = 0;
				motorHalt(station);	
				test_pause_bool = true;
				setTestTimeout(&test_pause_time);
			}
		} else if(result == -2){
			socketClose(test_data);
			println("\t\tERROR: reading socket");
			return -1;
		}
		
	}

	return 1;
}

int NonTimedTest(Test_Data *test_data){
	test_type_t test_type = test_data->test_type;
	time_t now, test_pause_time;
	bool test_pause_bool = false;
	int result, prev_state = 0, station = test_data->station;
	long double d0=0, d1=0, d2=0, d3=0, current=0;
	long double accept_min = test_data->accept_min; 
	long double accept_max = test_data->accept_max;
	long double goal = test_data->goal;
	char msg[MAX_LINE];

	time(&test_pause_time);
	
	while(1){
		// CHECK TIME AND EXIT IF NEEDED
		time(&now);
		// READ FROM SOCKET
		result = socketRead(test_data, msg);
		// If motor paused, check if end of pause period 
		if(test_pause_bool){
			time(&now);
			if(difftime(test_pause_time,now) <= 0)
				test_pause_bool = false;
		}
		// Motor actions: 
		// Check socket read
		if(result > 0) {
			// Pull out data for test data
			result = sscanf(msg," %Lf %Lf %Lf %Lf ",&d0,&d1,&d2,&d3);
			if(test_type == DISPLACEMENT)	current=d0;
			else				current=d1;
			// MOTOR ACTION
			if(!test_pause_bool && prev_state == 0){	// MOTOR HALTED
				// Check if still in acceptable range
				if(current >= accept_max){
					prev_state = -1;
					//motorMove((*test_data).station,prev_state,(*test_data).selector);
				} else if (current <= accept_min){
					prev_state = 1;
					//motorMove((*test_data).station,prev_state,(*test_data).selector);
				}
			} else if (!test_pause_bool && prev_state > 0 && current >= goal){ // MOTOR UP & needs to Stop
					prev_state = 0;
					//motorHalt(station);
					test_pause_bool = true;
					setTestTimeout(&test_pause_time);
			} else if (!test_pause_bool && prev_state < 0 && current <= goal){ // MOTOR DOWN & needs to Stop
					prev_state = 0;
					//motorHalt(station);
					test_pause_bool = true;
					setTestTimeout(&test_pause_time);
			}
			// PRINT OUTPUT
			if(test_type == DISPLACEMENT){
				if(prev_state == 0)
					printf("Current Displacement: %Lf\tMOTOR OFF\n",current);
				else if(prev_state > 0)
					printf("Current Displacement: %Lf\tMOTOR UP\n",current);
				else
					printf("Current Displacement: %Lf\tMOTOR DOWN\n",current);
			} else {
				if(prev_state == 0)
					printf("Current Pressure: %Lf\tMOTOR OFF\n",current);
				else if(prev_state > 0)
					printf("Current Pressure: %Lf\tMOTOR UP\n",current);
				else
					printf("Current Pressure: %Lf\tMOTOR DOWN\n",current);
			}
		}
		else if(result == -1){
			if(test_type == DISPLACEMENT)
				printf("Current Displacement: %Lf\tMOTOR OFF\n",(long double) 0);
			else
				printf("Current Pressure: %Lf\tMOTOR OFF\n",(long double) 0);
			if(prev_state != 0) {
				prev_state = 0;
				motorHalt(station);	
				test_pause_bool = true;
				setTestTimeout(&test_pause_time);
			}
		} else if(result == -2){
			socketClose(test_data);
			println("\t\tERROR: reading socket");
			return -1;
		}
		
	}

	return 1;
}
