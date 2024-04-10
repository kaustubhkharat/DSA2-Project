#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"
#include "hashing.h"


#define TABLE_SIZE 2000
#define MAX_COLLISIONS 50

void init_hashtable(hash_table* h){
    h->table=(char**)calloc(TABLE_SIZE,sizeof(char*));
    return;
}

unsigned int hash(char *str) {
    unsigned int hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash % TABLE_SIZE;
}

void delete_hash_table(hash_table* h) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (h->table[i] != NULL) {
            free(h->table[i]); // Free the memory allocated for the string
            h->table[i] = NULL; // Mark the slot as empty
        }
    }
}

int insert_hash(hash_table* h,char *str) {
    unsigned int index = hash(str);
    int collisions = 0;
    while (h->table[index] != NULL && strcmp(h->table[index], str) != 0 && collisions < MAX_COLLISIONS) {
        index = (index + 1) % TABLE_SIZE; // Linear probing
        collisions++;
    }
    if (collisions == MAX_COLLISIONS) {
        printf("Unable to insert '%s': Maximum collisions reached\n", str);
        return -1;
    }
    if (h->table[index] == NULL || strcmp(h->table[index], str) != 0) {
        h->table[index] = strdup(str); // Allocate memory for the string and insert into the hash table
    }
    return index;
}

int contains(hash_table* h,char *str) {
    unsigned int index = hash(str);
    int collisions = 0;
    while (h->table[index] != NULL && strcmp(h->table[index], str) != 0 && collisions < MAX_COLLISIONS) {
        index = (index + 1) % TABLE_SIZE; // Linear probing
        collisions++;
    }
    return h->table[index] != NULL && strcmp(h->table[index], str) == 0;
}

void create_trie(hash_table* h,trie *t)
{
    int i;

    for (i=0; i<TABLE_SIZE; i++){
        if (h->table[i]){
            insert_trie(t, h->table[i]);
        }
    }

    return;
}

int search_hash(hash_table* h,char *str){
    int hashIdx=hash(str), i=0;

    while ((h->table[hashIdx]) && (strcmp(h->table[hashIdx], str)) && (i<MAX_COLLISIONS)){
        hashIdx++;
    }

    if (i>=MAX_COLLISIONS || h->table[hashIdx]==NULL){
        return -1;
    }

    return hashIdx;
}
