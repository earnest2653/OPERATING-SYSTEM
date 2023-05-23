#include <stdio.h>
#include <pthread.h>

void *print_even(void *arg) {
    int limit = *(int *)arg;

    printf("Even numbers:\n");
    for (int i = 2; i <= limit; i += 2) {
        printf("%d ", i);
    }
    printf("\n");

    pthread_exit(NULL);
}

void *print_odd(void *arg) {
    int limit = *(int *)arg;

    printf("Odd numbers:\n");
    for (int i = 1; i <= limit; i += 2) {
        printf("%d ", i);
    }
    printf("\n");

    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;
    int limit = 20;

    pthread_create(&thread1, NULL, print_even, (void *)&limit);
    pthread_create(&thread2, NULL, print_odd, (void *)&limit);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
