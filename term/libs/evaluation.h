#ifndef EVALUATION_H
#define EVALUATION_H

#include "gantt.h"
#include "process.h"
#include "process_queue.h"

typedef struct {
    double avg_turnaround_time;
    double avg_waiting_time;
} Evaluation;

int find_completion_time(GanttChart *chart, int pid);

int calculate_waiting_time(Process process, GanttChart *chart);

int calculate_turnaround_time(Process process, GanttChart *chart);

Evaluation calculate_average_times(ProcessQueue *queue, GanttChart *chart);

void calculate_evaluation_table(Evaluation *evaluation, char **algorithm_names, int num_algorithms);

#endif
