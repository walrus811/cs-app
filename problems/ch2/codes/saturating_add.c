#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <stdlib.h>

int saturating_add(int x, int y)
{
  int w = sizeof(int) << 3;
  int sum = x + y;

  int sign_x = x >> (w - 1);
  int sign_y = y >> (w - 1);
  int sign_sum = sum >> (w - 1);

  int positive_overflow = ~sign_x & ~sign_y & sign_sum;
  int negative_overflow = sign_x & sign_y & ~sign_sum;

  return (positive_overflow & INT_MAX) | (negative_overflow & INT_MIN) | (~positive_overflow & ~negative_overflow & sum);
}

static int ref_saturating_add(int x, int y)
{
  int64_t sum = (int64_t)x + (int64_t)y;
  if (sum > INT_MAX)
    return INT_MAX;
  if (sum < INT_MIN)
    return INT_MIN;
  return (int)sum;
}

static void run_one(int x, int y)
{
  int got = saturating_add(x, y);
  int exp = ref_saturating_add(x, y);

  if (got != exp)
  {
    printf("[FAIL] x=%d y=%d  got=%d  expected=%d\n",
           x, y, got, exp);
    exit(1);
  }
  else
  {
    printf("[PASS] x=%d y=%d  result=%d\n", x, y, got);
  }
}

int main(void)
{
  int tests[][2] = {
      {0, 0},
      {1, 2},
      {-1, -2},
      {INT_MAX, 0},
      {INT_MIN, 0},
      {INT_MAX, 1},
      {INT_MIN, -1},
      {INT_MAX, INT_MAX},
      {INT_MIN, INT_MIN},
      {INT_MAX, -1},
      {INT_MIN, 1},
      {123456789, 987654321},
      {-123456789, -987654321}};

  int n = sizeof(tests) / sizeof(tests[0]);

  for (int i = 0; i < n; i++)
    run_one(tests[i][0], tests[i][1]);

  puts("All tests passed");
  return 0;
}