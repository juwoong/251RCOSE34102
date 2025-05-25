#ifndef GANTT_H
#define GANTT_H

// 간트 차트 항목을 나타내는 구조체
typedef struct {
    int pid;            // 프로세스 ID
    int start_time;     // 시작 시간
    int end_time;       // 종료 시간
    int type;          // IO 작업 여부 (1: IO, 0: CPU, 2: IDLE)
} GanttItem;

typedef struct {
    GanttItem *items;
    int size;
    int max_size;
} GanttChart;

GanttChart *create_gantt_chart(int size);
void add_gantt_item(GanttChart *chart, int pid, int start_time, int end_time, int is_io);
void print_gantt_chart(GanttChart *chart);
void free_gantt_chart(GanttChart *chart);

#endif