/*
    We will solve it with Reverse Pre-Order.
    Root-> Right-> Left

    f(node, level)
    {
        if(node==null)
            return;
        if(level==ds.size)
        {
            ds.add(node)
        }
        f(node->right, level+1);
        f(node->left, level+1);
    }
*/

#include<iostream>
#include<vector>

using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;
};

// Right View

void recursionRightView(Node* node, int level, vector<int> &res)
{
    if(node == NULL)
    {
        return;
    }
    if(res.size()==level)
    {
        res.push_back(node->val);
    }
    recursionRightView(node->right, level+1, res);
    recursionRightView(node->left, level+1, res);
}

vector<int> rightSideView(Node* root)
{
    vector<int> res;
    recursionRightView(root, 0, res);
    return res;
}

// Left View

void recursionLeftView(Node* node, int level, vector<int> &ans)
{
    if(node == NULL)
    {
        return;
    }
    if(ans.size()==level)
    {
        ans.push_back(node->val);
    }
    recursionLeftView(node->left, level+1, ans);
    recursionLeftView(node->right, level+1, ans);
}

vector<int> leftSideView(Node* root)
{
    vector<int> ans;
    recursionLeftView(root, 0, ans);
    return ans;
}