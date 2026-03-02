#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int value;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value);

Node *insert(Node *root, int value);

Node *minNode(Node *root);

Node *removeTree(Node *root, int value);

void printTree(Node *root, int depth);

int getTreeDegree(Node *root);

void freeTree(Node *root);

#endif