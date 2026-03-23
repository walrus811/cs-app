#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <string.h>

void *my_calloc(size_t nmemb, size_t size)
{
  if (nmemb == 0 || size == 0)
    return NULL;

  if (nmemb > SIZE_MAX / size)
    return NULL;

  size_t to_allocate = nmemb * size;

  void *result = malloc(to_allocate);
  if (result == NULL)
    return NULL;

  memset(result, 0, to_allocate);
  return result;
}

static void die(const char *msg)
{
  fprintf(stderr, "FAIL: %s\n", msg);
  exit(1);
}

static void ok(const char *msg)
{
  printf("OK  : %s\n", msg);
}

static int mul_overflow_size_t(size_t a, size_t b)
{
  if (a == 0 || b == 0)
    return 0;
  if (a > SIZE_MAX / b)
    return 1;
  return 0;
}

static void test_zero_args(void)
{
  if (my_calloc(0, 10) != NULL)
    die("calloc(0, x) must return NULL");
  if (my_calloc(10, 0) != NULL)
    die("calloc(x, 0) must return NULL");
  ok("zero arguments");
}

static void test_small_allocation(void)
{
  size_t n = 16;
  int *p = my_calloc(n, sizeof(int));
  if (!p)
    die("small allocation returned NULL");
  for (size_t i = 0; i < n; i++)
  {
    if (p[i] != 0)
      die("memory not zero-initialized");
  }
  free(p);
  ok("small allocation zero-init");
}

static void test_large_allocation(void)
{
  size_t n = 1024;
  size_t sz = 1024;
  if (mul_overflow_size_t(n, sz))
    die("unexpected overflow in test");
  unsigned char *p = my_calloc(n, sz);
  if (!p)
    die("large allocation returned NULL");
  for (size_t i = 0; i < n * sz; i++)
  {
    if (p[i] != 0)
      die("large memory not zero-initialized");
  }
  free(p);
  ok("large allocation zero-init");
}

static void test_overflow(void)
{
  size_t n = SIZE_MAX / 2 + 1;
  size_t sz = 2;
  if (!mul_overflow_size_t(n, sz))
    die("overflow test invalid");
  void *p = my_calloc(n, sz);
  if (p != NULL)
    die("overflow case must return NULL");
  ok("overflow handling");
}

int main(void)
{
  test_zero_args();
  test_small_allocation();
  test_large_allocation();
  test_overflow();
  printf("\nAll tests passed.\n");
  return 0;
}