#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node* left;
    Node* right;
};


class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        queue<pair<Node*,int>>q;
        q.push({root,0});
        map<int,int>mp;
        mp[0] = root->data;
        
        while(!q.empty()){
            auto front =  q.front();
            q.pop();
            
            mp[front.second] = front.first->data;
            if(front.first->left){
                q.push({front.first->left,front.second-1});
            }
            if(front.first->right){
                q.push({front.first->right,front.second+1});
            }
        }
        
        vector<int>ans;
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};