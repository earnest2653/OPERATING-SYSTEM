#include <stdio.h>

#define MAX_FRAMES 3
#define MAX_PAGES 20

int isPagePresent(int pages[], int n, int page) {
    for (int i = 0; i < n; i++) {
        if (pages[i] == page) {
            return 1;
        }
    }
    return 0;
}

int findOptimalPage(int pages[], int frames[], int n, int current, int start) {
    int index = -1;
    int farthest = start;
    for (int i = 0; i < MAX_FRAMES; i++) {
        int j;
        for (j = current + 1; j < n; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    index = i;
                }
                break;
            }
        }
        if (j == n) {
            return i;
        }
    }
    return (index == -1) ? 0 : index;
}

void optimalPageReplacement(int pages[], int n) {
    int frames[MAX_FRAMES] = {0};
    int faults = 0;

    printf("Optimal Page Replacement\n\n");
    printf("Page Fault Sequence: ");

    for (int i = 0; i < n; i++) {
        if (!isPagePresent(frames, MAX_FRAMES, pages[i])) {
            int pageToReplace = findOptimalPage(pages, frames, n, i, i);
            frames[pageToReplace] = pages[i];
            faults++;
            printf("%d ", pages[i]);
        }
    }

    printf("\n\nNumber of Page Faults: %d\n", faults);
}

int main() {
    int pages[] = {1, 2, 3, 4, 2, 1, 5, 6, 2, 1, 2, 3, 7, 6, 3, 2, 1, 2, 3, 6};
    int n = sizeof(pages) / sizeof(pages[0]);

    optimalPageReplacement(pages, n);

    return 0;
}
