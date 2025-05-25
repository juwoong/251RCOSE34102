#ifndef NPP_H
#define NPP_H

#include "../process_queue.h"

void npp_scheduling(ProcessQueue *queue, int *io_time, int io_time_length);

#endif