#include <stdio.h>

#define MAX_PARTITIONS 4

void worstFit(int processSize[], int m, int block[], int n) {
    int allocation[MAX_PARTITIONS] = {-1};
  
    for (int i = 0; i < m; i++) {
        int worstIdx = -1;
        for (int j = 0; j < n; j++) {
            if (block[j] >= processSize[i]) {
                if (worstIdx == -1 || block[j] > block[worstIdx])
                    worstIdx = j;
            }
        }
  
        if (worstIdx != -1) {
            allocation[i] = worstIdx;
  
            block[worstIdx] -= processSize[i];
        }
    }
  
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < m; i++) {
        printf("%d\t\t%d\t\t", i+1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i]+1);
        else
            printf("Not Allocated\n");
    }
}

int main() {
    int processSize[] = {100, 50, 30, 120, 35};
    int block[] = {40, 10, 30, 60};
  
    int m = sizeof(processSize) / sizeof(processSize[0]);
    int n = sizeof(block) / sizeof(block[0]);
  
    printf("Worst Fit Memory Allocation:\n");
    worstFit(processSize, m, block, n);
  
    return 0;
}
