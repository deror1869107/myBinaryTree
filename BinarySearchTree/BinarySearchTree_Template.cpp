//
//  BinarySearchTree_Template.cpp
//  
//
//  Created by Apple on 2015/5/23.
//
//

#include "BinarySearchTree_Template.h"
#include <iostream>
#include <functional>

void _clear(node*& ptr)
{
    if(ptr) _clear(ptr->left), _clear(ptr->right), delete ptr;
}

void _print(node*& ptr)
{
    if(ptr == NULL){
        return;
    }
    std::cout << ptr->data << " ";
    _print(ptr->left);
    _print(ptr->right);
}

/*node *search(int n, node *bst)     //old method
 {
 if(n > bst->data && bst->right != NULL) return search(n, bst->right);
 if(n < bst->data && bst->left != NULL) return search(n, bst->left);
 return bst;
 }*/

node *search(T n)
{
    node *temp = NULL;
    node *prev = NULL;
    temp = root;
    while(temp){
        prev = temp;
        if(n > temp->data) temp = temp->right;
        else temp = temp->left;
    }
    return prev;
}

BinarySearchTree():root(NULL){}
~BinarySearchTree(){_clear(root), root = NULL;}

inline bool find(T n)
{
    if(search(n)->data == n) return true;
    return false;
}

inline void insert(T n)
{
    node *ptr;
    ptr = new node(n);
    node *find = search(n);
    if(find == NULL) root = ptr;
    else if (n > find->data) find->right = ptr;
    else find->left = ptr;
}

inline void print()
{
    _print(root);
}

inline void clear()
{
    _clear(root);
    root = NULL;
}