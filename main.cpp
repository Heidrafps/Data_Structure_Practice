#include <iostream>

#include "BST/BinarySearchTree.h"

int main() {
    // DEMO
    BinarySearchTree<int> tree;
    tree.insert(5);
    tree.insert(4);
    tree.insert(6);
    tree.insert(7);

    // TRAVERSALS
    tree.printInorder();
    tree.printPreorder();
    tree.printPostorder();


    // COPY ASSIGNMENT
    BinarySearchTree<int> new_tree;
    new_tree = tree;
    // SEARCH
    if(new_tree.search(6)) {
        std::cout<<"Yes"<<std::endl;
    }else {
        std::cout<<"No"<<std::endl;
    }
    if(new_tree.search(9)) {
        std::cout<<"Yes"<<std::endl;
    }else {
        std::cout<<"No"<<std::endl;
    }

    tree.printInorder();
    return 0;
}
