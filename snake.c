#include "util.h"

struct Snake {
  struct SnakePoint *con; 
  int cur;
  int len;                 
};

struct SnakePoint {
  int x;
  int y;
  double a;
  double b;
  double g;
};

#define NORMALIZED(s, p) (s->con[p % s->len])

double strechingEnergySnake(struct Snake *snake)
{
  double sum = 0.0;
  int i;
  for (i = 0; i <= snake->len - 1; i++) {
    struct SnakePoint p0 = NORMALIZED(snake, i);
    struct SnakePoint p1 = NORMALIZED(snake, i + 1);
    sum += norm2(p0.x, p0.y, p1.x, p1.y);
  }
  double avg_dist = sum / snake->len;

  struct SnakePoint ps0 = NORMALIZED(snake, snake->cur);
  struct SnakePoint ps1 = NORMALIZED(snake, snake->cur + 1);
  double dist = norm2(ps0.x, ps0.y, ps1.x, ps1.y);

  return ABS(avg_dist - dist);
}

double bendingEnergySnake(struct Snake *snake)
{
  struct SnakePoint psp0 = NORMALIZED(snake, snake->cur);
  struct SnakePoint psp1 = NORMALIZED(snake, snake->cur + 1);
  struct SnakePoint psn1 = NORMALIZED(snake, snake->cur - 1 + snake->len);

  return SQUARE(psp1.x - 2 * psp0.x + psn1.x) * SQUARE(psp1.y - 2 * psp0.y + psp1.y);
}

double internalEnergySnake(struct Snake *snake)
{
  return strechingEnergySnake(snake) + bendingEnergySnake(snake);
}

double edgeEnergySnake(struct Snake *snake)
{
  return 0.0;
}

double imageEnergySnake(struct Snake *snake)
{
  return edgeEnergySnake(snake);
}

double energySnake(struct Snake *snake)
{
  return internalEnergySnake(snake) + imageEnergySnake(snake);
}

void greedySnake(struct Snake *snake)
{
  for (snake->cur = 0; snake->cur <= snake->len; snake->cur++) {
  }
}
