# OS Term Project - CPU Scheduling Simulator

## Term Project의 목적

- OS의 기본 개념을 바탕으로 CPU 스케줄러의 기능 및 작동 원리를 이해하는데 있다. [cite: 1]
- Project 의 수행을 통해 Linux 환경에서의 코딩 능력을 향상시킬 수 있다. [cite: 2]

## CPU Scheduling Simulator 의 구성 (예시 함수)

- **Create_Process()**: 실행할 프로세스를 생성하고 각 프로세스에 데이터가 주어진다. [cite: 3]
  - (Random data 부여) [cite: 4]
  - Process ID
  - Arrival time
  - CPU burst time
  - I/O burst time / I/O request time
  - Priority
- **Config()**: 시스템 환경 설정
  - Ready Queue / Waiting Queue
- **Schedule()**: CPU 스케줄링 알고리즘을 구현한다. [cite: 5]
  - FCFS(First Come First Served)
  - SJF(Shortest Job First)
    - Preemptive 방식 적용 - SJF, Priority
  - RR(Round Robin)
  - Priority
- **Evaluation()**: 각 스케줄링 알고리즘들간 비교 평가한다. [cite: 6]
  - Average waiting time
  - Average turnaround time

## 보고서

보고서의 양식은 서론, 본론, 결론, 참고문헌, 부록 등의 순서를 따른다. [cite: 7]

- **서론** [cite: 7]
  - CPU 스케줄러의 개념 등 [cite: 7]
  - 본인이 구현한 스케줄러에 대한 요약 설명(특징 등) [cite: 7]
- **본론**
  - 다른 CPU 스케줄링 시뮬레이터에 대한 소개
  - 본인이 구현한 시뮬레이터의 시스템 구성도
  - 각 모듈에 대한 설명(알고리즘으로 표현)
  - 시뮬레이터 실행 결과 화면
  - 알고리즘들간의 성능 비교 등
- **결론**
  - 구현한 시뮬레이터에 대한 정리
  - 프로젝트 수행 소감 및 향후 발전방향 등

소스코드는 보고서 마지막에 <부록>으로 첨부

## 평가 항목 (Evaluation Items)

| 평가 항목 (Evaluation Items)                                                       | 최대감점 (Deduct points) | 비고                                                        |
| :--------------------------------------------------------------------------------- | :----------------------- | :---------------------------------------------------------- |
| 1. Method for Data Creation PID, Arrival time, CPU (I/O) burst time, Priority etc. | -5                       | Random 생성 / 키보드 입력                                   |
| 2. Implementation of I/O operation                                                 | -7                       | I/O 발생: Random 또는 고정적(-3) 발생 횟수: 다수 or 1회(-3) |
| 3. Algorithm - FCFS                                                                | -5                       |                                                             |
| 4. Algorithm - Non-Preemptive SJF                                                  | -5                       |                                                             |
| 5. Algorithm Preemptive SJF                                                        | -6                       |                                                             |
| 6. Algorithm - Non-Preemptive Priority                                             | -5                       |                                                             |
| 7. Algorithm - Preemptive Priority                                                 | -6                       |                                                             |
| 8. Algorithm Round Robin                                                           | -6                       |                                                             |
| 9. Gantt Chart                                                                     | -5                       | 간트차트 Display 여부                                       |
| 10. Evaluation - Waiting Time / Turnaround Time                                    | -5                       | 성능분석 여부                                               |
| 11. Additional Functions (2-4 points per a function)                               |                          |                                                             |
| 12. Question and Answer                                                            |                          |                                                             |
| 13. Report                                                                         | -20                      |                                                             |
| Format                                                                             |                          |                                                             |
| Logical representation of Simulator                                                |                          |                                                             |
| Simulation Results Comparisons and Analysis                                        |                          |                                                             |
