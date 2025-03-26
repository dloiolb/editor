CC = gcc
CFLAGS = -Wall -g 
LDFLAGS = -lreadline
SRC_DIR = src
OBJ_DIR = obj
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES)) 

TARGET = ed

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) -o $@ $^ $(LDFLAGS) 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	-rm -f $(TARGET) $(OBJ_FILES)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run