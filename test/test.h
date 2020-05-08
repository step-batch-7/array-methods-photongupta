#ifndef __TEST_H
#define __TEST_H

#include "../array.h"
typedef char *Char_ptr;

typedef struct Test_report{
 int passed;
 int failed;
 int total;
} Test_report;

typedef Test_report * Test_report_ptr;

void it(Char_ptr);
void describe(Char_ptr);
void assert_int(int,int,Char_ptr,Test_report_ptr);
void assert_ok(int,Char_ptr,Test_report_ptr);
float percentage(int,int);

void test_create_array(Test_report_ptr test_watcher);
void test_filter(Test_report_ptr test_watcher);
void test_map(Test_report_ptr test_watcher);
void test_reduce(Test_report_ptr test_watcher);

Test_report_ptr run_tests(Test_report_ptr);

#endif