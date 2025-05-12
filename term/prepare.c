#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "prepare.h"

// 프로세스 데이터 생성 함수
void generate_processes(Process *processes, int n, int max_arrival_time, 
                        int max_cpu_burst, int max_priority) {
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        processes[i].arrival_time = rand() % max_arrival_time;
        processes[i].cpu_burst_time = rand() % max_cpu_burst + 1; // 최소 1
        processes[i].priority = rand() % max_priority + 1; // 최소 1
    }
}

// 프로세스 데이터 출력 함수
void print_processes(Process *processes, int n) {
    printf("PID\tArrival\tCPU Burst\tPriority\n");
    printf("-----------------------------------------------------------\n");
    
    for (int i = 0; i < n; i++) {
        printf("%4d\t%4d\t%4d\t\t%4d\n", 
               processes[i].pid,
               processes[i].arrival_time,
               processes[i].cpu_burst_time,
               processes[i].priority);
    }
}
