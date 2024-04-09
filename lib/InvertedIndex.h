#include "tokenizer.h"

#ifndef INVERTED_INDEX_H
#define INVERTED_INDEX_H

void init_inverted_index(InvertedIndex *i);
void addData(InvertedIndex *i, char *word, TokenData *data);
int readFromFiles(char *files[], int filesLen, InvertedIndex *i);
void searchInvertedIndex(InvertedIndex *i, char *word,int occurences);
void destroyInvertedIndex(InvertedIndex *i);

#endif
