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

  // route[0] = hash->storage[NONE];
  printf("route[0] = %s", route[0]);
  //shoudl be LAX 
  for(int j = 1; j < length; j++){
    // char *next = hash->storage["NONE"]->destination;
    printf("inside j loop");
    char *previous = route[j-1];
    printf("$d", hash->storage[previous])
    route[j] = hash->storage[previous];
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


  Ticket **tickets = malloc(3 * sizeof(Ticket *));

  Ticket *ticket_1 = malloc(sizeof(Ticket));
  ticket_1->source = "NONE";
  ticket_1->destination = "PDX";
  tickets[0] = ticket_1;

  Ticket *ticket_2 = malloc(sizeof(Ticket));
  ticket_2->source = "PDX";
  ticket_2->destination = "DCA";
  tickets[1] = ticket_2;

  Ticket *ticket_3 = malloc(sizeof(Ticket));
  ticket_3->source = "DCA";
  ticket_3->destination = "NONE";
  tickets[2] = ticket_3;

  // char *expected[] = { "PDX", "DCA", "NONE" };
  print_route(reconstruct_trip(tickets, 3), 3);

  return 0;
}
#endif
