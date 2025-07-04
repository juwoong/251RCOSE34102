#ifndef RR_H
#define RR_H

#include "../process_queue.h"
#include "../gantt.h"

GanttChart* rr_scheduling(ProcessQueue *queue, int *io_time, int io_time_length, int time_unit);

#endif