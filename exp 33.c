#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int isPrime(int number) {
    if (number <= 1)
        return 0;

    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0)
            return 0;
    }

    return 1;
}

void fibonacciSeries(int n) {
    int first = 0, second = 1, next;

    printf("Fibonacci Series: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", first);
        next = first + second;
        first = second;
        second = next;
    }

    printf("\n");
}

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        fibonacciSeries(10); // Generate Fibonacci series
    } else {
        // Parent process
        wait(NULL); // Wait for the child process to complete
        
        printf("Prime Numbers: ");
        for (int i = 2; i <= 20; i++) {
            if (isPrime(i))
                printf("%d ", i);
        }

        printf("\n");
    }

    return 0;
}
