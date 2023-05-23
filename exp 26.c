#include <stdio.h>

#define MAX_PROCESSES 3

typedef struct {
    int burstTime;
    int priority;
} Process;

void priorityScheduling(Process processes[], int n) {
    int waitingTime[MAX_PROCESSES], turnaroundTime[MAX_PROCESSES];

    waitingTime[0] = 0;
    turnaroundTime[0] = processes[0].burstTime;

    for (int i = 1; i < n; i++) {
        waitingTime[i] = waitingTime[i - 1] + processes[i - 1].burstTime;
        turnaroundTime[i] = waitingTime[i] + processes[i].burstTime;
    }

    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;

    printf("Process\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, processes[i].burstTime, processes[i].priority,
               waitingTime[i], turnaroundTime[i]);
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
    }

    double avgWaitingTime = (double)totalWaitingTime / n;
    double avgTurnaroundTime = (double)totalTurnaroundTime / n;

    printf("\nAverage Waiting Time: %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);
}

int main() {
    Process processes[MAX_PROCESSES] = {{30, 2}, {5, 1}, {12, 3}};

    priorityScheduling(processes, MAX_PROCESSES);

    return 0;
}
