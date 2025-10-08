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
    vector<int> zigZagTraversal(Node* root) {
        // code here
        vector<int>ans;
        queue<Node*>q;
        q.push(root);
        bool flag=true; //true->left
        while(!q.empty()){
            int n=q.size();
             deque<int>dq;
            for(int i=0;i<n;i++){
           
            Node* node=q.front();
            q.pop();
            if(flag){
                dq.push_back(node->data);
            }
            else{
                dq.push_front(node->data);
            }
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right); 
            
            }
            ans.insert(ans.end(),dq.begin(),dq.end());
            flag=!flag;
            
            
        }
        return ans;
    }
};