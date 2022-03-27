// BST- L < N < R

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

// Find where the node can be and insert and this where will always be some leaf psoition.

Node* insertIntoBST(Node* root, int val)
{
    if(root == NULL)
    {
        Node* newNode;
        newNode->val= val;
        return newNode;
    }

    Node* curr= root;
    while(true)
    {
        if(curr->val <= val)
        {
            if(curr->right != NULL)
            {
                curr= curr->right;
            }
            else
            {
                Node* newNode;
                newNode->val= val;
                curr->right = newNode;
                break;
            }
        }
        else
        {
            if(curr->left != NULL)
            {
                curr->left;
            }
            else
            {
                Node* newNode;
                newNode->val = val;
                curr->left = newNode;
                break;
            }
        }
    }
    return root;
}

 // TC- O(Log(N))