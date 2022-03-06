// TC- O(N)   SC- O(H)

#include<iostream>
#include<vector>

using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;
};

bool getPath(Node* root, vector<int> &arr, int x)
{
    if(root == NULL)
    {
        return false;
    }
    arr.push_back(root->val);

    if(root->val == x)
    {
        return true;
    }

    if (getPath(root->left, arr, x) || getPath(root->right, arr, x))
    {
        return true;
    }

    arr.pop_back();
    return false;
}

vector<int> solve(Node* A, int B)
{
    vector<int> ans;
    if(A==NULL)
    {
        return ans;
    }
    getPath(A, ans, B);
    return ans;
}