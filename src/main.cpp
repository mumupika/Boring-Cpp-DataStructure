# include "BinaryTree"
# include "BinaryTreeNode"
using namespace std;
int main()
{
    vector<BinaryTreeNode<int> *> preOrderList;
    vector<BinaryTreeNode<int> *> inOrderList;
    for(int i = 0; i < 6; i++)
    {
        BinaryTreeNode<int> * node = new BinaryTreeNode<int>(i);
        preOrderList.push_back(node);
    }
    inOrderList = {
        preOrderList[2],
        preOrderList[1],
        preOrderList[3],
        preOrderList[0],
        preOrderList[4],
        preOrderList[5]
    };
    BinaryTree<int> * root = new BinaryTree<int>();
    root -> fromPreInOrder(preOrderList, inOrderList);
    return 0;
}