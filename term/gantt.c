#include <stdio.h>
#include <stdlib.h>
#include "gantt.h"

GanttChart *create_gantt_chart(int size) {
    GanttChart *chart = (GanttChart *)malloc(sizeof(GanttChart));
    if (chart == NULL) {
        return NULL;
    }
    
    chart->items = (GanttItem *)malloc(sizeof(GanttItem) * size);
    if (chart->items == NULL) {
        free(chart);
        return NULL;
    }
    
    chart->max_size = size;
    chart->size = 0;
    return chart;
}

void add_gantt_item(GanttChart *chart, int pid, int start_time, int end_time, int type) {
    if (chart == NULL || chart->items == NULL) {
        return;
    }
    
    // 새로운 항목을 추가할 위치 찾기
    int idx = chart->size;
    
    chart->items[idx].pid = pid;
    chart->items[idx].start_time = start_time;
    chart->items[idx].end_time = end_time;
    chart->items[idx].type = type;

    chart->size++;
}

void print_gantt_chart(GanttChart *chart) {
    if (chart == NULL || chart->items == NULL) {
        return;
    }
    
    printf("\Gantt Chart:\n");
    printf("PID\t시작\t종료\t작업\n");
    printf("------------------------\n");

    for (int i = 0; i < chart->size; i++) {
        const char *type_str;
        switch (chart->items[i].type) {
            case 0:
                type_str = "CPU";
                break;
            case 1:
                type_str = "IO";
                break;
            case 2:
                type_str = "IDLE";
                break;
            default:
                type_str = "UNKNOWN";
        }
        
        printf("%d\t%d\t%d\t%s\n", 
               chart->items[i].pid,
               chart->items[i].start_time,
               chart->items[i].end_time,
               type_str);
    }
    printf("\n");
}

void free_gantt_chart(GanttChart *chart) {
    if (chart != NULL) {
        if (chart->items != NULL) {
            free(chart->items);
        }
        free(chart);
    }
}

