#ifndef hashtables_h
#define hashtables_h

typedef struct LinkedPair {
  int key;
  int value;
  struct LinkedPair *next;
} LinkedPair;

typedef struct HashTable {
  int capacity;
  LinkedPair **storage;
} HashTable;

// typedef struct Answer {
//   int index_1;
//   int index_2;
// } Answer;

HashTable *create_hash_table(int capacity);
void hash_table_insert(HashTable *ht, int key, int value);
void hash_table_remove(HashTable *ht, int key);
int hash_table_retrieve(HashTable *ht, int key);
void destroy_hash_table(HashTable *ht);
HashTable *hash_table_resize(HashTable *ht);
// Answer *create_answer(int* larger, int *smaller);

#endif