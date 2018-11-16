#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  printf("\n\ninside get_indicies_of_item_weights\n\n");

  Answer *ans;
  
  printf("length = %d\n", length);
  if (length == 1){
    printf("returning NULL");
    return NULL;
  }

  HashTable *ht = create_hash_table(16);
  //store limit - key as value 
  for(int i = 0; i < length; i++){
    printf(" i = %d\n", i);
    printf(" weights[i] = %d\n", weights[i]);
    hash_table_insert(ht, weights[i], i);
  }

  for(int j = 0; j < length; j++){
    printf(" length = %d\n", length);    
    printf(" j = %d\n", j);
    printf(" weights[j] = %d\n", weights[j]);
    int searchFor = limit - weights[j];
    if (ht->storage[searchFor]){
      //these might need to be reversed or checked
      ans->index_1 = weights[j];
      ans->index_2 = ht->storage[searchFor]->key;
      return ans;
      //this is also producing a memory leak
    } else {
      return NULL;
    }
  }
}

void print_answer(Answer *answer)
{
  if (answer != NULL) {
    printf("%d %d\n", answer->index_1, answer->index_2);
  } else {
    printf("NULL\n");
  }
}

#ifndef TESTING

int main(void)
{
  int weights_4[] = {12, 6, 7, 14, 19, 3, 0, 25, 40};

  Answer* answer_4 = get_indices_of_item_weights(weights_4, 9, 7);

  if (answer_4->index_1 != 6)
    printf("Your function did not return the expected answer for input {12, 6, 7, 14, 19, 3, 0, 25, 40}");
  if (answer_4->index_2 != 2)
    printf("Your function did not return the expected answer for input {12, 6, 7, 14, 19, 3, 0, 25, 40}");

  return 0;
}
#endif