#include "array.h"
#include <stdio.h>

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
  Array_ptr user_data = create_array(6);
  user_data->array[0] = 1;
  user_data->array[1] = 2;
  user_data->array[2] = 3;
  user_data->array[3] = 4;
  user_data->array[4] = 5;
  user_data->length = 5;
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