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
#include "libs/evaluation.h"

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
    GanttChart *fcfs_chart = fcfs_scheduling(queue, io_time, io_count);
    GanttChart *nsjf_chart = nsjf_scheduling(queue, io_time, io_count);
    GanttChart *psjf_chart = psjf_scheduling(queue, io_time, io_count);
    GanttChart *npp_chart = npp_scheduling(queue, io_time, io_count);
    GanttChart *pp_chart = pp_scheduling(queue, io_time, io_count);
    GanttChart *rr_chart = rr_scheduling(queue, io_time, io_count, 2);

    Evaluation fcfs_evaluation = calculate_average_times(queue, fcfs_chart);
    Evaluation nsjf_evaluation = calculate_average_times(queue, nsjf_chart);
    Evaluation psjf_evaluation = calculate_average_times(queue, psjf_chart);
    Evaluation npp_evaluation = calculate_average_times(queue, npp_chart);
    Evaluation pp_evaluation = calculate_average_times(queue, pp_chart);
    Evaluation rr_evaluation = calculate_average_times(queue, rr_chart);

    char *algorithm_names[] = {"FCFS", "NP-SJF", "P-SJF", "NP-P", "P-P", "RR"};

    GanttChart *gantt_charts[] = {fcfs_chart, nsjf_chart, psjf_chart, npp_chart, pp_chart, rr_chart};
    Evaluation evaluations[] = {fcfs_evaluation, nsjf_evaluation, psjf_evaluation, npp_evaluation, pp_evaluation, rr_evaluation};
    
    // print gantt chart 
    for(int i=0; i<6; i++) {
        printf("%s: \n", algorithm_names[i]);
        print_gantt_chart(gantt_charts[i]);
        printf("\n\n==============================================\n\n");
    }

    calculate_evaluation_table(evaluations, algorithm_names, 6);
    
    // Free memory.
    free(io_time);
    free_process_queue(queue);
    free(processes);
    
    return 0;
}
