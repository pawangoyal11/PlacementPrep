#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<sstream>

using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;
};

// Encodes a tree to a single string.
string serialize(Node* root)
{
    if(!root)
    {
        return "";
    } 

    string s = "";
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* curNode = q.front();
        q.pop();
        if(curNode == NULL)
        {
            s.append("#,");
        }
        else
        {
            s.append(to_string(curNode->val)+',');
        }
        if(curNode != NULL)
        {
            q.push(curNode->left);
            q.push(curNode->right);
        }
    }
    return s;
}

// Decodes your encoded data to tree.
Node* deserialize(string data)
{
    if(data.size() == 0)
    {
        return NULL;
    }
    stringstream s(data);
    string str;
    getline(s, str, ',');
    Node* root;
    root->val= stoi(str);
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* node = q.front();
        q.pop();

        getline(s, str, ',');
        if(str == "#")
        {
            node->left = NULL;
        }
        else
        {
            Node* leftNode;
            leftNode->val= stoi(str);
            node->left = leftNode;
            q.push(leftNode);
        }

        getline(s, str, ',');
        if(str == "#")
        {
            node->right = NULL;
        }
        else
        {
            Node* rightNode;
            rightNode->val= stoi(str);
            node->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

// TC- O(N)   SC- O(N)