#include<bits/stdc++.h>
using namespace std;



//User function Template for C++
// Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
            vector<int>result;
            if(root==NULL)
               return result;
            queue<Node*>q;
            q.push(root);
            bool isLeftToright = true;
            
            while(!q.empty()){
                int size = q.size();
                vector<int>ans;
                
                for(int i =0;i<size;i++){
                    Node* frontNode = q.front();
                    q.pop();
                    ans.push_back(frontNode->data);
                    
                    if(frontNode->left)
                       q.push(frontNode->left);
                       
                    if(frontNode->right)
                       q.push(frontNode->right);
                }
                if(isLeftToright==true){
                    for(auto it:ans)
                       result.push_back(it);
                    isLeftToright=false;
                }else{
                    reverse(ans.begin(),ans.end());
                    for(auto it:ans)
                       result.push_back(it);
                    isLeftToright=true;
                }
            }
       return result;
    }	
};