
#ifndef PROCESS_H
#define PROCESS_H

typedef struct Process {
    int pid;               // Process ID
    int arrival_time;      // Arrival Time
    int cpu_burst_time;    // CPU Burst Time
    int io_burst_time;     // IO Burst Time
    int priority;          // Priority -- Not used in some algorithms.
} Process;

#endif