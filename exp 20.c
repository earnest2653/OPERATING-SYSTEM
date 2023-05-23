#include <stdio.h>

#define MAX_PARTITIONS 6
#define MAX_PROCESSES 5

void worstFit(int partitions[], int n, int processes[], int m) {
    int allocation[MAX_PROCESSES];
    int i, j;

    for (i = 0; i < m; i++) {
        allocation[i] = -1; // Initialize allocation array

        int worstFitIndex = -1;
        for (j = 0; j < n; j++) {
            if (partitions[j] >= processes[i]) {
                if (worstFitIndex == -1 || partitions[j] > partitions[worstFitIndex]) {
                    worstFitIndex = j;
                }
            }
        }

        if (worstFitIndex != -1) {
            allocation[i] = worstFitIndex;
            partitions[worstFitIndex] -= processes[i];
        }
    }

    printf("Process No.\tProcess Size\tPartition No.\n");
    for (i = 0; i < m; i++) {
        printf("%d\t\t%d KB\t\t", i + 1, processes[i]);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i] + 1);
        } else {
            printf("Not Allocated\n");
        }
    }
}

int main() {
    int partitions[MAX_PARTITIONS] = {300, 600, 350, 200, 750, 125};
    int processes[MAX_PROCESSES] = {115, 500, 358, 200, 375};

    worstFit(partitions, MAX_PARTITIONS, processes, MAX_PROCESSES);

    return 0;
}
