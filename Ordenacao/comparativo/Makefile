CC = gcc
CFLAGS = -Wall -Iinclude/
OPT = -O3

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

EXEC = main

all: clean $(EXEC)
	@figlet Prog 2
$(EXEC): $(OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC Linker'
	@$(CC) -o $@ $^ $(LDFLAGS)
	@echo 'Finished building target: $@'
	@echo ' '

%.o: %.c
	@$(CC) $(OPT) $(CFLAGS) -c $^

clean:
	@rm -rf *.o $(EXEC)
