// Height of Binary Tree or Depth of Binary Tree
// TC- O(N)   SC- O(N)

#include<iostream>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;
};

int heightOfBinaryTree(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int lh= heightOfBinaryTree(root->left);
    int rh= heightOfBinaryTree(root->right);
    return 1 + max(lh,rh);
}
