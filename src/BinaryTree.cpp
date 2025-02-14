#include "BinaryTree.hpp"
#include "InstantBinaryTree.cpp"

#include <functional>
#include <queue>
#include <unordered_map>
#include <vector>
// Clear the Tree;
template<class T>
void clearTree(BinaryTree<T> *root) {
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
void preOrder(BinaryTree<T> *root, std::vector<BinaryTree<T> *> &list) {
    list.push_back(root);
    while (root->lChild) {
        preOrder(root->lChild, list);
    }
    while (root->rChild) {
        preOrder(root->rChild, list);
    }
}

template<class T>
void inOrder(BinaryTree<T> *root, std::vector<BinaryTree<T> *> &list) {
    while (root->lChild) {
        inOrder(root->lChild, list);
    }
    list.push_back(root);
    while (root->rChild) {
        inOrder(root->rChild, list);
    }
}

template<class T>
void postOrder(BinaryTree<T> *root, std::vector<BinaryTree<T> *> &list) {
    while (root->lChild) {
        postOrder(root->lChild, list);
    }
    while (root->rChild) {
        postOrder(root->rChild, list);
    }
    list.push_back(root);
}

template<class T>
void levelOrder(BinaryTree<T> *root, std::vector<BinaryTree<T> *> &list) {
    std::queue<BinaryTree<T> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTree<T> *cur = q.front();
        q.pop();
        list.push_back(cur);
        if (cur->lChild)
            q.push(cur->lChild);
        if (cur->rChild)
            q.push(cur->rChild);
    }
}

template<class T>
BinaryTree<T> *fromPreInOrder(std::vector<T> &preOrder,
                              std::vector<T> &inOrder) {
    std::unordered_map<BinaryTree<T> *, int> mappings;
    // Build the Hash map from Inorder.
    for (int i = 0; i < inOrder.size(); i++) {
        mappings[inOrder[i]] = i;
    }
    std::function<BinaryTree<T> *(int, int, int, int)> BuildTree = [&](
        int preLeft, int preRight,
        int inLeft, int inRight
    ) -> BinaryTree<T> * {
        if(preLeft > preRight) return nullptr;

        BinaryTree<T> * preRoot = preLeft;
        // Find it in InOrder.
        int rootIndex = mappings[preRoot];
        preRoot -> lChild = BuildTree(preLeft+1, preLeft + rootIndex - inLeft, inLeft, rootIndex - 1);
        preRoot -> rChild = BuildTree(preLeft+rootIndex-inLeft+1, preRight, rootIndex + 1, inRight);
        return preRoot;
    };
    return BuildTree(0, inOrder.size() - 1, 0, inOrder.size() - 1);
}
