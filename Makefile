
image: image.c image.h
	gcc -g -Wall image.c -o image -lm -lpthread -std=c99

clean:
	rm -f image output.png
