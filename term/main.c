#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "prepare.h"

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <number of processes> <max arrival time> <max cpu burst> <max priority>\n", argv[0]);
        return 1;
    }
    
    // Parse command line arguments.
    int n = atoi(argv[1]);
    int max_arrival_time = atoi(argv[2]);
    int max_cpu_burst = atoi(argv[3]);
    int max_priority = atoi(argv[4]);
    
    // Validate parameters.
    if (n <= 0 || max_arrival_time <= 0 || max_cpu_burst <= 0 || max_priority <= 0) {
        printf("All parameters must be positive.\n");
        return 1;
    }
    
    srand(time(NULL));
    
    // Allocate process array.
    Process *processes = (Process*)malloc(n * sizeof(Process));
    if (processes == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    // Generate process data.
    generate_processes(processes, n, max_arrival_time, max_cpu_burst, max_priority);
    
    // Print process data.
    print_processes(processes, n);
    
    // Free memory.
    free(processes);
    
    return 0;
}
