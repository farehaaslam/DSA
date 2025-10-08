#include<iostream>
#include<vector>
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
class Solution{
    public:
    int helper(Node * root, int maxi){
        if(!root) return 0;
        int l=helper(root->left,maxi);
        int r=helper(root->right,maxi);
        maxi=max(maxi,l+r);

        return max(l,r)+1;

    }
    int diam(Node * root){
        int maxi=0;
        return helper(root,maxi);
    }


};