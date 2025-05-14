#ifndef PREPARE_H
#define PREPARE_H

#include "process.h"

// Generate Processes. 
void generate_processes(Process *processes, int n, int max_arrival_time, 
                        int max_cpu_burst, int max_io_burst, int max_priority);

// Print Processes, with pointer array of Process.
void print_processes(Process *processes, int n);

#endif /* PREPARE_H */ 