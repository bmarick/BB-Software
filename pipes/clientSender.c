#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_LINE 80

int main(int argc, char **argv){
	char line[MAX_LINE];
	int pipe;

	printf("\tEnsuring the Pipe exists\n");
	if(access("./testPipe",F_OK)!=0)
		mkfifo("testPipe", S_IRWXU);
	
	printf("\tOpening the pipe\n");
	pipe = open("./testPipe", O_WRONLY, O_NONBLOCK);

	int r = 0;

	while(1){
		printf("Enter line: ");
		fgets(line, MAX_LINE, stdin);

		// send line to the pipe
		r = write(pipe, line, strlen(line));

		if(strncmp(line,"quit",4) == 0) break;

		memset(line,0,r);
	}

	close(pipe);

	return 0;
}
