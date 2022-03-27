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

Node* buildTree(vector<int>& preorder, vector<int>& inorder){
    map<int, int> inMap;

    for(int i=0; i<inorder.size(); i++)
    {
        inMap[inorder[i]]= i;
    }

    Node* root= buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);

    return root;
}

Node* buildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int> inMap)
{
    if(preStart > preEnd || inStart > inEnd)
    {
        return NULL;
    }

    Node* root;
    root->val= preorder[preStart];
    int inRoot= inMap[root->val];
    int numLeft= inRoot - inStart;
    
    root->left= buildTree(preorder, preStart + 1, preStart + numLeft, inorder, inStart, inRoot-1, inMap);
    root->right= buildTree(preorder, preStart + numLeft + 1, preEnd, inorder, inRoot+1, inEnd, inMap);

    return root;
}