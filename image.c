#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"

#include "image.h"

void imageLoad(struct image *image, const char *filename)
{
  image->data = stbi_load(filename, &image->width, &image->height, &image->no_channels, 0);
}

void imageFree(struct image *image)
{
  free(image->data);
}