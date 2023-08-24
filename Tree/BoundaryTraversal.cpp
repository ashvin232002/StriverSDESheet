#include<bits/stdc++.h>
using namespace std;



// /* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; 

class Solution {
public:
    void recursionLeft(Node* root,vector<int>&ans){
        if(root==NULL){
            return;
        }
        
        if(root->left==NULL && root->right==NULL){
            return;
        }
        
        ans.push_back(root->data);
        if(root->left){
            recursionLeft(root->left,ans);
        }else {
            recursionLeft(root->right,ans);
        }
    }
    void recursionRight(Node* root,vector<int>&ans){
        if(root==NULL){
            return;
        }
        
        if(root->left==NULL && root->right==NULL){
            return;
        }
        
        
        if(root->right){
            recursionRight(root->right,ans);
        }else {
            recursionRight(root->left,ans);
        }
        ans.push_back(root->data);
    }
    
    void recursionLeaf(Node* root,vector<int>& ans){
        if(root==NULL){
            return;
        }
        
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->data);
            return;
        }
        
        recursionLeaf(root->left,ans);
        recursionLeaf(root->right,ans);
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        if(root==NULL){
            return {};
        }
        
        vector<int>ans;
        ans.push_back(root->data);
        recursionLeft(root->left,ans);
        recursionLeaf(root->left,ans);
        recursionLeaf(root->right,ans);
        recursionRight(root->right,ans);
        return ans;
    }
};
