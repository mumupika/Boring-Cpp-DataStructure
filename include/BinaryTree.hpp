#ifndef BINARYTREE_HPP_
#define BINARYTREE_HPP_

#include <vector>
template<class T>
class BinaryTree {
private:
    BinaryTree<T> *lChild, *rChild;
    T data;

public:
    // Default Constructor.
    BinaryTree<T>() : lChild(nullptr), rChild(nullptr) {}

    // Constructor with value.
    BinaryTree<T>(T val) : lChild(nullptr), rChild(nullptr), data(val) {}

    // Constructor with value, left and right tree.
    BinaryTree<T>(T val, BinaryTree<T> *left, BinaryTree<T> *right) : lChild(left), rChild(right), data(val) {}

    // Deconstructor.
    ~BinaryTree<T>(){};

    // The friend function.
    template<class G>
    friend void clearTree(BinaryTree<G> *root);

    // From tree to Iteration
    void preOrder(BinaryTree<T> *root, std::vector<BinaryTree<T> *> &list);
    void inOrder(BinaryTree<T> *root, std::vector<BinaryTree<T> *> &list);
    void postOrder(BinaryTree<T> *root, std::vector<BinaryTree<T> *> &list);
    void levelOrder(BinaryTree<T> *root, std::vector<BinaryTree<T> *> &list);

    // From Iteration to Tree
    BinaryTree<T> *fromPreInOrder(std::vector<T> &, std::vector<T> &);
    BinaryTree<T> *fromPostInOrder(std::vector<T> &, std::vector<T> &);

    // The height of the tree.
    int height(BinaryTree<T> *root);

    // The data of this node.
    T getData(BinaryTree<T> *node);

    // The child of the node.
    BinaryTree<T> *getLeftChild(BinaryTree<T> *node);
    BinaryTree<T> *getRightChild(BinaryTree<T> *node);
};

template<class T>
void clearTree(BinaryTree<T> *root);
#endif