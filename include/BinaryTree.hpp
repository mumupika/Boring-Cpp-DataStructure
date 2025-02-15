#ifndef BINARYTREE_HPP_
#define BINARYTREE_HPP_

#include <queue>

#include "BinaryTreeNode.hpp"

template<class T>
class BinaryTree {
private:
    BinaryTreeNode<T> *root;
    int height;

public:
    // Default Constructor.
    BinaryTree<T>() : root(nullptr) {}

    // Constructor with value, left and right tree.
    BinaryTree<T>(BinaryTree<T> * root) : root(root), height(root -> height) {}

    // Constructor with Node pointer;
    BinaryTree<T>(BinaryTreeNode<T> * rt) {
        root = rt;
        if(rt == nullptr)
            height = 0;
        else findHeight(rt, height, 1);
    }

    // Deconstructor.
    ~BinaryTree<T>()
    {
        clearTree(root);
    }

    // From tree to Iteration
    void preOrder(std::vector<BinaryTree<T> *> &list) {
        list.push_back(root);
        while (root->lChild) {
            preOrder(root->lChild, list);
        }
        while (root->rChild) {
            preOrder(root->rChild, list);
        }
    }

    void inOrder(std::vector<BinaryTree<T> *> &list) {
        while (root->lChild) {
            inOrder(root->lChild, list);
        }
        list.push_back(root);
        while (root->rChild) {
            inOrder(root->rChild, list);
        }
    }

    void postOrder(std::vector<BinaryTree<T> *> &list) {
        while (root->lChild) {
            postOrder(root->lChild, list);
        }
        while (root->rChild) {
            postOrder(root->rChild, list);
        }
        list.push_back(root);
    }
    

    void levelOrder(std::vector<BinaryTree<T> *> &list) {
        std::queue<BinaryTree<T> *> q;
        q.push(root);
        while (!q.empty()) {
            BinaryTreeNode<T> *cur = q.front();
            q.pop();
            list.push_back(cur);
            if (cur->lChild)
                q.push(cur->lChild);
            if (cur->rChild)
                q.push(cur->rChild);
        }
    }

    // From Iteration to Tree
    void fromPreInOrder(std::vector<BinaryTreeNode<T> *> &preOrder,
                                  std::vector<BinaryTreeNode<T> *> &inOrder) {
        std::unordered_map<BinaryTreeNode<T> *, int> mappings;
        // Build the Hash map from Inorder.
        for (int i = 0; i < inOrder.size(); i++) {
            mappings[inOrder[i]] = i;
        }
        root = preInBuildTree(0, inOrder.size() - 1, 0, inOrder.size() - 1, mappings,preOrder,inOrder);
        height = getHeight();
    }

    void fromPostInOrder(std::vector<BinaryTreeNode<T> *> &postOrder,
                                   std::vector<BinaryTreeNode<T> *> &inOrder) {
        std::unordered_map<BinaryTreeNode<T> *, int> mappings;
        for(int i = 0; i < inOrder.size(); i++) {
            mappings[inOrder[i]] = i;
        }
        int n = inOrder.size();
        root = postInBuildTree(0, n-1, 0, n-1, mappings,postOrder, inOrder);
        height = getHeight();
    }



    // The height of the tree.
    int getHeight() {
        int height = 0;
        if(root == nullptr) return height;
        findHeight(root, height, 1);
        return height;
    }

    
    // The subTree.
    BinaryTree<T> * getLeftTree() {
        BinaryTree<T> * leftTree = new BinaryTree<T>(root -> lChild);
        leftTree -> height = height - 1;
        return leftTree;
    }

    BinaryTree<T> * getRightTree() {
        BinaryTree<T> * rightTree = new BinaryTree<T>(root -> rChild);
        rightTree -> height = height - 1;
        return rightTree;
    }

    // The friend function. All instance are friend function.
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

template<class G>
BinaryTree<G> * castNodeToTree(BinaryTreeNode<G> * node);

template<class G>
BinaryTreeNode<G> * preInBuildTree(int, int, int, int, 
    std::unordered_map<BinaryTreeNode<G> *, int> &, 
    std::vector<BinaryTreeNode<G> * > &, 
    std::vector<BinaryTreeNode<G> * > &);

template<class G>
BinaryTreeNode<G> * postInBuildTree(int, int, int, int, 
    std::unordered_map<BinaryTreeNode<G> *, int> &, 
    std::vector<BinaryTreeNode<G> * > &, 
    std::vector<BinaryTreeNode<G> * > &);
#endif