#include "test.h"
#include <stdio.h>

void describe(Char_ptr message)
{
  NEW_LINE;
  printf("%s", message);
  NEW_LINE;
}

void it(Char_ptr message)
{
  NEW_LINE;
  printf("%s", message);
}

void print_status(int status, Test_report_ptr test_watcher)
{
  if (status)
  {
    test_watcher->passed++;
    printf("✅ ");
  }
  else
  {
    test_watcher->failed++;
    printf("❌ ");
  }
  test_watcher->total++;
}

void assert_int(int actual, int expected, Char_ptr message, Test_report_ptr test_watcher)
{
  print_status(actual == expected, test_watcher);
  printf("%s", message);
  NEW_LINE;
}

float percentage(int total, int value)
{
  return (100 * value) / total;
}