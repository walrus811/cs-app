#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef unsigned float_bits;

static int is_nan_bits(unsigned x)
{
  unsigned exp = (x >> 23) & 0xFF;
  unsigned frac = x & 0x7FFFFF;
  return (exp == 0xFF) && (frac != 0);
}

float_bits float_twice(float_bits f)
{
  if (is_nan_bits(f))
    return f;

  unsigned sign = f & 0x80000000;
  unsigned exp = (f >> 23) & 0xFF;
  unsigned frac = f & 0x7FFFFF;

  unsigned is_special = !(exp ^ 0xFF);
  unsigned special_mask = -is_special;

  unsigned is_denorm = !exp;
  unsigned denorm_mask = -is_denorm;

  unsigned is_overflow = !((exp + 1) ^ 0xFF);
  unsigned overflow_mask = -is_overflow;

  unsigned normal_frac = ~overflow_mask & frac;

  unsigned special_result = f;
  unsigned denorm_result = sign | (frac << 1);
  unsigned normal_result = sign | ((exp + 1) << 23) | normal_frac;

  return (special_mask & special_result) | (~special_mask & denorm_mask & denorm_result) | (~special_mask & ~denorm_mask & normal_result);
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

static unsigned expected_float_twice(unsigned uf)
{
  if (is_nan_bits(uf))
    return uf;
  return f2u(2.0f * u2f(uf));
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
    unsigned got = float_twice(x);
    unsigned exp = expected_float_twice(x);

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