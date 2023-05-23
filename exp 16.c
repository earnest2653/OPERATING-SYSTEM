#include <stdio.h>

// Structure to represent a process
struct Process {
    int processId;
    int burstTime;
    int arrivalTime;
    int waitingTime;
    int turnaroundTime;
};

// Function to calculate average waiting time and average turnaround time
void calculateAverageTimes(struct Process processes[], int numProcesses) {
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;

    // Calculate waiting time and turnaround time for each process
    for (int i = 0; i < numProcesses; i++) {
        if (i == 0) {
            processes[i].waitingTime = 0;
        } else {
            processes[i].waitingTime = processes[i - 1].waitingTime + processes[i - 1].burstTime;
        }

        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;

        totalWaitingTime += processes[i].waitingTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
    }

    double averageWaitingTime = (double)totalWaitingTime / numProcesses;
    double averageTurnaroundTime = (double)totalTurnaroundTime / numProcesses;

    // Print the average waiting time and average turnaround time
    printf("Average Waiting Time: %.2lf\n", averageWaitingTime);
    printf("Average Turnaround Time: %.2lf\n", averageTurnaroundTime);
}

int main() {
    // Define the processes with their burst times
    struct Process processes[] = {
        {1, 10, 0, 0, 0},
        {2, 15, 0, 0, 0},
        {3, 25, 0, 0, 0}
    };

    int numProcesses = sizeof(processes) / sizeof(processes[0]);

    calculateAverageTimes(processes, numProcesses);

    return 0;
}
