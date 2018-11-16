#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "ex2.h"

char **reconstruct_trip(Ticket **tickets, int length)
{
  printf("start reconstruct_trip");
  HashTable *hash = create_hash_table(16);
  char **route = malloc(length * sizeof(char *));

  for(int i = 0; i < length; i++){
    printf(" i = %d\n", i);
    printf(" tickets[i] = %d\n", tickets[i]);
    hash_table_insert(hash, tickets[i]->source, tickets[i]->destination);
  }

 
  route[0] = hash->storage["NONE"];
  printf("route[0] = %s", route[0]);
  //shoudl be LAX 
  for(int j = 1; j < length; j++){
    // char *next = hash->storage["NONE"]->destination;
    // printf("inside j loop");
    route[j] = hash->storage[route[(j-0)]];
    // next = hash->storage[next]->destination;
  }


  // route[0] = hash->storage->NONE;
  // for (int i = 0; i < length; i++){
  //   route[i] = tickets[]
  // }

  return route;
}

void print_route(char **route, int length)
{
  for (int i = 0; i < length; i++) {
    printf("%s\n", route[i]);
  }
}
#ifndef TESTING
int main(void)
{
  
  typedef struct Ticket {
    char *source;
    char *destination;
  } Ticket;

  Ticket **ticketsss = {
    { source: "PIT", destination: "ORD" },
    { source: "XNA", destination: "CID" },
    { source: "SFO", destination: "BHM" },
    { source: "FLG", destination: "XNA" },
    { source: "NONE", destination: "LAX" },
    { source: "LAX", destination: "SFO" },
    { source: "CID", destination: "SLC" },
    { source: "ORD", destination: "NONE" },
    { source: "SLC", destination: "PIT" },
    { source: "BHM", destination: "FLG" }
  };

  Ticket* answer_4 = reconstruct_trip(ticketsss, 10);

  return 0;
}
#endif