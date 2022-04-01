// LCA- Lowest Common Ancestor- First from bottom or the last from top intersection point in the path

#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<stack>

using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;
};

Node* LCA(Node* root, Node* p, Node* q)
{
    if(root == NULL)
    {
        return NULL;
    }
    int curr= root->val;

    if(curr < p->val && curr < q-> val)
    {
        return LCA(root->right, p, q);
    }

    if(curr > p->val && curr > q-> val)
    {
        return LCA(root->left, p, q);
    }
    return root;
}