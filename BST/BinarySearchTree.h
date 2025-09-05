//
// Created by kylet on 8/29/2025.
//

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
/* CLASS INVARIANT
 * - This tree will only have an ability to have up to two child nodes
 * - Data is strictly less than the parent node will always be on the left subtree. Otherwise, it will be located on the
 * right subtree.
 * - Each node has at MOST one parent. Nodes nodes will not point to the same Nodes nodes on the same height.
 * - Deleting the root node will always make the predecessor the new root node as long as
 * the tree has more than 3 nodes.
 */
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
    /// @param node A valid Node. The Node cannot be null.
    void inorder(Node* node);

    /// Middle -> Left -> Right
    /// This helper method will print out the preorder traversal of the Binary Tree
    /// @param node A valid Node. The Node cannot be null.
    void preorder(Node* node);

    /// Left-> Right -> Middle
    /// This helper method will print out the postorder traversal of the Binary Tree
    /// @param node A valid Node. The Node cannot be null.
    void postorder(Node* node);

    /// This helper method will DEEP COPY the nodes.
    /// @param tree A valid Node. The Node cannot be null.
    Node* deepCopyTree(Node* tree);

    /// This helper method will deallocate and destroy the tree.
    /// @param node A valid Node. The Node cannot be null.
    void destroyTree(Node* node);

    /// This method will balance the tree
    void balanceTree(Node* node);

    int height(Node* node);
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
    /// @param data Must be a valid data with the correct data type.
    ///
    void insert(T data);

    /// This method will determine whether the tree is empty. This method
    /// DOES NOT modify the tree.
    /// @param data Must be a valid data with the correct data type.
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

    /// This method will remove the root node. The new root node will always be the predecessor
    /// of the original root node
    void deleteRoot();

    /// This method will balance the tree
    void balanceTree();
};

#include "BinarySearchTree.tpp"
#endif //BINARYSEARCHTREE_H
