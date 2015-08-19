//
//  BinarySearchTree.cpp
//  
//
//  Created by Apple on 2015/5/20.
//
//

#include <iostream>

using namespace std;

typedef struct Node{
    Node *left;
    int data;
    Node *right;
} BST_Node;

BST_Node *create_bst(int n)
{
    BST_Node *ptr;
    ptr = (BST_Node *)malloc(sizeof(BST_Node));
    ptr->data = n;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

BST_Node *search(int n, BST_Node *bst)
{
    if(n > bst->data && bst->right != NULL) return search(n, bst->right);
    if(n < bst->data && bst->left != NULL) return search(n, bst->left);
    return bst;
}

void insert(int n, BST_Node *bst)
{
    BST_Node *find;
    find = search(n, bst);
    if(n > find->data) find->right = create_bst(n);
    if(n < find->data) find->left = create_bst(n);
}

void print_bst(BST_Node *bt)
{
    BST_Node *ptr;
    ptr = bt;
    if(ptr == NULL){
        cout << 'X';
        return;
    }
    cout << ptr->data;
    print_bst(ptr->left);
    print_bst(ptr->right);
}

int main()
{
    int n;
    cin >> n;
    BST_Node *bst = create_bst(n);
    while(n){
        cin >> n;
        insert(n, bst);
    }
    print_bst(bst);
    return 0;
}
