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
class Solution{  ///pre order traversal
    public:
    bool identical(Node * p, Node* q){
        if((!p && !q ) ) return true;
        if(!p && q) return false;
        if(p && !q) return false;
        return ((p->data==q->data) &&  identical(p->left ,q->left) && identical(p->right,p->right));

    }
};
