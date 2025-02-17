module;

#import <vector>
#import <unordered_map>


export module BinaryTreeNode:BinaryTreeNode_impl;
import :BinaryTreeNode_defs;

void findHeight(BinaryTreeNode * root, int & height, int current) {
    height = height > current ? height : current;
    if(root -> lChild) {
        findHeight(root -> lChild, height, current + 1);
    }
    if(root -> rChild) {
        findHeight(root -> rChild, height, current + 1);
    }
}

// Clear the Tree;

void clearTree(BinaryTreeNode *root) {
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


BinaryTreeNode * postInBuildTree(int postLeft, int postRight, 
    int inLeft, int inRight, std::unordered_map<BinaryTreeNode *, int> & mappings, 
    std::vector<BinaryTreeNode * > &postOrder, std::vector<BinaryTreeNode * > &inOrder) {
    if(postLeft > postRight) {
        return nullptr;
    }
    BinaryTreeNode * root = postOrder[postRight];
    int rootIndex = mappings[root];
    root -> lChild = postInBuildTree(postLeft, postLeft + rootIndex - inLeft - 1, inLeft, rootIndex - 1, mappings, postOrder, inOrder);
    root -> rChild = postInBuildTree(postLeft + rootIndex - inLeft, postRight - 1, rootIndex + 1, inRight, mappings, postOrder, inOrder);
    return root;
}


BinaryTreeNode * preInBuildTree(int preLeft, int preRight,
    int inLeft, int inRight, std::unordered_map<BinaryTreeNode *, int> & mappings, 
    std::vector<BinaryTreeNode * > &preOrder, std::vector<BinaryTreeNode * > &inOrder) {
    if(preLeft > preRight) {
        return nullptr;
    }
    BinaryTreeNode * preRoot = preOrder[preLeft];
    // Find it in InOrder.
    int rootIndex = mappings[preRoot];
    preRoot -> lChild = preInBuildTree(preLeft+1, preLeft + rootIndex - inLeft, inLeft, rootIndex - 1, mappings, preOrder, inOrder);
    preRoot -> rChild = preInBuildTree(preLeft+rootIndex-inLeft+1, preRight, rootIndex + 1, inRight, mappings, preOrder, inOrder);
    return preRoot;
}