#include "tokenizer.h"
#include "hashing.h"

#ifndef INVERTED_INDEX_H
#define INVERTED_INDEX_H

void init_inverted_index(InvertedIndex *i);
void addData(InvertedIndex *i, char *word, TokenData *data,hash_table* h);
int readFromFiles(char *files[], int filesLen, InvertedIndex *i, hash_table *h);
void searchInvertedIndex(InvertedIndex *i, char *word,int occurences,hash_table* h);
void destroyInvertedIndex(InvertedIndex *i);

#endif
