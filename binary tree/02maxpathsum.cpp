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

class Solution {
  public:
  int helper(Node* root,int & maxsum){
      if(!root) return 0;
      int lmaxsum=max(0,helper(root->left,maxsum));
      int rmaxsum=max(0,helper(root->right,maxsum));
      maxsum=max(maxsum,lmaxsum+rmaxsum+root->data);
    return root->data +max(lmaxsum,rmaxsum);
      
  }
    int findMaxSum(Node *root) {
        // code here
        int maxsum=INT_MIN;
     helper(root,maxsum);
     return maxsum;
    }
};