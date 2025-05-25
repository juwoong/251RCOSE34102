#ifndef SORT_H
#define SORT_H

#include "../process_queue.h"

void sort_by_shortest_job_first(ProcessQueue *queue);
void sort_by_arrival_time(ProcessQueue *queue);
void sort_by_priority(ProcessQueue *queue);

#endif 