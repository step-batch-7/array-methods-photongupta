#include "../array_void.h"
#include "test.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test_create_array(Test_report_ptr test_watcher)
{
  NEW_LINE;
  describe("# CREATE_ARRAY");
  Array_ptr array = create_array(1);

  it("Should create an array: \n");
  assert_int(sizeof(array->array), 8, "should have an array pointer", test_watcher);
  assert_int(array->length, 0, "length should be zero", test_watcher);
  NEW_LINE;
}

Bool is_even(int value)
{
  return !(value % 2);
}
void test_filter(Test_report_ptr test_watcher)
{
  describe("# FILTER");
  int sample_data[5] = {10, 11, 6, 9, 5};
  int length = sizeof(sample_data) / sizeof(int);
  Array_ptr array1 = create_array(length);
  array1->length = length;
  memcpy(array1->array, sample_data, sizeof(sample_data));

  it("Should give all the even numbers of the list : \n");
  Array_ptr even_list1 = filter(array1, &is_even);
  assert_int(even_list1->array[0], 10, "number should be even", test_watcher);
  assert_int(even_list1->array[1], 6, "number should be even", test_watcher);
  assert_int(even_list1->length, 2, "count should be equal to the number of evens in the list", test_watcher);

  Array_ptr array2 = create_array(0);

  it("Should give the empty array if no element is even: \n");
  Array_ptr even_list2 = filter(array2, &is_even);
  assert_int(even_list2->length, 0, "length should be 0", test_watcher);

  it("Should give the empty array if input is empty array: \n");
  Array_ptr even_list3 = filter(array2, &is_even);
  assert_int(even_list3->length, 0, "length should be 0", test_watcher);

  NEW_LINE;
}

int add_one(int value)
{
  return value + 1;
}

void test_map(Test_report_ptr test_watcher)
{
  describe("# MAP");
  int sample_data[3] = {10, 11, 6};
  int length = sizeof(sample_data) / sizeof(int);
  Array_ptr array1 = create_array(length);
  array1->length = length;
  memcpy(array1->array, sample_data, sizeof(sample_data));

  it("Should add one in all elements of the list : \n");
  Array_ptr mapped_list1 = map(array1, &add_one);
  assert_int(mapped_list1->array[0], 11, "number should be increased by", test_watcher);
  assert_int(mapped_list1->array[1], 12, "number should be increased by", test_watcher);
  assert_int(mapped_list1->array[2], 7, "number should be increased by", test_watcher);
  assert_int(mapped_list1->length, 3, "count should be equal to the number of element in the list", test_watcher);

  Array_ptr array2 = create_array(0);
  it("Should give the empty array if input is empty array: \n");
  Array_ptr mapped_list2 = map(array2, &add_one);
  assert_int(mapped_list2->length, 0, "length should be 0", test_watcher);

  NEW_LINE;
}

int sum(int num1, int num2)
{
  return num1 + num2;
}

void test_reduce(Test_report_ptr test_watcher)
{
  describe("# REDUCE");
  int sample_data[3] = {1, 2, 3};
  int length = sizeof(sample_data) / sizeof(int);
  Array_ptr array1 = create_array(length);
  array1->length = length;
  memcpy(array1->array, sample_data, sizeof(sample_data));

  it("Should add all the numbers in the list : \n");
  int result1 = reduce(array1, 0, &sum);
  assert_int(result1, 6, "should give the sum of all the numbers of the array", test_watcher);

  Array_ptr array2 = create_array(0);
  it("Should give the context if input is empty array: \n");
  int result2 = reduce(array2, 0, &sum);
  assert_int(result2, 0, "should return the context if array is empty", test_watcher);

  NEW_LINE;
}
