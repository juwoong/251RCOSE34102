#ifndef NSJF_H
#define NSJF_H

#include "../process_queue.h"
#include "../gantt.h"

/**
 * Non-preemptive Shortest Job First 스케줄링 알고리즘을 실행합니다.
 * @param queue 스케줄링할 프로세스 큐
 * @param io_time IO 이벤트가 발생하는 시간 배열
 * @param io_time_length IO 이벤트 시간 배열의 길이
 */
GanttChart* nsjf_scheduling(ProcessQueue *queue, int *io_time, int io_time_length);

#endif // NSJF_H
