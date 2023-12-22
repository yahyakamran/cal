CFLAGS = -g -Wall -Wextra 

all:
	echo "Build the program"
build:
	clang $(CFLAGS) cal.c -o cal
	./cal
clean:
	rm cal
