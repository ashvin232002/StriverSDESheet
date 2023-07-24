#include<bits/stdc++.h>
using namespace std;

// dijksta's algorithm is usefull to find the sortd path

//Using Priority Queue Min Heap
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int>dist(V,1e9+7);
        dist[S]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,S});
        while(!pq.empty()){
            auto top  = pq.top();
            pq.pop();
            for(auto it :adj[top.second]){
                if(it[1]+top.first<dist[it[0]]){
                    dist[it[0]]=it[1]+top.first;
                    pq.push({dist[it[0]],it[0]});
                }
            }
        }
        return dist;
    }
};



//Using Set Data Structure
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int>dis(V,1e9);
        dis[S] = 0;
        set<pair<int,int>>s;
        s.insert({0,S});
        
        while(!s.empty()){
            auto top  =  *(s.begin());
            int node  =  top.second;
            int weight =  top.first;
            s.erase(top);
            
            
            for(auto it:adj[node]){
                if(weight+it[1] < dis[it[0]]){
                    if(dis[it[0]]!=1e9){
                        s.erase({dis[it[0]],it[0]});
                    }
                    
                   dis[it[0]]=weight+it[1];
                   s.insert({dis[it[0]],it[0]});
                }
            }
        }
        return dis;
    }
};
