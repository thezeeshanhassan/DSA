#ifndef TreeNode_h
#define TreeNode_h

class TreeNode
{
private:
    friend class Tree;
    int data;
    TreeNode *left;
    TreeNode *right;

public:
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};
#endif