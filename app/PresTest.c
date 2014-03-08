/* File: PresTest.h
 * Reason: Pressure tests
 *
 * Created by: Brandon Marick 03/04/14
 */

#include "DispTest.h"
/*
// VARIABLES
struct sockaddr_in SERVADDR;
int SOCKET_ID = 0;
int PORT_STATION_A = 32000, PORT_STATION_B = 32001;
// MESSAGES
int MAX_LINE = 80;
*/
int PressureTimedTest(time_t *end, uint16_t *goal, uint8_t *station){
	time_t now;
	int current = 0, i = 0, result;
	char msg[MAX_LINE];
	
	if(socketOpen(&SOCKET_ID, &SERVADDR, PORT_STATION_A) != 0){
		println("\t\tERROR: setting up socket");
		return -1;
	}
	
	while(1){
		//REMOVE AFTER TESTING
		if(++i > 50){
			println("EXITING TEST: LOOP COUNT");
			break;
		}
		// CHECK TIME AND EXIT IF NEEDED
		time(&now);
		if(difftime(*end,now) <= 0){
			println("EXITING TEST: DUE TO TIME NOW >= END");
			break;
		}

		result = socketRead(&SOCKET_ID, msg, &MAX_LINE);
		if(result == -2){
			socketClose(&SOCKET_ID);
			println("\t\tERROR: reading socket");
			return -1;
		}
		
	}

	return 1;
}

int PressureTest(uint16_t goal, uint8_t station){
	int current = 0, i = 0, result;
	char msg[MAX_LINE];
	
	if(socketOpen(&SOCKET_ID, &SERVADDR, PORT_STATION_A) != 0){
		println("\t\tERROR: setting up socket");
		return -1;
	}
	
	while(1){
		//REMOVE AFTER TESTING
		if(++i > 50){
			println("EXITING TEST: LOOP COUNT");
			break;
		}

		result = socketRead(&SOCKET_ID, msg, &MAX_LINE);
		if(result == -2){
			socketClose(&SOCKET_ID);
			println("\t\tERROR: reading socket");
			return -1;
		}
		
	}
	return 1;
}
