#include <stdio.h>

// Contiguous Allocation
int contiguousAllocation(int blockNumber) {
    return (2 * blockNumber);
}

// Linked Allocation
int linkedAllocation(int blockNumber) {
    return (blockNumber + 2);
}

// Indexed Allocation
int indexedAllocation(int blockNumber) {
    if (blockNumber == 0 || blockNumber == 99)
        return 2;
    else
        return 102;
}

int main() {
    int blockNumber;
    printf("Enter the block number (0-99): ");
    scanf("%d", &blockNumber);

    printf("\nContiguous Allocation:\n");
    printf("Adding block at the beginning: %d disk I/O operations\n", contiguousAllocation(blockNumber));
    printf("Adding block in the middle: %d disk I/O operations\n", contiguousAllocation(50) + 50);
    printf("Adding block at the end: 1 disk I/O operation\n");

    printf("\nLinked Allocation:\n");
    printf("Adding block at the beginning: 2 disk I/O operations\n");
    printf("Adding block in the middle: 3 disk I/O operations\n");
    printf("Adding block at the end: 2 disk I/O operations\n");

    printf("\nIndexed Allocation:\n");
    printf("Adding block at the beginning: 2 disk I/O operations\n");
    printf("Adding block in the middle: 102 disk I/O operations\n");
    printf("Adding block at the end: 2 disk I/O operations\n");

    return 0;
}
