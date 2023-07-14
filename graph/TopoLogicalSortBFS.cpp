#include<bits/stdc++.h>
using  namespace std;

//USING QUEUE(Kahn Algorithm)
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int>ans;
	    vector<int>Ind(V,0);
	    for(int i =0;i<V;i++){
	        for(int j =0;j<adj[i].size();j++){
	            Ind[adj[i][j]]++;
	        }
	    }
	    
	    queue<int>q;
	    for(int i =0;i<Ind.size();i++){
	        if(Ind[i]==0){
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()){
	        int top = q.front();
	        ans.push_back(top);
	        q.pop();
	        for(auto it:adj[top]){
	            Ind[it]--;
	            if(Ind[it]==0){
	                q.push(it);
	            }
	        }
	    }
	    
	    return ans;
	}
};