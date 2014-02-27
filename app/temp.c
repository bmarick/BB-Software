/* File: DevApplication
 * Purpose: Host all the testing applications
 *
 * Created by: Brandon Marick 1/22/14
 *
 * Modified by: 
 *
 */

#include "main.h"

int main(int argc, char *argv[]){
	int running = 1, count_break = 0,i=0; 
	int select,result;

	system("clear");
	while(running){
		printf("\nWelcome to the Grad Soils Lab Block Testing!\n");
		printf("\nPlease choose from the following sections ");
		printf("to run a test\n");
		printf("\t %d)  Set State, need root permisions\n", TEST_SET);
		printf("\t %d)  Save State\n", TEST_SAVE);
		printf("\t %d)  Read File\n", TEST_F_READ);
		printf("\t %d)  Read Pipe\n", TEST_PIPE);
		printf("\t %d)  Read Socket\n", TEST_SOCKET);
		printf("\t %d)  QUIT TESTING\n", TEST_EXIT);
		printf("Please enter the number or the test: ");
		result = scanf("%d", &select);
		
		if((result > 0 || result != EOF) && 
				select >= TEST_MIN_VALUE && 
				select <= TEST_MAX_VALUE ){
			count_break = 0;
			if (select == TEST_SET) {
				State_Set();
			} else if (select == TEST_SAVE) {
				State_Save();
			} else if (select == TEST_F_READ) {
				State_Read();
			} else if (select == TEST_PIPE) {
				State_Pipe();
			} else if (select == TEST_SOCKET) {
				State_Socket();
			} else if (select == TEST_EXIT) {
				break;
			}
			system("clear");
		} else {
			printf("You have given a invalid input\n");
			if(++count_break == 3) 
				break;
			if(count_break == 2){
				printf("Another consecutive invalid input ");
				printf("will result in terminating testing\n");
			}
		}
		if(i++>=25) break;
	}
	return 0;
}

int State_Pipe(){
	printf("In STATE_PIPE\n");
	int pipe; 
	char line[MAX_LINE];
	printf("\tEnsuring the Pipe exists\n");
	if(access("./testPipe",F_OK)!=0)
		mkfifo("testPipe", S_IRWXU);
	
	printf("\tNow exicute the PipeSend file\n");
	printf("\tTo exit the test type: quit\n");
	printf("\tOpening the pipe\n");
	pipe = open("./testPipe", O_RDONLY, O_NONBLOCK);
	
	printf("Msg #\tChar #\tMessage\n");
	int i = 1, r = 0;
	while(1){
		// memset(line,0,r));
		r = read(pipe, line, MAX_LINE);

		if(r != 0) printf("%d)\t%d,\t%s",i,r,line);

		if(strncmp(line,"quit",4) == 0) break;

		memset(line,0,r);

		sleep(1);
		i++;
	}

	close(pipe);
	printf("\tSUCCESSFUL\n");
	sleep(3);
	return 1;
}
int State_Read(){
	printf("In STATE_F_READ\n");
	FILE *fp; 
	char *line;
	size_t line_size = 0;
	ssize_t read_value = 0;
	int i = 0;
	printf("\tEnsuring the File exists\n");
	if(access("./testRead.txt",F_OK)!=0){
		printf("\tERROR: FILE DOES NOT EXIST!\n");
		printf("\tPlease create text file, testRead.txt.\n");
		printf("\tFile should be in current directory.\n");
		sleep(3);
		return -1;
	}
	printf("\tFile opening file.\n");
	fp = fopen("./testRead.txt","r");
	if(fp == NULL){
		printf("\tERROR: ON OPENING FILE!\n");
		printf("\tPlease check text file, testRead.txt.\n");
		sleep(3);
		return -1;
	}
	printf("\tLine#\tChar#\tMessage\n");
	while((read_value = getline(&line,&line_size,fp)) != -1){
		printf("\t%d\t%d\t%s",i,line_size,line);
		i++;
	}
	
	printf("\n\tClosing File\n");
	if(line) free(line);
	fclose(fp);
	printf("\tSUCCESSFUL\n");
	sleep(3);
	return 1;	
}
int State_Set(){
	int i = 0;
	printf("In STATE_SET\n");
	printf("\tMUST HAVE ROOT PERMISSONS\n");
	printf("\tExporting and Setting output of pins\n");
	for(i=0; i<GPIO_PIN_COUNT;i++){
		gpio_export(GPIO_D1[i]);
		gpio_export(GPIO_D2[i]);
        	gpio_set_dir(GPIO_D1[i], OUTPUT_PIN);
		gpio_set_dir(GPIO_D2[i], OUTPUT_PIN);
	}
	printf("\tDEVICE ONE\n");
	printf("\t\tMode => Manual\n");
	sleep(2);
	printf("\t\tMode => No Movement\n");
        gpio_set_value(GPIO_D1[0], HIGH);
        gpio_set_value(GPIO_D1[2], HIGH);
        gpio_set_value(GPIO_D1[4], HIGH);
	sleep(2);
	printf("\t\tMode => Forward\n");
        gpio_set_value(GPIO_D1[1], HIGH);
        gpio_set_value(GPIO_D1[3], HIGH);
	sleep(2);
        gpio_set_value(GPIO_D1[1], LOW);
        gpio_set_value(GPIO_D1[3], LOW);
	printf("\t\tMode => Reverse\n");
        gpio_set_value(GPIO_D1[1], HIGH);
        gpio_set_value(GPIO_D1[5], HIGH);
	sleep(2);
        gpio_set_value(GPIO_D1[0], LOW);
        gpio_set_value(GPIO_D1[1], LOW);
        gpio_set_value(GPIO_D1[2], LOW);
        gpio_set_value(GPIO_D1[4], LOW);
        gpio_set_value(GPIO_D1[5], LOW);
	printf("\tDEVICE TWO\n");
	printf("\t\tMode => Manual\n");
	sleep(2);
	printf("\t\tMode => No Movement\n");
        gpio_set_value(GPIO_D2[0], HIGH);
        gpio_set_value(GPIO_D2[2], HIGH);
        gpio_set_value(GPIO_D2[4], HIGH);
	sleep(2);
	printf("\t\tMode => Forward\n");
        gpio_set_value(GPIO_D2[1], HIGH);
        gpio_set_value(GPIO_D2[3], HIGH);
	sleep(2);
        gpio_set_value(GPIO_D2[1], LOW);
        gpio_set_value(GPIO_D2[3], LOW);
	printf("\t\tMode => Reverse\n");
        gpio_set_value(GPIO_D2[1], HIGH);
        gpio_set_value(GPIO_D2[5], HIGH);
	sleep(2);
        gpio_set_value(GPIO_D2[0], LOW);
        gpio_set_value(GPIO_D2[1], LOW);
        gpio_set_value(GPIO_D2[2], LOW);
        gpio_set_value(GPIO_D2[4], LOW);
        gpio_set_value(GPIO_D2[5], LOW);
	printf("\tUnexporting the Pins\n");
	for(i=0; i<GPIO_PIN_COUNT;i++){
		gpio_unexport(GPIO_D1[i]);
		gpio_unexport(GPIO_D2[i]);
	}
	printf("\tSUCCESSFUL\n");
	sleep(3);
	return 1;
}
int State_Save(){
	printf("In STATE_SAVE\n");
	printf("\tCreating a file in current directory\n");
	printf("\tFile name will be: HelloWorld.txt\n");
	FILE *fp;
	fp = fopen("HelloWorld.txt","w");
	fprintf(fp,"Hello World");
	fclose(fp);
	printf("\tSUCCESSFUL\n");
	sleep(3);
	return 1;
}
int State_Socket(){
	printf("IN STATE_SOCKET\n");
	int sockfd,n;
	struct sockaddr_in servaddr,cliaddr;
	socklen_t len;
	char mesg[MAX_LINE];
	printf("\tCreating socket\n");
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	printf("\tSetting up the handler\n");
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	servaddr.sin_port=htons(PORT);
	bind(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
	printf("\tReading from socket\n");
	while(true){
		len = sizeof(cliaddr);
		n = recvfrom(sockfd,mesg,MAX_LINE,0,(struct sockaddr *)&cliaddr,&len);
		//sendto(sockfd,mesg,n,0,(struct sockaddr *)&cliaddr,sizeof(cliaddr));
		mesg[n] = 0;
		printf("Received the following:\n");
		printf("%s\n",mesg);
		if(strncmp(mesg,"quit",4) == 0) break;
	}
	printf("\tSUCCESSFUL\n");
	sleep(3);
	return 1;
}
