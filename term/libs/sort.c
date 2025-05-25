#include "../process_queue.h"

void sort_by_shortest_job_first(ProcessQueue *queue) {
    for (int i=0; i < queue->size - 1; i++) {
        for (int j=i + 1; j < queue->size; j++) {
            if (queue->processes[i].cpu_burst_time > queue->processes[j].cpu_burst_time) {
                Process temp = queue->processes[i];
                queue->processes[i] = queue->processes[j];
                queue->processes[j] = temp;
            } else if (queue->processes[i].cpu_burst_time == queue->processes[j].cpu_burst_time) {
                // handle same cpu burst time
                if (queue->processes[i].pid > queue->processes[j].pid) {
                    Process temp = queue->processes[i];
                    queue->processes[i] = queue->processes[j];
                    queue->processes[j] = temp;
                }
            }
        }   
    }
}


void sort_by_arrival_time(ProcessQueue *queue) {
    for (int i=0; i < queue->size - 1; i++) {
        for (int j=i + 1; j < queue->size; j++) {
            if (queue->processes[i].arrival_time > queue->processes[j].arrival_time) {
                Process temp = queue->processes[i];
                queue->processes[i] = queue->processes[j];
                queue->processes[j] = temp;
            } else if (queue->processes[i].arrival_time == queue->processes[j].arrival_time) {
                if (queue->processes[i].pid > queue->processes[j].pid) {
                    Process temp = queue->processes[i];
                    queue->processes[i] = queue->processes[j];
                    queue->processes[j] = temp;
                }
            }
        } 
    }
}

void sort_by_priority(ProcessQueue *queue) {
    for (int i=0; i < queue->size - 1; i++) {
        for (int j=i + 1; j < queue->size; j++) {
            if (queue->processes[i].priority > queue->processes[j].priority) {
                Process temp = queue->processes[i];
                queue->processes[i] = queue->processes[j];
                queue->processes[j] = temp;
            } else if (queue->processes[i].priority == queue->processes[j].priority) {
                if (queue->processes[i].pid > queue->processes[j].pid) {
                    Process temp = queue->processes[i];
                    queue->processes[i] = queue->processes[j];
                    queue->processes[j] = temp;
                }
            }
        }
    }
}