#include <stdlib.h>
#include <stdbool.h>
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
