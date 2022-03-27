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

int findMaxDistance(map<Node*, Node*> &mp, Node* target)
{
    queue<Node*> q;
    q.push(target);
    map<Node*, int> vis;
    vis[target]= 1;
    int maxi= 0;
    while(!q.empty())
    {
        int sz= q.size();
        int f1=0;
        for(int i=0; i<sz; i++)
        {
            auto node= q.front();
            q.pop();

            if(node->left && !vis[node->left])
            {
                f1=1;
                vis[node->left]=1;
                q.push(node->left);
            }
            if(node->right && !vis[node->right])
            {
                f1=1;
                vis[node->right]=1;
                q.push(node->right);
            }
            if(mp[node] && !vis[mp[node]])
            {
                f1=1;
                vis[mp[node]]=1;
                q.push(mp[node]);
            }
        }
        if(f1)
        {
            maxi++;
        }
    }
    return maxi;
}

Node* bfsToMapParents(Node* root, map<Node*, Node*> &mp, int start)
{
    queue<Node*> q;
    q.push(root);
    Node* res;
    while(!q.empty())
    {
        Node* node= q.front();
        if(node->val == start)
        {
            res= node;
        }
        q.pop();
        if(node->left)
        {
            mp[node->left]= node;
            q.push(node->left);
        }
        if(node->right)
        {
            mp[node->right]= node;
            q.push(node->right);
        }
    }
    return res;
}

int timeToBurnTree(Node* root, int start)
{
    map<Node*,Node*> mp;
    Node* target= bfsToMapParents(root, mp, start);
    int maxi= findMaxDistance(mp, target);
    return maxi;
}

// TC- O(N)  SC- O(N)