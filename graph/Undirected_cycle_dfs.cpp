#include<bits/stdc++.h>
using namespace std;



//USING DFS APPROACH
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int node,vector<int> adj[],vector<int>& visited,int par){
        visited[node]=1;
        for(auto it:adj[node]){
            if(!visited[it]){
                if(dfs(it,adj,visited,node)){
                    return true;
                }
            }else if(it!=par){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>visited(V,0);
        for(int i =0;i<V;i++){
            if(!visited[i]){
                if(dfs(i,adj,visited,-1)){
                    return true;
                }
            }
        }
        return false;
    }
};
