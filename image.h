#ifndef ___IMAGE
#define ___IMAGE
#include <stdint.h>

#define Index(x, y, width, bit, bpp) ((x) * (bpp)) + ((y) * (width) * (bpp)) + (bit)
#define Min(a, b) ((a) < (b) ? (a) : (b))
#define StartIndex(t_rank, n_threads, n_items) ((t_rank) * ((n_items) / (n_threads)) + Min(t_rank, (n_items) % (n_threads)))

#define NTHREADS 8

typedef struct {
  uint8_t *data;
  int width;
  int height;
  int bpp;
} Image;

enum KernelTypes {
  EDGE = 0,
  SHARPEN = 1,
  BLUR = 2,
  GAUSE_BLUR = 3,
  EMBOSS = 4,
  IDENTITY = 5
};

typedef double Matrix[3][3];

typedef struct {
  Image *src, *dest;
	int t_rank, n_threads;
  int algorithm;
} ThreadData;

uint8_t getPixelValue(Image *srcImage, int x, int y, int bit, Matrix algorithm);
void convolute(Image *srcImage, Image *destImage, int algorithm);
int Usage();
enum KernelTypes GetKernelType(char *type);

#endif
