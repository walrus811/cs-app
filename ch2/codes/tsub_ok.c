#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <stdlib.h>

int tsub_ok(int x, int y)
{
  int w = sizeof(int) << 3;
  int diff = x + (~y + 1);

  int sx = x >> (w - 1);
  int sy = y >> (w - 1);
  int sd = diff >> (w - 1);

  int overflow = (sx ^ sy) & (sx ^ sd);
  return !overflow;
}

static int ref_tsub_ok(int x, int y)
{
  int64_t diff = (int64_t)x - (int64_t)y;
  return (diff <= INT_MAX && diff >= INT_MIN);
}

static void run_one(int x, int y)
{
  int got = tsub_ok(x, y);
  int exp = ref_tsub_ok(x, y);

  if (got != exp)
  {
    printf("[FAIL] x=%d y=%d  got=%d expected=%d\n",
           x, y, got, exp);
    exit(1);
  }
  else
  {
    printf("[PASS] x=%d y=%d\n", x, y);
  }
}

int main(void)
{
  int cases[][2] = {
      {0, 0},
      {1, 2},
      {-1, -2},
      {INT_MAX, 0},
      {INT_MIN, 0},
      {INT_MAX, -1}, // positive overflow
      {INT_MIN, 1},  // negative overflow
      {INT_MAX, INT_MIN},
      {INT_MIN, INT_MAX},
      {123456789, 987654321},
      {-123456789, -987654321},
      {100, -50},
      {-100, 50}};

  int n = sizeof(cases) / sizeof(cases[0]);

  for (int i = 0; i < n; i++)
    run_one(cases[i][0], cases[i][1]);

  puts("All tests passed");
  return 0;
}