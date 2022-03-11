#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class TreeGenerator{
    TreeNode *root;
    TreeGenerator(int val){
        queue<TreeNode*> nodes;
        TreeNode *head  = new TreeNode(0);
        root = head;
        nodes.push(head);
        int count = 1;
        while(count < val){
            int size = nodes.size();
            while(size -- > 0){
                TreeNode *cur = nodes.front();
                nodes.pop();
                cur->left = new TreeNode(count++);
                cur->right = new TreeNode(count++);
                nodes.push(cur->left);
                nodes.push(cur->right);
            }
        }
    }

    TreeNode* getRoot(){
        return root;
    }
};