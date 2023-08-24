#include<bits/stdc++.h>
using namespace std;


// A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
//  */

//Function to return a list containing elements of left view of the binary tree.
void traverseLeft(Node* root,vector<int>&ans,int level){
    if(root==NULL){
        return;
    }
    if(level==ans.size()){
        ans.push_back(root->data);
    }
    traverseLeft(root->left,ans,level+1);
    traverseLeft(root->right,ans,level+1);
     
}
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int>ans;
   traverseLeft(root,ans,0);
   return ans;
}