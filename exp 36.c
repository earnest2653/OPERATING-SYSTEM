#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int abs_diff(int a, int b) {
    return (a > b) ? (a - b) : (b - a);
}

int findShortestSeekTime(int tracks[], int n, int head) {
    int shortestSeekTime = INT_MAX;
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (tracks[i] != -1 && abs_diff(tracks[i], head) < shortestSeekTime) {
            shortestSeekTime = abs_diff(tracks[i], head);
            index = i;
        }
    }
    return index;
}

void sstf(int tracks[], int n, int head) {
    int totalHeadMovement = 0;
    printf("SSTF Disk Scheduling Algorithm\n\n");
    printf("Head Movement Sequence: ");

    for (int i = 0; i < n; i++) {
        int shortestSeekTimeIndex = findShortestSeekTime(tracks, n, head);
        if (shortestSeekTimeIndex == -1) {
            printf("\nError: Track not found!\n");
            return;
        }
        int shortestSeekTimeTrack = tracks[shortestSeekTimeIndex];
        totalHeadMovement += abs_diff(head, shortestSeekTimeTrack);
        head = shortestSeekTimeTrack;
        printf("%d ", head);
        tracks[shortestSeekTimeIndex] = -1;
    }

    printf("\n\nTotal Head Movement: %d\n", totalHeadMovement);
    double averageHeadMovement = (double)totalHeadMovement / n;
    printf("Average Head Movement: %.2lf\n", averageHeadMovement);
}

int main() {
    int tracks[] = {55, 58, 60, 70, 18};
    int n = sizeof(tracks) / sizeof(tracks[0]);
    int head = 50; // Starting head position

    sstf(tracks, n, head);

    return 0;
}
