#include<iostream>
#include<vector>
#include<queue>
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
void bfs(Node *root){
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node *node=q.front();
        q.pop();

        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
        
    }

}