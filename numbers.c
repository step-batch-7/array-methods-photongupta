#include "array_void.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Object sum(Object num1, Object num2)
{
  int sum = *(int *)num1 + *(int *)num2;
  Object result = malloc(sizeof(int));
  memcpy(result, &sum, sizeof(sum));
  return result;
}

void print_int(Object value)
{
  printf("%d ", *(int *)value);
}

void print_char(Object value)
{
  printf("%c ", *(int *)value);
}

int main(void)
{
  ArrayVoid_ptr int_list = create_void_array(3);
  int a[3] = {1, 2, 3};
  int_list->array[0] = a;
  int_list->array[1] = a + 1;
  int_list->array[2] = a + 2;
  int_list->length = 3;
  Display displayer = &print_int;
  printf("Given list :");
  print_void_array(int_list, displayer);
  NEW_LINE;

  printf("sum :");
  ReducerVoid reducer = &sum;
  Object context = malloc(sizeof(int));
  Object sum = reduce_void(int_list, context, reducer);
  print_int(sum);
  NEW_LINE;

  return 0;
}