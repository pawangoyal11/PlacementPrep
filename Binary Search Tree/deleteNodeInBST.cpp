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

// Search Node
// Delete Node

Node* findLastRight(Node* root)
{
    if(root->right == NULL)
    {
        return root;
    }

    return findLastRight(root->right);
}

Node* helper(Node* root)
{
    if(root->left == NULL)
    {
        return root->right;
    }
    else if(root->right == NULL)
    {
        return root->left;
    }
    Node* rightChild= root->right;
    Node* lastRight= findLastRight(root->left);
    lastRight->right= rightChild;
    return root->left;
}

Node* deleteNodeBST(Node* root, int key)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->val == key)
    {
        return helper(root);
    }

    Node* dummy= root;
    while(root != NULL)
    {
        if(root->val > key)
        {
            if(root->left != NULL && root->left->val == key)
            {
                root->left= helper(root->left);
                break;
            }
            else
            {
                root= root->left;
            }
        }
        else
        {
            if(root->right != NULL && root->right->val == key)
            {
                root->right= helper(root->right);
                break;
            }
            else
            {
                root= root->right;
            }
        }
    }
    return dummy;
}