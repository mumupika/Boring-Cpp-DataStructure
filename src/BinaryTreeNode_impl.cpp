module;

#import <vector>
#import <unordered_map>
#import <iostream>


export module BinaryTreeNode:BinaryTreeNode_impl;
import :BinaryTreeNode_defs;

export namespace BinaryTreeNode {
    template<class T>
    void findHeight(BinaryTreeNode<T> * root, int & height, int current) {
        height = height > current ? height : current;
        if(root -> lChild) {
            findHeight(root -> lChild, height, current + 1);
        }
        if(root -> rChild) {
            findHeight(root -> rChild, height, current + 1);
        }
    }

    // Clear the Tree;

    template<class T>
    void clearTree(BinaryTreeNode<T> *root) {
        while (root->lChild) {
            clearTree(root->lChild);
        }
        while (root->rChild) {
            clearTree(root->rChild);
        }
        root->lChild = nullptr;
        root->rChild = nullptr;
        delete root;
    }

    template<class T>
    BinaryTreeNode<T> * postInBuildTree(int postLeft, int postRight, 
        int inLeft, int inRight, std::unordered_map<BinaryTreeNode<T> *, int> & mappings, 
        std::vector<BinaryTreeNode<T> * > &postOrder, std::vector<BinaryTreeNode<T> * > &inOrder) {
        if(postLeft > postRight) {
            return nullptr;
        }
        BinaryTreeNode<T> * root = postOrder[postRight];
        int rootIndex = mappings[root];
        root -> lChild = postInBuildTree(postLeft, postLeft + rootIndex - inLeft - 1, inLeft, rootIndex - 1, mappings, postOrder, inOrder);
        root -> rChild = postInBuildTree(postLeft + rootIndex - inLeft, postRight - 1, rootIndex + 1, inRight, mappings, postOrder, inOrder);
        return root;
    }

    template<class T>
    BinaryTreeNode<T> * preInBuildTree(int preLeft, int preRight,
        int inLeft, int inRight, std::unordered_map<BinaryTreeNode<T> *, int> & mappings, 
        std::vector<BinaryTreeNode<T> * > &preOrder, std::vector<BinaryTreeNode<T> * > &inOrder) {
        if(preLeft > preRight) {
            return nullptr;
        }
        BinaryTreeNode<T> * preRoot = preOrder[preLeft];
        // Find it in InOrder.
        int rootIndex = mappings[preRoot];
        preRoot -> lChild = preInBuildTree(preLeft+1, preLeft + rootIndex - inLeft, inLeft, rootIndex - 1, mappings, preOrder, inOrder);
        preRoot -> rChild = preInBuildTree(preLeft+rootIndex-inLeft+1, preRight, rootIndex + 1, inRight, mappings, preOrder, inOrder);
        return preRoot;
    }

    template<class T>
    void BinaryTreeNode<T>::print() {
        std::cout << "Data: " << data << std::endl;
    }
};