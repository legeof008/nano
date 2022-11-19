CC=gcc
INC_DIR = ofiles
OBJECTS= main.c
OOBJECTS =main.o
CFLAGS= -fcommon
NAME=nano
Nano: $(OBJECTS)
	$(CC) $(CFLAGS) -c $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OOBJECTS)
	mv $(OOBJECTS) $(INC_DIR)
clean:
	rm $(NAME)
	rm ofiles/nano.o
	rm ofiles/main.o

