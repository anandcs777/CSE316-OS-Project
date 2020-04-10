
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main()
{
	int n=0;
	pid_t pid;
	
	A:
	 printf("\nEnter a positive integer\n"); 
  	scanf("%d", &n);	
	
if (n>=0)
{

	pid = fork();

	if (pid == 0)
	{
		
		printf("%d,",n);
	
		while (n!=1)
		{
			if (n%2 == 0)
			{
				n = n/2;
			}
			
			else if (n%2 == 1)
			{
			 n = 3 * (n) + 1;
			}	
			
			printf("%d,",n);
		}
		
			printf("Child process completed.\n");
	}
	
	else
	{
		printf("waiting child process to complete.\n");
		wait();
		
	}
}
else
{
    goto A;
}

return 0; 
}
