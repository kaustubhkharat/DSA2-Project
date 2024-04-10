#include <stdio.h>
#include "hashing.h"

#ifndef TOKENIZER_H
#define TOKENIZER_H

typedef struct TokenData{
  int lineNumber, documentNumber;
  struct TokenData *next;
}TokenData;

typedef struct TokenDataList{
  TokenData *front, *end;
}TokenDataList;

typedef struct{
    TokenDataList **TokenArray;
    int size;
}InvertedIndex;

int strtkns(FILE *ptr, char *tokens[]);
void toLowerCase(char *word);
void initDataList(TokenDataList *l);
void generateData(FILE *arr[], int fileArrSize, InvertedIndex *i, hash_table *h);
void AddToDataList(TokenDataList *l, TokenData *data);
void delDataList(TokenDataList *l);

#endif
