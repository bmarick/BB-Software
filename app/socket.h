/* File: socket.h
 * Reason: Header socket functionality
 * Created by: Brandon Marick 03/05/14
 */

#ifndef SOCKET_HEADER

#define SOCKET_HEADER
#include "testData.h"

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

int socketClose(Test_Data *test_data);
int socketOpen(Test_Data *test_data);
int socketRead(Test_Data *test_data, char *msg);
int socketSend(Test_Data *test_data, char *msg, int *length);

#endif /* SOCKET_HEADER */
