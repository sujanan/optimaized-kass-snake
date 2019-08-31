#include <stdio.h>

#include "image.h"
#include "snake.h"

int main(int argc, char **argv)
{
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <image>\n", argv[0]);
    return 1;
  }

  struct image image;
  imageLoad(&image, argv[1]);
  imageFree(&image);

  return 0;
}