#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

void copy_int(int val, void *buf, int maxbytes)
{
  if (maxbytes >= 0 && (size_t)maxbytes >= sizeof(val))
    memcpy(buf, (void *)&val, sizeof(val));
}

static int expected_copy(int maxbytes)
{
  return (maxbytes >= 0) && ((size_t)maxbytes >= sizeof(int));
}

static void dump_bytes(const uint8_t *p, size_t n)
{
  for (size_t i = 0; i < n; i++)
  {
    printf("%02X", p[i]);
    if (i + 1 != n)
      putchar(' ');
  }
}

static int buffer_changed(const uint8_t *p, size_t n, uint8_t pat)
{
  for (size_t i = 0; i < n; i++)
    if (p[i] != pat)
      return 1;
  return 0;
}

static void run_one(int val, int maxbytes)
{
  enum
  {
    N = 32
  };
  const uint8_t pat = 0xAA;
  uint8_t buf[N];

  memset(buf, pat, N);
  copy_int(val, buf, maxbytes);

  int exp = expected_copy(maxbytes);
  int changed = buffer_changed(buf, N, pat);
  int pass = (exp == changed);

  printf("[%s] maxbytes=%d  expected=%s  observed=%s  buf[0..7]=",
         pass ? "PASS" : "FAIL",
         maxbytes,
         exp ? "copy" : "no-copy",
         changed ? "copy" : "no-copy");

  dump_bytes(buf, 8);
  putchar('\n');

  if (!pass)
    exit(1);
}

int main(void)
{
  int vals[] = {0, 1, -1, 0x12345678, (int)0x80000000u};
  int maxs[] = {-5, -1, 0, 1, 2, 3, (int)sizeof(int) - 1, (int)sizeof(int), (int)sizeof(int) + 1, 8, 100};

  for (size_t i = 0; i < sizeof(vals) / sizeof(vals[0]); i++)
  {
    for (size_t j = 0; j < sizeof(maxs) / sizeof(maxs[0]); j++)
    {
      run_one(vals[i], maxs[j]);
    }
  }

  puts("All tests passed");
  return 0;
}