/* 
    Preorder Inorder Postroder Traversals in One Traversal

    Algorithm-

    |    |
    |    |
    |    |
    |    |
    |____| (node,num) Stack-> LIFO

    if num==1
    {
        Preorder
        num++
        left
    }
    if num==2
    {
        Inorder
        num++
        right
    }
    if num==3
        Postroder

        TC- O(3*N)
        SC- O(N)
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode
{
    /* data */
    int val;
    TreeNode* left;
    TreeNode* right;
};


vector<int> preInPost(TreeNode* root)
{
    stack<pair<TreeNode*,int>> st;
    st.push({root,1});
    vector<int> pre,in,post;
    if(root==NULL)
    {
        return;
    }
    while(!st.empty())
    {
        auto it=st.top();
        st.pop();

        // this is a part of preorder
        // increment 1 to 2
        // push left

        if(it.second==1)
        {
            pre.push_back(it.first->val);
            it.second++;
            st.push(it);

            if(it.first->left!=NULL)
            {
                st.push({it.first->left,1});
            }
        }

        // this is a part of inorder
        // increment 2 to 3
        // push right

        if(it.second==2)
        {
            in.push_back(it.first->val);
            it.second++;
            st.push(it);

            if(it.first->right!=NULL)
            {
                st.push({it.first->right,1});
            }
        }

        // don't push it back again
        else
        {
            post.push_back(it.first->val);
        }
    }
}