/* File: helper.h
 * Reason: Header functionality
 * Created by: Brandon Marick 1/22/14
 */

#include <iostream>
#include <stdio.h>
#include <string.h>

//FUNCTIONS
void testEndTime(int *dd, int *hr, int *min, int *sec, time_t *out);
int userConfrim();
int userInputRange(int min, int max);
int userInputTime(int *dd, int *hr, int *min, int *sec);

	//INLINE
inline void println(char line[]){
	printf("%s\n",line);
}

