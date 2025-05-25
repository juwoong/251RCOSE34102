#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "process_queue.h"

// Create an empty process queue
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

// Create a queue from an array of processes
ProcessQueue *create_process_queue(Process *processes, int size) {
    ProcessQueue *queue = create_empty_process_queue(size);
    if (queue == NULL) {
        return NULL;
    }
    
    memcpy(queue->processes, processes, sizeof(Process) * size);
    queue->size = size;
    return queue;
}

// Add a process to the queue
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

// Remove and return a process from the queue
Process dequeue(ProcessQueue *queue) {
    Process empty_process = {0, 0, 0, 0, 0};
    
    if (queue == NULL || is_empty(queue)) {
        return empty_process;
    }
    
    Process process = queue->processes[0];
    
    // Move all elements one position forward
    for (int i = 0; i < queue->size - 1; i++) {
        queue->processes[i] = queue->processes[i + 1];
    }
    
    queue->size--;
    return process;
}

// Insert a process at a specific position
int insert_process(ProcessQueue *queue, Process process) {
    if (queue == NULL || is_full(queue)) {
        return -1;
    }
    
    // 항상 맨 뒤에 추가
    queue->processes[queue->size] = process;
    queue->size++;
    return queue->size - 1;
}

// Check if the queue is empty
int is_empty(ProcessQueue *queue) {
    return (queue == NULL || queue->size == 0);
}

// Check if the queue is full
int is_full(ProcessQueue *queue) {
    // In the current implementation, we can't determine the maximum size
    // of the queue since we don't store it, so always return false
    return queue->size == queue->max_size;
}

// Print the contents of the queue
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

// Free the memory allocated for the queue
void free_process_queue(ProcessQueue *queue) {
    if (queue != NULL) {
        free(queue->processes);
        free(queue);
    }
}
