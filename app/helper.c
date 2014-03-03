/* File: helper.c
 * Reason: Header functionality
 * Created by: Brandon Marick 1/22/14
 */

#include "helper.h"

/* VARIABLES */
int INPUT_ATTEMPT_INIT=0, INPUT_ATTEMPT_MAX=5;

/* FUNCTIONS */
void clearToEndOfLine(){
	char ch;
	ch = getchar();
	while( ch != '\n' || ch != EOF )	ch = getchar();
}

int userInput(int min, int max){
	return userInputRecursive(min,max,INPUT_ATTEMPT_INIT);
}

int userInputRecursive(int min, int max, int count){
	int select, result; 

	clearToEndOfLine();
	result = scanf("%d",&select);
//	fflush(stdin);
	if((result > 0 || result != EOF) &&
			select >= min    &&
			select <= max){
		return select;
	} else if(++count < INPUT_ATTEMPT_MAX){
		println("You have supplied an invalid input.");
		printf("Please enter your selection, agian: ");
		return userInputRecursive(min,max,count);
	} else 
		return -1; 
}

int userInputTime(){
	int dd=0,hr=0,min=0,sec=0,result=0;
	result = scanf("%d:%d:%d:%d",&dd,&hr,&min,&sec);
	printf("\tRETURN VALUE: %d",result);
	if(result == 4 || result != EOF){
		if(dd==0 && hr==0 && min==0 && sec==0){
			println("\tNO TIMELIMIT");
		} else {
			println("\tTIMELIMIT");
			time_t timer;
			time(&timer);
			printf("current time is: %s\n", ctime(&timer));
			struct tm temp_tm = *localtime(&timer);
			temp_tm += sec;
			temp_tm += min*60;
		}
	} else {
		println("You have supplied an invalid input.");
		printf("Please enter your selection, agian: ");
		return userInputTime();
	}
	return 0;
}

int userInputDef(int min, int max, int def){
	int select = 0;

	if(std::cin.peek() == '\n')
		return def;
	else if(!(std::cin >> select) || 
			select < min  ||
			select > max){
		std::cin.clear();
		println("You have supplied an invalid input.");
		printf("Please enter your selection, agian: ");
		return userInputDef(min,max,def);
	} else
		return select;
}
