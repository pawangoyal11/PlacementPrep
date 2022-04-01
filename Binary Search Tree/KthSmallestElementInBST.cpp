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

// Inorder Traversal in BST is sorted
// Inorder- Left Node Right

// Recursive Traversal- TC-> O(N)  SC-> O(N)
// Iterative Traversal- TC-> O(N)  SC-> O(N)
// Morris Traversal- TC-> O(N)  SC-> O(1)

// One traversal to calc no. of nodes N
// for Kth largest-> (N-Kth) smallest

int kthSmallest(Node* root, int k)
{
    stack<Node*> st; 
    Node* node= root;
    int cnt= 0;

    while(true)
    {
        if(node != NULL)
        {
            st.push(node);
            node= node->left;
        }
        else
        {
            if(st.empty())
            {
                break;
            }
            node = st.top();
            st.pop();
            // inorder.add(node->val)
            cnt++;
            if(cnt==k)
            {
                return node->val;
            }
            node= node->right;
        }
        return -1;
    }
}