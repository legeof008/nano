CC=gcc
INC_DIR = ofiles
OBJECTS= nano.c main.c
OOBJECTS = nano.o main.o
CFLAGS= -fcommon -lncurses -Wall -pedantic
NAME=nano
Nano: $(OBJECTS)
	$(CC) $(CFLAGS) -c $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OOBJECTS)
	mv $(OOBJECTS) $(INC_DIR)
clean:
	rm $(NAME)
	rm ofiles/nano.o
	rm ofiles/main.o

