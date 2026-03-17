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

int threefourths(int x)
{
  // x = 4q + r
  int q = divide_power2(x, 2);
  int r = x - (q << 2);

  int q_result = (q << 1) + q;
  int r_result = divide_power2((r << 1) + r, 2);

  return q_result + r_result;
}

static int32_t ref_threefourths(int32_t x)
{
  int64_t t = (int64_t)x * 3;
  return (int32_t)(t / 4);
}

static void check_one(int32_t x, int *failed)
{
  int32_t expected = ref_threefourths(x);
  int32_t got = threefourths(x);

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
      63, -63, 64, -64,
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