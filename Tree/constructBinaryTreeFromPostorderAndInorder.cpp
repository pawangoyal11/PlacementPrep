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

Node* buildTree(vector<int>& postorder, vector<int>& inorder){
    map<int, int> inMap;

    if(postorder.size() != inorder.size())
    {
        return NULL;
    }

    for(int i=0; i<inorder.size(); i++)
    {
        inMap[inorder[i]]= i;
    }

    Node* root= buildTree(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, inMap);

    return root;
}

Node* buildTree(vector<int>& postorder, int postStart, int postEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int> inMap)
{
    if(postStart > postEnd || inStart > inEnd)
    {
        return NULL;
    }

    Node* root;
    root->val= postorder[postEnd];
    int inRoot= inMap[root->val];
    int numLeft= inRoot - inStart;

    root->left= buildTree(postorder, postStart, postStart + numLeft-1, inorder, inStart, inRoot-1, inMap);
    root->right= buildTree(postorder, postStart + numLeft, postEnd-1, inorder, inRoot+1, inEnd, inMap);

    return root;

}

// TC- O(N)*O(LogN)
// SC- O(N)