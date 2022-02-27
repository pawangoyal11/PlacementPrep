/*
    Using Recursion- getting maxL & maxR path sum
*/

#include<iostream>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;
};

int maxPathSum(Node* root)
{
    int maxi= INT8_MIN;
    maxPathDown(root,maxi);
    return maxi;
}

int maxPathDown(Node* node, int &maxi)
{
    if(node==NULL)
    {
        return 0; 
    }
    int leftSum= max(0, maxPathDown(node->left,maxi));
    int rightSum= max(0, maxPathDown(node->right, maxi));
    maxi= max(maxi, leftSum+rightSum+node->val);
    return (node->val) + max(leftSum,rightSum);
}