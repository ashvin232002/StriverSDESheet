#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool bfs(int node,vector<int>& color,vector<vector<int>>& graph){
            queue<pair<int,int>>q;
            q.push({node,0});
            color[0]=0;


            while(!q.empty()){
                auto front  =  q.front();
                q.pop();

                for(auto it:graph[front.first]){
                    if(color[it]==-1){
                        color[it]= (front.second== 0 ? 1 : 0);
                        q.push({it,color[it]});
                    }else if(color[it]==front.second){
                        return false;
                    }
                }
            }
            return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);


        for(int i = 0;i<n;i++){
            if(color[i]==-1){
                if(!bfs(i,color,graph))return false;
            }
        }
       return true;
    }
};