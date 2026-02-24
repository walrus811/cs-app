#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

int lower_one_mask(int n);

static unsigned ref_lower_one_mask(int n)
{
  int w = (int)(sizeof(unsigned) * CHAR_BIT);
  assert(1 <= n && n <= w);
  if (n == w)
    return ~0u;
  return (1u << n) - 1u;
}

static void test_one(int n)
{
  unsigned got = (unsigned)lower_one_mask(n);
  unsigned exp = ref_lower_one_mask(n);

  if (got != exp)
  {
    int w = (int)(sizeof(unsigned) * CHAR_BIT);
    printf("FAIL: n=%d (w=%d) got=0x%08X exp=0x%08X\n", n, w, got, exp);
    exit(1);
  }
}

int main(void)
{
  int w = (int)(sizeof(unsigned) * CHAR_BIT);
  printf("Running tests (w=%d)\n", w);

  test_one(1);
  test_one(2);
  test_one(3);
  test_one(6);
  if (w >= 17)
    test_one(17);
  test_one(w - 1);
  test_one(w);
  for (int n = 1; n <= w; n++)
    test_one(n);

  srand((unsigned)time(NULL));
  for (int i = 0; i < 10000; i++)
  {
    int n = (rand() % w) + 1;
    test_one(n);
  }

  printf("ALL PASS\n");
  return 0;
}

int lower_one_mask(int n)
{
  int w = sizeof(int) << 3;
  return (int)(~0u >> (w - n));
}