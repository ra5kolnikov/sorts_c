all: build

build:
	gcc -Wall -Werror -Wextra main.c sort.c -o sort
clean: 
	rm sort
rebuild: clean build
