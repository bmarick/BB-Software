/* File: helper.c
 * Reason: Header functionality
 * Created by: Brandon Marick 1/22/14
 */

#include "helper.h"

/* VARIABLES */
int INPUT_ATTEMPT_INIT=0, INPUT_ATTEMPT_MAX=5;

/* FUNCTIONS */
	//RECURSIVE FUNCTIONS
int userConfrimRecursive(int count){
	char sel = 'Q';
	int result;
	result = scanf(" %c",&sel);
	if(result > 0 && result != EOF){
		if (sel == 'y' || sel =='Y')
			return 1;
		else if( sel == 'n' || sel == 'N')
			return -1;
	} else if (count == INPUT_ATTEMPT_MAX -1){
		println("\t\tWARNING: YOU HAVE ONLY ONE MORE ATTEMPT!");
	} else if (count >= INPUT_ATTEMPT_MAX)
		return 0;
	println("You have supplied an invalid input.");
	printf("Please enter your selection, agian: ");
	return userConfrimRecursive(++count);
}

int userInputRangeRecursive(int min, int max, int count){
	int select, result; 

	result = scanf(" %d",&select);
	if((result > 0 && result != EOF) &&
			select >= min    &&
			select <= max){
		return select;
	} else if (count == INPUT_ATTEMPT_MAX -1){
		println("\t\tWARNING: YOU HAVE ONLY ONE MORE ATTEMPT!");
	} else if (count >= INPUT_ATTEMPT_MAX)
		return -1;
	println("You have supplied an invalid input.");
	printf("Please enter your selection, agian: ");
	return userInputRangeRecursive(min,max,++count); 
}

int userInputTimeRecursive(int *dd, int *hr, int *min, int *sec, int count){
	*dd=0;		*hr=0;		*min=0;		*sec=0;
	int result=0;
	result = scanf(" %d:%d:%d:%d",dd,hr,min,sec);
	printf("\t\tRESULT: %d", result);
	if(result == 4 && result != EOF){
		if(*dd==0 && *hr==0 && *min==0 && *sec==0){
			println("\tNO TIMELIMIT");
			return NULL;
		} else {
			println("\tTIMELIMIT");
			return 1;
/*			time_t timer;
			time(&timer);
			printf("start time is: %s\n", ctime(&timer));
			struct tm temp_tm = *localtime(&timer);
			temp_tm.tm_sec += sec;
			temp_tm.tm_sec += min*60;
			temp_tm.tm_sec += hr*3600;
			temp_tm.tm_sec += dd* 86400;
			timer = mktime(&temp_tm);
			printf("adjusted time is: %s\n", ctime(&timer));
			*out = timer;
			printf("adjusted time is: %s\n", ctime(out)); */
		}
	} else if (count == INPUT_ATTEMPT_MAX -1){
		println("\t\tWARNING: YOU HAVE ONLY ONE MORE ATTEMPT!");
	} else if (count >= INPUT_ATTEMPT_MAX){
		*dd=0;		*hr=0;		*min=0;		*sec=0;
		return -1;
	}
	println("You have supplied an invalid input.");
	printf("Please enter your selection, agian: ");
	return userInputTimeRecursive(dd,hr,min,sec,++count);
}

	//PUBLIC CALLS
int userConfrim(){
	return userConfrimRecursive(INPUT_ATTEMPT_INIT);
}

int userInputRange(int min, int max){
	return userInputRangeRecursive(min,max,INPUT_ATTEMPT_INIT);
}

int userInputTime(int *dd, int *hr, int *min, int *sec){
	*dd=0;		*hr=0;		*min=0;		*sec=0;
	return userInputTimeRecursive(dd,hr,min,sec,INPUT_ATTEMPT_INIT);
}
