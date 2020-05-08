#ifndef __ARRAY_H
#define __ARRAY_H

#define NEW_LINE printf("\n")

typedef enum
{
  False,
  True
} Bool;

typedef int (*Mapper)(int);
typedef Bool (*Predicate)(int);
typedef int (*Reducer)(int, int);

typedef int *Int_ptr;

typedef struct
{
  Int_ptr array;
  int length;
} Array;

typedef Array *Array_ptr;

Array_ptr create_array(int length);
void print_array(Array_ptr src);

Array_ptr map(Array_ptr src, Mapper mapper);
Array_ptr filter(Array_ptr src, Predicate predicate);
int reduce(Array_ptr src, int init, Reducer reducer);

#endif
