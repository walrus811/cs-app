#include <stdio.h>
#include <limits.h>

int divide_power2(int x, int k)
{
  int w = sizeof(x) * 8;
  int msb_mask = x >> (w - 1);
  int bias = (msb_mask) & ((1 << k) - 1);
  return (x + bias) >> k;
}

int main(void)
{
  int test_values[] = {
      0, 1, -1,
      7, -7,
      8, -8,
      15, -15,
      16, -16,
      31, -31,
      32, -32,
      INT_MAX, INT_MIN};

  int ks[] = {0, 1, 2, 3, 4};

  int num_values = sizeof(test_values) / sizeof(test_values[0]);
  int num_ks = sizeof(ks) / sizeof(ks[0]);

  int failed = 0;

  for (int i = 0; i < num_values; i++)
  {
    for (int j = 0; j < num_ks; j++)
    {
      int x = test_values[i];
      int k = ks[j];
      if (k < sizeof(int) * 8 - 1)
      {
        int expected = x / (1 << k);
        int result = divide_power2(x, k);
        if (result != expected)
        {
          printf("FAIL x=%d k=%d expected=%d got=%d\n",
                 x, k, expected, result);
          failed = 1;
        }
      }
    }
  }

  if (!failed)
  {
    printf("All tests passed\n");
  }

  return 0;
}