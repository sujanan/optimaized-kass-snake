#ifndef IMAGE_H
#define IMAGE_H

struct image {
  int width;
  int height;
  int no_channels;
  unsigned char *data;
};

void imageLoad(struct image *image, const char *filename);
void imageFree(struct image *image);

#endif
