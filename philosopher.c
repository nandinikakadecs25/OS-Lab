#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5

pthread_t philosopher[N];
sem_t chopstick[N];

void *dining(void *num)
{
    int phil = *(int *)num;

    while (1)
    {
        printf("Philosopher %d is Thinking\n", phil);
        sleep(1);

        sem_wait(&chopstick[phil]);
        printf("Philosopher %d picked up left chopstick %d\n", phil, phil);

        sem_wait(&chopstick[(phil + 1) % N]);
        printf("Philosopher %d picked up right chopstick %d\n",
               phil, (phil + 1) % N);

        // Eating
        printf("Philosopher %d is Eating\n", phil);
        sleep(2);

        sem_post(&chopstick[phil]);

        sem_post(&chopstick[(phil + 1) % N]);

        printf("Philosopher %d finished Eating and released chopsticks\n", phil);
    }
}

int main()
{
    int i;
    int phil_num[N];
    for (i = 0; i < N; i++)
    {
        sem_init(&chopstick[i], 0, 1);
    }

    for (i = 0; i < N; i++)
    {
        phil_num[i] = i;
        pthread_create(&philosopher[i], NULL, dining, &phil_num[i]);
    }

    for (i = 0; i < N; i++)
    {
        pthread_join(philosopher[i], NULL);
    }

    for (i = 0; i < N; i++)
    {
        sem_destroy(&chopstick[i]);
    }

    return 0;
}
