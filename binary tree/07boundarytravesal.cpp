#include<iostream>
#include<vector>
#include<queue>
#include<deque>
using namespace std;
class Node {
    public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    void left (Node * root,vector <int> & ans){
        if(!root->left && !root->right) return ;
         ans.push_back(root->data);
        if(!root->left) left(root->right,ans);
        else left(root->left,ans);
         return;
        
    }
    void leaf(Node* root, vector<int> &ans){
        if(! root) return ;
         if(!root->left && !root->right) ans.push_back(root->data);
        leaf(root->left,ans);
        leaf(root->right,ans);
       
        return;
    }
    void revright(Node* root, vector<int> & ans){
        if(!root->left && !root->right) return;
        if(!root->right) revright(root->left,ans);
        
       else  revright(root->right,ans);
        ans.push_back(root->data);
        return;
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int>ans;
        ans.push_back(root->data);
        if(!root->left && !root->right) return ans;
        //left trav
        if(root->left)
        left(root->left,ans);
        // leaf node
        leaf(root,ans);
        if(root->right)
        revright(root->right,ans);
        return ans;
    }
};