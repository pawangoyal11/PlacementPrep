/*
    Boundary Traversal in Binary Tree- Anticlockwise or Clockwise

    For Anticlockwise

    1. Left Boundary excluding leaf
    2. Leaf Nodes
    3. Right Boundary in reverse direction excluding leaf
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

void addLeftBoundary(Node* root, vector<int> &res)
{
    Node* curr= root->left;
    while(curr)
    {
        if((curr->left == NULL) && (curr->right == NULL))
        {
            res.push_back(root->val);
        }
        if(curr->left)
        {
            curr= curr->left;
        }
        else
        {
            curr= curr->right;
        }
    }
}

void addRightBoundary(Node* root, vector<int> &res)
{
    Node* curr= root->right;
    vector<int> tmp;
    while(curr)
    {
        if((curr->left == NULL) && (curr->right == NULL))
        {
            tmp.push_back(root->val);
        }
        if(curr->right)
        {
            curr= curr->right;
        }
        else
        {
            curr= curr->left;
        }
    }
    for(int i= tmp.size()-1; i>=0; i--)
    {
        res.push_back(tmp[i]);
    }
}

void addLeaves(Node* root, vector<int> &res)
{
    if((root->left == NULL) && (root->right == NULL))
        {
            res.push_back(root->val);
            return;
        }
        if(root->left)
        {
            addLeaves(root->left, res);
        }
        if(root->right)
        {
            addLeaves(root->right, res);
        }
}

vector<int> printBoundary(Node* root)
{
    vector<int> res;
    if(root == NULL)
    {
        return res;
    }
    if((root->left == NULL) && (root->right == NULL))
    {
        res.push_back(root->val);
    }
    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);
    return res;
}