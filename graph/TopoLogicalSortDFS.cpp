#include<bits/stdc++.h>
using namespace std;



//USING STACK
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void dfs(int node,vector<int>& visited,stack<int>&s,vector<int>adj[]){
	    visited[node]=1;
	    for(auto it:adj[node]){
	        if(visited[it]==-1){
	            dfs(it,visited,s,adj);
	        }
	    }
	    s.push(node);
	    return;
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int>ans;
	    vector<int>visited(V,-1);
	    
	    stack<int>s;
	    for(int i =0;i<V;i++){
	        if(visited[i]==-1){
	            dfs(i,visited,s,adj);
	        }
	    }
	    
	    while(!s.empty()){
	        ans.push_back(s.top());
	        s.pop();
	    }
	    return ans;
	}
};