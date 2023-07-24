#include<bits/stdc++.h>
using namespace std;


// MST - MINIMUM SPANNING TREE  (TO FIND THE MINIMUM SPANNING TREE)
// APPROACH (GREEDY )


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        //prime's algorithm
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>Vis(V,0);
        
        pq.push({0,0});
        int sum = 0;
        
        while(!pq.empty()){
            auto it =  pq.top();
            pq.pop();
            
            int node  =  it.second;
            int wt  =  it.first;
            
            if(Vis[node]==1){
               continue;
            }
            
            //This is when I add to The MST
            Vis[node]=1;
            sum+=wt;
            for(auto it: adj[node]){
                int adjnode=it[0];
                int edw=it[1];
                if(!Vis[adjnode])
                {
                    pq.push({edw,adjnode});
                }
            }
        }
        return sum;
    }
};
