#include<bits/stdc++.h>
using namespace std;

// MST - MINIMUM SPANNING TREE  
//KRUSHKAL ALGORITHM TO FIND THE MINIMUM SPANNING TREE
class DisjointSet{ 
    public:
    vector<int>rank,parent,size;
    
    DisjointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1);
        parent.resize(n+1);
        for(int i =1;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }

    int findUpar(int node){
        if(parent[node]==node){
            return node;
        }

        return  parent[node] = findUpar(parent[node]);
    }


    void unionByRank(int u ,int v){
        int ulp_u =  findUpar(u);
        int ulp_v =  findUpar(v);

        if(ulp_u==ulp_v){
            return;
        }

        if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]  = ulp_u;
            rank[ulp_u]++;
        }else{
            parent[ulp_u] =  ulp_v;
            rank[ulp_v]++;
        }
    }

    void unionBySize(int u,int v){
        int ulp_u =  findUpar(u);
        int ulp_v =  findUpar(v);

        if(ulp_u == ulp_v){
            return;
        }

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] =  ulp_v;
            size[ulp_v]+=size[ulp_u];
        }else{
            parent[ulp_v] =  ulp_u;
            size[ulp_u] += size[ulp_v] ; 
        }
    }
};


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        DisjointSet ds(V);
        
        
        vector<pair<int,pair<int,int>>>edges;
        for(int i = 0;i<V;i++){
            for(auto it:adj[i]){
                int adjNode  =  it[0];
                int wt  = it[1];
                int node  =i ;
                
                edges.push_back({wt,{node,adjNode}});
            }
        }
        
        sort(edges.begin(),edges.end());
        
        int ans  = 0;
        for(int i = 0;i<edges.size();i++){
            int ulp_u =  ds.findUpar(edges[i].second.first);
            int ulp_v =  ds.findUpar(edges[i].second.second);
            
            if(ulp_u==ulp_v){
                continue;
            }else{
                ans+= edges[i].first;
                ds.unionBySize(edges[i].second.first,edges[i].second.second);
                
            }
        }
        return ans;
    }
};
