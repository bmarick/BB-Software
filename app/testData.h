/* File: testData.h
 * Reason: Variables for tests
 *
 * Created by: Brandon Marick 03/04/14
 */

#ifndef TEST_DATA_HEADER

#define TEST_DATA_HEADER
#include <stdint.h>
#include <netinet/in.h>

const uint8_t		TEST_DISP = 2, TEST_PRES = 1;
const uint8_t		ERROR_LOW = 0, ERROR_HIGH = 5;
const uint8_t		GEAR_LOW = 1, GEAR_HIGH = 5;
const uint8_t		STATION_A = 1, STATION_B = 2;
const long double	PRESSURE_MAX = 2000, PRESSURE_MIN = 0;
const long double 	DISPLACEMENT_MAX = 1.5, DISPLACEMENT_MIN = 0;

const int		MAX_LINE = 80;
const int		PORT_A = 32000, PORT_B = 32002;

#ifndef STRUCT_TEST
#define	STRUCT_TEST
typedef struct Test_Data {
	int		type;
	long double	goal, accept_min, accept_max;
	time_t		end;
	int		station;
	int		timer;
	int 		gear;
	int 		error;
	int 		socketId;
	struct sockaddr_in servaddr;
} Test_Data;
#endif /* STRUCT_TEST */

#endif /* DISP_TEST_HEADER */
