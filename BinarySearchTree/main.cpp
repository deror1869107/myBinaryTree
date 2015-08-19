//
//  BinarySearchTree_Template.cpp
//  
//
//  Created by Apple on 2015/5/23.
//
//

#include "BinarySearchTree_Template.h"
#include <iostream>

using namespace std;

int main()
{
    BinarySearchTree<int> bst;
    int n;
    while(cin >> n){
        int now;
        while(n--){
            cin >> now;
            bst.insert(now);
        }
        bst.print();
        printf("\n");
        bst.clear();
    }
    return 0;
}
