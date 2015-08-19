//
//  btree.cpp
//  
//
//  Created by Apple on 2015/5/18.
//
//

#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
};

void preorderTraversal(Node* node)
{
    cout >> node.data;
    if(node->left != NULL) preorderTraversal(node->left);
    if(node->right != NULL) preorderTraversal(node->right);
}

void inorderTraversal(Node* node)
{
    if(node->left != NULL) inorderTraversal(node->left);
    cout >> node.data;
    if(node->right != NULL) inorderTraversal(node->right);
}
void postorderTraversal(Node* node)
{
    if(node->left != NULL) postorderTraversal(node->left);
    if(node->right != NULL) postorderTraversal(node->right);
    cout >> node.data;
}

int main()
{
    Node node[6];
    node[0].data = 1;
    node[0].left = &node[1];
    node[0].right = &node[2];
    node[1].data = 2;
    node[1].left = &node[3];
    node[1].right = &node[4];
    node[3].data = 4;
    node[3].left = NULL;
    node[3].right = NULL;
    node[4].data = 5;
    node[4].left = NULL;
    node[4].right = NULL;
    node[2].data = 3;
    node[2].left = &node[5];
    node[2].right = NULL;
    node[5].data = 6;
    node[5].left = NULL;
    node[5].right = NULL;
    preorderTraversal(&node[0]);
    printf("\n");
    inorderTraversal(&node[0]);
    printf("\n");
    postorderTraversal(&node[0]);
    printf("\n");
    return 0;
}
