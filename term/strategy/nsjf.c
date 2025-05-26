#include <stdio.h>
#include <stdlib.h>
#include "../process.h"
#include "../gantt.h"
#include "../process_queue.h"
#include "../libs/sort.h"

GanttChart* nsjf_scheduling(ProcessQueue *queue, int *io_time, int io_time_length) {
    // Copy the original Queue
    ProcessQueue *target = copy_process_queue(queue);
    ProcessQueue *ready_queue = create_empty_process_queue(target->size);
    ProcessQueue *io_queue = create_empty_process_queue(target->size);

    // Sort by first arrived
    sort_by_arrival_time(target);

    // Process Queue
    int current_io_idx = 0;
    int current_start_time = 0;
    int current_burst_time = 0;
    int current_resume_time = 0;

    Process next_process = {0, 0, 0, 0, 0};
    if (target->size > 0) {
        next_process = dequeue(target);
    }
    Process current = {0, 0, 0, 0, 0};
    GanttChart *gantt_chart = create_gantt_chart(target->size + 20); 

    int max_time = 1000;

    for(int i=0; i < max_time; i++) {
        // handle ready queue
        if (next_process.arrival_time <= i) {
            // handle multiple processes arriving at the same time
            while (next_process.arrival_time <= i && next_process.pid > 0) {
                insert_process(ready_queue, next_process);
                next_process = dequeue(target);
            }

            sort_by_shortest_job_first(ready_queue);
        }

        if (io_queue-> size > 0) {
            while(io_queue->size > 0) {
                Process io_process = io_queue->processes[0];
                if (io_process.arrival_time <= i) {
                    dequeue(io_queue);
                    insert_process(ready_queue, io_process);
                    continue;
                }
                break;
            }                    
            sort_by_shortest_job_first(ready_queue);
        }

        // case of idle
        if (current.pid == 0) {  // current is idle
            if (next_process.pid > 0) {
                sort_by_shortest_job_first(ready_queue);
                current = dequeue(ready_queue);
                if (current.pid > 0) {  // idle to running
                    add_gantt_item(gantt_chart, 0, current_start_time, i, 2);
                    current_start_time = i;
                    current_burst_time = 0;
                }
            }
            continue;
        }

        current_burst_time = i - current_start_time;

        // handle IO
        if (current_io_idx < io_time_length && io_time[current_io_idx] == i) {
            // handle current stops
            add_gantt_item(gantt_chart, current.pid, current_start_time, i, 0);
            current_io_idx++;

            current.arrival_time = i + current.io_burst_time;
            current.cpu_burst_time -= current_burst_time;

            if (current.cpu_burst_time > 0) {
                insert_process(io_queue, current);
            }

            sort_by_arrival_time(io_queue);
            current = dequeue(ready_queue);

            current_start_time = i;
            current_burst_time = 0;

            continue;
        }

        // handle context changes
        if (current.cpu_burst_time <= current_burst_time) {
            add_gantt_item(gantt_chart, current.pid, 
              (current_start_time > current_resume_time) ? current_start_time : current_resume_time, i, 0);
            
            current_start_time = i;
            current_burst_time = 0;

            if (target->size == 0 && ready_queue->size == 0 && io_queue->size == 0) break;
            if (ready_queue->size > 0) {
                current = dequeue(ready_queue);
            } else {
                current = (Process){0, 0, 0, 0, 0};
            }
        }
    }

    free_process_queue(target);
    free_process_queue(ready_queue);

    return gantt_chart;
}