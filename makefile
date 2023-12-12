all:
	echo "Build the program"
build:
	clang cal.c -o cal
	./cal
clean:
	rm cal
