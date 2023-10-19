
image: image.c image.h
	gcc -g -Wall image.c -o image -lm -fopenmp

clean:
	rm -f image output.png
