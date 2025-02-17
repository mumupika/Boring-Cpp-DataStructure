export module BinaryTreeNode;

export import :BinaryTreeNode_impl;
export import :BinaryTreeNode_defs;

export class BinaryTreeNode;

void clearTree(BinaryTreeNode *root);

void findHeight(BinaryTreeNode *, int &, int);
