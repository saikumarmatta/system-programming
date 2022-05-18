//Program to demonstrate a race condition
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>
using namespace std;
int balance = 0;
sem_t sem1;

void *computebal(void *arg){
        int b,c;
        cout<<"Balance cal start"<<endl;
        sem_wait(&sem1);
        b = balance;
        for(int i = 0;i<50000;i++){
                c = 5000*12334;
        }
        sleep(1);
        b += 10;
        balance = b;
        sem_post(&sem1);
        cout<<"Balance cal is Compltede " <<endl;
        return NULL;
}
int main(){
        int i;
        pthread_t thread_id[200];
        sem_init(&sem1,0,10);
        cout <<"Balance Before Thread: " <<balance<<endl;
        for(i=0;i<200;i++){
                pthread_create(&thread_id[i],NULL,computebal,NULL);
        }
        for(i=0;i<200;i++){
                pthread_join(thread_id[i],NULL);
        }
        sem_destroy(&sem1);
        cout <<"Balance After Thread: "<<balance <<endl;
        exit(EXIT_SUCCESS);
}
