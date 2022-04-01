#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<stack>
#include<limits.h>

using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;
};

bool isValidBST(Node* root, long minVal, long maxVal)
{
    if(root == NULL)
    {
        return true;
    }
    if(root->val >= maxVal || root->val <= minVal)
    {
        return false;
    }
    return isValidBST(root->left, minVal, root->val) && isValidBST(root->right, root->val, maxVal);
}

bool isValidBST(Node* root)
{
    return isValidBST(root, LONG_MIN, LONG_MAX);
}