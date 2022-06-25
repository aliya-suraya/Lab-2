#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void childTask()
{
	char name[25];
	printf("Enter your name: \n");
	fgets(name, 10, stdin);
	printf("Your Name is %s", name);
 }

void parentTask()
{
	printf("waiting for child process...\n");
	printf("Job is done\n");
}

int main (void) {
 
	for( int i=1; i<5; i++) 
   {
	pid_t pid = fork();
	if(pid==0)
	{
		childTask();
		exit(0);
	}

	else if(pid>0)
	{
		wait(NULL);
		parentTask();
	}

	else { printf("Unable to create child process"); }
   }
	return EXIT_SUCCESS;
}
