#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "tree.h"


void test1_insert_empty() {
    Node* root = NULL;
    root = insert(root, 52);

    assert(root != NULL);
    assert(root->value == 52);
    assert(root -> left == NULL);
    assert(root->right == NULL);
    freeTree(root);
}
void test2_insert(){
    Node * root = NULL;
    root = insert(root,5);
    root = insert(root, 6);
    root = insert(root, 7);
    assert(root->value == 5);
    assert(root->right->value == 6);
    assert(root->right->right->value == 7);
    freeTree(root);
}

void test3_remove_element(){
    Node *root = NULL;
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 52);

    root = removeTree(root, 10);

    assert(root->value == 7);
    assert(root->left == NULL);
    assert(root->right != NULL && root->right->value == 52);

    freeTree(root);
}

bool all_tests(){
    test1_insert_empty();
    printf("Test 1 complete\n");
    test2_insert();
    printf("Test 2 complete\n");
    test3_remove_element();
    printf("Test 3 complete\n");
    return true;
}

int main(){
    all_tests();
}