/*
    Zig Zag Traversal or Spiral Traversal - Code Similar to Level Order
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;
};

class Solution{
    vector<vector<int>> zigzagLevelOrder(Node* root)
    {
        vector<vector<int>> result;
        if(root==NULL)
        {
            return result;
        }

        queue<Node*> q;
        q.push(root);
        bool leftToRight= true;

        while(!q.empty())
        {
            int size= q.size();
            vector<int> row(size);

            for(int i=0; i<size; i++)
            {
                Node* newNode= q.front();
                q.pop();

                int index = leftToRight ? i : size-1-i;
                row[index]= newNode->val;

                if(newNode->left)
                {
                    q.push(newNode->left);
                }
                if(newNode->right)
                {
                    q.push(newNode->right);
                }
            }
            leftToRight= !leftToRight;
            result.push_back(row);
        }
        return result;
    }
};