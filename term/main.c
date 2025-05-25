#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "prepare.h"
#include "process_queue.h"
#include "strategy/fcfs.h"
#include "strategy/nsjf.h"
#include "strategy/psjf.h"
#include "strategy/npp.h"
#include "strategy/pp.h"
#include "strategy/rr.h"

int main(int argc, char *argv[]) {
    if (argc != 6) {
        printf("Usage: %s <number of processes> <max arrival time> <max cpu burst> <max io burst> <max priority>\n", argv[0]);
        return 1;
    }
    
    // Parse command line arguments.
    int n = atoi(argv[1]);
    int max_arrival_time = atoi(argv[2]);
    int max_cpu_burst = atoi(argv[3]);
    int max_io_burst = atoi(argv[4]);
    int max_priority = atoi(argv[5]);
    
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
    generate_processes(processes, n, max_arrival_time, max_cpu_burst, max_io_burst, max_priority);
    
    // Print process data.
    printf("Processes:\n");
    print_processes(processes, n);
    
    // Create process queue and run FCFS scheduling
    ProcessQueue *queue = create_process_queue(processes, n);
    if (queue == NULL) {
        printf("Fail to create process queue.\n");
        free(processes);
        return 1;
    }
    
    // 랜덤한 IO 시간 생성
    int io_count = rand() % 3 + 2;
    int *io_time = (int*)malloc(io_count * sizeof(int));
    if (io_time == NULL) {
        printf("Fail to allocate IO time array.\n");
        free_process_queue(queue);
        free(processes);
        return 1;
    }

    // 랜덤한 시간 간격으로 IO 시간 생성
    int current_time = 0;
    for (int i = 0; i < io_count; i++) {
        current_time += rand() % 10 + 5; // 5~14 시간 간격으로 IO 발생
        io_time[i] = current_time;
    }

    printf("IO times: ");
    for (int i = 0; i < io_count; i++) {
        printf("%d ", io_time[i]);
    }
    printf("\n");
    
    // Run scheduling algorithm
    fcfs_scheduling(queue, io_time, io_count);
    nsjf_scheduling(queue, io_time, io_count);
    psjf_scheduling(queue, io_time, io_count);
    npp_scheduling(queue, io_time, io_count);
    pp_scheduling(queue, io_time, io_count);
    rr_scheduling(queue, io_time, io_count, 2);
    
    // Free memory.
    free(io_time);
    free_process_queue(queue);
    free(processes);
    
    return 0;
}
