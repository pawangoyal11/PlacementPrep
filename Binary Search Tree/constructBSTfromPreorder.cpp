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

// BST Inorder traversal is sorted