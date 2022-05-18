//Program to Demonstrate an IPC using pipe
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <wait.h>
#define MAX 256
using namespace std;
char msg1[] = "Hello World #1\n";
char msg2[] = "Hello World #2\n";
char msg3[]= "Hello World #3\n";
int prnerr(int ret,const char msg[]){
        if(ret < 0){
        perror(msg);
        exit(EXIT_FAILURE);
        }
        return 0;
}
int main(){
        char buff[MAX];
        int pipefd[2],i,ret,len,status;
        pid_t child_pid;
        ret = pipe(pipefd);
        len = strlen(msg1);

       prnerr(ret,"Error Creating Pipe");
       ret = write(pipefd[1],msg1,strlen(msg1));
       prnerr(ret,"Unable to write Message to Pipe");

        ret = write(pipefd[1],msg2,strlen(msg2));
        prnerr(ret,"Unable to write Message to Pipe");
        ret = write(pipefd[1],msg3,strlen(msg3));

        prnerr(ret,"Unable to write Message to Pipe");
        child_pid =fork();
        if(child_pid == 0){
        close(0);

        dup(pipefd[0]);
        close(pipefd[0]);
        close(pipefd[1]);
        execlp("tr","tr","a-z","A-Z",0);
        }
/*
         for(i = 0;i < 3;i++){
                 ret = read(pipefd[0],buff,len);
                 prnerr(ret,"Error Reading the Pipe");
                 cout<<buff <<endl;
         }*/
         close(pipefd[0]);
         close(pipefd[1]);
         wait(&status);
         cout <<"Child Process Completed Sucessfully" <<endl;
         return 0;
}

