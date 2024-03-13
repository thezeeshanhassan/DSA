#include <iostream>
#include "Tree.h"
#include <queue>
using namespace std;

//// Create Tree Recursive

void Tree::create()
{
    root = createTreeR();
}

TreeNode *Tree::createTreeR()
{
    int data{};
    cout << "Enter Value" << endl;
    cin >> data;

    if (data == -1)
        return nullptr;
    TreeNode *newNode = new TreeNode(data);
    newNode->left = createTreeR();
    newNode->right = createTreeR();
    return newNode;
}

// PreOrder Traveral

void Tree::preOrder()
{
    cout << "Pre Order Traversal" << endl;
    preOrderTraversal(root);
}
void Tree::preOrderTraversal(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << ' ';
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// Level Order Traversal

void Tree::levelOrder()
{
    cout << "Level Order Traversal" << endl;
    levelOrderTraversal(root);
}

void Tree::levelOrderTraversal(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        TreeNode *front = q.front();
        q.pop();

        if (front == nullptr)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(nullptr);
            }
        }
        else
        {
            cout << front->data << ' ';
            if (front->left)
            {
                // cout << front->left->data << ' ';
                q.push(front->left);
            }
            if (front->right)
            {
                // cout << front->right->data << ' ';
                q.push(front->right);
            }
        }
    }
}

// Maximum Depth of Binary Tree

void Tree::maxDepth()
{
    cout << "Height Depth of Binary Tree Is " << endl;
    cout << maxDepthofBinaryTree(root);
}

int Tree::maxDepthofBinaryTree(TreeNode *root)
{
    if (!root)
        return 0;
    queue<TreeNode *> q;
    q.push(root);
    q.push(nullptr);
    int count{0};

    while (!q.empty())
    {
        TreeNode *front = q.front();
        q.pop();

        if (front == nullptr)
        {
            count += 1;
            if (!q.empty())
            {
                q.push(nullptr);
            }
        }
        else
        {
            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }
    }
    return count;
}

// Minimum Depth of Binary Tree

void Tree::minDepth()
{
    cout << "Minimum Depth of Binary Tree Is " << endl;
    cout << minepthofBinaryTree(root);
}

int Tree::minepthofBinaryTree(TreeNode *&root)
{
    if (!root)
        return 0;
    queue<TreeNode *> q;
    q.push(root);
    q.push(nullptr);
    int count{0};

    while (!q.empty())
    {
        TreeNode *front = q.front();
        q.pop();

        if (front == nullptr)
        {
            count += 1;
            if (!q.empty())
            {
                q.push(nullptr);
            }
        }
        else
        {
            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
            if (!front->left && !front->right)
            {
                break;
            }
        }
    }
    return count;
}