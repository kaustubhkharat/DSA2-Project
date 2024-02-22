#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

#define MAX_WORD_LENGTH 20

int strtkns(FILE *file_ptr, char *tokens[]){
  if (file_ptr==NULL)
    return;
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
// Anish
