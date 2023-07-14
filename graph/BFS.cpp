#include<bits/stdc++.h>
using namespace std;



class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
        queue<int>q;
        vector<int>ans;
        q.push(0);
        vector<int>Visited(V,0);
        Visited[0]=1;
        while(!q.empty()){
            int front  =  q.front();
            q.pop();
            ans.push_back(front);
            for(auto it:adj[front]){
                if(Visited[it]==1){
                    continue;
                }
                q.push(it);
                Visited[it]=1;
            }
        }
        return ans;
    }
};
