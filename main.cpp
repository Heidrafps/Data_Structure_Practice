#include <iostream>

#include "BST/BinarySearchTree.h"
void binarySearchTreeDemo();
int main() {
    // DEMO
    binarySearchTreeDemo();
    return 0;
}

void binarySearchTreeDemo() {
    // Instantiate an Integer Binary Search Tree with a root node of 4
    BinarySearchTree<int> tree(4);

    // Insert Values
    tree.insert(1);
    tree.insert(2);
    tree.insert(7);
    tree.insert(5);
    tree.insert(6);



    // Copy Tree
    BinarySearchTree<int> copyTree = tree;

    // Remove the root node of the Copy Tree using the Successor
    copyTree.deleteRootSuccessor();

    // Remove the root of the Original Tree using the Predecessor
    tree.deleteRootPredecessor();

    // Traversals ** THIS WILL NOT BE AFFECTED BY THE COPY TREE **
    std::cout << "---Original Tree--- \n";
    std::cout << "Inorder Traversal: ";
    tree.printInorder();
    std::cout << "Preorder Traversal: ";
    tree.printPreorder();
    std::cout << "Postorder Traversal: ";
    tree.printPostorder();

    // Copy Traversals
    std::cout << "---Copy Tree--- \n";
    std::cout << "Inorder Traversal: ";
    copyTree.printInorder();
    std::cout << "Preorder Traversal: ";
    copyTree.printPreorder();
    std::cout << "Postorder Traversal: ";
    copyTree.printPostorder();

    // Search
    if(tree.search(6)) {
        std::cout <<"Search for 6 Sucess\n";
    }else {
        std::cout <<"Search for 6 Not Found\n";
    }

    if(copyTree.search(4)) {
        std::cout <<"Search for 4 Sucess\n";
    }else {
        std::cout <<"Search for 4 Not Found\n";
    }
}
