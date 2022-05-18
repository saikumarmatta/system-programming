//The program to create a TCP server
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
        struct sockaddr_in servaddr,cliaddr;
        char smsg[MAX];
        char cmsg[MAX];
        int sockfd,mlen,slen,connfd;
        socklen_t clen;

        slen = sizeof(sockaddr_in);
        memset(&servaddr,0,slen);
        memset(&cliaddr,0,slen);
        memset(cmsg,0,MAX);


        servaddr.sin_family = AF_INET; //To use Internet Family of Addressing
        servaddr.sin_addr.s_addr = INADDR_ANY;
        servaddr.sin_port = htons(PORTNO);

        sockfd = socket(AF_INET,SOCK_STREAM,0);
        bind(sockfd,(const struct sockaddr *)&servaddr, slen);
        listen(sockfd,5);

        connfd=accept(sockfd,(struct sockaddr *) &cliaddr,&clen);


        mlen=read(connfd,cmsg,MAX);
        write(1,"Message from Client: ",21);
        write(1,cmsg,strlen(cmsg));
        write(1,"Enter your msg for Client1: ",32);
        mlen = read(0,smsg,MAX);
        mlen=write(connfd,smsg,strlen(smsg));
        cout << mlen << " Bytes Message Sent from The Server" << endl;
        close(connfd);
}

