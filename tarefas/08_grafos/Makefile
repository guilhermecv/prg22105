CC = gcc
CFLAGS = -Wall

# Incluir aqui as bibliotecas utilizadas
# LDFLAGS = -l wiringPi

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
	@$(CC) -c $(CFLAGS) $^

clean:
	@rm -rf *.o $(EXEC) graph.dot graph.png
