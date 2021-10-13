#include  <stdio.h>
#include  <sys/types.h>
#include <stdlib.h>

#define   MAX_COUNT  2

//.h
void  ChildProcess(int);                /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */

//main
void  main(void)
{
  pid_t  pid;
  int i;
  
  for(i = 1; i <= MAX_COUNT; i++){
    pid = fork();
    if (pid == 0){
      ChildProcess(i);
    }
    else{
      ParentProcess();
    }
    /*else if(pid > 0)
      ParentProcess();
    else
      printf("Error in Fork\n");*/
  }
}

//.c
void  ChildProcess(int cid)
{
  int i;
  pid_t  pid;
  pid_t  ppid;
  
  if(cid == 0){
    printf("In Child %d/n", cid);
  }
  else if (cid == 1){
    printf("In Child %d/n", cid);
  }
  
  for (i = 1; i <= MAX_COUNT; i++){
    pid = getpid();
    printf("Child Pid: %d is going to sleep!\n", pid);
    sleep(rand() % 10);
    ppid = getppid();
    printf("Child Pid: is awake!\n Where is my parent: %d", ppid);
  }
  
  exit(0);
}

void  ParentProcess(void)
{
  int   i;
  int status;
  pid_t cpid;
  
  for (i = 1; i <= MAX_COUNT; i++){
    cpid = wait(&status);
    for (i = 1; i <= MAX_COUNT; i++){
      printf("This line is from parent, value = %d\n", i);
    }
  }
  
  printf("*** Parent is done ***\n");    
}