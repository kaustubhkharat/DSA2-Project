#include"lib/InvertedIndex.h"
#include"lib/trie.h"
#include"lib/hashing.h"
#include<stdio.h>


int main(int argc,char* argv[]){
    if(argc==0) return 1;
    char* files[argc-1];
    for(int i=1;i<argc;i++){
        files[i]=argv[i];
    }

    InvertedIndex i;
    init_inverted_index(&i);
    readFromFiles(files,argc-1,&i);

    trie t;
    init_trie(&t);
    create_trie(&t);

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
                searchInvertedIndex(&i,word,occurences);
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
    return 0;
}