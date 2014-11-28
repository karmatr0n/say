PROGRAM  := say
SRC      := say.c
CC       := clang
CFLAGS   := -O3 -framework ApplicationServices

all: clean build

clean:
	rm -rf $(PROGRAM) 

build:
	$(CC) $(CFLAGS) -o $(PROGRAM) $(SRC)

