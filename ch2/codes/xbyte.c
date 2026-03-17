#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint32_t packed_t;

int xbyte(packed_t word, int bytenum)
{
  int shiftBits = (3 - bytenum) * 8;
  return ((int)word << shiftBits) >> 24;
}

int ref_xbyte(packed_t word, int bytenum)
{
  int8_t b = (word >> (bytenum * 8)) & 0xFF;
  return (int)b;
}

void test_one(packed_t word)
{
  for (int i = 0; i < 4; i++)
  {
    int r1 = xbyte(word, i);
    int r2 = ref_xbyte(word, i);
    if (r1 != r2)
    {
      printf("Mismatch: word=0x%08X byte=%d got=%d expected=%d\n",
             word, i, r1, r2);
      exit(1);
    }
  }
}

int main()
{
  packed_t tests[] = {
      0x00000000,
      0xFFFFFFFF,
      0x7F000000,
      0x80000000,
      0x12345678,
      0x87654321,
      0x00FF00FF,
      0xFF00FF00};

  for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    test_one(tests[i]);

  for (int i = 0; i < 100000; i++)
  {
    packed_t w = ((packed_t)rand() << 16) ^ rand();
    test_one(w);
  }

  printf("All tests passed\n");
  return 0;
}