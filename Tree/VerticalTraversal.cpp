#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node* left, * right;
};

class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        queue<pair<Node*,int>>q;
        map<int,vector<int>>mp;
        q.push({root,0});
        
        while(!q.empty()){
             auto top = q.front();
             q.pop();
             
             mp[top.second].push_back(top.first->data);
             if(top.first->left){
                 q.push({top.first->left, top.second-1});
             }
             if(top.first->right){
                 q.push({top.first->right,top.second+1});
             }
        }
        
        vector<int>ans;
        for(auto it:mp){
            vector<int>v =  it.second;
            for(int i =0;i<v.size();i++){
                ans.push_back(v[i]);
            }
        }
        return ans;
    }
};
