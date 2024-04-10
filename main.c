#include"lib/InvertedIndex.h"
#include"lib/trie.h"
#include"lib/hashing.h"
#include<stdio.h>


int main(int argc,char* argv[]){
    if(argc==1) return 1;

    InvertedIndex i;
    init_inverted_index(&i);
    readFromFiles(argv+1,argc-1,&i);

    hash_table h;
    init_hashtable(&h);

    trie t;
    init_trie(&t);
    create_trie(&h,&t);

    printf("Menu:\n");
    printf("1.Search.\n");
    printf("2.AutoComplete.\n");
    printf("3.Quit.\n");

    int choice;
    int flag=1;
    char word[20];
    char prefix[20];

    while(flag){
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                scanf("%s",word);
                int occurences;
                printf("Enter the number of inferences: ");
                scanf("%d",&occurences);
                searchInvertedIndex(&i,word,occurences,&h);
                break;
            case 2:
                scanf("%s",prefix);
                char* result[5];
                search_trie(t,prefix,result);
                for(int i=0;i<5;i++){
                    printf("%d.%s\n",i+1,result[i]);
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
    destroy(&t);
    destroyInvertedIndex(&i);
    delete_hash_table(&h);
    return 0;
}