#include "BinarySearchTree.h"
#include <iostream>
#include <bits/ranges_uninitialized.h>


BinarySearchTree::BinarySearchTree() {
    m_root = nullptr;
}

BinarySearchTree::BinarySearchTree(const int data): m_root(nullptr) {
    m_root = new Node(data);
}

BinarySearchTree::BinarySearchTree(const BinarySearchTree &other) {
    m_root = deepCopyTree(other.m_root);
}

BinarySearchTree& BinarySearchTree::operator=(const BinarySearchTree &other) {
    // Return self-assignment
    if(this == &other) {
        return *this;
    }
    destroyTree(m_root);
    m_root = deepCopyTree(other.m_root);
    return *this;
}

BinarySearchTree::BinarySearchTree(BinarySearchTree &&other) {
    // Steal the pointer
    m_root = other.m_root;
    other.m_root = nullptr;
}

BinarySearchTree& BinarySearchTree::operator=(BinarySearchTree &&other) {
    if(this == &other) {
        return *this;
    }
    destroyTree(m_root);
    m_root = other.m_root;
    other.m_root = nullptr;
    return *this;
}

BinarySearchTree::~BinarySearchTree() {
    destroyTree(m_root);
}

void BinarySearchTree::insert(int data) {
    // Create new Node
    Node* newNode = new Node(data);
    // If root is empty, make the new node the root
    if(isEmpty(m_root)) {
        m_root = newNode;
        return;
    }
    Node *current = m_root;
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

bool BinarySearchTree::search(int data) const{
    if(isEmpty(m_root)) {
        return false;
    }
    Node *current = m_root;
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
bool BinarySearchTree::isEmpty(Node* node) const {
    return node == nullptr;
}
void BinarySearchTree::inorder(Node *node) {
    // Base Case
    if(isEmpty(node)) {
        return;
    }
    // Recursive Case
    inorder(node->left);
    std::cout << node->data << " ";
    inorder(node->right);
}

void BinarySearchTree::preorder(Node *node) {
    // Base Case
    if(isEmpty(node)) {
        return;
    }
    // Recursive Case
    std::cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

void BinarySearchTree::postorder(Node *node) {
    // Base Case
    if(isEmpty(node)) {
        return;
    }
    // Recursive Case
    postorder(node->left);
    postorder(node->right);
    std::cout<<node->data << " ";
}

void BinarySearchTree::printInorder() {
    inorder(m_root);
    std::cout << std::endl;
}

void BinarySearchTree::printPreorder() {
    preorder(m_root);
    std::cout << std::endl;
}

void BinarySearchTree::printPostorder() {
    postorder(m_root);
    std::cout << std::endl;
}
BinarySearchTree::Node * BinarySearchTree::deepCopyTree(Node *node) {
    // Base Case
    if(isEmpty(node)) {
        return nullptr;
    }
    // Recursive Case
    // Make a new node
    Node* newnode = new Node(node->data);
    // Copy the left nodes
    newnode->left = deepCopyTree(node->left);
    // Copy the right nodes
    newnode->right = deepCopyTree(node->right);
    return newnode;
}
void BinarySearchTree::destroyTree(Node *node) {
    if(isEmpty(node)) {
        return;
    }
    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
}


