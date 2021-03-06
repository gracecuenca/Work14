#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>
#define KEY 14

int main(int argc, char * argv[]){
  int sd;
  int val;

  if(!strcmp(argv[1], "-c")){
    if(argv[2]){
      sd = semget(KEY, 1, IPC_CREAT | 0666 | IPC_EXCL);
      if(sd == -1){
        printf("semaphore exists already\n");
      }
      else{
        semctl(sd, 0, SETVAL, atoi(argv[2]));
        printf("semaphore created: %d\n", sd);
        printf("value: %d\n", atoi(argv[2]));
      }
    }
  }

  if(!strcmp(argv[1], "-v")){
    sd = semget(KEY, 1, 0664);
    printf("semaphore retrieved: %d\n", sd);
    val = semctl(sd, 0, GETVAL);
    printf("semaphore value: %d\n", val);
  }

  if(!strcmp(argv[1], "-r")){
    sd = semget(KEY, 1, 0664);
    val = semctl(sd, 0, IPC_RMID);
    printf("semaphore released: %d\n", val);
  }

}
