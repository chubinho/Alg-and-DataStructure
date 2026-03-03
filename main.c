#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

void print_help()
{
    printf("Commands:\n");
    printf("1.insert\n");
    printf("2.remove\n");
    printf("3.print\n");
    printf("4.degree\n");
    printf("5.free\n");
    printf("6.exit\n");
    printf("7.help\n");
}

int main()
{
    Node *root = NULL;
    char command[50];
    int value;
    print_help();
    while (1)
    {
        printf("> ");

        if (scanf("%s", command) != 1)
        {
            break;
        }

        if (strcmp(command, "insert") == 0)
        {
            if (scanf("%d", &value) == 1)
            {
                root = insert(root, value);
                printf("Inserted %d\n", value);
            }
            else
            {
                printf("Error");
            }
        }
        else if (strcmp(command, "remove") == 0)
        {
            if (scanf("%d", &value)){
                root = removeTree(root, value);
                printf("Removed %d\n", value);
            }
            else{
                printf("Error");
            }
        }
        else if (strcmp(command,"print") == 0){
            if (root == NULL){
                printf("ERROR: Tree is empty\n");
            
            }
            else{
                printTree(root,0);
            }
        }
        else if (strcmp(command,"degree") == 0){
            int degree = getTreeDegree(root);
            printf("Degree = %d\n", degree);

        }
        else if (strcmp(command,"free") == 0){
            freeTree(root);
            root = NULL;
        }
        else if (strcmp(command, "exit") == 0){
            break;
        }
        else if (strcmp(command,"help") == 0){
            print_help();
        }
        else{
            printf("Unknown command %s\n",command);
        }
    }
}