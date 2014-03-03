/* File: helper.h
 * Reason: Header functionality
 * Created by: Brandon Marick 1/22/14
 */

#include <iostream>
#include <stdio.h>
#include <string.h>

//FUNCTIONS
int userInput(int min, int max);
int userInputRecursive(int min, int max,int count);
int userInputDef(int min, int max, int def);
int userInputTime(int *dd, int *hr, int *min, int *sec);
int userConfrim();
//int userInputTime(time_t *out);

	//INLINE
inline void println(char line[]){
	printf("%s\n",line);
}

