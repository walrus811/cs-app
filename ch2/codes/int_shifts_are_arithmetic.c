#include <stdio.h>

int int_shifts_are_arithmetic()
{
  int shifted = -1 >> 1;
  return !(shifted ^ -1);
}

int main()
{
  printf("%d\n", int_shifts_are_arithmetic());
  return 0;
}