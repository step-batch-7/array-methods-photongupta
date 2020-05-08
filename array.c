#include "array.h"
#include <stdio.h>
#include <stdlib.h>

Array_ptr create_array(int length)
{
  Array_ptr array = malloc(sizeof(Array));
  array->array = malloc(length * sizeof(int));
  array->length = 0;
  return array;
}

Array_ptr get_copy(Array_ptr src)
{

  Array_ptr copy_of_src = create_array(src->length);
  for (int i = 0; i < src->length; i++)
  {
    copy_of_src->array[copy_of_src->length] = src->array[i];
    copy_of_src->length += 1;
  }
  return copy_of_src;
}

Array_ptr map(Array_ptr src, Mapper mapper)
{
  Array_ptr mapped_list = create_array(src->length);
  for (int index = 0; index < src->length; index++)
  {
    mapped_list->array[index] = mapper(src->array[index]);
    mapped_list->length++;
  }
  return mapped_list;
}

Array_ptr filter(Array_ptr src, Predicate predicate)
{
  Array_ptr filtered_list = create_array(src->length);
  for (int index = 0; index < src->length; index++)
  {
    if (predicate(src->array[index]))
    {
      filtered_list->array[filtered_list->length] = src->array[index];
      filtered_list->length += 1;
    }
  }
  return get_copy(filtered_list);
}

int reduce(Array_ptr src, int context, Reducer reducer)
{
  int result = context;
  for (int index = 0; index < src->length; index++)
  {
    result = reducer(result, src->array[index]);
  }
  return result;
}

void print_array(Array_ptr src)
{
  NEW_LINE;
  for (int i = 0; i < src->length; i++)
  {
    printf("%d ", src->array[i]);
  }
}
