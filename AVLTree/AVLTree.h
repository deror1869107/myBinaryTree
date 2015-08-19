//
//  AVLTree.h
//  
//
//  Created by Apple on 2015/5/24.
//
//

#ifndef ____AVLTree__
#define ____AVLTree__

#include <iostream>

class AVLTree{
private:
    struct node{
        int data, deep;
        node *left, *right;
        node(int val): data(val), deep(1), left(NULL), right(NULL);
    } *root;
    
    void rotate_left(node *&ptr)
    {
        node *temp = ptr;
        ptr->right = ptr->right->left;
        ptr = ptr->right->left;
        ptr->right = temp;
    }
    
    void rotate_right(node *&ptr)
    {
        node *temp = ptr;
        ptr->left = ptr->left->right;
        ptr = ptr->left->right;
        ptr->left = temp;
    }
    
    node* search(int n)
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
    
    void _clear(node *&ptr)
    {
        if(ptr) _clear(ptr->right), _clear(ptr->left), delete ptr;
    }
    
public:
    AVLTree():root(NULL){}
    ~AVLTree(){_clear(root), root = NULL;}
    
    inline boo find(int n)
    {
        if(search(n)->data == n) return true;
        return false;
    }
    
    inline void insert(int n)
    {
        
    }
    
};

#endif /* defined(____AVLTree__) */
