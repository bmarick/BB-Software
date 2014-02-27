/* File: helper.h
 * Reason: Header functionality
 * Created by: Brandon Marick 1/22/14
 */

#include <iostream>
#include <stdio.h>
#include <string.h>

//FUNCTIONS
int userInput(int min, int max);
int userInputDef(int min, int max, int def);
int userInputTime();

	//INLINE
inline void println(char line[]){
	printf("%s\n",line);
}
