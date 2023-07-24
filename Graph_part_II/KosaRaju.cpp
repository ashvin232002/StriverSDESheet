#include<bits/stdc++.h>
using namespace std;


// SCC
//KOSARAJU'S ALGORITHM TO FIND THE STRONGLY CONNECTED COMPONENTS
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	
	void dfs(vector<int>& Vis,int node,stack<int>& s,vector<vector<int>>& adj){
	     Vis[node] = 1;
	     
	     for(auto it:adj[node]){
	         if(Vis[it]==0){
	             dfs(Vis,it,s,adj);
	         }
	     }
	     s.push(node);
	}
	
	void dfs2(vector<int>adjT[] ,int node , vector<int>& Vis){
	    Vis[node]=1;
	    
	    for(auto it:adjT[node]){
	        if(Vis[it]==0){
	            dfs2(adjT,it,Vis);
	        }
	    }
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<int>Vis(V,0);
        stack<int>s;
        for(int i =0;i<V;i++){
            if(Vis[i]==0){
                dfs(Vis,i,s,adj);
            }
        }
        
        vector<int>adjT[V];
        
        for(int i =0;i<V;i++){
            Vis[i] = 0;
            for(auto it:adj[i]){
                adjT[it].push_back(i);
            }
        }
        
        int count  = 0;
        while(!s.empty()){
            int top = s.top();
            s.pop();
            
            if(Vis[top]==1){
                continue;
            }
            dfs2(adjT,top,Vis) ;
            count++;
        }
        
        return count;
    }
};
