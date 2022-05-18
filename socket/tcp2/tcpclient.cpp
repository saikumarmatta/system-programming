//The program to create a TCP Client
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#define ADDRSERV "127.0.0.1"
#define PORTNO 8005
#define MAX 256
using namespace std;

int main()
{
        struct sockaddr_in servaddr;
        char cmsg[MAX];
        char smsg[MAX];
        int sockfd,mlen,structlen;
        socklen_t servaddrlen;

        structlen = sizeof(sockaddr_in);
        memset(&servaddr,0,structlen);
//      memset(&cliaddr,0,slen);
        memset(smsg,0,MAX);


        servaddr.sin_family = AF_INET; //To use Internet Family of Addressing
        servaddr.sin_addr.s_addr = INADDR_ANY;
        servaddr.sin_port = htons(PORTNO);

        sockfd = socket(AF_INET,SOCK_STREAM,0);
//      bind(sockfd,(const struct sockaddr *)&servaddr, slen);
//      listen(sockfd,5);

        connect(sockfd,(struct sockaddr *) &servaddr,structlen);
        write(1,"Enter Your Message for Server: ",31);
        mlen=read(0,cmsg,MAX);
        mlen=write(sockfd,cmsg,strlen(cmsg));
        write(1,"Message Sent From Client1: ",31);
        write(1,cmsg,strlen(cmsg));
        mlen=read(sockfd,smsg,MAX);
        write(1,smsg,strlen(smsg));
        close(sockfd);
}

