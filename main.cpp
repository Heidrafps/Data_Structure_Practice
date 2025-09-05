#include <iostream>

#include "BinarySearchTree.h"

int main() {
    // DEMO
    BinarySearchTree tree;
    tree.insert(5);
    tree.insert(4);
    tree.insert(6);
    tree.insert(7);

    // TRAVERSALS
    tree.printinorder();
    tree.printpreorder();
    tree.printpostorder();


    // COPY ASSIGNMENT
    BinarySearchTree new_tree;
    new_tree = tree;
    // SEARCH
    if(new_tree.search(6)) {
        std::cout<<"Yes"<<std::endl;
    }else {
        std::cout<<"No"<<std::endl;
    }
    return 0;
}
