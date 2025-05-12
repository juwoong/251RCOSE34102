#ifndef PREPARE_H
#define PREPARE_H

typedef struct Process {
    int pid;               // Process ID
    int arrival_time;      // Arrival Time
    int cpu_burst_time;    // CPU Burst Time
    int priority;          // Priority -- Not used in some algorithms.
} Process;

// Generate Processes. 
void generate_processes(Process *processes, int n, int max_arrival_time, 
                        int max_cpu_burst, int max_priority);

// Print Processes, with pointer array of Process.
void print_processes(Process *processes, int n);

#endif /* PREPARE_H */ 