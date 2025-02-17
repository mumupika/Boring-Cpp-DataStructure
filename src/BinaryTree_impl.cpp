export module BinaryTree:BinaryTree_impl;
import :BinaryTree_defs;

template<class T>
BinaryTree<T> * castNodeToTree(BinaryTreeNode<T> * node) {
    BinaryTree<T> * ans = new BinaryTree<T>(node);
    return ans;
}