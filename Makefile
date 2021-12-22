CC=gcc
INC_DIR = ../
OBJECTS= nano.c
CFLAGS= -fcommon -lncurses
NAME=nano
GoL: $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) -lpng
	
clean:
	rm $(NAME)
