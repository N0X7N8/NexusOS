CC      = gcc
CFLAGS = -Wall -Wextra -g
SRC     = src/nexus_memory.c src/nexus_process.c src/nexus_main.c
OBJ     = $(SRC:.c=.o)
TARGET  = nexus

all: $(TARGET)

$(TARGET): $(OBJ)
 $(CC) $(CFLAGS) -o $@ $^

%.o: %.c
 $(CC) $(CFLAGS) -c -o $@ $<

clean:
 rm -f $(OBJ) $(TARGET)

.PHONY: all clean