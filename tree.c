#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

Node *createnode(int value)
{
    Node *NewNode = (Node *)malloc(sizeof(Node));
    if (NewNode == NULL)
    {
        printf("Error/n");
        exit(1);
    }

    NewNode->value = value;
    NewNode->left = NULL;
    NewNode->right = NULL;

    return NewNode;
} 

Node *insert(Node *root, int value)
{
    if (root == NULL)
    {
        return createnode(value);
    }
    if (value < root->value)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->value)
    {
        root->right = insert(root->right, value);
    }
    return root;
}
Node *minNode(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
Node *removeTree(Node *root, int value)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (value < root->value)
    {
        root->left = removeTree(root->left, value);
    }
    else if (value > root->value)
    {
        root->right = removeTree(root->right, value);
    }
    else
    {
        if (root->left == NULL)
        {
            Node *current = root->right;
            free(root);
            return current;
        }
        else if (root->right == NULL)
        {
            Node *current = root->left;
            free(root);
            return current;
        }
        else
        {
            Node *current = minNode(root->right);
            root->value = current->value;
            root->right = removeTree(root->right, current->value);
        }
    }
    return root;
}

void printTree(Node *root, int depth)
{
    if (root == NULL)
    {
        return;
    }

    for (int i = 0; i < depth; i++)
    {
        printf("  ");
    }
    printf("%d\n", root->value);
    printTree(root->left, depth + 1);
    printTree(root->right, depth + 1);
}

int getTreeDegree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int currentDegree = 0;
    if (root->left != NULL)
    {
        currentDegree++;
    }
    if (root->right != NULL)
    {
        currentDegree++;
    }
    if (currentDegree == 2)
    {
        return 2;
    }
    int leftDegree = getTreeDegree(root->left);
    int rightDegree = getTreeDegree(root->right);
    int maxDegree = currentDegree;
    if (leftDegree > maxDegree)
    {
        maxDegree = leftDegree;
    }
    if (rightDegree > maxDegree)
    {
        maxDegree = rightDegree;
    }

    return maxDegree;
}

void freeTree(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

