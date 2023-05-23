#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t semaphore;

void* process(void* process_id) {
    int id = *(int*)process_id;

    printf("Process P%d is waiting\n", id);
    sem_wait(&semaphore);
    printf("Process P%d has acquired the resource\n", id);

    // Simulating some work
    sleep(2);

    printf("Process P%d has released the resource\n", id);
    sem_post(&semaphore);

    pthread_exit(NULL);
}

int main() {
    sem_init(&semaphore, 0, 4);

    pthread_t threads[5];
    int process_ids[5] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, process, (void*)&process_ids[i]);
    }

    // Simulating the fifth process
    sleep(1);
    printf("Process P5 wants to acquire the resource\n");
    sem_wait(&semaphore);
    printf("Process P5 has acquired the resource\n");
    printf("Process P5 has released the resource\n");
    sem_post(&semaphore);

    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&semaphore);

    return 0;
}
