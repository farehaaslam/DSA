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
