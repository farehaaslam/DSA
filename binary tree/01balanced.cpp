#include<iostream>
#include<vector>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
  
    int helper(Node* root){
        if(!root) return 0;
        int l=helper(root->left);
        if(l==-1) return -1;
        int r=helper(root->right);
       if(r==-1) return -1;
        if(abs(l-r)>1) return -1;
        return 1+max(l,r);
    }
    bool isBalanced(Node* root) {
        // code here
        return (helper(root)!=-1);
        
    }
};

// post order traversal 