#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>

#define PHSEM "/ph_semm"

typedef struct s_sem
{
	sem_t *semaphore;
	int	thread_id;
}	t_sem;

void* thread_function(void* arg) {
	t_sem semid = *(t_sem *)arg;
    int thread_id = semid.thread_id;

    sem_wait(semid.semaphore);

     printf("Thread %d: Accessing shared resource\n", thread_id);

    sem_post(semid.semaphore);

    return NULL;
}

int main(void)
{
    pthread_t thread;
	t_sem	semid;
    int thread_id = 1;
	int i = 0;

	while (i < 3)
	{
    	semid.semaphore = sem_open(PHSEM, O_CREAT, 0600, 1);
    	if (semid.semaphore == SEM_FAILED) {
        	perror("sem_open");
        	return 1;
    	}
		semid.thread_id = thread_id;

    	pthread_create(&thread, NULL, thread_function, &semid);

    	pthread_join(thread, NULL);

    	sem_close(semid.semaphore);
		i++;
		thread_id++;
	}

	pid_t test = fork();
	
	if (!test)
	{
		semid.semaphore = sem_open(PHSEM, O_CREAT, 0600, 1);
		thread_id++;
		printf("child : %d\n", thread_id);
		return 0;
	}
	else
	{
		semid.semaphore = sem_open(PHSEM, O_CREAT, 0600, 1);
		usleep(1000000);
		printf("parents : %d\n", thread_id);
		//printf("%d\n", sem_close(semid.semaphore));
	}
    printf("%d\n", sem_unlink(PHSEM));

    return 0;
}

