//this program creates a udp client:
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
        struct sockaddr_in servaddr;
        char cmsg[MAX] = "Hello this is a UDP client";
        char smsg[MAX];
        int sockfd,mlen,slen,clen;
        slen = sizeof(servaddr); //length of the address
        memset(&servaddr,0,slen);
        memset(smsg,0,MAX);

        servaddr.sin_family = AF_INET; //To use internet family of Addressing
        servaddr.sin_addr.s_addr = inet_addr(IP);
        servaddr.sin_port = htons(PORTNO);

        sockfd = socket(AF_INET,SOCK_DGRAM,0); //socket created

        mlen = sendto(sockfd,cmsg,strlen(cmsg),MSG_CONFIRM,(struct sockaddr*)&servaddr,slen);
        cout<<"Request sent successfully"<<endl;
        mlen = recvfrom(sockfd,smsg,MAX,MSG_WAITALL,(struct sockaddr*)&servaddr,(socklen_t*)&slen);
        cout<<"Message received : "<< smsg <<endl;
        exit(0);}
