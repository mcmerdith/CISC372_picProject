
image: image.c image.h
	gcc -g -Wall image.c -o image -lm

clean:
	rm -f image output.png
