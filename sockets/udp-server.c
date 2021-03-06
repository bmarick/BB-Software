
/* Sample UDP server */

#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char**argv){
	int sockfd,n,port =32000,i;
	long double d0 = 0, d1 =0, d2 =0, d3 =0;
	struct sockaddr_in servaddr,cliaddr;
	struct timeval timeout;
	socklen_t len;
	char mesg[1000];

	printf("\t\tSOCKET READ FROM PORT %d\n",port);

	timeout.tv_sec=10;
	timeout.tv_usec=0;

	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	servaddr.sin_port=htons(port);
	bind(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));

	if(setsockopt(sockfd,SOL_SOCKET,SO_RCVTIMEO,(char *)&timeout,sizeof(timeout)) < 0){
      		close(sockfd);
		printf("\t\tSET SOCKET TIME OUT FAIL\n");
		return -1;
	}

	printf("\tSocket Set up, Begining reads: \n");
	

	for (;;){
		len = sizeof(cliaddr);
		n = recvfrom(sockfd,mesg,1000,0,(struct sockaddr *)&cliaddr,&len);
		if(n>=0){
         		mesg[n] = 0;
			i = sscanf(mesg," %lf %lf %lf %lf ",&d0,&d1,&d2,&d3);
			printf("Received %d characters, transfered %d to doubles\n",n,i);
			printf(" %s",mesg);
			printf(mesg," %lf %lf %lf %lf \n",d0,d1,d2,d3);
		} else if (errno == EWOULDBLOCK  || errno == EAGAIN) {
			printf("\t\ttimeout\n");
		} else {
			close(sockfd);
			printf("\t\tFAILURE\n");
			break;
		}
	}
}
