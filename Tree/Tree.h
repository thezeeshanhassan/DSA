#ifndef Tree_h
#define Tree_h
#include "TreeNode.h"

class Tree
{
private:
    TreeNode *root;

public:
    Tree() : root(nullptr){};
    TreeNode *createTreeR();
    void create();
    void preOrder();
    void preOrderTraversal(TreeNode *);
    void levelOrderTraversal(TreeNode *);
    void levelOrder();
    int maxDepthofBinaryTree(TreeNode *);
    void maxDepth();
    int minepthofBinaryTree(TreeNode *&);
    bool pathSumofBinaryTree(TreeNode *, int sum, int targetSum);
    void pathSum();
    void minDepth();
};
#endif
