targets = main1.bin main2.bin main3.bin main4.bin
CC = gcc
C_OPTS = -std=gnu11 -g -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -I./src 
all: clean prep compile run

clean:
	rm -rf dist
prep:
	mkdir dist
compile: main1.bin main2.bin main3.bin main4.bin

main1.bin: src/main1.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
main2.bin: src/main2.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
main3.bin: src/main3.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
main4.bin: src/main4.c
	$(CC) $(C_OPTS) $< -o ./dist/$@

run: clean prep compile
	./dist/main1.bin ./dist/main2.bin
doxygen:
	doxygen Doxyfile
format: #TODO

tidy: # TODO

