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

int findHeightLeft(Node* node)
{
    int height=0;
    while(node)
    {
        height++;
        node= node->left;
    }
    return height;
}

int findHeightRight(Node* node)
{
    int height=0;
    while(node)
    {
        height++;
        node= node->right;
    }
    return height;
}

int countNodes(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int lh= findHeightLeft(root);
    int rh= findHeightRight(root);

    if(lh == rh)
    {
        return (1<<lh)-1;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

// TC- O((LogN)^2)
// SC- O(LogN)