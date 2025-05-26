#ifndef PP_H
#define PP_H

#include "../process_queue.h"
#include "../gantt.h"

GanttChart* pp_scheduling(ProcessQueue *queue, int *io_time, int io_time_length);

#endif