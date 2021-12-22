CC=gcc
INC_DIR = ../
OBJECTS= *.c
CFLAGS= -fcommon -lncurses
NAME=nano
GoL: $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) -lpng
	
clean:
	rm $(NAME)
