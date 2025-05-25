CC = gcc
CFLAGS = -Wall -Wextra -g
INCLUDES = -I.

SRC_DIR = .
STRATEGY_DIR = strategy

SRCS = $(SRC_DIR)/main.c \
       $(SRC_DIR)/prepare.c \
       $(SRC_DIR)/process_queue.c \
	   $(SRC_DIR)/libs/sort.c \
       $(STRATEGY_DIR)/fcfs.c \
	   $(STRATEGY_DIR)/nsjf.c \
	   $(STRATEGY_DIR)/psjf.c \
	   $(STRATEGY_DIR)/npp.c \
	   $(STRATEGY_DIR)/pp.c \
	   $(STRATEGY_DIR)/rr.c \
	   $(SRC_DIR)/gantt.c

OBJS = $(SRCS:.c=.o)

TARGET = scheduler

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
