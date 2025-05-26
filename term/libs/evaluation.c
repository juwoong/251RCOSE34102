#include <stdio.h>
#include <stdlib.h>
#include "gantt.h"
#include "process.h"
#include "process_queue.h"
#include "evaluation.h"

int find_completion_time(GanttChart *chart, int pid) {
    int completion_time = 0;
    for (int i = 0; i < chart->size; i++) {
        if (chart->items[i].pid == pid && chart->items[i].type == 0) { // IO 작업이 아닌 경우만 고려
            completion_time = chart->items[i].end_time;
        }
    }
    return completion_time;
}

int calculate_waiting_time(Process process, GanttChart *chart) {
    int completion_time = find_completion_time(chart, process.pid);
    return completion_time - process.arrival_time - process.cpu_burst_time;
}

int calculate_turnaround_time(Process process, GanttChart *chart) {
    int completion_time = find_completion_time(chart, process.pid);
    return completion_time - process.arrival_time;
}

Evaluation calculate_average_times(ProcessQueue *queue, GanttChart *chart) {
    double total_turnaround_time = 0;
    double total_waiting_time = 0;
    
    for (int i = 1; i <= queue->size; i++) {
        Process process = queue->processes[i-1];
        int turnaround_time = calculate_turnaround_time(process, chart);
        int waiting_time = calculate_waiting_time(process, chart);
        
        total_turnaround_time += turnaround_time;
        total_waiting_time += waiting_time;
    }
    
    Evaluation evaluation = {
        .avg_turnaround_time = total_turnaround_time / queue->size,
        .avg_waiting_time = total_waiting_time / queue->size
    };
    
    return evaluation;
}

void calculate_evaluation_table(Evaluation *evaluation, char **algorithm_names, int num_algorithms) {
    printf("|----------------|---------------------|------------------|\n");
    printf("|   Algorithm    | Avg Turnaround Time | Avg Waiting Time |\n");
    printf("|----------------|---------------------|------------------|\n");
    for (int i = 0; i < num_algorithms; i++) {
        printf("| %-14s | %-18.2f  | %-16.2f |\n", algorithm_names[i], evaluation[i].avg_turnaround_time, evaluation[i].avg_waiting_time);
    }
    printf("|----------------|---------------------|------------------|\n");
}