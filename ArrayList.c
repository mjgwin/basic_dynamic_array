#include "ArrayList.h"


ArrayList *array_list_create(){
  ArrayList *list = (ArrayList *)malloc(sizeof(ArrayList));
  list->size = 0;
  list->capacity = DEFAULT_STARTING_CAPACITY;

  list->data = (void **)malloc(sizeof(void *) * list->capacity);

  return list;
}


void array_list_add(ArrayList *list, void *element){
  if(list->size == list->capacity){
    list->capacity *= 2;
    list->data = (void **)realloc(list->data, sizeof(void *) * list->capacity);
  }
  
  list->data[list->size] = element;
  list->size++;
}


void array_list_remove(ArrayList *list, int index){
  if(index >= list->size){
    return;
  }
  if(index + 1 == list->size){
    list->data[index] = NULL;
    list->size--;
    return;
  }else{
    int i;
    for(i = index + 1; i < list->size; i++){
      list->data[i-1] = list->data[i];
    }
    list->data[list->size - 1] = NULL;
  }
  list->size--;
}


void *array_list_get(ArrayList *list, int index){
  if(index > list->size){
    return NULL;
  }else{
    return list->data[index];
  }
}


void array_list_delete(ArrayList *list){
  free(list->data);
  free(list);
}
