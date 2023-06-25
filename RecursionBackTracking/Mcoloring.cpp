#include<bits/stdc++.h>
using namespace std;


//Important problem
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    
    bool isPossibleToassign(bool graph[101][101],vector<int>& color,int m,int n,int i,int assigncolor){
        for(int k =0;k<n;k++){
            if(graph[i][k]==1){
                if(color[k]==assigncolor){
                    return false;
                }
            }
        }
        return true;
    }
    bool recursion(bool graph[101][101] , vector<int>& color , int m ,int n,int  i){
        if(i==n){
            return true;
        }
        
        for(int j =0;j<m;j++){
            if(isPossibleToassign(graph,color,m,n,i,j)){
                color[i]=j;
                if(recursion(graph,color,m,n,i+1))return true;
                color[i]=-1;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<int>color(n,-1);
        return recursion(graph,color,m,n,0);
    }
};