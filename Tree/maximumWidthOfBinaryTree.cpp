/*
    Width- no. of nodes in a level between any 2 nodes

    1. First we wil do indexing 0-based or 1-based
*/

#include<iostream>
#include<queue>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;
};

int maxWidthOfBinaryTree(Node* root)
{
    if(!root)
    {
        return 0;
    }
    int ans= 0;

    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while(!q.empty())
    {
        int size= q.size();
        int min= q.front().second;
        int first, last;
        for(int i=0; i<size; i++)
        {
            int curr_id= q.front().second-min;
            Node* node= q.front().first;
            q.pop();
            if(i==0)
            {
                first= curr_id;
            }
            if(i==size-1)
            {
                last= curr_id;
            }
            if(node->left)
            {
                q.push({node->left, curr_id*2+1});
            }
            if(node->right)
            {
                q.push({node->right, curr_id*2+2});
            }
        }
        ans= max(ans, last-first+1);
    }
    return ans;
}