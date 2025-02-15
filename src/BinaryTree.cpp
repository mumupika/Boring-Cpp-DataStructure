#include "BinaryTree.hpp"

template<class T>
BinaryTree<T> * castNodeToTree(BinaryTreeNode<T> * node) {
    BinaryTree<T> * ans = new BinaryTree<T>(node);
    return ans;
}