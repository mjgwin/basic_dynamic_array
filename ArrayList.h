#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_STARTING_CAPACITY 5

typedef struct ArrayList{
  int size;
  int capacity;
  void **data;

} ArrayList;

ArrayList *array_list_create();

void array_list_add(ArrayList *list, void *element);

void array_list_remove(ArrayList *list, int index);

void *array_list_get(ArrayList *list, int index);

void array_list_delete(ArrayList *list);
