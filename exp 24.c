#include <stdio.h>

#define BLOCK_SIZE 8192  // Size of each disk block in bytes

int main() {
    int direct_blocks = 12;
    int single_indirect_blocks = BLOCK_SIZE / sizeof(int);
    int double_indirect_blocks = (BLOCK_SIZE / sizeof(int)) * single_indirect_blocks;
    int triple_indirect_blocks = (BLOCK_SIZE / sizeof(int)) * double_indirect_blocks;

    // Calculate the maximum file size
    long long max_size = direct_blocks * BLOCK_SIZE + single_indirect_blocks * BLOCK_SIZE +
                         double_indirect_blocks * BLOCK_SIZE + triple_indirect_blocks * BLOCK_SIZE;

    printf("Maximum file size that can be stored: %lld bytes\n", max_size);

    return 0;
}
