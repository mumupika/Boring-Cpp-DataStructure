// main.cpp
import BinaryTree;

int main() {
    BinaryTreeNode<int> * root = new BinaryTreeNode<int>(3);
    root -> print();
    clearTree(root);
    return 0;
}