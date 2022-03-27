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

int findCeil(Node* root, int key)
{
    int ceil= -1;
    while(root)
    {
        if(root->val == key)
        {
            ceil= root->val;
            return ceil;
        }

        if(key > root->val)
        {
            root= root->right;
        }

        else
        {
            ceil= root->val;
            root= root->left;
        }
    }
    return ceil;
}

// TC- O(Log(N))