#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

unsigned srl(unsigned x, int k);
int sra(int x, int k);

/* reference for srl */
static unsigned ref_srl(unsigned x, int k)
{
  return x >> k;
}

int main()
{
  int w = sizeof(int) * 8;
  int errors = 0;

  srand((unsigned)time(NULL));

  unsigned test_vals[] = {
      0,
      1,
      0xFFFFFFFFu,
      0x80000000u,
      0x7FFFFFFFu,
      0x12345678u,
      0x87654321u};

  int num_vals = sizeof(test_vals) / sizeof(test_vals[0]);

  /* ========================= */
  /*        SRL TESTS          */
  /* ========================= */

  /* 1️⃣ deterministic test */
  for (int i = 0; i < num_vals; i++)
  {
    for (int k = 0; k < w; k++)
    {
      unsigned x = test_vals[i];

      unsigned ref = ref_srl(x, k);
      unsigned got = srl(x, k);

      if (ref != got)
      {
        printf("SRL ERROR: x=0x%08x k=%d ref=0x%08x got=0x%08x\n",
               x, k, ref, got);
        errors++;
      }
    }
  }

  /* 2️⃣ random test */
  for (int i = 0; i < 100000; i++)
  {
    unsigned x = ((unsigned)rand() << 16) ^ rand();
    int k = rand() % w;

    unsigned ref = ref_srl(x, k);
    unsigned got = srl(x, k);

    if (ref != got)
    {
      printf("SRL RANDOM ERROR: x=0x%08x k=%d ref=0x%08x got=0x%08x\n",
             x, k, ref, got);
      errors++;
      break;
    }
  }

  if (errors == 0)
    printf("All srl tests passed!\n");
  else
    printf("Total srl errors: %d\n", errors);

  /* ========================= */
  /*        SRA TESTS          */
  /* ========================= */

  errors = 0;

  /* 1️⃣ deterministic test */
  for (int i = 0; i < num_vals; i++)
  {
    for (int k = 0; k < w; k++)
    {
      int x = (int)test_vals[i];

      int ref = x >> k; /* arithmetic */
      int got = sra(x, k);

      if (ref != got)
      {
        printf("SRA ERROR: x=0x%08x k=%d ref=0x%08x got=0x%08x\n",
               x, k, ref, got);
        errors++;
      }
    }
  }

  /* 2️⃣ random test */
  for (int i = 0; i < 100000; i++)
  {
    int x = ((unsigned)rand() << 16) ^ rand();
    int k = rand() % w;

    int ref = x >> k;
    int got = sra(x, k);

    if (ref != got)
    {
      printf("SRA RANDOM ERROR: x=0x%08x k=%d ref=0x%08x got=0x%08x\n",
             x, k, ref, got);
      errors++;
      break;
    }
  }

  if (errors == 0)
    printf("All sra tests passed!\n");
  else
    printf("Total sra errors: %d\n", errors);

  return 0;
}

unsigned srl(unsigned x, int k)
{
  /* Perform shift arithmetically */
  unsigned xsra = (int)x >> k;
  unsigned w = sizeof(unsigned) * 8;
  /* In x86 and AArch64, the right-shift operation is performed modulo w.
   * Therefore, Applying a right shift by w results in no change.
   */
  unsigned mask = ~(((unsigned)-1 << (w - k - 1)) << 1);

  return xsra & mask;
}

int sra(int x, int k)
{
  /* Perform shift logically */
  int xsrl = (unsigned)x >> k;
  unsigned w = sizeof(unsigned) * 8;

  unsigned sign = 0u - !!(x & INT_MIN);
  unsigned mask = sign << (w - k - 1);
  return xsrl | mask;
}