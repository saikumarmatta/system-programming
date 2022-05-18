//this program creates a udp server
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<iostream>
#include<unistd.h>
#include<string.h>
using namespace std;
#define MAX 256
#define IP "127.0.0.1"
#define PORTNO 8005
int main(int argc,char*argv[]){
        //socket creation
        struct sockaddr_in servaddr,cliaddr;
        char smsg[MAX] = "Hello this is a UDP server";
        char cmsg[MAX];
        int sockfd,mlen,slen,clen;
        slen = sizeof(servaddr); //length of the address
        memset(&servaddr,0,slen);
        memset(&cliaddr,0,slen);
        memset(cmsg,0,MAX);

        servaddr.sin_family = AF_INET; //To use internet family of Addressing
        servaddr.sin_addr.s_addr = inet_addr(IP);
        servaddr.sin_port = htons(PORTNO);

        sockfd = socket(AF_INET,SOCK_DGRAM,0); //socket created
        bind(sockfd,(struct sockaddr*)&servaddr,slen);
        listen(sockfd,5);

        mlen = recvfrom(sockfd,cmsg,MAX,MSG_WAITALL,(struct sockaddr*)&cliaddr,(socklen_t*)&clen);
        cout<<cmsg<<endl;
        mlen = sendto(sockfd,smsg,strlen(smsg),MSG_CONFIRM,(struct sockaddr*)&cliaddr,slen);
        cout<<"Message sent successfully"<<endl;
}
