CC=gcc
INC_DIR = ../
OBJECTS= nano.c main.c
CFLAGS= -fcommon -lncurses
NAME=nano
Nano: $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)
	
clean:
	rm $(NAME)
