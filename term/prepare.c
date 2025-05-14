#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "prepare.h"

// Generate processes
void generate_processes(Process *processes, int n, int max_arrival_time, 
                        int max_cpu_burst, int max_io_burst, int max_priority) {
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        processes[i].arrival_time = rand() % max_arrival_time;
        processes[i].cpu_burst_time = rand() % max_cpu_burst + 1; // 최소 1
        processes[i].io_burst_time = rand() % max_io_burst + 1; // 최소 1
        processes[i].priority = rand() % max_priority + 1; // 최소 1
    }
}

// Print processes
void print_processes(Process *processes, int n) {
    printf("PID\tArrival\tCPU Burst\tIO Burst\tPriority\n");
    printf("-----------------------------------------------------------\n");
    
    for (int i = 0; i < n; i++) {
        printf("%4d\t%4d\t%4d\t%4d\t%4d\n", 
               processes[i].pid,
               processes[i].arrival_time,
               processes[i].cpu_burst_time,
               processes[i].io_burst_time,
               processes[i].priority);
    }
}
