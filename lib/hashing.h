#ifndef HASHING_H
#define HASHING_H
#include "trie.h"

typedef struct hash_table{
    char** table;
}hash_table;

void init_hashtable(hash_table* h);
unsigned int hash(char *str);
void delete_hash_table(hash_table* h);
int insert_hash(hash_table* h,char *str);
int contains(hash_table* h,char *str);
void create_trie(hash_table* h,trie *t);
int search_hash(hash_table* h,char *str);


#endif
