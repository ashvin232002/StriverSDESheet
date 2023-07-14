#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool recursion(int src,int col,vector<vector<int>>&graph,vector<int>&colorVec){
        colorVec[src]=col;
        for(auto it : graph[src]){
            if(colorVec[it]==-1){
                if(recursion(it,!col,graph,colorVec)==false){
                    return false;
                }
            }else if(colorVec[it]!=-1){
                if(colorVec[it]==col){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int m = graph[0].size();
        
        vector<int>colorVec(n,-1);
        for(int i =0;i<n;i++){
            if(colorVec[i]==-1){
                if(recursion(i,0,graph,colorVec)==false){
                    return false;
                }
            }
        }
        return true;
    }
};


//Bipartate odd length cycle
class Solution {
public:

    bool dfs(int node,vector<vector<int>>& graph,vector<int>& Visited,int count){
          Visited[node]=count;
          

          for(auto it:graph[node]){
              if(Visited[it]==0){
                  if(!dfs(it,graph,Visited,count+1))return false;
              }else if((count+1-Visited[it])%2==1){
                    return false;
              }
          }
          
          return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        //for dfs if the length of the cycle is odd then return false
        // if the length of the cycle is even no worries


        int n = graph.size();
        vector<int>Visited(n,0);
        int count  = 0;
        for(int i =0;i<n;i++){
            if(Visited[i]==0){
                if(!dfs(i,graph,Visited,count))return false;
            }
        }

        return true;
    }
};