#ifndef FCFS_H
#define FCFS_H

#include "../process_queue.h"

/**
 * First Come First Serve 스케줄링 알고리즘을 실행합니다.
 * 
 * @param queue 프로세스 큐
 * @param io_time IO 작업 시간 배열
 * @param io_time_length IO 작업 시간 배열의 길이
 */
void fcfs_scheduling(ProcessQueue *queue, int *io_time, int io_time_length);

#endif 