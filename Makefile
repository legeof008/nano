CC=gcc
O_DIR = ofiles
C_DIR = cfiles
CFLAGS= -fcommon -lncurses -Wall -pedantic
NAME= nano
OBJ= $(O_DIR)/nano.o $(O_DIR)/main.o
DEPS = hfiles/nano.h
all: $(NAME)

$(O_DIR)/%.o: $(C_DIR)/%.c
	$(CC) -c -o $@ $^ $(CFLAGS)
 
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^
	
clean:
	rm -f $(OBJ)
	rm -f $(NAME)
