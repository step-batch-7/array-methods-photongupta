#include "array_void.h"
#include <stdio.h>
#include <stdlib.h>

ArrayVoid_ptr create_void_array(int length)
{
  ArrayVoid_ptr array = malloc(sizeof(ArrayVoid));
  array->array = malloc(length * sizeof(Object));
  array->length = 0;
  return array;
}

ArrayVoid_ptr get_void_copy(ArrayVoid_ptr src)
{

  ArrayVoid_ptr copy_of_src = create_void_array(src->length);
  for (int i = 0; i < src->length; i++)
  {
    copy_of_src->array[copy_of_src->length] = src->array[i];
    copy_of_src->length += 1;
  }
  return copy_of_src;
}

ArrayVoid_ptr filter_void(ArrayVoid_ptr src, PredicateVoid predicate)
{
  ArrayVoid_ptr filtered_list = create_void_array(src->length);
  for (int index = 0; index < src->length; index++)
  {
    if (predicate(src->array[index]))
    {
      filtered_list->array[filtered_list->length] = src->array[index];
      filtered_list->length += 1;
    }
  }
  return get_void_copy(filtered_list);
}

void print_void_array(ArrayVoid_ptr src, Display displayer)
{
  NEW_LINE;
  for (int i = 0; i < src->length; i++)
  {
    (*displayer)(src->array[i]);
  }
}