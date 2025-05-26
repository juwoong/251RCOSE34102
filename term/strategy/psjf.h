#ifndef PSJF_H
#define PSJF_H

#include "../process_queue.h"
#include "../gantt.h"

// Preemptive Shortest Job First 스케줄링을 수행합니다.
GanttChart* psjf_scheduling(ProcessQueue *queue, int *io_time, int io_time_length);

#endif // PSJF_H
