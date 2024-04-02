#include <stdio.h>
#include <stdlib.h>
#include "InvertedIndex.h"
#include "tokenizer.h"
#include "hash.h"

#define MAX_WORD 1000

void init_inverted_index(InvertedIndex *i){
    int k;
    i->TokenArray=(TokenDataList **)malloc(MAX_WORD*sizeof(TokenDataList *));
    i->size=MAX_WORD;
    for (k=0; k<MAX_WORD; k++){
        initDataList(i->TokenArray[k]);
    }
    return;
}

void addData(InvertedIndex *i, char *word, TokenData *data){
    int index=HashStr(word);
    if (index >=  MAX_WORD){
        printf("overflow\n");
        return;
    }
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

    generateData(arr, filesLen ,i);

    for (j=0; j<filesLen; j++){
        fclose(arr[j]);
    }

    return 0;
}


