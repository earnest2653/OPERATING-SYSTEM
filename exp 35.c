#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define DISK_SIZE 16
#define INODE_BLOCKS 8
#define AVAILABLE_BLOCKS (DISK_SIZE - INODE_BLOCKS)
#define BLOCK_SIZE 1024

bool isBlockFree(int block, bool allocatedBlocks[]) {
    if (block < INODE_BLOCKS || block >= DISK_SIZE) {
        return false;
    }

    return !allocatedBlocks[block];
}

bool allocateBlocks(int startBlock, int numBlocks, bool allocatedBlocks[]) {
    for (int i = startBlock; i < startBlock + numBlocks; i++) {
        if (!isBlockFree(i, allocatedBlocks)) {
            return false;
        }
    }

    for (int i = startBlock; i < startBlock + numBlocks; i++) {
        allocatedBlocks[i] = true;
    }

    return true;
}

void printAllocatedBlocks(bool allocatedBlocks[]) {
    printf("Allocated Blocks:\n");
    for (int i = 0; i < DISK_SIZE; i++) {
        printf("%d: %s\n", i, allocatedBlocks[i] ? "Allocated" : "Free");
    }
}

int main() {
    bool allocatedBlocks[DISK_SIZE] = {false};

    int fileSize[] = {1, 2, 3, 4, 8, 9};

    int numFiles = sizeof(fileSize) / sizeof(fileSize[0]);

    for (int i = 0; i < numFiles; i++) {
        int startBlock = -1;
        int requiredBlocks = fileSize[i] / BLOCK_SIZE;
        
        if (fileSize[i] % BLOCK_SIZE != 0) {
            requiredBlocks++;
        }

        if (requiredBlocks > AVAILABLE_BLOCKS) {
            printf("Not enough contiguous blocks available for file %d. Exiting...\n", i + 1);
            exit(0);
        }

        for (int j = INODE_BLOCKS; j <= DISK_SIZE - requiredBlocks; j++) {
            if (allocateBlocks(j, requiredBlocks, allocatedBlocks)) {
                startBlock = j;
                break;
            }
        }

        if (startBlock == -1) {
            printf("Not enough contiguous blocks available for file %d. Exiting...\n", i + 1);
            exit(0);
        }

        printf("Allocated %d blocks for file %d starting from block %d\n", requiredBlocks, i + 1, startBlock);
    }

    printAllocatedBlocks(allocatedBlocks);

    return 0;
}
