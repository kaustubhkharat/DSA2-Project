#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"


#define TABLE_SIZE 1000
#define MAX_COLLISIONS 50

char *hash_table[TABLE_SIZE]; // Hash table to store strings

unsigned int hash(char *str) {
    unsigned int hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash % TABLE_SIZE;
}

void delete_hash_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] != NULL) {
            free(hash_table[i]); // Free the memory allocated for the string
            hash_table[i] = NULL; // Mark the slot as empty
        }
    }
}

int insert_hash(char *str) {
    unsigned int index = hash(str);
    int collisions = 0;
    while (hash_table[index] != NULL && strcmp(hash_table[index], str) != 0 && collisions < MAX_COLLISIONS) {
        index = (index + 1) % TABLE_SIZE; // Linear probing
        collisions++;
    }
    if (collisions == MAX_COLLISIONS) {
        printf("Unable to insert '%s': Maximum collisions reached\n", str);
        return -1;
    }
    if (hash_table[index] == NULL || strcmp(hash_table[index], str) != 0) {
        hash_table[index] = strdup(str); // Allocate memory for the string and insert into the hash table
    }
    return index;
}

int contains(char *str) {
    unsigned int index = hash(str);
    int collisions = 0;
    while (hash_table[index] != NULL && strcmp(hash_table[index], str) != 0 && collisions < MAX_COLLISIONS) {
        index = (index + 1) % TABLE_SIZE; // Linear probing
        collisions++;
    }
    return hash_table[index] != NULL && strcmp(hash_table[index], str) == 0;
}

void create_trie(trie *t)
{
    int i;

    for (i=0; i<TABLE_SIZE; i++){
        if (hash_table[i]){
            insert_trie(t, hash_table[i]);
        }
    }

    return;
}

int search_hash(char *str){
    int hashIdx=hash(str), i=0;

    while ((hash_table[hashIdx]) && (strcmp(hash_table[hashIdx], str)) && (i<MAX_COLLISIONS)){
        hashIdx++;
    }

    if (i>=MAX_COLLISIONS || hash_table[hashIdx]==NULL){
        return -1;
    }

    return hashIdx;
}
