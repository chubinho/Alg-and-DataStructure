#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "tree.h"

void test1_insert_empty()
{
    Node *root = NULL;
    root = insert(root, 52);

    assert(root != NULL);
    assert(root->value == 52);
    assert(root->left == NULL);
    assert(root->right == NULL);
    freeTree(root);
}
void test2_insert()
{
    Node *root = NULL;
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 7);
    assert(root->value == 5);
    assert(root->right->value == 6);
    assert(root->right->right->value == 7);
    freeTree(root);
}

void test3_remove_element()
{
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

void test4_remove_root()
{
    Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 12);
    root = insert(root, 0);
    root = insert(root, 5);
    root = insert(root, 15);

    root = removeTree(root,10);
    assert(root != NULL && root->value == 12);

    assert(root->left != NULL && root->left->value == 0);
    assert(root->right != NULL && root->right->value == 15);
    freeTree(root);

}
test5_degree_tree(){
    Node* root = NULL;
    assert(getTreeDegree(root) == 0);

    root = insert(root,5);
    root = insert(root, 1);
    assert(getTreeDegree(root) == 1);

    root = insert(root,2);
    root = insert(root,6);
    assert(getTreeDegree(root) == 2);
    
}

bool all_tests()
{
    test1_insert_empty();
    printf("Test 1 complete\n");
    test2_insert();
    printf("Test 2 complete\n");
    test3_remove_element();
    printf("Test 3 complete\n");
    test4_remove_root();
    printf("Test 4 complete\n");
    test5_degree_tree();
    printf("Test 5 complete\n");
    return true;
}

int main()
{
    all_tests();
}