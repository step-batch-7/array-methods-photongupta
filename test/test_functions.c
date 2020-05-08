#include "test.h"
#include <stdio.h>
#include <stdlib.h>

void test_create_array(Test_report_ptr test_watcher)
{
  NEW_LINE;
  describe("# CREATE_NODE");
  Array_ptr array = create_array(1);

  it("Should create an array: \n");
  assert_int(sizeof(array->array), 8, "should have an array pointer", test_watcher);
  assert_int(array->length, 0, "length should be zero", test_watcher);

  NEW_LINE;
}