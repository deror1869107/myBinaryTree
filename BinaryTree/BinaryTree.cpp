//
//  BinaryTree.cpp
//  
//
//  Created by Apple on 2015/5/20.
//
//

#include <iostream>

using namespace std;

typedef struct Node{
    struct Node *left;
    char data;
    struct Node *right;
} T_Node;

T_Node *create_bt()
{
    T_Node *ptr;
    char data;
    cin >> data;
    if(data == '0') return NULL;
    ptr = (T_Node *)malloc(sizeof(T_Node));
    ptr->data = data;
    ptr->left = create_bt();
    ptr->right = create_bt();
    return ptr;
}

void print_bt(T_Node *bt)
{
    T_Node *ptr;
    char data;
    ptr = bt;
    if(ptr == NULL){
        cout << '0';
        return;
    }
    cout << ptr->data;
    print_bt(ptr->left);
    print_bt(ptr->right);
}

int main()
{
    T_Node *bt;
    bt = create_bt();
    print_bt(bt);
    cout << endl;
    return 0;
}
