
/* Sample UDP client */

#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>

int main(int argc, char**argv)
{
   int sockfd;
   struct sockaddr_in servaddr;
   char sendline[80];

   if (argc != 2)
   {
      printf("usage:  udpcli <IP address>\n");
      exit(1);
   }
   
   printf("Set up Socket\n");
   sockfd=socket(AF_INET,SOCK_DGRAM,0);
   bzero(&servaddr,sizeof(servaddr));
   servaddr.sin_family = AF_INET;
   servaddr.sin_addr.s_addr=inet_addr(argv[1]);
   servaddr.sin_port=htons(32000);

   printf("Type 'quit' to exit program. (with out 's)\n");
   printf("Type messages you would like to send.\n\n");

   while (fgets(sendline, 80,stdin) != NULL)
   {
      sendto(sockfd,sendline,strlen(sendline),0,
             (struct sockaddr *)&servaddr,sizeof(servaddr));
      if(strncmp(sendline,"quit",4) == 0) break;
   }
}
