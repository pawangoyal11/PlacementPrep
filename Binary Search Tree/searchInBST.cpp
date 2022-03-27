#include<iostream>
#include<vector>
#include<queue>
#include<map>

using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;
};

Node* searchBST(Node* root, int val)
{
    while(root != NULL && root->val != val)
    {
        root = val < root->val ? root->left: root->right;
    }
    return root;
}