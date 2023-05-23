#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define N 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2
#define LEFT (philosopher + 4) % N
#define RIGHT (philosopher + 1) % N

int state[N];
pthread_mutex_t mutex;
pthread_cond_t condition[N];

void test(int philosopher) {
    if (state[philosopher] == HUNGRY &&
        state[LEFT] != EATING &&
        state[RIGHT] != EATING) {
        state[philosopher] = EATING;
        sleep(2); // Simulating eating
        printf("Philosopher %d is eating\n", philosopher);
        pthread_cond_signal(&condition[philosopher]);
    }
}

void take_forks(int philosopher) {
    pthread_mutex_lock(&mutex);
    state[philosopher] = HUNGRY;
    printf("Philosopher %d is hungry\n", philosopher);
    test(philosopher);
    while (state[philosopher] != EATING)
        pthread_cond_wait(&condition[philosopher], &mutex);
    pthread_mutex_unlock(&mutex);
}

void put_forks(int philosopher) {
    pthread_mutex_lock(&mutex);
    state[philosopher] = THINKING;
    printf("Philosopher %d is thinking\n", philosopher);
    test(LEFT);
    test(RIGHT);
    pthread_mutex_unlock(&mutex);
}

void* philosopher_thread(void* arg) {
    int philosopher = *(int*)arg;
    sleep(1); // Delay to stagger the starting time of philosophers

    while (1) {
        take_forks(philosopher);
        sleep(1); // Simulating eating
        put_forks(philosopher);
        sleep(1); // Simulating thinking
    }
}

int main() {
    pthread_t philosophers[N];
    int philosopher_ids[N];

    pthread_mutex_init(&mutex, NULL);
    for (int i = 0; i < N; i++)
        pthread_cond_init(&condition[i], NULL);

    for (int i = 0; i < N; i++) {
        philosopher_ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher_thread, &philosopher_ids[i]);
    }

    for (int i = 0; i < N; i++)
        pthread_join(philosophers[i], NULL);

    pthread_mutex_destroy(&mutex);
    for (int i = 0; i < N; i++)
        pthread_cond_destroy(&condition[i]);

    return 0;
}
