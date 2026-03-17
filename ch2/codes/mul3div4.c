#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int divide_power2(int x, int k)
{
  int w = sizeof(x) * 8;
  int msb_mask = x >> (w - 1);
  int bias = (msb_mask) & ((1 << k) - 1);
  return (x + bias) >> k;
}

int mul3div4(int x)
{
  int mul = (x << 1) + x;
  return divide_power2(mul, 2);
}

static int32_t ref_mul3div4(int32_t x)
{
  uint32_t ux = (uint32_t)x;
  uint32_t uprod = ux * 3u;
  int32_t prod = (int32_t)uprod;
  return prod / 4;
}

static void check_one(int32_t x, int *failed)
{
  int32_t expected = ref_mul3div4(x);
  int32_t got = mul3div4(x);

  if (got != expected)
  {
    printf("FAIL x=%d expected=%d got=%d\n",
           (int)x, (int)expected, (int)got);
    *failed = 1;
  }
}

int main(void)
{
  int failed = 0;

  int32_t fixed[] = {
      0, 1, -1, 2, -2, 3, -3,
      4, -4, 7, -7, 8, -8,
      15, -15, 16, -16,
      31, -31, 32, -32,
      INT_MAX, INT_MIN,
      INT_MAX - 1, INT_MIN + 1};

  int nfixed = sizeof(fixed) / sizeof(fixed[0]);
  for (int i = 0; i < nfixed; i++)
    check_one(fixed[i], &failed);

  srand((unsigned)time(NULL));
  for (int i = 0; i < 200000; i++)
  {
    uint32_t r = ((uint32_t)rand() << 16) ^ (uint32_t)rand();
    int32_t x = (int32_t)r;
    check_one(x, &failed);
  }

  if (!failed)
    printf("All tests passed\n");

  return failed ? 1 : 0;
}