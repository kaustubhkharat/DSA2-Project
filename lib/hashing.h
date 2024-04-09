#ifndef HASHING_H
#define HASHING_H
#include <trie.h>

unsigned int hash(char *str);
void delete_hash_table();
int insert_hash(char *str);
int contains(char *str);
void create_trie(trie *t);




#endif