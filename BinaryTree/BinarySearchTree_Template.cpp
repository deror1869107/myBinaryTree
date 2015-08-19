//
//  BinarySearchTree_Class.cpp
//  
//
//  Created by Apple on 2015/5/20.
//
//

#include <iostream>
#include <functional>

using namespace std;

class BinarySearchTree{
private:
    struct node{
        int data;
        node *left, *right;
        node(int val): data(val), left(NULL), right(NULL){}
    } *null, *root;
    
    void _clear(node*& ptr)
    {
        if(ptr) _clear(ptr->left), _clear(ptr->right), delete ptr;
    }
    
    void print_bst(node*& bst)
    {
        if(bst == NULL){
            return;
        }
        printf("%d ", bst->data);
        print_bst(bst->left);
        print_bst(bst->right);
    }
    
    /*node *search(int n, node *bst)     //old method
     {
     if(n > bst->data && bst->right != NULL) return search(n, bst->right);
     if(n < bst->data && bst->left != NULL) return search(n, bst->left);
     return bst;
     }*/
    
    node *search(int n)
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
    
public:
    BinarySearchTree():root(NULL){}
    ~BinarySearchTree(){_clear(root), root = NULL;}
    
    inline bool find(int n)
    {
        if(search(n) != NULL) return true;
        return false;
    }
    
    inline void insert(int n)
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
        print_bst(root);
    }
    
    void clear()
    {
        _clear(root);
        root = NULL;
    }
};


int main()
{
    BinarySearchTree bst;
    int n;
    cin >> n;
    while(n){
        bst.insert(n);
        cin >> n;
    }
    bst.print();
    cin >> n;
    cout << bst.find(n);
    return 0;
}
