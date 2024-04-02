#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "InvertedIndex.h"

#define MAX_WORD_LENGTH 20

int strtkns(FILE *file_ptr, char *tokens[]){
  if (file_ptr==NULL)
    return 0;
  int i,j=0;
  char c, *str;
  c=getc(file_ptr);

  while (c != EOF){
    str=(char*)malloc(sizeof(char)*MAX_WORD_LENGTH);
    i=0;
    while ( (i<20) && ((('a'<=c)&&(c<='z')) || (('A'<=c)&&(c<='Z'))) ){
      str[i++]=c;
      c=getc(file_ptr);
    }
    if (i==0){
      free(str);
      c=getc(file_ptr);
      continue;
    }
    str[i]=0;
    tokens[j++]=str;
    c=getc(file_ptr);
  }
  
  return j;
}

void toLowerCase(char *word){
  const int offset='a'-'A';
  int i;
  for (i=0; word[i]; i++){
    if (('A'<= word[i]) && (word[i] <= 'Z'))
      word[i]+=offset;
  }
  return;
}

void initDataList(TokenDataList *l){
  l->front=l->end=NULL;
  return;
}

void AddToDataList(TokenDataList *l, TokenData *data){
  TokenData *r;
  r=l->end;
  if (r==NULL){
    l->front=l->end=data;
    return;
  }

  r->next=data;
  l->end=data;
  return;
}

void generateFileData(FILE *ptr, InvertedIndex *i, int documentNumber){
  char c,*word=(char *)malloc(MAX_WORD_LENGTH*sizeof(char));
  int k=0, lineNumber=1;
  TokenData *data;
  while ((c=getc(ptr)) != EOF){
    word=0;
    k=0;
    while((k<MAX_WORD_LENGTH) && (('a'<=c)&&(c<='z') || ('A'<=c && c<='Z'))){
      word[k++]=c;
      c=getc(ptr);
    }
    word[k]=0;
    data=(TokenData *)malloc(sizeof(TokenData));
    data->documentNumber=documentNumber;
    data->lineNumber=lineNumber;
    toLowerCase(word);
    addData(i, word, data);
    if (c=='\n'){
      lineNumber++;
    }
  }
  return;
}
void generateData(FILE **arr, int fileArrSize, InvertedIndex *i){
  int k;
  for (k=0; k<fileArrSize; k++){
    generateFileData(arr[k], i, k);
  }
  return;
}

void delDataList(TokenDataList *l){
  TokenData *p, *q;
  p=l->front;
  while (p){
    q=p->next;
    free(p);
    p=q;
  }
  return;
}
