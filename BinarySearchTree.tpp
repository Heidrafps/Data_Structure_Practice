#include <iostream>

#include "BinarySearchTree.h"

template<class T>
bool BinarySearchTree<T>::isEmpty(Node* node) const {
    return node == nullptr;
}

template<class T>
void BinarySearchTree<T>::inorder(Node* node) {
    if (isEmpty(node)) return;
    inorder(node->left);
    std::cout << node->data << " ";
    inorder(node->right);
}

template<class T>
void BinarySearchTree<T>::preorder(Node* node) {
    if (isEmpty(node)) return;
    std::cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

template<class T>
void BinarySearchTree<T>::postorder(Node* node) {
    if (isEmpty(node)) return;
    postorder(node->left);
    postorder(node->right);
    std::cout << node->data << " ";
}

template<class T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::deepCopyTree(Node* tree) {
    if (isEmpty(tree)) return nullptr;
    Node* newNode = new Node(tree->data);
    newNode->left = deepCopyTree(tree->left);
    newNode->right = deepCopyTree(tree->right);
    return newNode;
}

template<class T>
void BinarySearchTree<T>::destroyTree(Node* node) {
    if (isEmpty(node)) return;
    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
}

// Constructors
template<class T>
BinarySearchTree<T>::BinarySearchTree() : m_root(nullptr) {}

template<class T>
BinarySearchTree<T>::BinarySearchTree(T data) {
    m_root = new Node(data);
}

// Copy constructor
template<class T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree& other) {
    m_root = deepCopyTree(other.m_root);
}

// Copy assignment
template<class T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(const BinarySearchTree& other) {
    if (this == &other) return *this;
    destroyTree(m_root);
    m_root = deepCopyTree(other.m_root);
    return *this;
}

// Move constructor
template<class T>
BinarySearchTree<T>::BinarySearchTree(BinarySearchTree&& other) noexcept {
    m_root = other.m_root;
    other.m_root = nullptr;
}

// Move assignment
template<class T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(BinarySearchTree&& other) noexcept {
    if (this == &other) return *this;
    destroyTree(m_root);
    m_root = other.m_root;
    other.m_root = nullptr;
    return *this;
}

// Destructor
template<class T>
BinarySearchTree<T>::~BinarySearchTree() {
    destroyTree(m_root);
}

// Insert
template<class T>
void BinarySearchTree<T>::insert(T data) {
    Node* newNode = new Node(data);
    if (isEmpty(m_root)) {
        m_root = newNode;
        return;
    }
    Node* current = m_root;
    Node* parent = nullptr;
    while (current != nullptr) {
        parent = current;
        if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    if (data < parent->data) parent->left = newNode;
    else parent->right = newNode;
}

// Search
template<class T>
bool BinarySearchTree<T>::search(T data) const {
    Node* current = m_root;
    while (current != nullptr) {
        if (data == current->data) return true;
        if (data < current->data) current = current->left;
        else current = current->right;
    }
    return false;
}

// Traversals
template<class T>
void BinarySearchTree<T>::printInorder() {
    inorder(m_root);
    std::cout << std::endl;
}

template<class T>
void BinarySearchTree<T>::printPreorder() {
    preorder(m_root);
    std::cout << std::endl;
}

template<class T>
void BinarySearchTree<T>::printPostorder() {
    postorder(m_root);
    std::cout << std::endl;
}

template<class T>
void BinarySearchTree<T>::deleteRoot() {
    if (isEmpty(m_root)) return;

    Node* oldRoot = m_root;

    // Case 1: No children
    if (!oldRoot->left && !oldRoot->right) {
        delete oldRoot;
        m_root = nullptr;
    }
    // Case 2: Only right child
    else if (!oldRoot->left) {
        m_root = oldRoot->right;
        delete oldRoot;
    }
    // Case 3: Only left child
    else if (!oldRoot->right) {
        m_root = oldRoot->left;
        delete oldRoot;
    }
    // Case 4: Two children+
    else {
        // Find inorder predecessor (max node in left subtree)
        Node* parent = oldRoot;
        Node* predecessor = oldRoot->left;
        while (predecessor->right) {
            parent = predecessor;
            predecessor = predecessor->right;
        }

        // Copy predecessor's value into root
        oldRoot->data = predecessor->data;

        // Delete predecessor node (it has at most one child)
        if (parent == oldRoot) {
            parent->left = predecessor->left;
        } else {
            parent->right = predecessor->left;
        }
        delete predecessor;
    }
}

