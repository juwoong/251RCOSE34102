#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "process_queue.h"

ProcessQueue *create_empty_process_queue(int size) {
    ProcessQueue *queue = (ProcessQueue *)malloc(sizeof(ProcessQueue));
    if (queue == NULL) {
        return NULL;
    }
    
    queue->processes = (Process *)malloc(sizeof(Process) * size);
    if (queue->processes == NULL) {
        free(queue->processes);
        free(queue);
        return NULL;
    }
    
    queue->size = 0;
    queue->max_size = size;
    return queue;
}

ProcessQueue *create_process_queue(Process *processes, int size) {
    ProcessQueue *queue = create_empty_process_queue(size);
    if (queue == NULL) {
        return NULL;
    }
    
    memcpy(queue->processes, processes, sizeof(Process) * size);
    queue->size = size;
    return queue;
}

void enqueue(ProcessQueue *queue, Process process) {
    if (queue == NULL || is_full(queue)) {
        return;
    }
    
    queue->processes[queue->size++] = process;
}

ProcessQueue *copy_process_queue(ProcessQueue *queue) {
    if (queue == NULL) {
        return NULL;
    }
    
    return create_process_queue(queue->processes, queue->size);
}

Process dequeue(ProcessQueue *queue) {
    Process empty_process = {0, 0, 0, 0, 0};
    
    if (queue == NULL || is_empty(queue)) {
        return empty_process;
    }
    
    Process process = queue->processes[0];
    
    for (int i = 0; i < queue->size - 1; i++) {
        queue->processes[i] = queue->processes[i + 1];
    }
    
    queue->size--;
    return process;
}

int insert_process(ProcessQueue *queue, Process process) {
    if (queue == NULL || is_full(queue)) {
        return -1;
    }
    
    queue->processes[queue->size] = process;
    queue->size++;
    return queue->size - 1;
}

int is_empty(ProcessQueue *queue) {
    return (queue == NULL || queue->size == 0);
}

int is_full(ProcessQueue *queue) {
    return queue->size == queue->max_size;
}

void print_process_queue(ProcessQueue *queue) {
    if (queue == NULL) {
        printf("Queue is NULL\n");
        return;
    }
    
    if (is_empty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    
    printf("PID\tArrival\tCPU Burst\tIO Burst\tPriority\n");
    printf("-----------------------------------------------------------\n");
    
    for (int i = 0; i < queue->size; i++) {
        printf("%4d\t%4d\t%4d\t%4d\t%4d\n", 
               queue->processes[i].pid,
               queue->processes[i].arrival_time,
               queue->processes[i].cpu_burst_time,
               queue->processes[i].io_burst_time,
               queue->processes[i].priority);
    }
}

void free_process_queue(ProcessQueue *queue) {
    if (queue != NULL) {
        free(queue->processes);
        free(queue);
    }
}
