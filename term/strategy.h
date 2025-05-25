#ifndef STRATEGY_H
#define STRATEGY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "process.h"

// CPU 스케줄링 알고리즘의 기본 인터페이스
typedef struct {
    // 스케줄링 알고리즘 실행
    void (*schedule)(void* self, Process* processes, int processCount);
    
    // 평균 대기 시간 계산
    double (*getAverageWaitingTime)(void* self);
    
    // 평균 반환 시간 계산
    double (*getAverageTurnaroundTime)(void* self);
    
    // 스케줄링 결과 출력
    void (*printResults)(void* self);
} SchedulingStrategy;

#endif // STRATEGY_H
