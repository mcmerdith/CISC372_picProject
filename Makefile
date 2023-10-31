
image: image.c image.h
	gcc -g -Wall image.c -o image -lm -fopenmp -std=c99

clean:
	rm -f image output.png
