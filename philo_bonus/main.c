#include "../include/philosophers."
int main()
{
	int pid = fork();

	if (pid == 0)
	{
		
		sleep(3);

		exit(1);
	}
}
