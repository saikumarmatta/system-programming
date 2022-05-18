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
        char smsg[MAX] = "Hello From Server to Client";
        char cmsg[MAX];
        int sockfd,mlen,slen,connfd;
        socklen_t clen;

        slen = sizeof(sockaddr_in);
        memset(&servaddr,0,slen);
        memset(&cliaddr,0,slen);
        memset(cmsg,0,MAX);


        servaddr.sin_family = AF_INET; //To use Internet Family of Addressing
        servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
        servaddr.sin_port = htons(PORTNO);

        sockfd = socket(AF_INET,SOCK_STREAM,0);
        bind(sockfd,(const struct sockaddr *)&servaddr, slen);
        listen(sockfd,5);

        connfd=accept(sockfd,(struct sockaddr *) &cliaddr,&clen);


        mlen=recv(connfd,cmsg,MAX,0);
        cout << cmsg << endl;
        mlen=send(connfd,smsg,strlen(smsg),0);
        cout << mlen << " Bytes Message Sent from The Server" << endl;
        close(connfd);
}




