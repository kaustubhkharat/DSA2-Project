#include"lib/InvertedIndex.h"
#include"lib/trie.h"
#include"lib/hashing.h"
#include<stdio.h>
#include <stdlib.h>


int main(int argc,char* argv[]){
    if(argc==0) return 1;
    char* files[argc-1];
    for(int i=1;i<argc;i++){
        files[i-1]=argv[i];
    }

    hash_table h;
    init_hashtable(&h);

    InvertedIndex i;
    init_inverted_index(&i);
    readFromFiles(files,argc-1,&i, &h);

    trie t;
    init_trie(&t);
    create_trie(&h, &t);

    printf("Menu:\n");
    printf("1.Search.\n");
    printf("2.AutoComplete.\n");
    printf("3.Quit.\n");

    int choice, count;
    int flag=1;
    char word[20];
    char prefix[20];
    char *result[20];

    while(flag){
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                scanf("%s",word);
                int occurences;
                printf("Enter the number of inferences: ");
                scanf("%d",&occurences);
                searchInvertedIndex(&i,word,occurences, &h);
                break;
            case 2:
                scanf("%s",prefix);
                printf("number of words: ");
                scanf("%d",&count);
                search_trie(t,prefix,result, count);
                for(int i=0;result[i] && i<count;i++){
                    printf("%d.%s\n",i+1,result[i]);
                    if (result[i])
                        free(result[i]);
                }
                break;
            case 3:
                flag=0;
                break;
            default:
                printf("Enter a valid choice. \n");
                break;
        }
    }
    destroyInvertedIndex(&i);
    destroy(t);
    free(t->A);
    delete_hash_table(&h);
    return 0;
}
