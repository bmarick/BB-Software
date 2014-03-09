/* File: helper.h
 * Reason: Header functionality
 * Created by: Brandon Marick 1/22/14
 */

#ifndef HELPER_HEADER

#define HELPER_HEADER

#include <iostream>
#include <stdio.h>
#include <string.h>

//FUNCTIONS
void testEndTime(int *dd, int *hr, int *min, int *sec, time_t *out);
int userConfrim();
long double userInputDoubleRange(long double min, long double max);
int userInputIntRange(int min, int max);
int userInputTime(int *dd, int *hr, int *min, int *sec);

	//INLINE
inline void println(char line[]){
	printf("%s\n",line);
}

#endif /* HELPER_HEADER */
