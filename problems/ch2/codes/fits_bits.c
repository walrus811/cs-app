#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int fits_bits(int x, int n);

static int ref_fits_bits(int x, int n)
{
  int w = (int)(sizeof(int) << 3);
  if (n < 1 || n > w)
    return 0;
  if (n == w)
    return 1;
  int min = -(1 << (n - 1));
  int max = (1 << (n - 1)) - 1;
  return x >= min && x <= max;
}

static void test_one(int x, int n)
{
  int got = fits_bits(x, n);
  int exp = ref_fits_bits(x, n);
  if (got != exp)
  {
    int w = (int)(sizeof(int) << 3);
    printf("FAIL: x=%d (0x%08X) n=%d (w=%d) got=%d exp=%d\n",
           x, (unsigned)x, n, w, got, exp);
    exit(1);
  }
}

int main(void)
{
  int w = (int)(sizeof(int) << 3);
  printf("Running tests (w=%d)\n", w);

  for (int n = 1; n <= w; n++)
  {
    test_one(0, n);
    test_one(1, n);
    test_one(-1, n);
  }

  test_one(INT_MAX, w);
  test_one(INT_MIN, w);

  for (int n = 1; n <= w; n++)
  {
    if (n == w)
      continue;
    int min = -(1 << (n - 1));
    int max = (1 << (n - 1)) - 1;

    test_one(min, n);
    test_one(max, n);

    test_one(min - 1, n);
    test_one(max + 1, n);
  }

  srand((unsigned)time(NULL));
  for (int i = 0; i < 200000; i++)
  {
    int x = (int)(((unsigned)rand() << 16) ^ (unsigned)rand());
    int n = (rand() % w) + 1;
    test_one(x, n);
  }

  printf("ALL PASS\n");
  return 0;
}

int fits_bits(int x, int n)
{
  int w = sizeof(int) << 3;
  int shift = w - n;
  return (x << shift >> shift) == x;
}