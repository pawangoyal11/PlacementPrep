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

 int floorBST(Node* root, int key)
 {
     int floor= -1;
     while(root)
     {
         if(key == root->val)
         {
             floor= root->val;
             return floor;
         }
         
         if(key > root->val)
         {
             floor= root->val;
             root= root->right;
         }

         else
         {
             root= root->left;
         }
     }
     return floor;
 }