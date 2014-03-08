/* File: DispTest.h
 * Reason: Displacement tests
 *
 * Created by: Brandon Marick 03/04/14
 */

#include "DispTest.h"

// VARIABLES
struct sockaddr_in D_SERVADDR;
int D_SOCKET_ID = 0;
int D_PORT_STATION_A = 32000, D_PORT_STATION_B = 32001;
// MESSAGES
int D_MAX_LINE = 80;

int DisplacementTimedTest(time_t *end, uint16_t *goal, uint8_t *station){
	time_t now;
	int result;
	long double d0 = 0, d1 =0, d2 =0, d3 =0;
	char msg[D_MAX_LINE];

	if(socketOpen(&D_SOCKET_ID, &D_SERVADDR, D_PORT_STATION_A) != 0){
		println("\t\tERROR: setting up socket");
		return -1;
	}
	
	while(1){
		// CHECK TIME AND EXIT IF NEEDED
		time(&now);
		if(difftime(*end,now) <= 0){
			println("EXITING TEST: DUE TO TIME NOW >= END");
			time_t now;
			time(&now);
			printf("\tEnd   time: %s\n",ctime(&now));
			break;
		}

		result = socketRead(&D_SOCKET_ID, msg, &D_MAX_LINE);
		if(result > 0) {
			result = sscanf(msg," %Lf %Lf %Lf %Lf ",&d0,&d1,&d2,&d3);
			printf("Transfered %d to doubles\n",result);
			printf(" %s",msg);
			printf(msg," %Lf %Lf %Lf %Lf \n",d0,d1,d2,d3);
		} else if(result == -2){
			socketClose(&D_SOCKET_ID);
			println("\t\tERROR: reading socket");
			return -1;
		}
		
	}

	return 1;
}

int DisplacementTest(uint16_t goal, uint8_t station){
	int i = 0, result;
	char msg[D_MAX_LINE];
	
	if(socketOpen(&D_SOCKET_ID, &D_SERVADDR, D_PORT_STATION_A) != 0){
		println("\t\tERROR: setting up socket");
		return -1;
	}
	
	while(1){
		//REMOVE AFTER TESTING
		if(++i > 50){
			println("EXITING TEST: LOOP COUNT");
			break;
		}

		result = socketRead(&D_SOCKET_ID, msg, &D_MAX_LINE);
		if(result == -2){
			socketClose(&D_SOCKET_ID);
			println("\t\tERROR: reading socket");
			return -1;
		}
		
	}
	return 1;
}
