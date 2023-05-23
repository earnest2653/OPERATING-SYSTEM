#include <stdio.h>
#include <stdlib.h>

int main() {
    int tracks[] = {55, 58, 60, 70, 18, 90, 150, 160, 184};
    int numTracks = sizeof(tracks) / sizeof(tracks[0]);
    int currentPosition = 50;  // Initial position of the disk head
    int totalHeadMovement = 0;
    int i;

    // Calculate head movement for each track
    for (i = 0; i < numTracks; i++) {
        int distance = abs(tracks[i] - currentPosition);
        totalHeadMovement += distance;
        currentPosition = tracks[i];
    }

    double averageHeadMovement = (double)totalHeadMovement / numTracks;

    printf("Average Head Movement: %.2lf\n", averageHeadMovement);

    return 0;
}
