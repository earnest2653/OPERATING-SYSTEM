#include <stdio.h>

#define MAX_PARTITIONS 5
#define MAX_PROCESSES 5

int main() {
    int partitions[MAX_PARTITIONS] = {40, 10, 30, 60};
    int processes[MAX_PROCESSES] = {100, 50, 30, 120, 35};
    int allocation[MAX_PROCESSES] = {-1};

    int i, j;

    for (i = 0; i < MAX_PROCESSES; i++) {
        for (j = 0; j < MAX_PARTITIONS; j++) {
            if (partitions[j] >= processes[i]) {
                allocation[i] = j;
                partitions[j] -= processes[i];
                break;
            }
        }
    }

    printf("Process\tSize\tPartition\n");
    for (i = 0; i < MAX_PROCESSES; i++) {
        printf("%d\t%d KB\t", i + 1, processes[i]);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i] + 1);
        } else {
            printf("Not Allocated\n");
        }
    }

    return 0;
}
