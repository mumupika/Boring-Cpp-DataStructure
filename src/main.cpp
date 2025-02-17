// main.cpp
import BinaryTreeNode;

int main() {
    BinaryTreeNode::BinaryTreeNode<int> * root = new BinaryTreeNode::BinaryTreeNode<int>(3);
    root -> print();
    BinaryTreeNode::clearTree(root);
    return 0;
}