#include "array.h"
#include <stdio.h>
#include <string.h>

int add_one(int value)
{
  return value + 1;
}

Bool is_even(int value)
{
  return !(value % 2);
}

int sum(int num1, int num2)
{
  return num1 + num2;
}

int main(void)
{
  int sample_data[5] = {10, 2, 6, 4, 5};
  int length = sizeof(sample_data) / sizeof(int);
  Array_ptr user_data = create_array(length);
  user_data->length = length;
  memcpy(user_data->array, sample_data, sizeof(sample_data));

  printf("Given list :");
  print_array(user_data);
  NEW_LINE;

  printf("Mapped list(add one):");
  Array_ptr mapped_list = map(user_data, &add_one);
  print_array(mapped_list);
  NEW_LINE;

  printf("Even list :");
  Array_ptr even_list = filter(user_data, &is_even);
  print_array(even_list);
  NEW_LINE;

  printf("Sum of all numbers in the list :\n");
  int result = reduce(user_data, 0, &sum);
  printf("%d", result);
  NEW_LINE;

  return 0;
}