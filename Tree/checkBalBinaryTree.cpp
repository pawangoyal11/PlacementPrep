/*
    A tree is Balanced Binary Tree if the |height(left)-height(right)|<=1 for each node
*/

#include<iostream>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;
};

// Basic Approach  TC- O(N^2)

int findHeight(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int lh= findHeight(root->left);
    int rh= findHeight(root->right);
    return 1 + max(lh,rh);
}

bool check(Node* node)
{
    if (node==NULL)
    {
        return true;
    }

    int lh= findHeight(node->left);
    int rh= findHeight(node->right);

    if(abs(rh-lh)>1)
    {
        return false;
    }

    bool left= check(node->left);
    bool right= check(node->right);

    if(!left || !right)
    {
        return false;
    }

    return true;
}


// For TC- O(N) Solution

int findTreeHeight(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int lh= findTreeHeight(root->left);
    int rh= findTreeHeight(root->right);

    if(lh==-1 || rh==-1)
    {
        return -1;
    }
    if(abs(lh-rh)>1)
    {
        return -1;
    }
    return 1 + max(lh,rh);
}  
