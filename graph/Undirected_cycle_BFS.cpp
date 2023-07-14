#include<bits/stdc++.h>
using namespace std;



//USING BFS APPROACH
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfs(int node,vector<int> adj[],vector<int>& visited){
        queue<pair<int,int>>q;
        q.push({node,-1});
        visited[node]=1;
        
        while(!q.empty()){
            auto front   =  q.front();
            q.pop();
            visited[front.first]=1;
            for(auto it:adj[front.first]){
                if(!visited[it]){
                    q.push({it,front.first});
                }else if(it!=front.second){
                        return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>visited(V,0);
        for(int i =0;i<V;i++){
            if(!visited[i]){
                if(bfs(i,adj,visited)){
                    return true;
                }
            }
        }
        return false;
    }
};