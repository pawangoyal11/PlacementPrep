//  Check if two trees are identical

#include<iostream>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;
};

class Solution{
    public:
        bool isSameTree(Node* p, Node* q)
        {
            if(p==NULL && q==NULL)
            {
                return (p==q);
            }
            return ((p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
        }
};