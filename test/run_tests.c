#include "test.h"
#include <stdio.h>

Test_report_ptr run_tests(Test_report_ptr test_watcher)
{
  test_create_array(test_watcher);
  return test_watcher;
}

void print(Test_report_ptr test_report)
{
  int total = test_report->total;
  int passed = test_report->passed;
  int failed = test_report->failed;
  printf("\n_____________REPORT_____________\n\n");
  printf("✅ Passed :\t%02d \t %.1f%% \n", passed, percentage(total, passed));
  printf("❌ Failed :\t%02d \t %.1f%% \n", failed, percentage(total, failed));
  printf("\n* Total tests : %d\n", total);
}

int main(void)
{
  Test_report_ptr test_watcher, test_report;
  test_watcher->failed = 0;
  test_watcher->passed = 0;
  test_watcher->total = 0;

  printf("Testing start.............\n");
  test_report = run_tests(test_watcher);
  printf(".............Testing end\n");

  print(test_report);
  return 0;
}