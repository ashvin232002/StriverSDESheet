#include<bits/stdc++.h>
using namespace std;



// DFS + CYCLE DETECTION IN DIRECTED GRAPH
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node,vector<int>adj[] ,vector<int>& visited,vector<int>& pathVis){
        visited[node]=1;
        pathVis[node] = 1;
        
        for(auto it:adj[node]){
            if(visited[it]==0){
                if(dfs(it,adj,visited,pathVis))return true;
            }else if(pathVis[it]==1) {
                return true;
            }
        }
        pathVis[node]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>visited(V,0);
        vector<int>pathVis(V,0);
        
        
        for(int i =0 ;i<V;i++){
            if(visited[i]==0){
                if(dfs(i,adj,visited,pathVis))return true;
            }
        }
        return false;
    }
};