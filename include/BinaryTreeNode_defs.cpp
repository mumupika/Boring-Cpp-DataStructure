module;
#import <unordered_map>
#import <vector>


export module BinaryTreeNode:BinaryTreeNode_defs;

export template<class T>
class BinaryTreeNode {
private:
    BinaryTreeNode<T> *lChild, *rChild;
    T data;

public:
    // Default Constructor.
    BinaryTreeNode<T>() : lChild(nullptr), rChild(nullptr) {}

    // Constructor with value.
    BinaryTreeNode<T>(int val) : lChild(nullptr), rChild(nullptr), data(val) {}

    // Constructor with value, left and right tree.
    BinaryTreeNode<T>(int val, BinaryTreeNode *left, BinaryTreeNode *right) : lChild(left), rChild(right), data(val) {}

    // Deconstructor.
    ~BinaryTreeNode<T>(){};

    void print();

    template<class G>
    friend void clearTree(BinaryTreeNode<G> *root);

    template<class G>
    friend void findHeight(BinaryTreeNode<G> *, int &, int);

    template<class G>
    friend BinaryTreeNode<G> *preInBuildTree(int, int, int, int,
                                             std::unordered_map<BinaryTreeNode<G> *, int> &,
                                             std::vector<BinaryTreeNode<G> *> &,
                                             std::vector<BinaryTreeNode<G> *> &);

    template<class G>
    friend BinaryTreeNode<G> *postInBuildTree(int, int, int, int,
                                              std::unordered_map<BinaryTreeNode<G> *, int> &,
                                              std::vector<BinaryTreeNode<G> *> &,
                                              std::vector<BinaryTreeNode<G> *> &);
};

template<class G>
void clearTree(BinaryTreeNode<G> *root);

template<class G>
void findHeight(BinaryTreeNode<G> *, int &, int);

template<class G>
BinaryTreeNode<G> *preInBuildTree(int, int, int, int,
                                  std::unordered_map<BinaryTreeNode<G> *, int> &,
                                  std::vector<BinaryTreeNode<G> *> &,
                                  std::vector<BinaryTreeNode<G> *> &);

template<class G>
BinaryTreeNode<G> *postInBuildTree(int, int, int, int,
                                   std::unordered_map<BinaryTreeNode<G> *, int> &,
                                   std::vector<BinaryTreeNode<G> *> &,
                                   std::vector<BinaryTreeNode<G> *> &);