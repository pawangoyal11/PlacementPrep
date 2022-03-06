/*
    Symetric Binary Tree- It forms a mirror image arounf the center.

    For Mirror- 
    1. Left appears Right
    2. Right appears Left
*/

#include<iostream>
#include<vector>

using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;
};

bool isSymetricHelp(Node* left, Node* right)
{
    if(left==NULL || right==NULL)
    {
        return left == right;
    }
    if(left->val!=right->val)
    {
        return false;
    }
    return isSymetricHelp(left->left, right->right) && isSymetricHelp(left->right, right->left);
}

bool isSymetric(Node* root)
{
    return root==NULL || isSymetricHelp(root->left, root->right);
}