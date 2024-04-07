#include <stdio.h>

int main() {
    int n; // Number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int arrivalTime[n]; // Array to store arrival time of processes
    int burstTime[n]; // Array to store burst time of processes

    // Input arrival time and burst time for each process
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &arrivalTime[i], &burstTime[i]);
    }

    // Sort the processes based on arrival time using bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arrivalTime[j] > arrivalTime[j + 1]) {
                // Swap arrival time
                int temp = arrivalTime[j];
                arrivalTime[j] = arrivalTime[j + 1];
                arrivalTime[j + 1] = temp;

                // Swap burst time
                temp = burstTime[j];
                burstTime[j] = burstTime[j + 1];
                burstTime[j + 1] = temp;
            }
        }
    }

    int completionTime[n]; // Array to store completion time of processes
    int waitingTime[n]; // Array to store waiting time of processes
    int turnaroundTime[n]; // Array to store turnaround time of processes

    // Calculate completion time, waiting time, and turnaround time for each process
    

    for (int i = 0; i < n; i++) {
        waitingTime[i] = completionTime[i] - arrivalTime[i] - burstTime[i];
        turnaroundTime[i] = completionTime[i] - arrivalTime[i];
    }

    // Calculate average waiting time and average turnaround time
    float avgWaitingTime = 0;
    float avgTurnaroundTime = 0;
    for (int i = 0; i < n; i++) {
        avgWaitingTime += waitingTime[i];
        avgTurnaroundTime += turnaroundTime[i];
    }
    avgWaitingTime /= n;
    avgTurnaroundTime /= n;

    // Print the results
    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, arrivalTime[i], burstTime[i], completionTime[i], waitingTime[i], turnaroundTime[i]);
    }
    printf("\nAverage Waiting Time: %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);

    return 0;
}
