/* File: socket.h
 * Reason: Header socket functionality
 * Created by: Brandon Marick 03/05/14
 */

#include "socket.h"

/* FUNCTION ==>> socketClose( *int);
 * Return Values:
 * Success:	0
 * Error:	-1 => Check errno
 */
int socketClose(int *sockId){
	return close(*sockId);
}

/*  FUNCTION ==>> socketOpen( *int, int);
 *  Return Values: 
 *  Success: 	 0
 *  Error:	-1 => Unable to setup timeout
 *  Error: 	-2 => Unable to setup Socket, check errno
 *  Error:	-3 => Unable to bind Socket, check errno
 */
int socketOpen(int *sockId, struct sockaddr_in *servaddr, int port){
	struct timeval timeOut;
	int result;
	
	result = socket(AF_INET, SOCK_DGRAM,0);
	if(result == -1)	return -2;
	else			*sockId = result;

	bzero(servaddr,sizeof(*servaddr));
	(*servaddr).sin_family = AF_INET;
	(*servaddr).sin_addr.s_addr=htonl(INADDR_ANY);
	(*servaddr).sin_port=htons(port);
	
	result = bind(*sockId,(struct sockaddr *)servaddr,sizeof(*servaddr));
	if(result == -1){
		close(*sockId);
		return -3;
	}

	timeOut.tv_sec  = 1;
	timeOut.tv_usec = 0;

	if(setsockopt(*sockId,SOL_SOCKET,SO_RCVTIMEO,(char *)&timeOut,sizeof(timeOut)) < 0){
		close(*sockId);
		return -1;
	}

	return 0;
}

/* FUNCTION ==>> socketRead( *int, *char, *int)
 * Return Value:
 * Success:	Length of read
 * Error:	-1 => TIMEOUT
 * Error:	-2 => check errno
 */
int socketRead(int *sockId, char *msg, int *length){
	struct sockaddr_in cliaddr;
	socklen_t len;
	int n;

	len = sizeof(cliaddr);
	n = recvfrom(*sockId,msg,*length,0,(struct sockaddr *)&cliaddr,&len);
	if(n>=0) {
         	msg[n] = 0;
		return n;
	} else if (errno == EWOULDBLOCK  || errno == EAGAIN) {
		printf("\t\ttimeout\n");
		return -1;
	} else {
		printf("\t\tFAILURE\n");
		return -2;
	}
}

/* FUNCTION ==>> socketSend( *int, struct *sockaddr_in, *char, *int)
 * Return Value:
 * Success:	Length of write
 * Error:	-1 => check errno
 */
int socketSend(int *sockId, struct sockaddr_in *servaddr, char *msg, int *length){
	return sendto(*sockId,msg,*length,0,(struct sockaddr *)servaddr,sizeof(*servaddr));
}
