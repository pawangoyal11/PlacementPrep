#include<iostream>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;
};

Node* lowestCommonAncestor(Node* root, Node* p, Node* q)
{
    if(root==NULL || root==p || root==q)
    {
        return root;
    }
    Node* left= lowestCommonAncestor(root->left, p, q);
    Node* right= lowestCommonAncestor(root->right, p, q);

    if(left==NULL)
    {
        return right;
    }
    if(right==NULL)
    {
        return left;
    }
    else
    {
        return root;
    }
}

// TC- O(N)   SC- O(N)
