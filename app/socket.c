/* File: socket.h
 * Reason: Header socket functionality
 * Created by: Brandon Marick 03/05/14
 */

#include "socket.h"

/* FUNCTION ==>> socketClose( *Test_Data);
 * Return Values:
 * Success:	0
 * Error:	-1 => Check errno
 */
int socketClose(Test_Data *test_data){
	return close((*test_data).socketId);
}

/*  FUNCTION ==>> socketOpen( *Test_Data);
 *  Return Values: 
 *  Success: 	 0
 *  Error:	-1 => Unable to setup timeout
 *  Error: 	-2 => Unable to setup Socket, check errno
 *  Error:	-3 => Unable to bind Socket, check errno
 */
int socketOpen(Test_Data *test_data){
	struct timeval timeOut;
	int result, port , *sockId = &(*test_data).socketId;
	struct sockaddr_in *servaddr = &(*test_data).servaddr;
	
	port = (int) (*test_data).station;
	
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

/* FUNCTION ==>> socketRead( *Test_Data, *char)
 * Return Value:
 * Success:	Length of read
 * Error:	-1 => TIMEOUT
 * Error:	-2 => check errno
 */
int socketRead(Test_Data *test_data, char *msg){
	struct sockaddr_in cliaddr;
	socklen_t len;
	int n, *sockId = &(*test_data).socketId;

	len = sizeof(cliaddr);
	n = recvfrom(*sockId,msg,MAX_LINE,0,(struct sockaddr *)&cliaddr,&len);
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

/* FUNCTION ==>> socketSend( *Test_Data, *char, *int)
 * Return Value:
 * Success:	Length of write
 * Error:	-1 => check errno
 */
//int socketSend(int *sockId, struct sockaddr_in *servaddr, char *msg, int *length){
int socketSend(Test_Data *test_data, char *msg, int *length){
	int *sockId = &(*test_data).socketId;
	struct sockaddr_in *servaddr = &(*test_data).servaddr;
	return sendto(*sockId,msg,*length,0,(struct sockaddr *)servaddr,sizeof(*servaddr));
}
