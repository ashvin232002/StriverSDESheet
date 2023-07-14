#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>Indegree(V,0);
        queue<int>q;
        for(int i =0 ;i<V;i++){
            for(auto it:adj[i]){
                Indegree[it]++;
            }
        }
        
        for(int i =0;i<V;i++){
            if(Indegree[i]==0){
                q.push(i);
            }
        }
        
        int count = 0 ; 
        while(!q.empty()){
            int top =  q.front();
            q.pop();
            
            count++;
            for(auto it:adj[top]){
                Indegree[it]--;
                if(Indegree[it]==0){
                    q.push(it);
                }
            }
        }
        
        if(count==V){
            return false;
        }
        return true;
        
    }
};


