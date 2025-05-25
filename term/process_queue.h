#ifndef PROCESS_QUEUE_H
#define PROCESS_QUEUE_H

#include "process.h"

typedef struct ProcessQueue {
    Process *processes;
    int size;
    int max_size;
} ProcessQueue;

ProcessQueue *create_empty_process_queue(int size);
ProcessQueue *create_process_queue(Process *processes, int size);
ProcessQueue *copy_process_queue(ProcessQueue *queue);

void enqueue(ProcessQueue *queue, Process process);
Process dequeue(ProcessQueue *queue);
int insert_process(ProcessQueue *queue, Process process);

int is_empty(ProcessQueue *queue);
int is_full(ProcessQueue *queue);
void print_process_queue(ProcessQueue *queue);
void free_process_queue(ProcessQueue *queue);

#endif