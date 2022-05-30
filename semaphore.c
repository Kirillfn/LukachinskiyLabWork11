#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <stdio.h>

#define SEMAPHORE_NAME "/Lukachinskij"

int main(int argc, char ** argv) {
	sem_t *sem;
	if (argc != 2) 
	{
		if ((sem = sem_open(SEMAPHORE_NAME, O_CREAT, 0770, 0)) == SEM_FAILED)
		{
			fprintf(stderr, "Lukachinskij semaphore_open error");
			return 1;
		}
		printf("Lukachinskij sem_open. Lukachinskij semaphore is taken.\nwaiting for it to be dropped.\n");
		if (sem_wait(sem) < 0)
			fprintf(stderr, "Lukachinskij sem_wait error");
		if (sem_close(sem) < 0)
			fprintf(stderr , "Lukachinskij sem_close error ");
		return 0;
	}
	else
	{
		printf("Dropping Lukachinskij semaphore...\n");
		if ((sem = sem_open (SEMAPHORE_NAME, 0)) == SEM_FAILED)
		{
			fprintf(stderr, "Lukachinskij sem_open error");
			return 1;
		}
		sem_post(sem);
		printf("Lukachinskij sem_post. Lukachinskij semaphore dropped. \n");
		return 0;
	}
}
