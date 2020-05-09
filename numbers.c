#include "array_void.h"
#include <stdio.h>
#include <string.h>

Bool is_even(Object value)
{
  return !(*(int *)value % 2);
}

Bool is_capital(Object value)
{
  return (*(char *)value >= 65) && (*(char *)value <= 90);
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
  int a = 2;
  int b = 3;
  int c = 4;
  int_list->array[0] = &a;
  int_list->array[1] = &b;
  int_list->array[2] = &c;
  int_list->length = 3;
  Display displayer = &print_int;
  printf("Given list :");
  print_void_array(int_list, displayer);
  NEW_LINE;

  printf("Even list :");
  PredicateVoid predicate = &is_even;
  ArrayVoid_ptr even_list = filter_void(int_list, predicate);
  print_void_array(even_list, displayer);
  NEW_LINE;

  ArrayVoid_ptr char_list = create_void_array(3);
  char a2 = 'A';
  char b2 = 'm';
  char c2 = 'K';
  char_list->array[0] = &a2;
  char_list->array[1] = &b2;
  char_list->array[2] = &c2;
  char_list->length = 3;
  displayer = &print_char;

  printf("Given list :");
  print_void_array(char_list, displayer);
  NEW_LINE;

  printf("Capital letters :");
  predicate = &is_capital;
  ArrayVoid_ptr capital_letters = filter_void(char_list, predicate);
  print_void_array(capital_letters, displayer);
  NEW_LINE;

  return 0;
}