#include <stdlib.h>
#include <string.h>
#include "trie.h"


void init_trie(trie *t){
  *t=NULL;
  return;
}

int isNULL(trie t){
  if(t==NULL) return 0;
  for(int i=0;i<26;i++){
    if(t->A[i]==NULL) continue;
    else return 0;
  }
  return 1;
}

trieNode *new_node_trie(bool isEnd){
  trieNode *nn;
  int i;
  nn=(trieNode *)malloc(sizeof(trieNode));
  nn->isEndWord=isEnd;
  
  for (i=0;i<26;i++)
    nn->A[i]=NULL;

  return nn;
}

void insert_trie(trie *t, char *word){
 if (word == NULL)
   return;
 if (*t == NULL)
   *t=new_node_trie(false);
 int i=0;
 trie t_ptr=*t;

 while (word[i]){
   if (t_ptr->A[(word[i]-97)] == NULL){
    t_ptr->A[(word[i]-97)]=new_node_trie(false);
   }
   t_ptr=t_ptr->A[(word[i])-97];
   i++;
  }
  t_ptr->isEndWord=true;

  return;
}

void destroy(trie* t){
  if(isNULL(*t)) {
    free(t);
    return;
  }
  for(int i=0;i<26;i++){
    if((*t)->A[i]!=NULL) destroy(&(*t)->A[i]);
    else free(t);
  }
  return; 
} 
char *get_one_word(trie t, char *prefix){
  char *word;
  int i=0,j=0;
  trieNode *p;
  p=t;
  word=(char *)malloc(20*sizeof(char));
  
  for (;p && prefix[i];i++){
    p=p->A[prefix[i]-'a'];
  }

  strcpy(word, prefix);
  i=strlen(prefix);

  while (p && p->isEndWord==false){
    for (j=0;p->A[j]==NULL;j++);
    word[i++]=(char)j+'a';
    p=p->A[j];
  }
  return word;
}

void helper(trieNode *t, char* prefix, char *res[], int *count){
  if (*count > 4 || t==NULL || prefix==NULL)
    return;
  
  if (t->isEndWord){
    char *word;
    word=(char *)malloc(20*sizeof(char));
    strcpy(word, prefix);
    res[*count]=word;
    *count=*count+1;
  }
  int i,l=strlen(prefix);
  
  for (i=0;t && i<26;i++){
    if (t && t->A[i]){
      prefix[l]=i+'a';
      prefix[l+1]=0;
      helper(t->A[i], prefix, res, count);
      prefix[l]=0;
    }
  }
  return;
}

void search_trie(trie t, char *prefix, char *res[]){
  int i,count=0;
  char *word;
  word=(char *)malloc(20*sizeof(char));
  strcpy(word, prefix);
  for (i=0;i<5;i++)
    res[i]=NULL;

  for (i=0;t && prefix[i];i++)
    t=t->A[prefix[i]-'a'];

  helper(t, word, res, &count);
  return;
}

