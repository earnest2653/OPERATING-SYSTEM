#include <stdio.h>

struct Process {

    int process_id;

    int burst_time;

    int remaining_time;

    int waiting_time;

    int turnaround_time;

};

void calculate_round_robin(struct Process processes[], int n, int quantum_time) {

    int total_waiting_time = 0;

    int total_turnaround_time = 0;

    int completed = 0;

    // Initialize remaining time for all processes

    for (int i = 0; i < n; i++) {

        processes[i].remaining_time = processes[i].burst_time;

    }

    // Perform round-robin scheduling

    int time = 0;

    while (completed < n) {

        for (int i = 0; i < n; i++) {

            if (processes[i].remaining_time > 0) {

                if (processes[i].remaining_time <= quantum_time) {

                    // Process completes

                    time += processes[i].remaining_time;

                    processes[i].waiting_time = time - processes[i].burst_time;

                    processes[i].turnaround_time = time;

                    processes[i].remaining_time = 0;

                    completed++;

                } else {

                    // Process still needs more time

                    time += quantum_time;

                    processes[i].remaining_time -= quantum_time;

                }

            }

        }

    }

    // Calculate total waiting time and total turnaround time

    for (int i = 0; i < n; i++) {

        total_waiting_time += processes[i].waiting_time;

        total_turnaround_time += processes[i].turnaround_time;

    }

    // Calculate average waiting time and average turnaround time

    float avg_waiting_time = (float) total_waiting_time / n;

    float avg_turnaround_time = (float) total_turnaround_time / n;

    // Print the results

    printf("Average Waiting Time: %.2f ms\n", avg_waiting_time);

    printf("Average Turnaround Time: %.2f ms\n", avg_turnaround_time);

}

int main() {

    struct Process processes[] = {

        {1, 24, 0, 0, 0},

        {2, 3, 0, 0, 0},

        {3, 3, 0, 0, 0}

    };

    int num_processes = sizeof(processes) / sizeof(processes[0]);

    int quantum_time = 4;

    calculate_round_robin(processes, num_processes, quantum_time);

    return 0;

}
