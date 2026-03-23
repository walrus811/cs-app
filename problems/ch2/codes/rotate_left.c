#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <assert.h>

unsigned rotate_left(unsigned x, int n);

static unsigned ref_rotate_left(unsigned x, int n)
{
  int w = (int)(sizeof(unsigned) << 3);
  assert(0 <= n && n < w);
  if (n == 0)
    return x;
  return (x << n) | (x >> (w - n));
}

static void test_one(unsigned x, int n)
{
  unsigned got = rotate_left(x, n);
  unsigned exp = ref_rotate_left(x, n);
  if (got != exp)
  {
    int w = (int)(sizeof(unsigned) << 3);
    printf("FAIL: x=0x%08X n=%d (w=%d) got=0x%08X exp=0x%08X\n",
           x, n, w, got, exp);
    exit(1);
  }
}

int main(void)
{
  int w = (int)(sizeof(unsigned) << 3);
  printf("Running tests (w=%d)\n", w);

  test_one(0u, 0);
  test_one(~0u, 0);
  test_one(1u, 0);
  test_one(1u, 1);
  test_one(1u, w - 1);

  if (w == 32)
  {
    test_one(0x12345678u, 4);
    test_one(0x12345678u, 20);
  }

  for (int n = 0; n < w; n++)
  {
    test_one(0u, n);
    test_one(~0u, n);
    test_one(0x80000000u, n);
    test_one(0x7FFFFFFFu, n);
  }

  srand((unsigned)time(NULL));
  for (int i = 0; i < 200000; i++)
  {
    unsigned x = ((unsigned)rand() << 16) ^ (unsigned)rand();
    int n = rand() % w;
    test_one(x, n);
  }

  printf("ALL PASS\n");
  return 0;
}

unsigned rotate_left(unsigned x, int n)
{
  int w = sizeof(unsigned) << 3;
  return (x << n) | ((x >> (w - 1 - n)) >> 1);
}