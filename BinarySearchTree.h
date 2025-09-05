//
// Created by kylet on 8/29/2025.
//

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
template<class T>
class BinarySearchTree {
private:
    struct Node {
        T data;
        Node *left, *right;
    };
    Node *m_root;

    /// This method will determine whether the tree is empty
    /// @return
    bool isEmpty(Node* node) const;
    // Traversals
    /// Left -> Middle -> Right
    /// This helper method will print the inorder traversal of the Binary Tree
    /// @param node
    void inorder(Node* node);

    /// Middle -> Left -> Right
    /// This helper method will print out the preorder traversal of the Binary Tree
    /// @param node
    void preorder(Node* node);

    /// Left-> Right -> Middle
    /// This helper method will print out the postorder traversal of the Binary Tree
    /// @param node
    void postorder(Node* node);

    /// This helper method will DEEP COPY the nodes.
    /// @param tree
    Node* deepCopyTree(Node* tree);

    /// This helper method will deallocate and destroy the tree.
    /// @param node
    void destroyTree(Node* node);
    public:
    // Constructor
    BinarySearchTree();
    explicit BinarySearchTree(T data);

    // **RULE OF 5**
    /// Copy Constructor: preforms a deep copy of another tree
    BinarySearchTree(const BinarySearchTree&);

    /// Copy Assignment Operator: Deletes the current tree and deep copies another tree
    /// @return 
    BinarySearchTree& operator=(const BinarySearchTree&);

    /// Move Constructor: Transfers the ownership of the tree to another resource
    BinarySearchTree(BinarySearchTree&&) noexcept;

    /// Move Assignment Operator: Deletes the current tree and transfers the owndership to another resource
    /// @return
    BinarySearchTree& operator=(BinarySearchTree&&) noexcept;

    /// Destructor: Deallocates all the memory used by the tree
    ~BinarySearchTree();

    // Method
    /// This method will add a node onto the tree. If there isn't a tree yet instantiated,
    /// the provided data will become the root node in the tree.
    /// ** PRECONDITION ***
    ///
    /// * POST CONDITION **
    /// All the nodes on the left side will be STRICTLY less than the parent node
    /// All the nodes on the right side will be GREATER THAN or EQUAL to the parent node
    /// @param data
    ///
    void insert(T data);

    /// This method will determine whether the tree is empty. This method
    /// DOES NOT modify the tree.
    /// @param data 
    /// @return 
    bool search(T data) const;

    // Traversals
    /// Left -> Middle -> Right
    /// This method will print the inorder traversal of the Binary Tree
    void printInorder();

    /// Middle -> Left -> Right
    /// This method will print out the preorder traversal of the Binary Tree
    void printPreorder();

    /// Left-> Right -> Middle
    /// This method will print out the postorder traversal of the Binary Trer
    void printPostorder();

};

#include "BinarySearchTree.tpp"
#endif //BINARYSEARCHTREE_H
