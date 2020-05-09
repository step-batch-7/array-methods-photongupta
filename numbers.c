#include "array_void.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_int(Object value)
{
  printf("%d ", *(Int_ptr)value);
}

void print_char(Object value)
{
  printf("%c ", *(Int_ptr)value);
}

int main(void)
{

  return 0;
}