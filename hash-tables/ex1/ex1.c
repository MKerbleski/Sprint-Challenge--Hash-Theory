#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);
  printf("\n\ninside\n\n");
  //store limit - key as value 
  for(int i = 0; i < length; i++){
    printf(" i = %d\n", i);
    hash_table_insert(ht, weights[i], i);
  }
  
  //given parameters 
  // find 2 items whose combined weights equal weight limit 4+6 = 10

  for(int j = 0; j < length; j++){
    int searchFor = limit - weights[j];
    if (ht->storage[searchFor]){
      //these might need to be reversed or checked
      return create_answer(weights[j], ht->storage[searchFor]);
      //this is also producing a memory leak
    } else {
      return NULL;
    }
  }

  //return Answer struct of 
    //int weight 1
    //int weight 2

  // typedef struct Answer {
  //     index_1;
  //     index_2;
  //   } Answer;

  // if(smaller + larger == limit){
  //   Answer *answer = Answer(index_1, index_2);
  //   return answer(larger, smaller);
  // }
  // else{
    return NULL;
  // } 
}

void print_answer(Answer *answer)
{
  if (answer != NULL) {
    printf("%d %d\n", answer->index_1, answer->index_2);
  } else {
    printf("NULL\n");
  }
}