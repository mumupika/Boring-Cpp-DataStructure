#ifndef BINARY_TREE_NODE_HPP_
#define BINARY_TREE_NODE_HPP_

#include <vector>
#include <unordered_map>

template<class T>
class BinaryTree;

template<class T>
class BinaryTreeNode {
    private:
        BinaryTreeNode<T> * lChild, *rChild;
        T data;
    public:
        // Default Constructor.
        BinaryTreeNode<T>() : lChild(nullptr), rChild(nullptr) {}

        // Constructor with value.
        BinaryTreeNode<T>(T val) : lChild(nullptr), rChild(nullptr), data(val) {}

        // Constructor with value, left and right tree.
        BinaryTreeNode<T>(T val, BinaryTreeNode<T> *left, BinaryTreeNode<T> *right) : lChild(left), rChild(right), data(val) {}

        // Deconstructor.
        ~BinaryTreeNode<T>(){};

        template<class G>
        friend void clearTree(BinaryTreeNode<T> *root);

        template<class G>
        friend void findHeight(BinaryTreeNode<G> *, int &, int);

        template<class G>
        friend BinaryTree<G> * castNodeToTree(BinaryTreeNode<G> * node);

        template<class G>
        friend BinaryTreeNode<G> * preInBuildTree(int, int, int, int, 
            std::unordered_map<BinaryTreeNode<G> *, int> &, 
            std::vector<BinaryTreeNode<G> * > &, 
            std::vector<BinaryTreeNode<G> * > &);

        template<class G>
        friend BinaryTreeNode<G> * postInBuildTree(int, int, int, int, 
            std::unordered_map<BinaryTreeNode<G> *, int> &, 
            std::vector<BinaryTreeNode<G> * > &, 
            std::vector<BinaryTreeNode<G> * > &);
};

template<class T>
void clearTree(BinaryTreeNode<T> *root);

template<class T>
void findHeight(BinaryTreeNode<T> *, int &, int);
#endif