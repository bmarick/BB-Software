/* File: socket.h
 * Reason: Header socket functionality
 * Created by: Brandon Marick 03/05/14
 */

#ifndef SOCKET_HEADER

#define SOCKET_HEADER

#include <errno.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

int socketClose(int *sockId);
int socketOpen(int *sockId, struct sockaddr_in *servaddr, int port);
int socketRead(int *sockId, char *msg, int *length);
int socketSend(int *sockId, struct sockaddr_in *servaddr, char *msg, int *length);

#endif /* SOCKET_HEADER */
