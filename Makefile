CC=gcc
CFLAGS=-fPIC -Wall -Wextra
LDFLAGS=-shared
TARGET=calcunix
SRC=src
OBJ=Calculate.so

all: $(OBJ) $(TARGET)

$(OBJ): $(SRC)/Calculate.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $<

$(TARGET): $(SRC)/calcunix.c $(OBJ)
	$(CC) -o $@ $(SRC)/calcunix.c -L. -l:$(OBJ)
	chmod +x $(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)
