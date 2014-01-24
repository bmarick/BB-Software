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

	// open pipe
	pipe = open("./testPipe", O_RDONLY, O_NONBLOCK);

	printf("Msg #\tChar #\tMessage\n");

	int i = 1, r = 0;
	while(1){
		// memset(line,0,r));
		r = read(pipe, line, MAX_LINE);

		if(r != 0) printf("%d)\t%d,\t%s",i,r,line);

		if(strncmp(line,"quite",5) == 0) break;

		memset(line,0,r);

		sleep(1);
		i++;
	}

	close(pipe);

	return 0;
}
