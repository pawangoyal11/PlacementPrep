/*
    Diameter of a Binary Tree is the longest path between any 2 nodes
    This path does not compulsorily need to pass via root
*/

#include<iostream>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;
};

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

// BRUTE FORCE APPROACH   TC- O(N^2)
int maxi= -1999;
void findMax(Node* node)
{
    if(node==NULL)
    {
        return;
    }

    int lh= findHeight(node->left);
    int rh= findHeight(node->right);
    maxi=max(maxi,lh+rh);
    findMax(node->left);
    findMax(node->right);
}

// TC- O(N)

int height(Node* node, int &maxVal)
{
    if(node==NULL)
    {
        return 0;
    }
    int lh= height(node->left,maxVal);
    int rh= height(node->right,maxVal);
    maxVal= max(maxVal,lh+rh);
    return 1+ max(lh,rh);
}

int diameter(Node* root)
{
    int diameter= 0;
    height(root, diameter);
    return diameter; 
}