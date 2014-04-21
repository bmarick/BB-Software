/* File: testData.h
 * Reason: Variables for tests
 *
 * Created by: Brandon Marick 03/04/14
 */

#ifndef TEST_DATA_HEADER

#define TEST_DATA_HEADER
#include <stdint.h>
#include <netinet/in.h>

const uint8_t		SELECTOR_LOW = 1, SELECTOR_HIGH = 5;
const long double	PRESSURE_MAX = 2000, PRESSURE_MIN = 0;
const long double 	DISPLACEMENT_MAX = 1.5, DISPLACEMENT_MIN = 0;
const long double	ERROR_LOW = 0, ERROR_HIGH = 5;
const int		MAX_LINE = 80;

#ifndef STRUCT_TEST
#define	STRUCT_TEST

typedef enum { PRESSURE, DISPLACEMENT } test_type_t;
typedef enum { STATION_A = 32000, STATION_B = 32002 } port_t;

typedef struct Test_Data {
	test_type_t 	test_type;
	long double	goal, accept_min, accept_max;
	time_t		end;
	port_t		station;
	int		timer;
	int 		selector;
	long double	error;
	int 		socketId;
	struct sockaddr_in servaddr;
} Test_Data;
#endif /* STRUCT_TEST */

#endif /* DISP_TEST_HEADER */
