#include<bits/stdc++.h>
using namespace std;




class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    void dfs(int V,vector<int> adj[] ,vector<int>& ans ,  vector<int>& Visited,int node){
        Visited[node]  =  1;
        ans.push_back(node);
        for(auto it:adj[node]){
            if(Visited[it]==-1){
                dfs(V,adj,ans,Visited,it);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>ans;
        vector<int>Visited(V,-1);
        for(int i =0;i<V;i++){
            if(Visited[i]==-1){
                dfs(V,adj,ans,Visited,i);
            }
        }
        return ans;
    }
};
