/* File: PresTest.h
 * Reason: Displacement tests
 *
 * Created by: Brandon Marick 03/04/14
 */

#include "DispTest.h"

int DisplacementTimedTest(Test_Data *test_data){
	time_t now, end = (*test_data).end;
	int result, prev_state = 0;
	long double d0=0, d1=0, d2=0, d3=0, current=0;
	long double accept_min = (*test_data).accept_min; 
	long double accept_max = (*test_data).accept_max;
	char msg[MAX_LINE];
	
	while(1){
		// CHECK TIME AND EXIT IF NEEDED
		time(&now);
		if(difftime(end,now) <= 0){
			println("EXITING TEST: DUE TO TIME NOW >= END");
			printf("\tEnd   time: %s\n",ctime(&now));
			break;
		}

		result = socketRead(test_data, msg);
		if(result > 0) {
			result = sscanf(msg," %Lf %Lf %Lf %Lf ",&d0,&d1,&d2,&d3);
			current=d0;
			if(current > accept_max){ // DOWN
				if(prev_state > 0){
					motorHalt((*test_data).station);
					prev_state = 0;
					sleep(1);
				} 
				if(prev_state == 0){
					prev_state = -1;
					motorMove((*test_data).station,prev_state,(*test_data).gear);
				}
				printf("Current Displacement: %Lf\tMOTOR DOWN\n",current);
			} else if(current < accept_min) { // UP
				if(prev_state < 0){
					motorHalt((*test_data).station);
					prev_state = 0;
					sleep(1);
				} 
				if(prev_state == 0){
					printf("\tMOTOR UP\n");
					prev_state = 1;
					motorMove((*test_data).station,prev_state,(*test_data).gear);
				}
				printf("Current Displacement: %Lf\tMOTOR UP\n",current);
			} else {
				printf("Current Displacement: %Lf\tMOTOR OFF\n",current);
				motorHalt((*test_data).station);
				if(prev_state != 0)
					sleep(1);
				prev_state = 0;
			}
		} else if(result == -1){
			printf("Current Displacement: %f",0.000000);
			printf("\tMOTOR OFF\n");
			motorHalt((*test_data).station);
			if(prev_state != 0)
				sleep(1);
			prev_state = 0;
		} else if(result == -2){
			socketClose(test_data);
			println("\t\tERROR: reading socket");
			return -1;
		}
		
	}

	return 1;
}

int DisplacementTest(Test_Data *test_data){
	int result, prev_state = 0;
	long double d0=0, d1=0, d2=0, d3=0, current=0;
	long double accept_min = (*test_data).accept_min; 
	long double accept_max = (*test_data).accept_max;
	char msg[MAX_LINE];
	
	while(1){
		// CHECK TIME AND EXIT IF NEEDED
		result = socketRead(test_data, msg);
		if(result > 0) {
			result = sscanf(msg," %Lf %Lf %Lf %Lf ",&d0,&d1,&d2,&d3);
			current=d0;
			if(current > accept_max){ // DOWN
				if(prev_state > 0){
					motorHalt((*test_data).station);
					prev_state = 0;
					sleep(1);
				} 
				if(prev_state == 0){
					prev_state = -1;
					motorMove((*test_data).station,prev_state,(*test_data).gear);
				}
				printf("Current Displacement: %Lf\tMOTOR DOWN\n",current);
			} else if(current < accept_min) { // UP
				if(prev_state < 0){
					motorHalt((*test_data).station);
					prev_state = 0;
					sleep(1);
				} 
				if(prev_state == 0){
					printf("\tMOTOR UP\n");
					prev_state = 1;
					motorMove((*test_data).station,prev_state,(*test_data).gear);
				}
				printf("Current Displacement: %Lf\tMOTOR UP\n",current);
			} else {
				printf("Current Displacement: %Lf\tMOTOR OFF\n",current);
				motorHalt((*test_data).station);
				if(prev_state != 0)
					sleep(1);
				prev_state = 0;
			}
		} else if(result == -1){
			printf("Current Displacement: %f",0.000000);
			printf("\tMOTOR OFF\n");
			motorHalt((*test_data).station);
			if(prev_state != 0)
				sleep(1);
			prev_state = 0;
		} else if(result == -2){
			socketClose(test_data);
			println("\t\tERROR: reading socket");
			return -1;
		}
		
	}

	return 1;
}
