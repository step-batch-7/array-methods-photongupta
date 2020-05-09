#include "array_void.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Object add_one(Object value)
{
  int incremented_value = (*(int *)value + 1);
  Object new_value = malloc(sizeof(int));
  memcpy(new_value, &incremented_value, sizeof(incremented_value));
  return new_value;
}

Object to_upper_case(Object value)
{
  char val = *(char *)value;
  char in_upper_case = val >= 97 && val <= 122 ? val - 32 : val;
  Object new_value = malloc(sizeof(char));
  memcpy(new_value, &in_upper_case, sizeof(in_upper_case));
  return new_value;
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

  printf("Mapped list :");
  MapperVoid mapper = &add_one;
  ArrayVoid_ptr mapped_list = map_void(int_list, mapper);
  print_void_array(mapped_list, displayer);
  NEW_LINE;

  ArrayVoid_ptr char_list = create_void_array(3);
  char a2[3] = {'a', 'b', 'z'};
  char_list->array[0] = a2;
  char_list->array[1] = a2 + 1;
  char_list->array[2] = a2 + 2;
  char_list->length = 3;
  displayer = &print_char;

  printf("Given list :");
  print_void_array(char_list, displayer);
  NEW_LINE;

  printf("List in capital letters :");
  mapper = &to_upper_case;
  ArrayVoid_ptr capital_letters = map_void(char_list, mapper);
  print_void_array(capital_letters, displayer);
  NEW_LINE;

  return 0;
}