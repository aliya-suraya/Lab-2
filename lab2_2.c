#include <stdlib.h> // to define exit
#include <unistd.h> // for fork() and getpaid()
#include <stdio.h>  // for print()
#include <sys/wait.h>
int main (int argc, char **argv)
{
	int pid; //process id

	switch (pid=fork()) 
{
	case 0: //fork retuns 0 to the child
		printf("I am the child process: pid=%d\n", getpid());
		break;

	default: /* fork return pid to the parent*/
		wait(NULL);
		printf("I am the parent process: pid=%d, child pid%d\n", getpid(), pid);
		break;

	case -1: //somethign went wrong
		perror("fork");
		exit(1);
	}
	exit(0);
}
