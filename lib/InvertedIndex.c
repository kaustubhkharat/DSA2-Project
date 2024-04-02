#include <stdio.h>
#include <stdlib.h>
#include "InvertedIndex.h"
#include "tokenizer.h"
#include "hash.h"

void init_inverted_index(InvertedIndex *i){
    i->TokenArray=(TokenDataList **)malloc(1000*sizeof(TokenDataList *));
    i->size=1000;
    return;
}

void addData(InvertedIndex *i, char *word, TokenData *data){
    int index=HashStr(word);
    AddToDataList(i->TokenArray[index], data);
    return;
}

int readFromFiles(char *files[], int filesLen, InvertedIndex *i){
    int j;
    FILE* arr[filesLen];

    for (j=0; j<filesLen; j++){
        arr[j]=fopen(files[j], "r");
        if (arr[j]==NULL)
            return 1;
    }

    generateData(arr, i);

    for (j=0; j<filesLen; j++){
        fclose(arr[j]);
    }

    return 0;
}


