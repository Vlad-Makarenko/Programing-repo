#targets = main.bin test.bin
CC = gcc
C_OPTS = -std=gnu11 -g -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -I./src src/list.c

all: clean prep compile

clean:
	rm -rf dist
prep:
	mkdir dist
compile:
	##main.bin test.bin
	cp src/list.h ../shared
	$(CC) -c $(C_OPTS) -o ./dist/list.o
	ar rcs ./dist/liblist.a ./dist/list.o
	cp ./dist/liblist.a ../shared
	

#main.bin: src/main.c
#	$(CC) $(C_OPTS) $< -o ./dist/$@
#test.bin: test/test.c
#	$(CC) $(C_OPTS) $< -o ./dist/$@
#test: clean prep compile
#	./dist/test.bin
#run: clean prep compile
#	./dist/main.bin
#doxygen:
#	doxygen Doxyfile
#format: #TODO
#
#tidy: # TODO
