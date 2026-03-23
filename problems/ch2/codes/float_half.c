#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef unsigned float_bits;

float_bits float_half(float_bits f){
  
}

static int is_nan_bits(unsigned x)
{
  unsigned exp = (x >> 23) & 0xFF;
  unsigned frac = x & 0x7FFFFF;
  return (exp == 0xFF) && (frac != 0);
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

static unsigned expected_float_half(unsigned uf)
{
  if (is_nan_bits(uf))
    return uf;
  return f2u(0.5f * u2f(uf));
}

int main(void)
{
  unsigned x = 0;
  int pass = 1;

  unsigned fail_input = 0;
  unsigned fail_got = 0;
  unsigned fail_expected = 0;

  do
  {
    unsigned got = float_half(x);
    unsigned expected = expected_float_half(x);

    if (got != expected)
    {
      pass = 0;
      fail_input = x;
      fail_got = got;
      fail_expected = expected;
      break;
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
    printf("input    : 0x%08X\n", fail_input);
    printf("got      : 0x%08X\n", fail_got);
    printf("expected : 0x%08X\n", fail_expected);
  }

  return 0;
}