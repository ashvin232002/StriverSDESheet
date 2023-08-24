#include<bits/stdc++.h>
using namespace std;



struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        queue<pair<Node*,int>>q;
        q.push({root,0});
        map<int,int>mp;
        
        mp[0] = (root->data);
        
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            if(!mp[top.second]){
                mp[top.second] = top.first->data;
            }
            if(top.first->left){
                q.push({top.first->left,top.second-1});
            }
            if(top.first->right){
                q.push({top.first->right,top.second+1});
            }
        }
        
        vector<int>ans;
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }

};