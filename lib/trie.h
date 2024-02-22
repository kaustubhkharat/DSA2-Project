#include <stdbool.h>
#ifndef TRIE_H
#define TRIE_H

typedef struct trieNode{
  struct trieNode *A[26];
  bool isEndWord;
}trieNode;

typedef trieNode *trie;

void init_trie(trie *t);
void insert_trie(trie *t, char *word);
void search_trie(trie t, char *prefix, char *result[]); // returns 5 matches
<<<<<<< HEAD
void destroy(trie *t);
int isNULL(trie t); //checks if all 26 nodes of a node are NULL

=======
char *get_one_word(trie t, char *prefix);
>>>>>>> 64cf101d56ea639da83c5e2f5b25618f15ce9a71
#endif
