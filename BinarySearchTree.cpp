#include "BinarySearchTree.h"
#include <iostream>
#include <bits/ranges_uninitialized.h>


BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

BinarySearchTree::BinarySearchTree(const int data): root(nullptr) {
    root = new Node(data);
}

BinarySearchTree::BinarySearchTree(const BinarySearchTree &other) {
    root = deepcopytree(other.root);
}

BinarySearchTree& BinarySearchTree::operator=(const BinarySearchTree &other) {
    // Return self-assignment
    if(this == &other) {
        return *this;
    }
    destroytree(root);
    root = deepcopytree(other.root);
    return *this;
}

BinarySearchTree::BinarySearchTree(BinarySearchTree &&other) {
    // Steal the pointer
    root = other.root;
    other.root = nullptr;
}

BinarySearchTree& BinarySearchTree::operator=(BinarySearchTree &&other) {
    if(this == &other) {
        return *this;
    }
    destroytree(root);
    root = other.root;
    other.root = nullptr;
    return *this;
}

BinarySearchTree::~BinarySearchTree() {
    destroytree(root);
}

void BinarySearchTree::insert(int data) {
    // Create new Node
    Node* newNode = new Node(data);
    // If root is empty, make the new node the root
    if(isempty(root)) {
        root = newNode;
        return;
    }
    Node *current = root;
    Node *parent = nullptr;
    // Interation to traverse left or right
    while(current != nullptr) {
        parent = current;
        if(data < current->data) {
            current = current->left;
        }else if(data >= current->data) {
            current = current->right;
        }
    }
    // Attaching Node
    if (data < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}

bool BinarySearchTree::search(int data) {
    if(isempty(root)) {
        return false;
    }
    Node *current = root;
    while(current != nullptr) {
        if(data == current->data) {
            return true;
        }
        if(data < current->data) {
            current = current->left;
        }else {
            current = current->right;
        }
    }
    return false;
}
bool BinarySearchTree::isempty(Node* node) {
    return node == nullptr;
}
void BinarySearchTree::inorder(Node *node) {
    // Base Case
    if(isempty(node)) {
        return;
    }
    // Recursive Case
    inorder(node->left);
    std::cout << node->data << " ";
    inorder(node->right);
}

void BinarySearchTree::preorder(Node *node) {
    // Base Case
    if(isempty(node)) {
        return;
    }
    // Recursive Case
    std::cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

void BinarySearchTree::postorder(Node *node) {
    // Base Case
    if(isempty(node)) {
        return;
    }
    // Recursive Case
    postorder(node->left);
    postorder(node->right);
    std::cout<<node->data << " ";
}

void BinarySearchTree::printinorder() {
    inorder(root);
    std::cout << std::endl;
}

void BinarySearchTree::printpreorder() {
    preorder(root);
    std::cout << std::endl;
}

void BinarySearchTree::printpostorder() {
    postorder(root);
    std::cout << std::endl;
}
BinarySearchTree::Node * BinarySearchTree::deepcopytree(Node *node) {
    // Base Case
    if(isempty(node)) {
        return nullptr;
    }
    // Recursive Case
    // Make a new node
    Node* newnode = new Node(node->data);
    // Copy the left nodes
    newnode->left = deepcopytree(node->left);
    // Copy the right nodes
    newnode->right = deepcopytree(node->right);
    return newnode;
}
void BinarySearchTree::destroytree(Node *node) {
    if(isempty(node)) {
        return;
    }
    destroytree(node->left);
    destroytree(node->right);
    delete node;
}


