module;
#import <vector>
#import <unordered_map>

export module BinaryTreeNode: BinaryTreeNode_defs;

export class BinaryTreeNode
{
    private:
        BinaryTreeNode * lChild, *rChild;
        int data;
    public:
        // Default Constructor.
        BinaryTreeNode() : lChild(nullptr), rChild(nullptr) {}

        // Constructor with value.
        BinaryTreeNode(int val) : lChild(nullptr), rChild(nullptr), data(val) {}

        // Constructor with value, left and right tree.
        BinaryTreeNode(int val, BinaryTreeNode *left, BinaryTreeNode *right) : lChild(left), rChild(right), data(val) {}

        // Deconstructor.
        ~BinaryTreeNode(){};

        friend void clearTree(BinaryTreeNode *root);

        friend void findHeight(BinaryTreeNode *, int &, int);

        friend BinaryTreeNode * preInBuildTree(int, int, int, int, 
            std::unordered_map<BinaryTreeNode *, int> &, 
            std::vector<BinaryTreeNode * > &, 
            std::vector<BinaryTreeNode * > &);

        friend BinaryTreeNode * postInBuildTree(int, int, int, int, 
            std::unordered_map<BinaryTreeNode *, int> &, 
            std::vector<BinaryTreeNode * > &, 
            std::vector<BinaryTreeNode * > &);
};