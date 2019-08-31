#include <math.h>

#include "util.h"

double norm2(double x1, double y1, double x2, double y2) 
{
  return sqrt(SQUARE(x1 - x2) + SQUARE(y1 - y2));
}
