#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef unsigned float_bits;

float_bits float_absval(float_bits f)
{
  unsigned exp = (f >> 23) & 0xFF;
  unsigned frac = f & 0x7FFFFF;

  unsigned is_nan = !(exp ^ 0xFF) & !!frac;
  unsigned mask = -is_nan;

  return (mask & f) | (~mask & ((f << 1) >> 1));
}

static float u2f(unsigned x)
{
  float f;
  memcpy(&f, &x, sizeof(f));
  return f;
}

static unsigned f2u(float f)
{
  unsigned x;
  memcpy(&x, &f, sizeof(x));
  return x;
}

static int is_nan_bits(unsigned x)
{
  unsigned exp = (x >> 23) & 0xFF;
  unsigned frac = x & 0x7FFFFF;
  return (exp == 0xFF) && (frac != 0);
}

static unsigned expected_float_abs(unsigned uf)
{
  if (is_nan_bits(uf))
    return uf;
  return uf & 0x7FFFFFFF;
}

int main(void)
{
  unsigned x = 0;
  int pass = 1;

  unsigned last_input = 0;
  unsigned last_got = 0;
  unsigned last_expect = 0;

  do
  {
    unsigned got = float_absval(x);
    unsigned exp = expected_float_abs(x);

    if (got != exp)
    {
      pass = 0;
      last_input = x;
      last_got = got;
      last_expect = exp;
    }

    x++;
  } while (x != 0);

  if (pass)
  {
    printf("PASS\n");
  }
  else
  {
    printf("FAIL\n");
    printf("last input : 0x%08X\n", last_input);
    printf("got        : 0x%08X\n", last_got);
    printf("expected   : 0x%08X\n", last_expect);
  }

  return 0;
}