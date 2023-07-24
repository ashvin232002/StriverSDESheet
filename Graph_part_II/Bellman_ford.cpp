#include<bits/stdc++.h>
using namespace std;


class Solution{
	public:
	/*  Function to implement Dijkstra
    *   adj: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector <int> bellman_ford(int V, vector<vector<int>> adj, int src) {
        // Code here
        vector<int> dist(V,1e8);
        
        dist[src] = 0;

        //try for the n-1 possible states 
        for(int i=0; i<V-1; i++){
           for (int j = 0; j < adj.size(); j++){
            int u = adj[j][0];  
            int v = adj[j][1];
            int w = adj[j][2];

            //update the distance like the dijktra 
            if(dist[u]!=1e8 && dist[v] > dist[u]+w)
                dist[v] = dist[u]+w;
           }
            
        }
        
        //try for the one last time
        //if the distance would be updated then we can prove that
        //there is a negative weight cycle, 
        bool flag =false;
        for(int j=0;j<adj.size();j++){
            int u = adj[j][0];  
            int v = adj[j][1];
            int w = adj[j][2];
            if(dist[v] > dist[u]+w)
                return {-1};
           }
        return dist;
    }
};