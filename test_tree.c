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

bool all_tests(){
    test1_insert_empty();
    printf("Test complete");
    return true;
}

int main(){
    all_tests();
}