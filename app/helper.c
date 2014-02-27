/* File: helper.c
 * Reason: Header functionality
 * Created by: Brandon Marick 1/22/14
 */

#include "helper.h"

int userInput(int min, int max){
	int select, result; 

	result = scanf("%d",&select);
	if((result > 0 || result != EOF) &&
			select >= min    &&
			select <= max){
		return select;
	} else {
		println("You have supplied an invalid input.");
		printf("Please enter your selection, agian: ");
		return userInput(min,max);
	}
}

int userInputTime(){
	int dd=0,hr=0,min=0,sec=0,result=0;
	result = scanf("%d:%d:%d:%d",&dd,&hr,&min,&sec);
	if(result > 0 || result != EOF){
		if(dd==0 && hr==0 && min==0 && sec==0)
			println("\tNO TIMELIMIT");
			
		else
			println("\tTIMELIMIT");
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
