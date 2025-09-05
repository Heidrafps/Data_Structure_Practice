//
// Created by kylet on 8/29/2025.
//

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

class BinarySearchTree {
private:
    struct Node {
        int data;
        Node *left, *right;
    };
    Node *root;

    /// This method will determine whether the tree is empty
    /// @return
    bool isempty(Node* node);
    // Traversals
    /// Left -> Middle -> Right
    /// This is helper method will print the inorder traversal of the Binary Tree
    /// @param tree
    void inorder(Node* node);

    /// Middle -> Left -> Right
    /// This is helper method will print out the preorder traversal of the Binary Tree
    /// @param tree
    void preorder(Node* node);

    /// Left-> Right -> Middle
    /// This is helper method will print out the postorder traversal of the Binary Tree
    /// @param tree
    void postorder(Node* node);

    /// This is helper method will DEEP COPY the nodes.
    /// @param trree
    Node* deepcopytree(Node* tree);

    /// This is helper method will deallocate and destroy the tree.
    /// @param node
    void destroytree(Node* node);
    public:
    // Constructor
    BinarySearchTree();
    explicit BinarySearchTree(const int data);

    // RULE OF 5
    BinarySearchTree(const BinarySearchTree&);
    BinarySearchTree& operator=(const BinarySearchTree&);
    BinarySearchTree(BinarySearchTree&&);
    BinarySearchTree& operator=(BinarySearchTree&&);
    ~BinarySearchTree();

    // Method
    /// This method will add a node onto the tree. If there isn't a tree yet instantiated,
    /// the provided data will become the root node in the tree.
    /// ** PRECONDITION **
    /// @param data Must be a valid integer type
    /// ** POST CONDITION **
    /// All the nodes on the left side will be STRICTLY less than the parent node
    /// All the nodes on the right side will be GREATER THAN or EQUAL to the parent node
    void insert(int data);

    /// 
    /// @param data 
    /// @return 
    bool search(int data);

    // Traversals
    /// Left -> Middle -> Right
    /// This method will print the inorder traversal of the Binary Tree
    /// @param tree
    void printinorder();

    /// Middle -> Left -> Right
    /// This method will print out the preorder traversal of the Binary Tree
    /// @param tree
    void printpreorder();

    /// Left-> Right -> Middle
    /// This method will print out the postorder traversal of the Binary Tree
    /// @param tree
    void printpostorder();

};


#endif //BINARYSEARCHTREE_H
